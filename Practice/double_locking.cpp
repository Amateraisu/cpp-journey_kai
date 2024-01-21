#include <bits/stdc++.h>
#include <atomic>

struct T{};
// double locking
bool compare_exchange_weak(T& old_v, T new_v) {

    T tmp = value;
    if (tmp != old_v) {
        old_v = tmp;
        return false;
    }
    TimedLock L;
    tmp = value;
    if (tmp != old_v) {
        old_v = tmp;
        return false;
    }
    value = new_v;
    return true;
}

int main() {
    std::cout << "Hello I am Kai!\n";
}