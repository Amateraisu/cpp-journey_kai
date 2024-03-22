#include <time.h>

void work() {
    for (int i = 0; i < 1000000; ++i);
}


int main() {
    struct timespec start, end;
    long long elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);
    // monotonic clock, CPU_clock, thread_clock
    // if the CPU_clock does not add up to the monotonic clock,
    // it means the machine is overloaded, many processes running at the same time competing for the CPU, or
    // the process is running out of memory, disk swap, cant do any work until the memory is waiting to be paged in.
    work();

    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec);
    return 0;

}