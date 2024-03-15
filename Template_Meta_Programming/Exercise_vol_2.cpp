// https://www.slamecka.cz/posts/2021-12-05-cpp-metaprogramming-exercises-2/
//
// A set of exercises for type level programming in C++ suitable for programmers with
// intermediate knowledge of template programming and algorithm problems.
//
// Scope:
// - Standard template metaprogramming techniques of moderate difficulty.
// - Focused on algorithm problems.
//
// How to solve it:
// - Make sure you understand topics from Set 1.
// - You should be able to compile with gcc version 11.2, g++ --std=c++20 typelevel_set2.cpp
// - Tests are commented-out and you should uncomment them as you go.
// - You might want to solve the problems on value level first.

#include <algorithm>
#include <iostream>
#include <type_traits>

namespace {

/**
 * 1. Define Fibonacci to contain the n-th number in the series 0,1,1,2,3,5,8,13,...
 *
 * Try three implementations:
 * - Using templated structs (hint: use the SFINAE Enable trick).
 * - Recursive constexpr function.
 * - Iterative constexpr function.
 *
 * Measure the compilation time of each implementation. Observe how the templated-structs implementation
 * is a direct implementation of the recursive definition of Fibonacci sequence, yet it's as fast as the
 * iterative implementation thanks to memoization built into the template system.
 */

// Your code goes here:
// general template


//====================================
// number 1, SFINAE enable trick
// template <int, typename = void>
// struct Fibonacci;

// template <int I>
// struct Fibonacci<I, typename std::enable_if<I == 0>::type> {
//   constexpr static int value = 0;
// };

// template <int I>
// struct Fibonacci<I, typename std::enable_if<I == 1>::type> {
//   constexpr static int value = 1;
// };

// template <int I>
// struct Fibonacci<I, typename std::enable_if< I >= 2>::type> {
//   constexpr static int value = Fibonacci<I - 1>::value + Fibonacci<I - 2>::value;

// };

// // primary template
// template <int>
// struct Fibonacci;

// // explicit specialization
// template <>
// struct Fibonacci<0> {
//   constexpr static int value = 0;
// };

// template <>
// struct Fibonacci<1> {
//   constexpr static int value = 1;
// };

// template <int I>
// struct Fibonacci {
//   constexpr static int value = Fibonacci<I - 1>::value + Fibonacci<I - 2>::value;
// };


// number 3
// iterative approach

    constexpr int fib(int i) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        int p1 = 0;
        int p2 = 1;
        int res = -1;
        for (int j = 2; j <= i; ++j) {
            res = p1 + p2;
            p1 = p2;
            p2 = res;

        }
        return res;

    }

    template <int>
    struct Fibonacci;

    template <int I>
    struct Fibonacci {
        constexpr static int value = fib(I);
    };










// ^ Your code goes here

    static_assert(Fibonacci<0>::value == 0);
    static_assert(Fibonacci<1>::value == 1);
    static_assert(Fibonacci<2>::value == 1);
    static_assert(Fibonacci<3>::value == 2);
    static_assert(Fibonacci<4>::value == 3);
    static_assert(Fibonacci<5>::value == 5);
    static_assert(Fibonacci<6>::value == 8);
    static_assert(Fibonacci<7>::value == 13);
    static_assert(Fibonacci<41>::value % 2 == 1); // Useful for benchmarking, make sure your compiler calculates LHS.


/**
 * 2. Define Concat that takes two vectors and concatenates them into one.
 *
 * This is a warmup before the next exercise.
 */

    template<int...>
    struct Vector
    {};

// Your code goes here:
    template <typename V1, typename V2>
    struct Concat;


    template <int... I1, int... I2>
    struct Concat<Vector<I1...>,  Vector<I2...>> {
        using type = Vector<I1... , I2...>;
    };



// ^ Your code goes here

    static_assert(std::is_same_v<Concat<Vector<1,2>, Vector<3,4>>::type, Vector<1,2,3,4>>);
    static_assert(std::is_same_v<Concat<Vector<455, 200>, Vector<0, 0>>::type, Vector<455, 200, 0, 0>>);
    static_assert(std::is_same_v<Concat<Vector<200>, Vector<>>::type, Vector<200>>);


/**
 * 3. Run Length Encoding
 */

// Your code goes here:
// the run length encoding makes it become a
// I need to build the Vector subarray, keep incrementing a value but until I see a different value ?

// base case
    template <int...>
    struct RLE;

    template<>
    struct RLE<> {
        using type = Vector<>;
    };

    template <int I1, int... Is>
    struct RLE<I1, Is...> {

    };


// ^ Your code goes here


    static_assert(std::is_same_v< RLE<>::type, Vector<> >);
// static_assert(std::is_same_v<RLE<0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1>::type, Vector<5,0,2,1,12,0,1,1>>);
// static_assert(std::is_same_v<RLE<1,1,1,1,9,9,9,2>::type, Vector<4,1,3,9,1,2>>);


/**
 * 4. Minimum Subset Sum Difference
 *    Given a set of numbers, consider partitioning them into two sets, summing each to receive two numbers.
 *    Find the absolute difference between these two numbers that is the smallest (over all possible partitions).
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(MSSD<>::value == 0);
// static_assert(MSSD<1>::value == 1);
// static_assert(MSSD<1, 1>::value == 0);
// static_assert(MSSD<1, 1, 1>::value == 1);
// static_assert(MSSD<20, 30, 10, 10, 20>::value == 10);
// static_assert(MSSD<5, 20, 25, 10, 10, 20>::value == 0);
// static_assert(MSSD<5, 10, 15, 20, 25, 10, 10, 20>::value == 5);


/**
 * 5. Define type Middle to contain the middle letter of a string with an odd length.
 *
 * We'll need a type level string container (requires C++20).
 * This is a warmup before the next exercise.
 */
    template<size_t N>
    struct MetaString {
        constexpr MetaString(const char (&s)[N])
        {
            std::copy_n(s, N, value);
        }

        char value[N];
        std::size_t size = N;
    };

    template<MetaString S>
    struct Middle
    {
// Your code goes here:
// ^ Your code goes here
    };

// static_assert(Middle<"abc">::value == 'b');
// static_assert(Middle<"abcde">::value == 'c');

/**
 * 6. Define DeletesToEqual which calculates the minimum number of letters to delete from two strings to make
 * them equal.
 *
 * (This is a simplification of the well-known edit distance problem.)
 */

// Your code goes here:
// ^ Your code goes here

// static_assert(DeletesToEqual<"a", "b">::value == 2);
// static_assert(DeletesToEqual<"abc", "bcd">::value == 2);
// static_assert(DeletesToEqual<"abcd", "bcd">::value == 1);
// static_assert(DeletesToEqual<"abc", "xbz">::value == 4);
// static_assert(DeletesToEqual<"ababa", "bb">::value == 3);
// static_assert(DeletesToEqual<"chocolatefactory", "charlie">::value == 15);

}

int main()
{
}
