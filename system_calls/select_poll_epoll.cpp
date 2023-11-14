#include <bits/stdc++.h>
using namespace std;
bool is_ready(int fd);

struct fd_info {
    int fd;
    bool ready;
};

int select(int max_fd, set<fd_info>& fds) {
    int count = 0;
    while (count == 0) {
        for (int i = 0; i < max_fd; i++) {
            if (is_ready(i)) {
                auto it = fds.find(i);
                it->ready = true;
                count++;
            }
        }
    }
    return count;
}

