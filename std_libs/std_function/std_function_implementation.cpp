#include <bits/stdc++.h>
#include <memory>
template<typename T>
class function;

template<typename Ret, typename ... Param>
class function<Ret(Param...)>{

public:
    function(Ret (*f)(Param...));
    Ret operator () (Param... param) {
        return callable->call(param...);
    }
private:
    struct function_interface {
        virtual Ret call(Param...) = 0;
        virtual ~function_interface() = default;
    };

    std::unique_ptr<function_interface>callable;

};

int f(int x, int y) {
    return x + y;
}


int main() {
    function<int(int, int)>func{f};
}
