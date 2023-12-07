#include <bits/stdc++.h>

// basically you take charge of its creation and deletion using the heap

// this one takes up alot of space here!
struct TE {
    void* repre_{};
    void* (*a) (void*){};
    void* (*b) (void*){};
    void* (*c) (void*){}; //  40 bytes
};

template <class Number>
void *ABC(int op, void* r, void* out) {

}

struct TE1 {
    void* repre_{};
    void* (*abc) (void*) {};
    template <typename Number> TE(Number n):repre_(new Number(std::move(n))), abc_(ABC<Number>){};
};
