#include <bits/stdc++.h>
using namespace std;


void func() {
    int i = 0;
    std::cout << "address of func " << std::addressof(i) << '\n';
}

void func2() {
    int i = 0;
    std::cout << "address of func2 " << std::addressof(i) << '\n';

}

int main() {
    std::cout << "Hello world!\n";
    func();
    func2();
}