
#include <bits/stdc++.h>

struct some_resource{};
std::mutex mut;
std::shared_ptr<some_resource>ptr;
void UB_double_checked_locking() {
    if (!ptr) { // the read is not synchronized here
        std::lock_guard<std::mutex>lk(mut);
        if (!ptr) {
            ptr.reset(new some_resource());
        }
    }
    ptr->do_something(); // may not see the correct value of ptr
}
