#include <memory>

namespace STD {
    template <class T>
    class allocator;

    // void specialisation
    template <>
    class allocator<void> {
    public:
        typedef void* pointer;
        typedef const void* const_pointer;
        typedef void value_type;
        // this part is simply a way to convert the allocator to a different type
        template <class U>
        struct rebind {
            typedef allocator<U> other;
        };
    };

    template <class T>
    class allocator {
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;
        template <class U>
        struct rebind {
            typedef allocator<U> other;
        };
        allocator() noexcept;
        // void allocator
        allocator(const allocator&) noexcept;

        // for allocator of another type
        template <class U>
        allocator(const allocator<U>&) noexcept;
        ~allocator() noexcept;
        pointer address(reference x) const;
        const_pointer address(const_reference x) const;

        pointer allocate(size_type, allocator<void>::const_pointer hint = 0);
        void deallocate(pointer p, size_type n);
        size_type max_size() const noexcept;
        void construct (pointer p, const T& val);
        void destroy(pointer p);

    };
    template <class T1, class T2>
    bool operator==(const allocator<T1>&, const allocator<T2>&) noexcept;

    template <class T1, class T2>
    bool operator!=(const allocator<T1>&, const allocator<T2>&) noexcept;
}
