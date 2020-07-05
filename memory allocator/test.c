#include <stddef.h>
#include "memory_allocator.h"
#include <malloc.h>
#include "test.h"

void test_MemoryAllocator_init()
{
	void* myHeap = malloc(512);
	MemoryAllocator* allocator = MemoryAllocator_init(myHeap, 512);
	MemoryAllocator_release(allocator);
	free(myHeap);
}

void test_MemoryAllocator_allocate()
{
	void* myHeap = malloc(512);
	MemoryAllocator* allocator = MemoryAllocator_init(myHeap, 512);
	void* ptr1 = MemoryAllocator_allocate(allocator, 16); //32
	void* ptr2 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr3 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr4 = MemoryAllocator_allocate(allocator, 50); //80
	if (*(size_t*)ptr1 == 33 && *(size_t*)ptr2 ==49 && *(size_t*)ptr3 == 49 && *(size_t*)ptr4 == 81 && *(size_t*)((char*)ptr4 +80) == 320)
	{
		printf("MemoryAllocator_allocate pass\n");
	}
	else
	{
		printf("MemoryAllocator_allocate failed\n");
	}
	ptr1 = MemoryAllocator_allocate(allocator, 500);//NULL
	if (ptr1 == NULL)
	{
		printf("MemoryAllocator_allocate pass\n");
	}
	else
	{
		printf("MemoryAllocator_allocate failed\n");
	}
	MemoryAllocator_release(allocator);
	free(myHeap);
}
void test_MemoryAllocator_free()
{
	void* myHeap = malloc(512);
	MemoryAllocator* allocator = MemoryAllocator_init(myHeap, 512);
	void* ptr1 = MemoryAllocator_allocate(allocator, 16); //32
	void* ptr2 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr3 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr4 = MemoryAllocator_allocate(allocator, 50); //80
	MemoryAllocator_free(allocator, ptr4);
	MemoryAllocator_free(allocator, ptr3);
	MemoryAllocator_free(allocator, ptr1);
	if (*(size_t*)ptr1 == 32 && *(size_t*)ptr2 == 49 && *(size_t*)ptr3 == 448 && *(size_t*)ptr4 == 400)
	{
		printf("MemoryAllocator_free pass\n");
	}
	else
	{
		printf("MemoryAllocator_free failed\n");
	}
	MemoryAllocator_release(allocator);
	free(myHeap);
}
void test_MemoryAllocator_optimizee()
{
	size_t max_free_block_size;
	void* myHeap = malloc(512);
	MemoryAllocator* allocator = MemoryAllocator_init(myHeap, 512);
	void* ptr1 = MemoryAllocator_allocate(allocator, 16); //32
	void* ptr2 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr3 = MemoryAllocator_allocate(allocator, 30); //48
	void* ptr4 = MemoryAllocator_allocate(allocator, 50); //80
	void* ptr5 = MemoryAllocator_allocate(allocator, 30); //48
	MemoryAllocator_free(allocator, ptr1);
	MemoryAllocator_free(allocator, ptr2);
	MemoryAllocator_free(allocator, ptr3);
	MemoryAllocator_free(allocator, ptr5);
	max_free_block_size = MemoryAllocator_optimizee(allocator);
	if (*(size_t*)ptr1 == 128 && *(size_t*)ptr4 == 81 && *(size_t*)ptr5 == 320 && max_free_block_size == 320)
	{
		printf("MemoryAllocator_optimizee pass\n");
	}
	else
	{
		printf("MemoryAllocator_optimizee failed\n");
	}
	MemoryAllocator_release(allocator);
	free(myHeap);
}
