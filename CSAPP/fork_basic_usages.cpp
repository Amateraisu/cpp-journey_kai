// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    int x = 1;
    int pid;
    pid = fork();
    if (pid == 0) {
        cout << "Child\n";
        exit(0);
    }

    cout << "parent" << ' ' << x << '\n';
    exit(0);
}

// the guaranteed behaviour isnt confirmed because it depends on how the systems schedule the processes.
// the changes in the value of x is not reflected in the child and parent processes.
// duplicate and separate address spacessx, different stack.
// shared libraries of the cout function, hence prints to the same output page.
