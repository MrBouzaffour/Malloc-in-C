#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024

char heap[HEAP_CAP] = {0};
size_t heap_size = 0;

typedef struct
{
	void *start;
	size_t size;
} Heap_Chunk;

Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP] ={0};
size_t heap_alloced_size = 0;	


void *heap_alloc(size_t size)
{
	if (size > 0){
	assert(heap_size + size <= HEAP_CAP);
	void *result = heap + heap_size;	// Begining of the chunk
	heap_size +=size;	// Size of the chunk
	
	const Heap_Chunk chunk = {
	.start = result,
	.size = size
	};
	
	assert(heap_alloced_size < HEAP_ALLOCED_CAP);
	heap_alloced[heap_alloced_size++] = chunk;

	return result;}
	else{return NULL;}
}

void heap_dump_alloced_chunks(void){
	printf("Allocated Chunks (%zu):\n",heap_alloced_size);
	for (size_t i = 0; i <heap_alloced_size;++i)
	{
		printf(" Start: %p,size: %zu\n",
				heap_alloced[i].start,
				heap_alloced[i].size);	
	}
}

void heap_free(void *ptr)
{
	(void) ptr;
	assert(false && "TODO : heap_free is not implemented");

}

void heap_collect()
{
	assert(false && "TODO : heap_collect is not implemented");
}


int main()
{
	for (int i = 0 ; i< 100; ++i){
		void *p = heap_alloc(i);
		if (i % 2 == 0)
		{
			heap_free(p);
		}
	}

	heap_dump_alloced_chunks();
	//heap_free(root);
	return 0;
}
