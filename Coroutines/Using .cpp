//
// Created by admin on 17/11/2023.
//
#include <bits/stdc++.h>
#include "coro.hpp"

int main() {


    auto coroTask = coro(3);
    std::cout << "Coro() started!\n";
    while (coroTask.resume()) {
        std::cout << "coro() suspended\n";
    }
    std::cout << "coro() ended!\n";
}
