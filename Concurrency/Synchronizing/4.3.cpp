#include <memory>


// 1 try_pop
// tries to pop, but if empty returns with indication of failure
// 2 wait and pop
// waits until there isa  value to pop



template <typename T>
class threadSafe_queue {
public:
    threadSafe_queue();
    threadSafe_queue(threadSafe_queue const &);
    threadSafe_queue& operator = (const threadSafe_queue&) = delete;
    void push(T new_value);
    bool try_pop(T& value);
    std::shared_ptr<T> try_pop();
    void wait_and_pop(T& value);
    std::shared_ptr<T> wait_and_pop();
    bool empty() const;


};