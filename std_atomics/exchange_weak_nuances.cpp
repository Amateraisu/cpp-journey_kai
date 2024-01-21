#include <bits/stdc++.h>
#include <atomic>

struct T{};
struct Lock{};

bool compare_exchange_strong(T& old_v , T new_v) {
    Lock L; // get exclusive access
    T tmp = value; // current value
    if (tmp != old_v) {
        old_v = tmp;
        return false;
    }
    value = new_v;
    return true;
}

// NUANCE HERE
// double locking pattern here too.
bool compare_exchange_weak(T& old, T new_v) {
    // why do I need to get exclusive access to it ? just read it first because it is faster
    T tmp = value;
    if (tmp != old) {
        old = tmp;
        return false;
    }
    Lock L; // get exclusive access; ==== ********** THIS MAY BE A TIMED LOCK! because exclusive access may be hard to get on a particular platform

    // however, values could have changed!
    tmp = value; // read again
    if (tmp != old) {
        old = tmp;
        return false;
    }
    value = new_v;
    return false;


}

int main() {

}
