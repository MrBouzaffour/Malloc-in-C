#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define HEAP_CAPACITY 640000

char heap[HEAP_CAPACITY] = {0};
size_t heap_size = 0;

void *heap_alloc(size_t size)
{
	assert(heap_size + size <= HEAP_CAPACITY);
	void *result = heap + heap_size;
	heap_size +=size;
	return result;
}

void heap_free(void *ptr)
{
	assert(false && "TODO : heap_free is not implemented");

}

void heap_collect()
{
	assert(false && "TODO : heap_collect is not implemented");
}


int main()
{
	void *root = heap_alloc(69);
}
