#include <assert.h>

// Assuming isLittleEndian() returns 1 for little endian, and 0 for big endian.
int isLittleEndian() {
    int i = 1;
    int* ptr = &i;
    char* cPtr = reinterpret_cast<char*>(ptr);
    if (*cPtr == 1) {
        return 1;
    }
    return 0;

}

int main() {
    // Portable checks might rely on predefined macros or specific conditions known to match your system's architecture.
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    assert(isLittleEndian() == 1);
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    assert(isLittleEndian() == 0);
    #else
    #error "Endianness check: Unknown byte order!"
#endif

    return 0;
}

