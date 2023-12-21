#include "bubble.h"
#include <stdio.h>
#include "stats.h"
#include "shell.h"
#include "heap.h"
#include "mtrand.h"
#include "set.h"
#include "quick.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t elements = 100;
int main (int argc, char ** argv) {
    int opt = 0; // used for getopt
    // set default numbers
    uint64_t seed = 13371453; 
    uint32_t size = 100;
    Set set = 0;

    // gets user input and runs until processes all the commands
    while ((opt = getopt(argc, argv, "asbqhr:n:p:h:H")) != -1) { //list of valid commands
        // runs all sorts
	if (opt == 'a') {
		 set =set_insert(set, 0);
		 set =set_insert(set, 1);
		 set =set_insert(set,2);
		 set =set_insert(set, 3);
	}
	// runs shell sort
	else if (opt=='s') {
		set =set_insert(set, 0); // bit 0 goes for shell
	}
	// runs bubble sort
	 else if (opt=='b') {
                set = set_insert(set, 1); // bit 1 goes for shell
        }
	 // runs quick sort
	 else if (opt=='q') {
                set = set_insert(set, 2); // bit 2 goes for shell
        }
	 // runs heap sort
	 else if (opt=='h') {
                set =set_insert(set, 3); // bit 3 goes for shell
        }
	// set seed
	else if (opt=='r') { 
		 // turn their input into an int 
       		seed = strtoul(optarg, NULL, 10);
        }
	// set number of elements in the array
	else if (opt=='n') {
		int n = strtoul(optarg, NULL, 10); // turn their input into an int
		if (n>=1 && n<=250000000) { // valid options
			size = n;
		} else {
			return 1;
		}
	}
	// set number of elements to be printed
	 else if (opt=='p') {
                 int n = atoi(optarg);
		 elements = n;
        }
	 // usage message
	else if (opt=='H') { 
         	set=set_insert(set,4);
		printf("SYNOPSIS\n");
                printf("   A collection of comparison-based sorting algorithms.\n\n");
                printf("USAGE\n");
                printf("   ./sorting [-Hasbhq] [-n length] [-p elements] [-r seed]\n\n");
                printf("OPTIONS\n");
                printf("   -H              Display program help and usage.\n   -a              Enable all sorts.\n   -b              Enable Bubble Sort.\n   -h              Enable Heap Sort.\n   -q              Enable Quick Sort.\n   -s              Enable Shell Sort.\n   -n length       Specify number of array elements (default: 100).\n   -p elements     Specify number of elements to print (default: 100).\n   -r seed         Specify random seed (default: 13371453).\n");
 
        }
	// if it's not in the above options, return an error number
	else {
		printf("SYNOPSIS\n");
		printf("   A collection of comparison-based sorting algorithms.\n\n");
                printf("USAGE\n");
		printf("   ./sorting [-Hasbhq] [-n length] [-p elements] [-r seed]\n\n");
                printf("OPTIONS\n");
		printf("   -H              Display program help and usage.\n   -a              Enable all sorts.\n   -b              Enable Bubble Sort.\n   -h              Enable Heap Sort.\n   -q              Enable Quick Sort.\n   -s              Enable Shell Sort.\n   -n length       Specify number of array elements (default: 100).\n   -p elements     Specify number of elements to print (default: 100).\n   -r seed         Specify random seed (default: 13371453).\n");

		return 1;
	}
	
    }
   	mtrand_seed(seed);
	uint32_t *arr = (uint32_t *) calloc(size, sizeof(uint32_t)); // allocate memory for an array
 	for (uint32_t i=0; i<size; i+=1) {
//		uint32_t mask = 0x3fffffff
		arr[i] = (mtrand_rand64()) & (0x3fffffff); //gets a random number and masks it
	} 
/*
	printf("reverse array\n");
	for (uint32_t n=0; n<size; n+=1) {
                        printf("%13"PRIu32,arr[n]);
                        if ((n+1)%5==0 && n>0) {
                                printf("\n");
                        }
        }

*/

	Stats stats; // intialize a stats structure
        stats.moves=0;
        stats.compares=0;
	if (set_member(set,4)) { // if asks for help, don't display any of the sorts
		set=set_remove(set,0);
		set=set_remove(set,1);
		set=set_remove(set,2);
		set=set_remove(set,3);
	}
        if (set_member(set, 0)) { // do shell sort
		reset(&stats);
		shell_sort(&stats, arr, size);
	        if (size<elements) {
        	        elements = size;
        	}
          	printf("Shell Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves, stats.compares);
        	for (uint32_t n=0; n<elements; n+=1) {
                	printf("%13"PRIu32,arr[n]);
                	if ((n+1)%5==0 && n>0) {
                        	printf("\n");
               	 	}
			
			if (n==elements-1 && ((n+1)%5!=0)) {
					printf("\n");
			}
			
        	}
		// reset the array
		mtrand_seed(seed);	
		for (uint32_t i=0; i<size; i+=1) {
        	        arr[i] = (mtrand_rand64()) & (0x3fffffff); //gets a random number and saves it in num
        	}
		reset(&stats);
	} 

	if (set_member(set, 1)) {
		bubble_sort(&stats, arr, size);
		mtrand_seed(seed);
                for (uint32_t i=0; i<size; i+=1) {
                        arr[i] = (mtrand_rand64()) & (0x3fffffff); //gets a random number and saves it in num
                }
                reset(&stats);
	} if (set_member(set, 2)) {
		quick_sort(&stats, arr, size);	
		if (size<elements) {
                elements = size;
        	}

		printf("Quick Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves, stats.compares);
         	for (uint32_t n=0; n<elements; n+=1) {
                        printf("%13"PRIu32,arr[n]);
                        if ((n+1)%5==0 && n>0) {
                                printf("\n");
                        }

                        if (n==elements-1 && ((n+1)%5!=0)) {
                                        printf("\n");
                        }

                }
	
		mtrand_seed(seed); // reset the array
                for (uint32_t i=0; i<size; i+=1) {
                        arr[i] = (mtrand_rand64()) & (0x3fffffff); //gets a random number and saves it in num
                }

                reset(&stats);

        }
	
	 if (set_member(set,3)) {
		heap_sort(&stats, arr, size);
	       	mtrand_seed(seed); // reset the array
                for (uint32_t i=0; i<size; i+=1) {
                        arr[i] = (mtrand_rand64()) & (0x3fffffff); //gets a random number and saves it in num
                }
                reset(&stats);

	}
	free(arr); // free the array
	return 0;
}

