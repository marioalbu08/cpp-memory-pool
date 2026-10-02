#include "MemoryPool.h"
#include <cassert>
#include <iostream>

int main() {
    // 1024 blocks of 32 bytes each
    MemoryPool pool(1024, 32);
    
    void* ptr1 = pool.allocate();
    assert(ptr1 != nullptr);
    
    void* ptr2 = pool.allocate();
    assert(ptr2 != nullptr);
    assert(ptr1 != ptr2);
    
    pool.deallocate(ptr1);
    pool.deallocate(ptr2);
    
    std::cout << "Memory pool tests passed successfully.\n";
    return 0;
}
