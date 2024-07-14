#include <iostream>
#include <unistd.h>

using word_t = intptr_t;

int align(int n) {
    return (n + sizeof(word_t) - 1) & ~(sizeof(word_t) - 1);
}

struct Block {
    int size;
    Block* next;
    bool used;
    word_t data[1];
};

static Block* heapStart = nullptr;
static Block* top = heapStart;


int addHeader(int reqSize) {
    return reqSize + sizeof(Block) - sizeof(std::declval<Block>().data);
}

Block* requestFromOS(int requiredSize) {
    std::cout << "Req from OS " << requiredSize << '\n';
    auto block = (Block*)sbrk(0);
    if (sbrk(addHeader(requiredSize)) == (void*)(-1)) { // we are OOM
        return nullptr;
    }
    return block;
}

Block* findFromList(int requiredSize) {
    auto block = heapStart;
    while (block != nullptr) {
        if (block->used || block->size < requiredSize) {
            block = block->next;
        } else {
            break;
        }
    }

    return block;
}



word_t* alloc(int size) {
    int alignedSize = align(size);

    if (auto oldBlock = findFromList(alignedSize)) {
        return oldBlock->data;
    }

    auto block = requestFromOS(alignedSize);
    if (block == nullptr) return nullptr;

    block->used = true;
    block->size = alignedSize;
    if (heapStart == nullptr) {
        heapStart =block;
    }
    if (top == nullptr) {
        top = block;
    } else {
        top = block;
    }

    return block->data;

}

Block* getHeader(word_t* data) {
    return reinterpret_cast<Block*>((char*)data + sizeof(std::declval<Block>().data) - sizeof(Block));
}


void free(word_t* data) {
    auto hdr = getHeader(data);
    hdr->used = false;
}






int main() {
    std::cout << align(3) << '\n';
    std::cout << align(6) << '\n';
    std::cout << align(9) << '\n';
    std::cout << align(27) << '\n';

    auto data = alloc(5);
    Block* block = getHeader(data);
    std::cout << block->size << '\n';
    assert(block->size == 8);

    return 0;
}
