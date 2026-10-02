#include "MemoryPool.h"
#include <cstdlib>
#include <new>

MemoryPool::MemoryPool(size_t blocks, size_t blockSize) 
    : blockSize(blockSize) {
    if (blockSize < sizeof(Block)) {
        this->blockSize = sizeof(Block);
    }
    
    memoryBlock = static_cast<char*>(malloc(blocks * this->blockSize));
    if (!memoryBlock) throw std::bad_alloc();
    
    freeList = reinterpret_cast<Block*>(memoryBlock);
    Block* current = freeList;
    
    for (size_t i = 1; i < blocks; ++i) {
        current->next = reinterpret_cast<Block*>(memoryBlock + i * this->blockSize);
        current = current->next;
    }
    current->next = nullptr;
}

MemoryPool::~MemoryPool() {
    free(memoryBlock);
}

void* MemoryPool::allocate() {
    std::lock_guard<std::mutex> lock(mtx);
    if (!freeList) return nullptr; // Pool exhausted
    
    Block* block = freeList;
    freeList = freeList->next;
    return block;
}

void MemoryPool::deallocate(void* ptr) {
    if (!ptr) return;
    std::lock_guard<std::mutex> lock(mtx);
    Block* block = static_cast<Block*>(ptr);
    block->next = freeList;
    freeList = block;
}
