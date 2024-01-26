#include <iostream>
using namespace std;

// To execute C++, please define "int main()"

struct animal {
    virtual ~animal(){}
    int x;
};

struct cat : virtual animal {
    int y;
};


struct dog: virtual animal {
    int z;
};

struct catDog: public cat, dog {
    int xyz;
};





int main() {
    cat c;
    cat* ptrCat = &c;
    animal* ptrAnimal = &c;
    std::cout << "Address of ptr animal " << ptrAnimal << '\n';
    ptrAnimal = dynamic_cast<cat*>(ptrAnimal);
    std::cout << "after dynamic casting " << ptrAnimal << '\n';
    std::cout << "Address does not change !\n";
    // casting to sibling base does not work because they are unrelated
    return 0;
}

