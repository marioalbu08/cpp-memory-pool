#include "MemoryPool.h"
#include <cassert>
int main() {
    MemoryPool pool(1024);
    void* ptr = pool.allocate(32);
    assert(ptr != nullptr);
    pool.deallocate(ptr);
    return 0;
}
