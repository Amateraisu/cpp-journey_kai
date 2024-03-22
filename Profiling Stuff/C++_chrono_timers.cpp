#include <chrono>
#include <iostream>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::cout;
using std::endl;

int main() {
    auto t0 = system_clock::now();
    // do some work here

    auto t1 = system_clock::now();
    auto delta_t = duration_cast<milliseconds>(t1 - t0);
    cout << "Time: " << delta_t.count() << endl;
}
