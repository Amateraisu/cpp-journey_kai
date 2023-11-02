#include <bits/stdc++.h>



template <size_t N>
class Arena {
    static constexpr size_t alignment = alignof(std::max_align_t);
    alignas(alignment) std::byte buffer_[N];
    std::byte* ptr_;
    auto align(size_t n) -> size_t {
        return (n + (alignment - 1)) & ~(alignment - 1);
    }
    auto ptrInBuffer(std::byte* ptr) {
        return (std::uintptr_t(ptr) >= std::uintptr_t(buffer_) && std::uintptr_t(ptr) < std::uintptr_t(buffer_ + N));
    }

public:
    Arena(): ptr_(buffer_) {}
    Arena(const Arena& other) = delete;
    Arena& operator = (const Arena& other) = delete;
    auto size() -> size_t {
        return N;
    }
    auto used()->size_t {
        return static_cast<size_t>(ptr_ - buffer_);
    }
    auto allocate(size_t) -> std::byte*;
    auto deallocate(std::byte* p, size_t n)->void;
};


template<size_t N>
auto Arena<N>::allocate(size_t n) -> std::byte* {
    auto aligned_n = align(n);
    auto available_bytes = static_cast<size_t>(buffer_ + N - ptr_);
    if (available_bytes >= aligned_n) {
        std::byte* ptr = ptr_;
        ptr_ += aligned_n;
        return ptr;
    }
    return static_cast<std::byte*>(std::malloc(n));
}

template<size_t N>
void Arena<N>::deallocate(std::byte* p, size_t n) {
    if (ptrInBuffer(p)) {
        n = align(n);
        if (p + n == ptr_) {
            ptr_ = p;
        }

    } else {
        ::operator delete(p);
    }
}

auto user_area = Arena<1024>{};

int main() {




    return 0;
}