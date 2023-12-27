#include <bits/stdc++.h>
using namespace std;

template <typename T>
class func;

template<typename Ret, typename ... Args>
class func<Ret(Args...)>{
public:
    // this takes in a function pointer
    func(Ret (*f)(Args...));
};


int f(int x) {
    return x;
}

int main() {
    std::function ptr = [](){};
    decltype(ptr) ptr2;
    std::function<int(int)>ptr3 = f;

    // now try to implement std::function here
    func<int(int)>ptr4{f};
    // now we need to have something callable.. ?

}


