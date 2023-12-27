#include <bits/stdc++.h>
using namespace std;

class user {
public:
    int x{5};
    int y{10};

};

int main() {
    user* ptr = static_cast<user*>(std::malloc(sizeof(user) * 10));
    user* u = ::new (&ptr[5]) user();
    u->~user();
    std::free(ptr);
}
