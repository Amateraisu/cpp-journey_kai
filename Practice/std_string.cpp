#include <bits/stdc++.h>

// we can just implement the rule of 5 simply since we are violating it right now
struct String {
public:
    String():size{0}, ptr{nullptr}{}
    ~String() {size = 0; ptr =nullptr}
    String(const char* other) {
        size = strlen(other);
        ptr = new char[size + 1];
        strcpy(ptr, other);
    }
    String(String& other) {
        size = other.size;
        ptr = new char[size + 1];
        strcpy(ptr, other.ptr);
    }
    String(String&& other) {
        // take over
        ptr = other.ptr;
        size = other.size;
        other.ptr = nullptr;
        other.size = 0;
    }
    // so far the above is the old classic rule of 3
    // copy assignment
    String& operator = (String& other) {
        if (this != &other) {
            delete[] ptr;
            ptr = new char[other.size + 1];
            strcpy(ptr, other.ptr);
            size = other.size;

        }

        return *this;
    }
    int length() const noexcept {
        return size;
    }
    // we usually expect our class to be on the left side of the argueement, but here it is std::ostream.
    friend std::ostream& operator << (std::ostream& out , const String& other);

private:
    int size;
    char* ptr;

};

std::ostream& operator << (std::ostream& out , const String& other) {

    out << other.ptr;

    return out;
}

int main() {
    String str1;// default constructor
    String str2 = "hello"; // parameterised constructor
    String str3 = str1; // copy constructor
    str3 = str2; // copy assignment
    String str4 = std::move(str2); // this is the move semantics stuff.
    int len = str1.length();
    std::cout << str2 << '\n'; // operator overloading
    std::cin >> str1;

}
