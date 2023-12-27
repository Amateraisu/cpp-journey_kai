//
// Created by admin on 27/12/2023.
//
#include <bits/stdc++.h>

class pool {
        enum {
        size = 0x3f3f3f3f;
    };
public:
    // whatever
private:

    char mem_[size];
};
// problem of not being able to expand the memory.
// cannot guarantee objects of other types can be aligned properly, such as int. because for ints they are typicall 4 or 8 bytes,
// so the memory address needs to be in multiples of that.

// what about this then ?

class pool2 {
    const std::size_t size_;
public:
    // whatever
    pool2(): size_{0xffff}, mem_{new char[size_]} {}

private:
    char* mem_;
};