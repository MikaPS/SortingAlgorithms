#include "bubble.h"
#include <stdio.h>
#include "stats.h"
#include <inttypes.h>

// sorts a given array using bubble sort. Takes three arguments: a pointer to the stats structure, an array, and the number of elements in the array.
void bubble_sort(Stats *stats, uint32_t *arr, uint32_t n_elements) {
	extern uint32_t elements;
	for (unsigned long i=0; i<=n_elements-1; i+=1) { // go through each element of the array
		int swap_status = 1;
		for (unsigned long j=n_elements-1; j!=i; j-=1) { // reverse through the array
			if (cmp(stats, arr[j], arr[j-1]) == -1) { // if the numbers are not sorted
				swap(stats, &arr[j], &arr[j-1]);  // swap them
				swap_status = 0;
			}
		}
		if (swap_status==1) { // if the array was sorted after the first iteration, stop the loop
			break;
		}
	}

        if (n_elements<elements) { // checks if the length of the array is smaller than the amount of elements the user asked to print
                elements = n_elements; 
        }
        printf("Bubble Sort, %d elements, %lu moves, %lu compares\n", n_elements, stats->moves, stats->compares);
        for (uint32_t n=0; n<elements; n+=1) { // prints all the asked values!
		printf("%13"PRIu32,arr[n]);
		if ((n+1)%5==0 && n>0) {
                	printf("\n");
		}
		if (n==elements-1 && ((n+1)%5!=0)) {
                                        printf("\n");
                }

        }
}

