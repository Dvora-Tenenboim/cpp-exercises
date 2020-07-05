#include "test.h"

int main()
{
	test_MemoryAllocator_init();
	test_MemoryAllocator_allocate();
	test_MemoryAllocator_free();
	test_MemoryAllocator_optimizee();
	return 0;
}
