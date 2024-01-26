#include <bits/stdc++.h>


struct alignas(64) padded_atomic{
    std::atomic<int>value{0};
};


void update(std::atomic<int>& atom) {
    for (int i = 0; i < 10000; ++i) {
        ++atom;
    }
}

void update(padded_atomic& a) {
    for (int i = 0; i < 10000; ++i) {
        ++a.value;
    }
}

void multiple_thread() {
    std::atomic<int>a, b, c, d;

    std::thread t1([&](){update(a);});
    std::thread t2([&](){update(b);});
    std::thread t3([&](){update(c);});
    std::thread t4([&](){update(d);});

    t1.join();
    t2.join();
    t3.join();
    t4.join();

}
void single_thread() {
    std::atomic<int>a, b, c, d;
    a = b= c=d = 0;
    // std::cout << &a << '\n';
    // std::cout << std::addressof(b) << '\n';
    // std::cout << std::addressof(c) << '\n';
    // std::cout << std::addressof(d) << '\n';
    update(a);
    update(b);
    update(c);
    update(d);
}

void updated_thread() {
    padded_atomic a, b, c, d;
    std::thread t1([&](){update(a);});
    std::thread t2([&](){update(b);});
    std::thread t3([&](){update(c);});
    std::thread t4([&](){update(d);});
    std::cout << std::addressof(a) << '\n';
    std::cout << std::addressof(b) << '\n';
    std::cout << std::addressof(c) << '\n';
    std::cout << std::addressof(d) << '\n';
    t1.join();
    t2.join();
    t3.join();
    t4.join();

}

int main() {
    // multiple_thread(); // (took 3.94s)
    updated_thread(); // took 3.77s
    // single_thread();

}
