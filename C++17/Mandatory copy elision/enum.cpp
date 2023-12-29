#include <bits/stdc++.h>

enum month {
    Jan,
    Feb,
    Mar,
    Apr,
    month_end
}; // treated as distinct types


typedef enum month month;

// cannot use parameters of pointer types
// hence we need references
month& operator ++ (month& x) {
    x = static_cast<month>(x + 1);
    return x;
}


int main() {

    // this doesnt compile in C++, but compiles in C because of move semantics
    for (month m = Jan; m <= month_end; ++m) {

    }
    std::cout << month::Jan << '\n';

}

