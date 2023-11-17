//
// Created by admin on 17/11/2023.
//
#include <iostream>
#include "corotask.hpp"

#ifndef RULE_CORO_HPP
#define RULE_CORO_HPP

CoroTask coro(int max) {
    std::cout << "           CORO " << max << " start\n";
    for (int val = 1; val <= max; ++val) {
        std::cout << "       CORO " << val << '/' << max <<'\n';
        co_await std::suspend_always();
    }

    std::cout << "          CORO " << max << " end\n";
}


#endif //RULE_CORO_HPP
