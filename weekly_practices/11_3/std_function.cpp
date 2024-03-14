#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
// implement std:: function
template <typename T>
struct MyFunction;

template <typename Ret, typename... Args>
struct MyFunction<Ret(Args...)> {
    // we have a constructor which takes in a pointer to a function of return type Ret and takes in a bunch of arguements Args...
    MyFunction(Ret(*f)(Args...) = nullptr):ptr_{std::make_unique<child<decltype(f)>>(f)}{}

    // copy constructor
    MyFunction(const MyFunction<Ret(Args...)>& other) {
        // I need to duplicate this
        ptr_ = nullptr;
        if (other.ptr_ != nullptr) ptr_ = other.ptr_->clone();


    }

    // assignment operator
    MyFunction& operator=(const MyFunction<Ret(Args...)>& other) {
        if (this == &other) {
            // Handle self-assignment: do nothing
            return *this;
        }

        // Clone the other's ptr_ if it's not nullptr, else set ptr_ to nullptr
        ptr_ = other.ptr_ ? other.ptr_->clone() : nullptr;

        return *this;
    }




    Ret operator() (Args... args) {
        return ptr_->call(args...);
    }

    struct base {
        base() = default;
        virtual Ret call(Args...) = 0;
        virtual std::unique_ptr<base> clone() const = 0;
        virtual ~base() = default;
    };
    // what about copy constructors ?
    template <typename T>
    struct child: base {
        child(T callable):callable_(std::move(callable)){}
        Ret call(Args... args) override {
            return callable_(args...);
        }

        std::unique_ptr<base> clone() const override {

            return std::make_unique<child<T>>(*this);
        }



        ~child(){
            cout << "destructor!\n";
        }

        T callable_;
    };




private:

    std::unique_ptr<base>ptr_;
};


void testFunction() {
    assert(true); // Simplest test to confirm that the function is called.
}

int add(int a, int b) {
    return a + b;
}



int main() {
    MyFunction<void(void)> func(testFunction);
    func(); // Should call testFunction without any issue.
    cout << "Passed basic functionality!\n";
    MyFunction<int(int, int)> addFunc(add);
    assert(addFunc(2, 3) == 5);
    cout << "Passed basic functionality 2 ! \n";

    MyFunction<int(int, int)> lambdaFunc([](int a, int b) { return a - b; });
    assert(lambdaFunc(5, 3) == 2);
    cout << "Passed lambda functionality! \n";

    MyFunction<int(int, int)> originalFunc([](int a, int b) { return a * b; });
    MyFunction<int(int, int)> copyFunc = originalFunc; // Copy constructor
    assert(copyFunc(3, 4) == 12);

    cout << "Passed copy constructor functionality!\n";

    MyFunction<int(int, int)> assignedFunc;
    assignedFunc = originalFunc; // Assignment operator
    assert(assignedFunc(3, 4) == 12);

    cout << "Passed assignmnet operator functionality!\n";




    return 0;
}

