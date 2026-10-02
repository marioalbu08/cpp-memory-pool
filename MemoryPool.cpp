#include "MemoryPool.h"
#include <cstdlib>
MemoryPool::MemoryPool(size_t size) : freeList(nullptr) {}
MemoryPool::~MemoryPool() {}
void* MemoryPool::allocate(size_t size) { std::lock_guard<std::mutex> lock(mtx); return malloc(size); }
void MemoryPool::deallocate(void* ptr) { std::lock_guard<std::mutex> lock(mtx); free(ptr); }
