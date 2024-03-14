#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

template <typename T, typename Obj>
Obj my_for_each(T iterStart, T iterEnd, Obj callable) {
    while (iterStart != iterEnd) {
        callable(*iterStart);
        ++iterStart;


    }

    return callable;
}


template <typename T, typename Obj, typename... Args>
Obj my_for_each2(T iterStart, T iterEnd, Obj callable, Args&... args) {
    cout << __PRETTY_FUNCTION__ << '\n';
    while (iterStart != iterEnd) {
        std::invoke(callable,
                    args... ,
                    *iterStart);

        ++iterStart;
    }

    return callable;
}

// template <typename T, typename O, typename Obj, typename... Args>
// Obj my_for_each2(T iterStart, T iterEnd, Obj callable, O obj) {
//   while (iterStart != iterEnd) {
//     std::invoke(callable,
//                 obj,
//                 *iterStart);

//     ++iterStart;
//   }

//   return callable;
// }



struct Obj {
    void memberFunc(int i) {
        cout <<  " Member func called! " << i << '\n';
    }
};

// vector<int>P= {2, 3, 5, 7, 11};
// my_for_each2(P.begin(), P.end(), [](string const& str,string const& str2 , int i) {
//   std::cout << str << ' ' << i << '\n';
//   cout << str2 << '\n';

// }, "TestString1 \n", "TestString2\n");
// std::cout << "This works for non member functions still ! std::invoke \n";
// Obj obj;
// my_for_each2(P.begin(), P.end(), &Obj::memberFunc, obj); // this line here, why does it only work for the second and not the first for_each?

// why wont the for_each with template parameter template <typename T, typename Obj, typename... Args>
// work for P.begin(), P.end(), &Obj::memberFunc, obj ?
// args.... should expand to obj no ?



int main() {
    // Test 1: Ensure each element is processed
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = 0;
    my_for_each(numbers.begin(), numbers.end(), [&sum](int n) { sum += n; });
    assert(sum == 15);

    // Test 2: Ensure elements can be modified
    my_for_each(numbers.begin(), numbers.end(), [](int& n) { n *= 2; });
    assert((numbers == std::vector<int>{2, 4, 6, 8, 10}));
    // Test 3: Check the order is maintained
    std::vector<int> originalOrder = numbers;
    my_for_each(numbers.begin(), numbers.end(), [](int& n) { n += 1; }); // Increment each element
    for (size_t i = 0; i < numbers.size(); ++i) {
        assert(numbers[i] == originalOrder[i] + 1);
    }

    // Test 4: Work with different container types, like array
    int arr[] = {5, 10, 15};
    my_for_each(std::begin(arr), std::end(arr), [](int& n) { n -= 1; });
    assert(arr[0] == 4 && arr[1] == 9 && arr[2] == 14);

    // Test 5: Handle empty containers
    std::vector<int> empty;
    bool called = false;
    my_for_each(empty.begin(), empty.end(), [&called](int) { called = true; });
    assert(!called);

    // Test 6: Check return value is the function object
    sum = 0; // reset sum
    auto lambda = [&sum](int n) { sum += n; };
    auto returned = my_for_each(numbers.begin(), numbers.end(), lambda);
    cout << sum << '\n';
    assert(sum == 35); // Sum after modifying numbers in previous tests
    returned(4); // Test if the returned function can be called
    assert(sum == 39);
    cout << "All test cases passed, for general functions!\n";
    vector<int>P= {2, 3, 5, 7, 11};
    my_for_each2(P.begin(), P.end(), [](string const& str,string const& str2 , int i) {
        std::cout << str << ' ' << i << '\n';
        cout << str2 << '\n';

    }, "TestString1 \n", "TestString2\n");
    std::cout << "std::invoke: Lambda case passed \n";
    Obj obj;
    my_for_each2(P.begin(), P.end(), &Obj::memberFunc, obj);
    // my_for_each2(P.begin(), P.end(), &Obj::memberFunc, obj);
    std::cout << "Std::invoke: member functions case passed! \n";

    return 0;
}
