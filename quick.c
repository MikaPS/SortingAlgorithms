#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <inttypes.h>

void quick_sort(Stats *stats, uint32_t *arr, uint32_t n_elements) {
	extern uint32_t elements;
	// since every time we call the function with different portions of the array, we need to initalzie left&right each time
	uint32_t left = 0; // left is always the first index of the array
	uint32_t right = n_elements-1; // right is always the biggest index
//	uint32_t middle = (left+right)/2;
	// Used the middle value as pivot
	uint32_t pivot = arr[right];//(arr[left] + arr[middle] + arr[right])/3;	
	if (n_elements < 8) { // if the length of the array is small, call shell sort
		shell_sort(stats, arr, n_elements);
	}
	else { // if the array has more than 8 elements
		while (left < right) { 
			while (cmp(stats,arr[left], pivot)==-1 || cmp(stats,arr[left], pivot)==0) {//find the first element bigger than pivot
                        	if (left+1<n_elements) { // if the values are less than pivot, move to the next value
					left+=1;
				}
				else { // stop when "left" is out of bounds
					break;
				}
               		}
                	while (cmp(stats, arr[right], pivot) == 1) { //find the first element smaller than pivot
                        	if (right-1>=0) { 
					right-=1; // if the values are bigger than pivot, go to the next index
				}
				else { // stop when the var "right" is out of bounds
					break;
				}
                	}
			if (left <= right) { // swap the two values we found
				swap(stats, &arr[left], &arr[right]);
			}
		}
		// call quick sort on the left side of the array (all values are smaller than or equal to pivot)
		quick_sort(stats, arr, left);
		// call quick sort on the right side of the array (all values are bigger than pivot)
		quick_sort(stats, &arr[right], n_elements-right);
	}
}
