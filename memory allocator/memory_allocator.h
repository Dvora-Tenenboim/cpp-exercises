#ifndef __MEMORY_ALLOCATOR_H__
#define __MEMORY_ALLOCATOR_H__

typedef struct MemoryAllocator MemoryAllocator;
MemoryAllocator* MemoryAllocator_init(void* memoryPool,size_t size);
void* MemoryAllocator_release(MemoryAllocator* allocator);
void* MemoryAllocator_allocate(MemoryAllocator* allocator,size_t size);
void MemoryAllocator_free(MemoryAllocator* allocator, void* ptr);
size_t MemoryAllocator_optimizee(MemoryAllocator* allocator);

#endif
