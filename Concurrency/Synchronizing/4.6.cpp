#include <bits/stdc++.h>
using namespace std;


int find_ans(){return 1;}

void do_other_stuff() {
    for (int i = 0 ; i <= 1e5 ; ++i) {
        std::cout << "i am doing some other stuff\n";
    }
}


int main() {
    std::future<int>future = std::async(find_ans);

    do_other_stuff();
    std::cout << "The Final answer is: " << future.get() << '\n';
}
