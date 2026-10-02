#include "MemoryPool.h"
#include <cstdlib>
MemoryPool::MemoryPool(size_t size) {}
MemoryPool::~MemoryPool() {}
void* MemoryPool::allocate(size_t size) { return malloc(size); }
void MemoryPool::deallocate(void* ptr) { free(ptr); }
