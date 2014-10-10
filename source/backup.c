     1	/* heap.c */
     2	#include <stdlib.h>
     3	#include <string.h>
     4	
     5	#include "heap.c"
     6	
     7	/* Define private macros used by the heap implementation */
     8	#define heap_parent(npos) ((int)(((npos)-1) / 2))
     9	#define heap_left(npos) (((npos) * 2) + 1)
    10	#define heap_righe(npos) (((npos) * 2) + 2)
    11	
    12	/* heap_init.c */
    13	void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data))
    14	{
    15		heap->size = 0;
    16		heap->compare = compare;
    17		heap->destroy = destroy;
    18		heap->tree = NULL;
    19	
    20		return ;
    21	}
    22	
    23	/* heap_destroy */
    24	void heap_destroy(Heap *heap)
    25	{
    26		int i;
    27		/* Remove all the nodes from the heap */
    28		if(heap->destroy != NULL)
    29		{
    30			for(i = 0; i < heap_size(heap); i++)
    31			{
    32				heap_destroy(heap->tree[i]);
    33			}
    34		}
    35	
    36		/* Free the storage allocated for the heap */
    37		free(heap->tree);
    38	
    39		/* No operation are allowed now, but clear the structure as precaution */
    40		memset(heap, 0, sizeof(Heap));
    41	
    42		return ;
    43	}
    44	
    45	/* heap_insert.c */
    46	int heap_insert(Heap *heap, const void *data)
    47	{
    48	
    49	}
