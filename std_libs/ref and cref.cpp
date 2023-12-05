#include <bits/stdc++.h>

namespace std {
    template <typename T>
    class reference_Wrapper {
    private:
        T* ptr;
    public:
        reference_Wrapper(T& ref): ptr(&ref) {}
    };

    template <typename T>
    reference_Wrapper<T> ref(const T& other) {
        return reference_Wrapper(other);
    }
}



int main() {


    return 0;
}
