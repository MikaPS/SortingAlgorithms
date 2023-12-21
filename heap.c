#include "stats.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// returns the index of the left child of the node
uint32_t l_child(uint32_t n) {
	return (2*n+1);
}

// returns the index of the right child of the node
uint32_t r_child(uint32_t n) {
        return (2*n+2);
}

// returns the index of the parent
uint32_t parent(uint32_t n) {
//	if (n <= 1) {
//		return 0;
//	}
  	return ((n-1)/2);
}

// organizes a min heap; organizes values so all parents would have smaller values than their children
void up_heap(Stats *stats, uint32_t *arr, uint32_t n) {
	while (n>0 && cmp(stats, arr[n], arr[parent(n)]) == -1) {
		swap(stats, &arr[n], &arr[parent(n)]);
		n = parent(n);
	}
}

// part of the process to fix the heap. it takes the min heap and ensures that the values are fully sorted
void down_heap (Stats *stats, uint32_t *arr, uint32_t heap_size) {
	uint32_t n = 0;
	uint32_t smaller;
	while (l_child(n) < heap_size) { //makes sure we stay in bounds 
		if (r_child(n) == heap_size) { // if the child=0, than they are the smallest value
			smaller = l_child(n);
		}
		else {
			if (cmp(stats,arr[l_child(n)],arr[r_child(n)]) == -1) { // checks if left child is smaller than right child
				smaller = l_child(n);
			} else {
				smaller = r_child(n);
			}
		}
		// swap values if needed
		if (cmp(stats,arr[n], arr[smaller])==-1) {
			break;
		}
		swap(stats, &arr[n], &arr[smaller]);
		n = smaller;
	}	 
}

// builds a heap and returns a pointer to it. creates an empty array and copies the values of the given array into it. organizes them using the min heap function described above

uint32_t * build_heap(Stats *stats, uint32_t *arr, uint32_t n_elements) {
//	stats->moves+=1;
	uint32_t *heap;
	heap = (uint32_t *) calloc(n_elements, sizeof(uint32_t)); 
	for (uint32_t n=0; n<n_elements; n+=1) {
                heap[n] = move(stats, arr[n]);
		move(stats, heap[n]);
	//	stats->moves+=1;
                up_heap(stats, heap, n);
        }
	return heap;
}
void heap_sort(Stats *stats, uint32_t *arr, uint32_t n_elements) {
	reset(stats);
	extern uint32_t elements;
	uint32_t * heap = build_heap(stats, arr, n_elements);
	
	for (uint32_t n=0; n<n_elements; n+=1) {		
		arr[n] = move(stats, heap[0]);
		move(stats,heap[n]);
		heap[0] = move(stats, heap[n_elements-n-1]); // move the biggest element to index 0
		move(stats, heap[0]);
		down_heap(stats, heap, n_elements-n); // call down heap to place the new value at the right place
	}
	
	// prints the sorted array
	if (elements>n_elements) {
		elements = n_elements;
	}
	printf("Heap Sort, %d elements, %lu moves, %lu compares\n", n_elements, stats->moves, stats->compares);
        for (uint32_t h=0; h<elements; h+=1) {
                printf("%13"PRIu32,arr[h]);
                if ((h+1)%5==0 && h>0) {
                        printf("\n");
                }
		if (h==elements-1 && ((h+1)%5!=0)) {
                                        printf("\n");
                }
        }

	free(heap);
}
