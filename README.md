**How to run the script (sorting.c)** <br>
The script simulate four different sorting algorithms. To compile the script, type in the command line “make sorting”. Afterwards, you can run the program by writing “./sorting” followed by command line options. It will print the name of the sorting algorithm, number of moves used, number of comparisons, and the first few sorted elements of the array.  
<br>

**Command Line Options**

Need to call the script following these options: -a (calls all sorting algorithms). -s (shell sort), -b (shell sort), -q (quick sort), -h (heap sort), -r followed by seed number, -n followed by the number of elements in the array, -p followed by the number of elements to print, and -H (prints program usage). The number of elements needs to be between 1 to 250,000,000 inclusive. If a different number would be entered, it will return an error number. You can mix and match the command options. For example, you are allowed to call -q -b to print both the quicksort and bubble sort.
<br>

**Files**

DESIGN.pdf - shows my general idea and pseudo code for my code. It has both my initial design and final one. 

WRITEUP.pdf - answers the pre lab questions and has graphs that visually explain my answers. Also, contains my reflection of the assignment (what I learned) and citations of websites I used while completing the assignment.

README.md - has descriptions on how to run the script, files in the directory, and citations. 

Makefile - a script used to compile my sorting file and clean the files after running. You can use it by writing “make {name of function}”. 

bubble.c - implements bubble sort that checks adjacent pairs of numbers and swap them if needed.

bubble.h - a header file that has the declaration of all the functions and used in bubble.c and specify its interface

heap.c - implements a min heap sort using two routines: building a heap and fixing it.

heap.h - a header file that has the declaration of all the functions and used in heap.c and specify its interface

shell.c - implements shell sort that checks pairs of far apart elements using a gap sequence.

shell.h - a header file that has the declaration of all the functions and used in shell.c and specify its interface

quick.c - implements quicksort that is supposed to be the fastest comparison sorting algorithm.

quick.h - a header file that has the declaration of all the functions and used in quick.c and specify its interface

set.c - implements a set structure with a few basic arithmetic operations (such as complement, difference, intersection, union, deletion, and insertion)

set.h - a header file that has the declaration of all the functions and used in set.c and specify its interface of set ADT

stats.c - implements a stats structure that is used to save the amount of moves and comparisons each sorting algorithm uses.

stats.h - a header file that has the declaration of all the functions and used in stats.c and specify its interface

mtranc.c - has functions that are used to create random numbers.

mtrand.h - a header file that has the declaration of all the functions used in the mtrand.c

sorting.c -  contains the main(). Gets user input from the command line and prints data based on that. Explained in more details in the ‘command line options’ section.
<br>

**Citations:**
 
1)) Helped with build heap function https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm 

2)) Used to understand how to use structures https://www.programiz.com/c-programming/c-structures-pointers 

3)) Heap Sort Visualization https://bl.ocks.org/mpmckenna8/5b01b4f6e5cfb8ce022e287c80edaf8d 

