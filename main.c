#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024
#define UNEMPLEMENTED \
	do {	\
		fprintf(stderr,"%s:%d: TODO: %s is not implemented yet.\n",\
				__FILE__,__LINE__,__func__);\
		abort();\
	}while(0)


typedef struct
{
	void *start;
	size_t size;
} Chunk;

typedef struct 
{
	size_t count;
	Chunk chunks[HEAP_ALLOCED_CAP];

}Chunk_List;

int chunk_list_find(const Chunk_List *list, void *ptr)
{
	UNEMPLEMENTED;
	return -1;
}
void chunk_list_insert(const Chunk_List *List, void *ptr, size_t size)
{
	UNEMPLEMENTED;
}
void chunk_list_remove(const Chunk_List *list, size_t index)
{
	UNEMPLEMENTED;
}

char heap[HEAP_CAP] ={0};
size_t heap_size = 0;
 
Chunk_List alloced_chunks = {0};
Chunk_List freed_chunks = {0};

void *heap_alloc(size_t size)
{
	if (size > 0){
	assert(heap_size + size <= HEAP_CAP);
	void *ptr = heap + heap_size;
	heap_size +=size;
	chunk_list_insert(&alloced_chunks, ptr, size);
	return ptr;
	}
	else{
		return NULL;
	}
}

void chunk_list_dump(const Chunk_List *list){
	printf("Allocated Chunks (%zu):\n", list->count);
	for (size_t i = 0; i < list->count; ++i)
	{
		printf(" Start: %p,size: %zu \n",
				list->chunks[i].start,
				list->chunks[i].size);	
	}
}

void heap_free(void *ptr)
{
	UNEMPLEMENTED;
}

void heap_collect()
{
	UNEMPLEMENTED;
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

	//chunk_list_dump();
	//heap_free(root);
	return 0;
}
