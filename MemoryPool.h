#pragma once
#include <cstddef>
class MemoryPool {
public:
    MemoryPool(size_t size);
    ~MemoryPool();
    void* allocate(size_t size);
    void deallocate(void* ptr);
};
