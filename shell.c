#include <stdio.h>
#include "shell.h"
#include <inttypes.h>

// calculates the next gap based on the previous one. Takes one integer argument and returns one int variable.
static uint32_t next_gap(uint32_t gap) {
	if (gap>1) { // only change value if gap is bigger than 1
		if (gap<=2) { // if prev gap is smaller than 3
			gap = 1;
		} else { // else set gap to the provided formula
			gap = 5 * gap / 11;
		}
	}
	return gap;
}

// sorts a given array using shell sort. Takes three arguments: a pointer to the Stats structure, an array, and number of elements of the array
void shell_sort(Stats *stats, uint32_t *arr, uint32_t n_elements) {
//	reset(stats);
	int check = 1; // checks if we are using the same gap twice (if yes, stop the loop)
	uint32_t gap = 0;
	extern uint32_t elements; 
	for (gap=next_gap(n_elements); check==1; gap=next_gap(gap)) { // for each iteration of the loop, calculate the next gap
		for (uint32_t i=gap; i<n_elements; i+=1) { // while the gap is smaller than the number of elements
			uint32_t j = i;
			uint32_t temp = move(stats, arr[i]);
			while ((j>=gap) && cmp(stats, temp, arr[j-gap])==-1) { // checks if the array is sorted based on the gap
				arr[j] = move(stats, arr[j-gap]);
				move(stats, arr[j]);
				j -= gap;
			}
			arr[j] = move(stats, temp);
		//	move(stats, arr[j]);
		}
		if (gap == 1) { // if the array ran once with gap=1, stop the loop
			check = 0;
		}
	}
}

