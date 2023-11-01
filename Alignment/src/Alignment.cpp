//
// Created by admin on 1/11/2023.
//

#include "Alignment.h"
#pragma pack(1)

size_t alignment = alignof(std::max_align_t);

auto align(size_t n) -> size_t {
    return (n + (alignment - 1)) & ~(alignment - 1);
}