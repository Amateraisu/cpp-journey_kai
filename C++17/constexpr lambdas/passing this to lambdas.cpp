#include <bits/stdc++.h>
using namespace std;



class myStruct {
public:
    int x{5};
    void foo() {
        auto v = [=](int y) -> int {
            cout << "changing the value inside the lambda copy by value\n";
            // this wuill still auto decay into a reference.
            x = 100;
            return y * y;
        };
        cout << v(10) << '\n';

        cout << "new current x value " << x << '\n';
    }

};

class WorkaroundStruct {
public:
    int x{5};
    void foo() {
        auto v = [*this](int y) mutable -> int {
            cout << "changing the value inside the lambda copy by value\n";
            // this wuill still auto decay into a reference.
            this->x = 100;
            return y * y;
        };
        cout << v(10) << '\n';

        cout << "new current x value " << x << '\n';
    }

};

int main() {
    myStruct c;
    c.foo();

    WorkaroundStruct c2;
    c2.foo();

}