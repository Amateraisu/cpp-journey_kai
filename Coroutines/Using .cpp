//
// Created by admin on 17/11/2023.
//
#include <bits/stdc++.h>
#include "corotask.hpp"

void coro(int max) {
    std::cout << "CORO " << max << " start\n";
    for (int i = 1; i <= max; ++i) {
        std::cout << "CORO " << i << '/' << max << '\n';
    }
    std::cout << "CORO" << max << " END" << '\n';
}
