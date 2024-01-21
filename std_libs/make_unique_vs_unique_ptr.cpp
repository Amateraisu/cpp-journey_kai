#include <bits/stdc++.h>


int main() {
    std::unique_ptr<int>ptr(new int(50)); // valid way;
    // invalid way std::unique_ptr<int>ptr = new int(40); because this is implicit conversion
    std::unique_ptr<int>ptr2 = std::make_unique<int>(50); // valid way too
    // here we have more exception safety, prevent memory leaks if we just use make_unique because we dont need to call new


}
