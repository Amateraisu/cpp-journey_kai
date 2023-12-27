//
// Created by admin on 28/12/2023.
//
// we could check if an address is a multiple using the modulo oeprator
// this kinda makes sure that objects exist on separate cache lines

#include <bits/stdc++.h>

struct alignas(64) buffer {
    std::byte data[64];
};

bool is_aligned(void* ptr, std::size_t alignment) {
    assert(ptr != nullptr);
    assert(std::has_single_bit(alignment));
    std::size_t s = std::numeric_limits<std::size_t>::max();
    void* aligned_ptr = ptr;
    std::align(alignment, 1, aligned_ptr, s);
    return ptr == aligned_ptr;
}


bool is_aligned2(void* ptr, std::size_t alignment) {
    assert(ptr != nullptr);
    assert(std::has_single_bit(alignment));
    std::size_t maxi = std::numeric_limits<std::size_t>::max();
    void* aligned_ptr = ptr;
    std::align(alignment, 1, aligned_ptr, maxi);

    return aligned_ptr == ptr;
}

int main() {
    int* ptr = new int(10);
    assert(is_aligned(ptr, 4));
}