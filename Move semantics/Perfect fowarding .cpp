#include <bits/stdc++.h>
// perfect forwarding has 3 cases.
// it means to forward objects to be used later on
// read only objects
// modifiable objects to be modified later
// constant unmodifyable objects

void foo(int const x) {
    return;
}

void foo(int& x) {}


int main() {

    foo(5);


    return 0;
}