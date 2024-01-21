#include <bits/stdc++.h>
#include <atomic>


int main() {
    std::atomic<int>x(10);
    x += 1;
    x += 2;
    x = x + 5; // not an atomic operation!
//    x *= 2; // not supported!
//    x /= 2;// not supported too !
// and many others .
// methods==========
    int val = x.load();
    x.store(20);

    // or we can use both combined into one
    int old_val = x.fetch_add(5);
    int old_val2 = x.fetch_sub(10);
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    flag.clear();
    if (!flag.test_and_set()) {
        std::cout << "FLAG WAS NOT SET BEFORE!\n";
    }
    std::cout << "FLAG IS SET!\n";


}
