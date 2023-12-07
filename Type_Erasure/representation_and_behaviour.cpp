#include <bits/stdc++.h>

bool (*behaviour)(void*) = [](void* r) -> bool {
    return !(*(int*)r);
};

// Now it should compile without issues
int main() {
    int x = 4;
    void* representation = &x;
    assert(behaviour(representation) == !x);

}
