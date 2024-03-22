#include <list>
#include <mutex>
#include <algorithm>
std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);

    some_list.push_back(new_value);
}

bool list_contains(int target) {
    std::lock_guard<std::mutex>guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), target) != some_list.end();

}
