#include <bits/stdc++.h>
#include <cstdlib>
#include <sys/wait.h>
#include <unistd.h>


#define N 20
using namespace std;

int main() {
    int status;

    for (int i = 0 ; i < N; ++i) {
        if ( auto pid = fork(); pid == 0) {
            // we are in the child
            exit(100 + i);
        }
    }
    int pid;
    // non deterministic order.
    // or here, we can specify pid to wait in a specific order
    while (pid = waitpid(-1, &status, 0) > 0) {
        if (WIFEXITED(status)) {
            cout << "Child exited normally with status " << WEXITSTATUS(status) << '\n';
        } else {
            cout << "Exited abnormally!\n";
        }
    }


}
