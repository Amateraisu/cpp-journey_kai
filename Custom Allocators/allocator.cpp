#include <bits/stdc++.h>
#include <unistd.h>

using word_t = intptr_t;

struct Block {
    int size;
    bool used;
    Block* next;
    word_t* data; // payload ptr;
};

static Block *heapStart = nullptr;

static auto top = heapStart;

inline size_t align(size_t n) {
    return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}


inline size_t allocSize(size_t size) {
    return size + sizeof(Block) - sizeof(std::declval<Block>().data);
}

Block* requestFromOS(size_t size) {
    auto block = (Block *) sbrk(0);

    if (sbrk(allocSize(size)) == (void*)-1) {
        return nullptr;
    }

    return block;
}

word_t* alloc(size_t size) {
    size = align(size);
    auto block = requestFromOS(size);
    block->size = size;
    block->used = true;
    if (heapStart == nullptr) {
        heapStart = block;
    }
    if (top != nullptr) {
        top->next = block;
    }
    top = block;

    return block->data;

}




