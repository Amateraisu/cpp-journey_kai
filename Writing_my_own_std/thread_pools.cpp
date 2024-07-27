#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <future>
#include <chrono>

// Macros to measure time
#define TIME_START(label) auto start_##label = std::chrono::high_resolution_clock::now();
#define TIME_END(label) auto end_##label = std::chrono::high_resolution_clock::now(); \
                        std::cout << #label << " duration: " \
                                  << std::chrono::duration_cast<std::chrono::microseconds>(end_##label - start_##label).count() \
                                  << " microseconds." << std::endl;

namespace MySpace {
    class ThreadPool {
    private:
        int worker_num_;
        int tasks_size_;

        bool stop = false;

        std::vector<std::thread> workers_;
        std::mutex mut_;
        std::condition_variable cv_;
        std::queue<std::function<void()>> tasks_queue_;

    public:
        ThreadPool(int worker_num, int tasks_size) :
                worker_num_(worker_num),
                tasks_size_(tasks_size) {
            // Start worker threads
            for (int i = 0; i < worker_num_; ++i) {
                workers_.emplace_back([this]() {
                    for (;;) {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lk(this->mut_);
                            this->cv_.wait(lk, [this]() {
                                return this->stop || !this->tasks_queue_.empty();
                            });
                            if (this->stop && this->tasks_queue_.empty()) return;
                            task = std::move(this->tasks_queue_.front());
                            this->tasks_queue_.pop();
                        }
                        task();
                    }
                });
            }
        }

        ~ThreadPool() {
            {
                std::unique_lock<std::mutex> lk(this->mut_);
                stop = true;
            }
            this->cv_.notify_all();
            for (std::thread &worker : workers_) {
                worker.join();
            }
        }

        template <typename F, typename... Args>
        auto enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> {
            using ReturnType = std::invoke_result_t<F, Args...>;
            auto task = std::make_shared<std::packaged_task<ReturnType()>>(
                    std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );
            std::future<ReturnType> res = task->get_future();
            {
                std::unique_lock<std::mutex> lk(this->mut_);
                if (stop) {
                    throw std::runtime_error("enqueue on stopped ThreadPool");
                }
                this->tasks_queue_.emplace([task]() { (*task)(); });
            }
            this->cv_.notify_one();
            return res;
        }
    };
}

void loop1() {
    int j = 0;
    for (int i = 0 ; i < 1e5 ; ++i) {
        j += 1;
    }
}

void loop2() {
    int j = 0;
    for (int i = 0; i < 1e6; ++i) {
        j++;
    }
}

int main() {
    MySpace::ThreadPool pool(2, 2);
//    TIME_START(pool)
//    TIME_END(pool)
    auto start = std::chrono::high_resolution_clock::now();
    auto future1 = pool.enqueue(loop1);
    auto future2 = pool.enqueue(loop2);
    future1.get();
    future2.get();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';




    return 0;
}
