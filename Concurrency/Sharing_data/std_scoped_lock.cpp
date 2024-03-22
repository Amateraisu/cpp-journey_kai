#include <thread>
#include <mutex>
std::mutex m1;
std::mutex m2;


void something() {
    std::lock_guard<std::mutex>g(m1);
}

void do_something() {
    // there is some algorithm to avoid deadlock, and can take in multiple mutexes.
    std::scoped_lock g(m1, m2); // C++ 17,
}


