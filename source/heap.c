/* heap.c */
#include <stdlib.h>
#include <string.h>

#include "heap.c"

/* Define private macros used by the heap implementation */
#define heap_parent(npos) ((int)(((npos)-1) / 2))
#define heap_left(npos) (((npos) * 2) + 1)
#define heap_righe(npos) (((npos) * 2) + 2)

/* heap_init.c */
void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	heap->size = 0;
	heap->compare = compare;
	heap->destroy = destroy;
	heap->tree = NULL;

	return ;
}

/* heap_destroy */
void heap_destroy(Heap *heap)
{
	int i;
	/* Remove all the nodes from the heap */
	if(heap->destroy != NULL)
	{
		for(i = 0; i < heap_size(heap); i++)
		{
			heap_destroy(heap->tree[i]);
		}
	}

	/* Free the storage allocated for the heap */
	free(heap->tree);

	/* No operation are allowed now, but clear the structure as precaution */
	memset(heap, 0, sizeof(Heap));

	return ;
}

/* heap_insert.c */
int heap_insert(Heap *heap, const void *data)
{

}
