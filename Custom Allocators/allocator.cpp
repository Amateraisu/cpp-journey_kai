#include <bits/stdc++.h>
#include <sys/mman.h>
#include <unistd.h>
using word_t = intptr_t;

struct Block {
    size_t size;
    bool used;

    Block* next;

    word_t* data;
};

static Block* heapStart = nullptr;
static auto top = heapStart;

size_t align(size_t size) {
    return (size + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

Block* requestFromOS(size_t size) {
    auto sizeOfPage = sysconf(_SC_PAGESIZE);

    size_t numberOfPages = (size + sizeOfPage - 1)/sizeOfPage;
    void* ptr = mmap(NULL, numberOfPages, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return nullptr;
    }

    return (Block*)ptr;
}

word_t* alloc(size_t size) {
    size = align(size);
    // so we need this amount of size of memory

}




