// by value
#include <iostream>
class is_above {
public:
    is_above(int x): x{x} {}
    auto operator () (int y) const {
        return y > x;
    }
private:
    int x;
};

// by refrence
class isAbove {
public:
    isAbove(int x): x{x} {}
    auto operator () (int y) const {
        return y > x;
    }
private:
    int& x;
};

//mutating with reference

class Lambda {
private:
    int& x;
public:
    Lambda(int m): x{m} {}
    auto operator () () const {
        std::cout << x << '\n';
        ++x;
    }
};

// mutating without reference

class Lmbda {
private:
    int x;
public:
    Lmbda(int m): x{m} {}
    auto operator () () const {
        std::cout << x << '\n';
//        ++x; it will cause an error , add mutable
    }
};



int main(){
    auto x = 3;
    auto is_above = [x](int y) mutable {
        return y > x;
    };
    auto test = is_above(5);



}

