#pragma once
#include <cstddef>
#include <mutex>

struct Block {
    Block* next;
};

class MemoryPool {
private:
    Block* freeList;
    std::mutex mtx;
    size_t blockSize;
    char* memoryBlock;

public:
    // Initialize pool with a specific number of blocks of a specific size
    MemoryPool(size_t blocks, size_t blockSize);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* ptr);
};
