#include "RuleOfFive.h"
#include <iostream>

using namespace std;


Kai::Kai() {
    cout << "Kai constructor is called!" << '\n';
}
Kai::Kai(Kai const& other) {
    cout << "COPY constructor is called!" << '\n';
}
Kai::~Kai() {
    cout << "DESTRUCTOR is called!\n";
}
Kai::Kai(Kai const&& other) {
    cout << "Move constructor is called!\n";
}
Kai& Kai::operator = (Kai const& other) {
    cout << "copy assignment operator is called!\n";
    return *this;
}
Kai& Kai::operator = (Kai const&& other) {
    cout << "move assingment operator is called!\n";
    return *this;
}


