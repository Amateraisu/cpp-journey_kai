//
// Created by admin on 29/12/2023.
//

struct A {
    static constexpr int x = 5;
};

struct B {
    inline static constexpr int x = 6;
};
// they are the same here since C++17;
