#include <bits/stdc++.h>
class String {
private:
    char* ptr_{nullptr};
    unsigned int capacity_{0};
    unsigned int size_{0};
public:
    unsigned int size() const noexcept {
        return size_;
    }
    unsigned int capacity() const noexcept {
        return capacity_;
    }
    char operator [] (int index) const {
        assert(index + 1 <= size_);

        return ptr_[index];
        // error!
    }
    String() {
        std::cout << "declaration here \n";
    }
    ~String() {
        // 3rd
        delete[] ptr_;
        ptr_ = nullptr;
        return;

    }
    String(const char* ptr) {
        size_ = strlen(ptr);
        ptr = new char[size_ + 1];
        strcpy(ptr_, ptr);
    }
    String(String& rhs) {
        // 1st
        // copy constructor
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;
        delete[] ptr_;
        ptr_ = new char[size_ + 1];
        strcpy(ptr_, rhs.ptr_);
    }
    String(String&& rhs) { // move constructor;
        // 4th rule
        capacity_ = rhs.capacity_;
        rhs.capacity_ = 0;
        size_ = rhs.size_;
        rhs.size_ = 0;
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;

    }
    // move assignement
    String& operator = (String&& rhs) {
        capacity_ = rhs.capacity_;
        rhs.capacity_ = 0;
        size_ = rhs.size_;
        rhs.size_ = 0;
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
        return *this;
    }

    String& operator = (String& rhs) {
        // 2nd
        if (this != &rhs) {
            delete[] ptr_;
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            ptr_ = new char[size_ + 1];
            strcpy(ptr_, rhs.ptr_);
        }
        return *this;
    }
    // 5th rule ?







};


int main() {
    String str1;
    String str2 = "Hello world!";
    String str3 = str1;
    str3 = str2;
    int len = str1.size();
    char c = str2[0];

}
