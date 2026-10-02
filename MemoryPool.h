#pragma once
#include <cstddef>
#include <mutex>
struct Block { Block* next; };
class MemoryPool {
    Block* freeList;
    std::mutex mtx;
public:
    MemoryPool(size_t size);
    ~MemoryPool();
    void* allocate(size_t size);
    void deallocate(void* ptr);
};
