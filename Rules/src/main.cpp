#include <iostream>
#include "RuleOfFive.h"


int main() {
    std::cout << "HELLO WORLD!\n";
    Kai k;
    Kai k2 = k;
    Kai k3(std::move(k));
    Kai k4 = std::move(k2);
    return 0;
}
