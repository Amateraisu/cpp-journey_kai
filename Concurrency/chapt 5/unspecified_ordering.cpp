#include <bits/stdc++.h>



struct BigData {
    int array[100];
};

int get() {
    static int i = 0;

    return ++i;
}

void call(int a, int b) {
    std::cout << a << ' ' << b << '\n';
}

int main() {
    call(get(), get()); // unspecificed ordering

    return 0;
}
