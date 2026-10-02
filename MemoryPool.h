#pragma once
#include <cstddef>
struct Block { Block* next; };
class MemoryPool {
    Block* freeList;
public:
    MemoryPool(size_t size);
    ~MemoryPool();
    void* allocate(size_t size);
    void deallocate(void* ptr);
};
