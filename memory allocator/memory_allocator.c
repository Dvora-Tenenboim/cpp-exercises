#include <malloc.h>
#include <stdbool.h>
#include "memory_allocator.h"

typedef struct MemoryAllocator
{
	size_t size;
	void* ptr;
}MemoryAllocator;

static const bool LSB_BIT = 1;
static const short 	ALLIGHMENT = 16; 
static const short SIZE_T_AFTER_PADDING = 16;

//------------------Auxiliary functions----------------------

static bool isValid(const void* ptr);
static size_t getSizeAfterPadding(size_t size);
static size_t getSize(const void* ptr);
static bool getLSB(const void* ptr);
static bool isBigEnough(const void* ptr, size_t size);
static void turnOnLSB(void* ptr);
static void turnOffLSB(void* ptr);
static void setSize(void* ptr, size_t size);
static void split(void* ptr, size_t size);
static void* getNextBlock(MemoryAllocator* allocator, void* ptr);
static size_t mergeAdjacentFreeBlocks(MemoryAllocator* allocator, void* ptr); // merge adjacent free blocks and returns the size of the block after merge
size_t max(size_t x, size_t y);

static bool isValid(const void* ptr)
{
	return getLSB(ptr);
}
static size_t getSizeAfterPadding(size_t size)
{
	return size + (ALLIGHMENT-(size %  ALLIGHMENT))%ALLIGHMENT;
}
static size_t getSize(const void* ptr)
{
	return (*(size_t*)ptr)-isValid(ptr);
}
bool getLSB(const void* ptr)
{
	return *(size_t*)ptr & LSB_BIT;
}
bool isBigEnough(const void* ptr, size_t size)
{
	return getSize(ptr) >= size;
}
static void turnOnLSB(void* ptr)
{
	*(size_t*)ptr = (*(size_t*)ptr) | LSB_BIT;
}
static void turnOffLSB(void* ptr)
{
	if(isValid(ptr))
	{
		*(size_t*)ptr -= 1;
	}
}
static void setSize(void* ptr, size_t size)
{
	*((size_t*)ptr) = size ;
}
static void split(void* ptr, size_t size)
{
	size_t splt = getSize(ptr) - size;
	if(splt >= SIZE_T_AFTER_PADDING)
	{
		setSize((char*)ptr + size , splt);
	}
	setSize(ptr, size);
	turnOnLSB(ptr);
}
static void* getNextBlock(MemoryAllocator* allocator, void* ptr)
{
	if ((char*)ptr + getSize(ptr) >= (char*)(allocator->ptr) + allocator->size)
		return NULL;
	return (char*)ptr + getSize(ptr);
}
static size_t mergeAdjacentFreeBlocks(MemoryAllocator* allocator, void* ptr)
{
	size_t counter = getSize(ptr);
	void *tmp_ptr;
	for (tmp_ptr = getNextBlock(allocator, ptr); tmp_ptr && !isValid(tmp_ptr); tmp_ptr = getNextBlock(allocator, tmp_ptr))
	{
		counter += getSize(tmp_ptr);
	}
	setSize(ptr, counter);
	return counter;
}
size_t max(size_t x, size_t y)
{
	return x>y ? x: y;
}
//--------------------------------------------------------------

MemoryAllocator* MemoryAllocator_init(void* memoryPool,size_t size)
{
	MemoryAllocator* allocator = (MemoryAllocator*)malloc(sizeof(MemoryAllocator));
	allocator->size = getSizeAfterPadding(size) + SIZE_T_AFTER_PADDING;
	setSize(memoryPool, allocator->size);
	allocator->ptr = memoryPool;
	return allocator;
}
void* MemoryAllocator_release(MemoryAllocator* allocator)
{
	void *memoryPool = allocator->ptr;
	free((void*)allocator);
	allocator = NULL;
	return memoryPool;
}
void* MemoryAllocator_allocate(MemoryAllocator* allocator,size_t size)
{
	size = getSizeAfterPadding(size) + SIZE_T_AFTER_PADDING;
	void *tmp_ptr ;
	for(tmp_ptr = allocator->ptr; tmp_ptr ;)
	{
		if(isValid(tmp_ptr))
		{
			tmp_ptr = getNextBlock(allocator, tmp_ptr);
		}
		else
		{
			if(isBigEnough(tmp_ptr,size))
			{
				split(tmp_ptr, size);
				return tmp_ptr;
			}
			if (getNextBlock(allocator, tmp_ptr) && !isValid(getNextBlock(allocator, tmp_ptr)))  // else if free memory isn't big enough and the next block is free
			{
				setSize(tmp_ptr, getSize(tmp_ptr) + getSize(getNextBlock(allocator, tmp_ptr)));
			}
			else //memory isn't big enough and the next block is allocated
			{
				tmp_ptr = getNextBlock(allocator, tmp_ptr);
			}
		}
	}
	return NULL;
	
}
void MemoryAllocator_free(MemoryAllocator* allocator, void* ptr)
{
	mergeAdjacentFreeBlocks(allocator, ptr);
	turnOffLSB(ptr);
}
size_t MemoryAllocator_optimizee(MemoryAllocator* allocator)
{
	size_t max_size = 0;
	void *tmp_ptr ;
	for(tmp_ptr = allocator->ptr; tmp_ptr ;)
	{
		if(isValid(tmp_ptr))
		{
			tmp_ptr = getNextBlock(allocator, tmp_ptr);
		}
		else
		{
			max_size = max(mergeAdjacentFreeBlocks(allocator, tmp_ptr), max_size);
			tmp_ptr = getNextBlock(allocator, tmp_ptr);
		}
	}
	return max_size;
}









