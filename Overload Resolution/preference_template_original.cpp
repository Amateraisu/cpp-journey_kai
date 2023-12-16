#include <bits/stdc++.h>

int call(int a, int b) {
    std::cout << "Non templated is called!\n";
    return b;
}

template <typename t1>
t1 call(t1 a, t1 b) {
    std::cout << "Templated is called!\n";
    return b;
}


int main() {


    call(1, 2);

    return 0;
}
