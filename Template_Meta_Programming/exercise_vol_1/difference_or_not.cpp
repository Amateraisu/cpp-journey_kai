#include <bits/stdc++.h>


template <int T>
void foo(int);


template <int T>
void foo() {
    std::cout << "T is " << T << '\n';

}


template <>
void foo<5>() {
    std::cout << "foo 5 is called! " << 5 << '\n';
    return;
}


int main() {
    foo<5>();
    foo<10>();


}
