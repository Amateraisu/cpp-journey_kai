#include <bits/stdc++.h>
using namespace std;

class C {
    const int data{};
    C() {
        cout << "C is constructed!\n";
    }
    void operator () () const {
        cout << "Calling from inside an object!\n";
    }
};

int main() {
    // lambdas are just objects with overloaded ()
    // they have a name also called functors
    auto c = [](){
        cout << "Calling from a functor!\n";
    };

    // an empty functor;
}
