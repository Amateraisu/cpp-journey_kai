#include <bits/stdc++.h>

template <typename T>
struct MySharedPtr {
    MySharedPtr(T* ptr = nullptr):ptr_(ptr), cnt(new int(0)){
        if (ptr != nullptr)  increment();

    }
    MySharedPtr(MySharedPtr<T>& other) {
        ptr_ = other.ptr_;
        cnt = other.cnt;
        increment();
    }

    MySharedPtr(MySharedPtr<T>&& other) {
        ptr_ = other.ptr_;
        cnt = other.cnt;
        other.cnt = nullptr;
        other.ptr_ = nullptr;
    }

    MySharedPtr<T> operator = (MySharedPtr<T>& other) {
        if (this == &other) return *this;
        decrement();
        ptr_ = other.ptr_;
        cnt = other.cnt;
        increment();
        return *this;
    }

    MySharedPtr<T> operator = (MySharedPtr<T>&& other) {
        if (this == &other) return *this;
        decrement();
        ptr_ = other.ptr_;
        cnt = other.cnt;
        other.ptr_ = nullptr;
        other.cnt = nullptr;

        return *this;
    }
    void reset(T* ptr) {
        decrement();
        ptr_ = ptr;
        increment();

    }
    int use_count() {
        return *cnt;
    }
    ~MySharedPtr() {
        decrement();
    }
    void increment() {
        if (cnt == nullptr) cnt = new int(0);
        ++(*cnt);
    }

    T* get() {
        return ptr_;
    }

    void decrement() {
        if (cnt == nullptr) return;
        --(*cnt);
        if (*cnt == 0) {
            delete cnt;
            cnt = nullptr;
            delete ptr_;
            ptr_ = nullptr;
        }

    }
    T& operator * () {
        return *ptr_;
    }

private:
    T* ptr_;
    int* cnt;
};

void test_shared_ptr() {
    {
        auto ptr = MySharedPtr<int>(new int(10));
        assert(*ptr == 10); // Verify managed object value
    }
    {
        auto ptr1 = MySharedPtr<int>(new int(20));
        {
            auto ptr2 = ptr1; // Use the copy constructor
            assert(*ptr2 == 20); // Verify copied value
            // Assuming you have a method to check reference count:
            assert(ptr1.use_count() == 2 && ptr2.use_count() == 2); // Verify ref count is 2
        }
        assert(ptr1.use_count() == 1); // Verify ref count is back to 1 after ptr2 is destroyed
    }
    {
        auto ptr1 = MySharedPtr<int>(new int(30));
        auto ptr2 = std::move(ptr1); // Use the move constructor
        assert(ptr1.get() == nullptr); // Verify ptr1 is null after move
        assert(*ptr2 == 30); // Verify ptr2 has the correct value
        // Assuming use_count() works correctly with moved-from objects:
        assert(ptr2.use_count() == 1); // Verify ptr2's ref count is correct
    }
    {
        auto ptr1 = MySharedPtr<int>(new int(40));
        MySharedPtr<int> ptr2;
        ptr2 = ptr1; // Use the copy assignment operator
        assert(*ptr1 == 40 && *ptr2 == 40); // Verify both point to the same value
        assert(ptr1.use_count() == 2 && ptr2.use_count() == 2); // Verify ref count is 2
    }
    {
        auto ptr1 = MySharedPtr<int>(new int(50));
        MySharedPtr<int> ptr2;
        ptr2 = std::move(ptr1); // Use the move assignment operator
        assert(ptr1.get() == nullptr); // Verify ptr1 is null after move
        assert(*ptr2 == 50); // Verify ptr2 has the correct value
        assert(ptr2.use_count() == 1); // Verify ptr2's ref count is correct
    }

    {
        auto ptr = MySharedPtr<int>(new int(60));
        ptr.reset(new int(70)); // Reset to manage a new object
        assert(*ptr == 70); // Verify the managed object is the new one
        // Check ref count if applicable. It should be 1 for a newly managed object:
        assert(ptr.use_count() == 1);
    }
    {
        auto ptr = MySharedPtr<int>(new int(80));
        ptr = ptr; // Self-copy assignment
        assert(*ptr == 80 && ptr.use_count() == 1); // Should be no-op
//
        auto ptr2 = MySharedPtr<int>(new int(90));
        ptr2 = std::move(ptr2); // Self-move assignment
        assert(*ptr2 == 90 && ptr2.use_count() == 1); // Should be no-op or safe
    }







}


int main() {
    test_shared_ptr();
    std::cout << "All assert statements passed!\n";
    return 0;
}