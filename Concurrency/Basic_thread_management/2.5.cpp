
#include <thread>
#include <bits/stdc++.h>
using std::cout;

void some_function() {
    cout << "Hello world!\n";
}

std::thread f() {
    return std::thread(some_function);
}


