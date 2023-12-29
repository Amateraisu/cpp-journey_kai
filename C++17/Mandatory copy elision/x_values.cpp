//
// Created by admin on 30/12/2023.
//

struct myClass {
    myClass(myClass& other) = default;
    myClass& operator = (myClass&& other) {
        myClass temp(other); // x value because in this context it is a x value;

        return *this;
    }
};

