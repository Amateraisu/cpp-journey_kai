#include <bits/stdc++.h>

// can do a brief recap of the rule of 5
struct user {
    int x{5};
    user() {}
    ~user(){} // 3rd
    user(user& u) {}; // first
    user& operator = (user& rhs) {} // second

    user(user&& rhs) {} // 4th
    user& operator = (user&& rhs) {} // 5th
};

// by default compiler generates the 5 basic rules
struct user2 {
    int x{10};
    // but by making copy elision optional, it relies on copy constructors
    user2(){}
    user2(user2& rhs) = delete;
    user2(user2&& rhs) = delete;
    user2& operator = (user2&& rhs) = delete;
};
// so there would be a compilation error here

void get(user x) {}

// this is a NRVO , hence requires a copy constructor
//user2 foo() {
//    user2 x;
//    return x;
//}

// same case as
user2 foo(user2 x) { // copy elision for passed temporaries
    return x;// invalid here because this is a copy construction, x still requires copy / move support because it is an l value;
}



user2 bar() {
    return user2{};
}
int main() {
    get(user{});  // passing temporaries
    user2 x = bar(); // declaring x and then using copy assignment operator to initialise it
    user2 y = foo(user2{}); // this is valid here but not in the function.

}
