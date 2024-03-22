#include <thread>
#include <iostream>
using namespace std;

void do_something() {

}
struct background {
    void operator() () const {
        do_something();
    }
};

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):t(t_){}
    thread_guard(std::thread const& t_) = delete;
    std::thread& operator = (std::thread const& t_) = delete;
    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }

};

void f1() {
    int some_local_state = 0;
    background b;
    std::thread t(b);
    try {
        do_something();
    } catch(...) {
        t.join();
        throw;
    }
    t.join();
    // this state is hard to keep track , so we prefer to use RAII

}

void f2() {
    background b;
    std::thread t(b);
    thread_guard g(t);
}


int main() {

}
