#include <bits/stdc++.h>
using namespace std;

class C {
    int data{};
    C() {
        cout << "C is constructed!\n";
    }
    void operator () () {
        cout << "Calling from inside an object!\n";
    }
};

int main() {
    // lambdas are just objects with overloaded ()
    // they have a name also called functors
    auto c = []() mutable {
        cout << "Calling from a functor!\n";
    };
    c();
    // an empty functor;
}