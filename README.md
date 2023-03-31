


## Short Description:
	This program implements the famous sorting algorithms: quick sort, heap sort, 
	shell sort, and batcher sort. Each of these algorithms input an array and depending on their sorting method, loop through the array to sort them in ascending order

## Build:
	To build/compile this program we can make use of the following commands:
	$ make
	$ make all
	$ make sorting
	
	To delete all the files that are compiler generated use the following command:
	$ make clean
	
	To make all the files clang formatted use the following command:
	$ make format
	

## Running:
	SYNOPSIS
   	collection of comparison-based sorting algorithms.

	USAGE
	   ./sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]

	OPTIONS
	   -H              Display program help and usage.
	   -a              Enable all sorts.
	   -s              Enable Shell Sort.
	   -b              Enable Batcher Sort.
	   -h              Enable Heap Sort.
	   -q              Enable Quick Sort.
	   -n length       Specify number of array elements (default: 100).
	   -p elements     Specify number of elements to print (default: 100).
	   -r seed         Specify random seed (default: 13371453).

