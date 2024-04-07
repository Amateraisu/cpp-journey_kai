#include <bits/stdc++.h>




template <typename T>
class thread_safe_queue {
public:
    thread_safe_queue() {}
    thread_safe_queue(thread_safe_queue const& other) {
        std::lock_guard<std::mutex>lk(mut);
        data_queue = other.data_queue;
    }
    thread_safe_queue& operator = (const thread_safe_queue&) = delete;
    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
    }
    bool try_pop(T& value) {
        std::lock_guard<std::mutex>lk(mut);
        if (data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    // an overload in improvement of the previous method
    std::shared_ptr<T> try_pop() {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty()) return std::make_shared<T>();
        std::shared_ptr<T> res = std::make_shared<T>(data_queue.front());
        data_queue.pop();

        return res;
    }

    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        // so this will first, lock the
        cond_variable.wait(lk, [this](){return !data_queue.empty();});
        value = data_queue.front();
        data_queue.pop();
        return;
    }

    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mut);

        cond_variable.wait(lk, [this](){return !data_queue.empty();});

        std::shared_ptr<T> res = std::make_shared<T>(data_queue.front());
        data_queue.pop();

        return res;
    }
    bool empty() {

        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }







private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable cond_variable;
};
