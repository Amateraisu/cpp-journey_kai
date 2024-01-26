#include <iostream>

template <typename T>
struct Vector {
    Vector(): size{0}, capacity{1}, ptr{new T[1]} {}

    void push_back(T obj) {
        if (size == capacity) {
            expand();
        }
        ptr[size++] = obj;
    }

    int size_() const {
        return size;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& operator[](int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return ptr[index];
    }

    ~Vector() {
        delete[] ptr;
    }

private:
    void expand() {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
    }

    int size;
    int capacity;
    T* ptr;
};

int main() {
    Vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    for (int i = 0; i < nums.size_(); ++i) {
        std::cout << nums[i] << '\n';
    }
}
