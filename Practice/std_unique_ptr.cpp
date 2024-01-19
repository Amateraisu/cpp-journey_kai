#include <bits/stdc++.h>

// make_unique vs unique_ptr
//

class Unique_ptr {

};


int main() {

    std::unique_ptr<int>ptr(new int(1)); // this one calls the constructor and uses new. so it has less exception safety.
    // what if the current constructor is not available in my current namespace?

    auto myIntPtr = std::make_unique<int>(42);

}