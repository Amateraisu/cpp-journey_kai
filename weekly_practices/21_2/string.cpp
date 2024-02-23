#include <bits/stdc++.h>


struct MyString {
    MyString():size_(1), length_(0), arr(nullptr){}
    MyString(char* other) {
        int length = 0;
        for (char* c = other; *c != '\0' ; ++c) {
            ++length;
        }
        arr = new char[length + 1];
        arr[length] = '\0';
        for(int i = 0; i < length; ++i) {
            arr[i] = other[i];
        }
    }
    ~MyString() {
        length_ = 0;
        size_ = 0;
        delete[] arr;
        arr = nullptr;
    }
    MyString(const MyString& other) {

    }

    MyString(const MyString&& other) {

    }

    MyString& operator = (MyString& other) {
        if (this == &other) return *this;

        size_ = other.size_;
        length_ = other.length_;
        arr = new char[size_];
        arr[size_] = '\0';
        for(int i = 0; i < size_; ++i) {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    MyString& operator = (MyString&& other) {
        if (this == &other) return *this;
        size_ = other.size_;
        other.size_ = 0;
        length_ = other.length_;
        arr = other.arr;
        other.arr = nullptr;
        return *this;

    }
    int length() { return length_; }
    auto operator <=> (const MyString& other) const = default;



private:
    int size_; // includes the nullptr
    int length_;
    char* arr;


};


int main() {
    MyString s1; // Default constructor
    assert(s1.length() == 0); // Empty string

    MyString s2("Hello"); // Constructor with C-string
    assert(s2.length() == 5);

    MyString s3 = s2; // Copy constructor
    assert(s3.length() == s2.length());
    assert(s3 == s2);

    MyString s4;
    s4 = s3; // Copy assignment operator
    assert(s4.length() == s3.length());
    assert(s4 == s3);

    MyString s5(std::move(s2)); // Move constructor
    assert(s5.length() == 5);
    assert(s2.length() == 0); // Assuming s2 is in a valid but unspecified state

    MyString s6;
    s6 = std::move(s5); // Move assignment operator
    assert(s6.length() == 5);
    assert(s5.length() == 0); // Assuming s5 is in a valid but unspecified state


    MyString str1("Apple");
    MyString str2("Banana");
    MyString str3("Apple");

    assert(str1 == str3);
    assert(str1 != str2);
    assert(str2 > str1);
    assert(str1 < str2);
    assert(str1 <= str3);
    assert(str2 >= str1);

//    MyString str("Hello");
//    str.append(" World"); // Assuming append method exists
//    assert(str == "Hello World");
//
//    str.insert(0, "Start "); // Assuming insert method exists
//    assert(str == "Start Hello World");
//
//    str.erase(0, 6); // Assuming erase method exists
//    assert(str == "Hello World");
//
//    str.replace(0, 5, "Goodbye"); // Assuming replace method exists
//    assert(str == "Goodbye World");
//
//    MyString str("Hello World");
//    MyString sub = str.substring(6, 5); // Assuming substring method exists
//    assert(sub == "World");
//
//    MyString concat = MyString("Hello") + " World"; // Assuming operator+ is overloaded
//    assert(concat == "Hello World");
//
//    MyString upper = str.toUpperCase(); // Assuming toUpperCase method exists
//    assert(upper == "HELLO WORLD");
//
//    MyString lower = str.toLowerCase(); // Assuming toLowerCase method exists
//    assert(lower == "hello world");
//
//    MyString str("Test");
//    assert(str.length() == 4);
//    assert(str.capacity() >= 4); // Assuming capacity method exists
//    assert(str[0] == 'T');
//    assert(str.at(3) == 't'); // Assuming at method exists with bounds checking



}