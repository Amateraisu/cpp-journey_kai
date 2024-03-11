#include <bits/stdc++.h>


template <typename T>
struct MyUniquePtr {
    MyUniquePtr(T* ptr = nullptr):ptr_{ptr} {
    } // constructor
    MyUniquePtr(MyUniquePtr<T>& other) = delete; // copy constructor

    MyUniquePtr(MyUniquePtr<T>&& other) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    MyUniquePtr<T>& operator = (MyUniquePtr<T>&& other) {
        if (this == &other) return *this;
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;

    }

    ~MyUniquePtr() {
        if (ptr_) delete ptr_;

        ptr_ = nullptr;
    }

    T* release() {
        auto* temp = ptr_;
        ptr_ = nullptr;

        return temp;
    }

    void reset(T* ptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    T* get() {
        return ptr_;
    }

    T* operator -> (){
        if (ptr_ == nullptr) {
            throw std::runtime_error("Dereferencing a nullptr");
        }
        return ptr_;
    }

private:
    T* ptr_;

};


class TestObject {
public:
    int value;
    TestObject(int value) : value(value) {}
};

void testDefaultConstructor() {
    MyUniquePtr<TestObject> ptr;
    assert(ptr.get() == nullptr); // Test 1: Default constructor initializes to nullptr
}

void testPointerConstructor() {
    auto* rawPtr = new TestObject(10);
    MyUniquePtr<TestObject> ptr(rawPtr);
    auto* rawPtr2 = new TestObject(20);
    MyUniquePtr<TestObject>ptr2(rawPtr2);
    assert(ptr.get() == rawPtr); // Test 2: Pointer constructor sets internal pointer
    assert(ptr->value == 10); // Test 3: Check dereference operator
    assert(ptr2->value == 20);
}

void testMoveConstructor() {
    MyUniquePtr<TestObject> ptr1(new TestObject(20));
    MyUniquePtr<TestObject> ptr2(std::move(ptr1));
    assert(ptr1.get() == nullptr); // Test 4: ptr1 should be null after move
    assert(ptr2->value == 20); // Test 5: ptr2 now owns the object
}

void testMoveAssignment() {
    MyUniquePtr<TestObject> ptr1(new TestObject(30));
    MyUniquePtr<TestObject> ptr2;
    ptr2 = std::move(ptr1);
    assert(ptr1.get() == nullptr); // Test 6: ptr1 should be null after move assignment
    assert(ptr2->value == 30); // Test 7: ptr2 now owns the object
}

void testReset() {
    MyUniquePtr<TestObject> ptr(new TestObject(40));
    ptr.reset(new TestObject(50));
    assert(ptr->value == 50); // Test 8: Reset should replace the managed object
}

void testRelease() {
    auto* rawPtr = new TestObject(60);
    MyUniquePtr<TestObject> ptr(rawPtr);
    auto* releasedPtr = ptr.release();
    assert(ptr.get() == nullptr); // Test 9: UniquePtr should be null after release
    assert(releasedPtr == rawPtr); // Test 10: The released pointer matches the original
    delete releasedPtr; // Clean up
}

void testDestructor() {
    auto* rawPtr = new TestObject(70);
    {
        MyUniquePtr<TestObject> ptr(rawPtr);
    } // Test 11: Destructor should delete managed object, use a tool like Valgrind to check for leaks
}





int main() {
    testDefaultConstructor();
    testPointerConstructor();
    testMoveConstructor();
    testMoveAssignment();
    testReset();
    testRelease();
    testDestructor();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
