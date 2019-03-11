/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			compare_sorts_main.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

/**
*** @file sorting_algorithms_main_driver.cpp
*** @brief File with main function built if <code>make</code> is called
*** @details <code>make</code> makes an executable by linking the main
*** function of this file. This function has to call the sorting algorithms on
*** arrays of the sizes as defined below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stopwatch.h"
#include "sorting_algorithms.h"

#define HUGE			65535	// 2^16
#define VERY_LARGE 		16384	// 2^14
#define LARGE			8192	// 2^13
#define MIDDLE			4096	// 2^12
#define SMALL			2048	// 2^11
#define VERY_SMALL		1024	// 2^10
#define TINY			256 	// 2 ^8

int* clone_array(int* huge_Array, int* other_array, unsigned long length);

struct sorting_times {
  float insertion_sort_TINY;
  float bubble_sort_TINY;
  float insertion_sort_VSMALL;
  float bubble_sort_VSMALL;
  float insertion_sort_SMALL;
  float bubble_sort_SMALL;
  float insertion_sort_MIDDLE;
  float bubble_sort_MIDDLE;
  float insertion_sort_LARGE;
  float bubble_sort_LARGE;
  float insertion_sort_VLARGE;
  float bubble_sort_VLARGE;
  float insertion_sort_HUGE;
  float bubble_sort_HUGE;
};

int main(int argc, char const *argv[])
{
  int test_data[HUGE];
  int huge[HUGE];
  int very_large[VERY_LARGE];
  int large[LARGE];
  int middle[MIDDLE];
  int small[SMALL];
  int very_small[VERY_SMALL];
  int tiny[TINY];

  struct sorting_times* results = (sorting_times*) malloc(sizeof(struct sorting_times));

  init_random(test_data, HUGE);
  clone_array(test_data, huge, HUGE);
  clone_array(test_data, very_large, VERY_LARGE);
  clone_array(test_data, large, LARGE);
  clone_array(test_data, middle, MIDDLE);
  clone_array(test_data, small, SMALL);
  clone_array(test_data, very_small, VERY_SMALL);
  clone_array(test_data, tiny, TINY);

  printf("Started testing!\n");
  start_stopwatch();
  bubble_sort(huge, HUGE);
  results -> bubble_sort_HUGE = elapsed_time();
  start_stopwatch();
  bubble_sort(very_large, VERY_LARGE);
  results -> bubble_sort_VLARGE = elapsed_time();
  start_stopwatch();
  bubble_sort(large, LARGE);
  results -> bubble_sort_LARGE = elapsed_time();
  start_stopwatch();
  bubble_sort(middle, MIDDLE);
  results -> bubble_sort_MIDDLE = elapsed_time();
  start_stopwatch();
  bubble_sort(small, SMALL);
  results -> bubble_sort_SMALL = elapsed_time();
  start_stopwatch();
  bubble_sort(very_small, VERY_SMALL);
  results -> bubble_sort_VSMALL = elapsed_time();
  start_stopwatch();
  bubble_sort(tiny, TINY);
  results -> bubble_sort_TINY = elapsed_time();
  printf("Finished bubble sort!\n");

  clone_array(test_data, huge, HUGE);
  clone_array(test_data, very_large, VERY_LARGE);
  clone_array(test_data, large, LARGE);
  clone_array(test_data, middle, MIDDLE);
  clone_array(test_data, small, SMALL);
  clone_array(test_data, very_small, VERY_SMALL);
  clone_array(test_data, tiny, TINY);

  start_stopwatch();
  insertion_sort(huge, HUGE);
  results -> insertion_sort_HUGE = elapsed_time();
  start_stopwatch();
  insertion_sort(very_large, VERY_LARGE);
  results -> insertion_sort_VLARGE = elapsed_time();
  start_stopwatch();
  insertion_sort(large, LARGE);
  results -> insertion_sort_LARGE = elapsed_time();
  start_stopwatch();
  insertion_sort(middle, MIDDLE);
  results -> insertion_sort_MIDDLE = elapsed_time();
  start_stopwatch();
  insertion_sort(small, SMALL);
  results -> insertion_sort_SMALL = elapsed_time();
  start_stopwatch();
  insertion_sort(very_small, VERY_SMALL);
  results -> insertion_sort_VSMALL = elapsed_time();
  start_stopwatch();
  insertion_sort(tiny, TINY);
  results -> insertion_sort_TINY = elapsed_time();
  printf("Finished insertion sort!\n");

  printf("Algorithm\tTiny\t\tV_Small\t\tSmall\t\tMiddle\t\tLarge\t\tV_Large\t\tHuge\n");
  printf("%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n","Bubblesort", results -> bubble_sort_TINY, results -> bubble_sort_VSMALL, results -> bubble_sort_SMALL, results -> bubble_sort_MIDDLE, results -> bubble_sort_LARGE, results -> bubble_sort_VLARGE, results -> bubble_sort_HUGE);
  printf("%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n","Insertionsort", results -> insertion_sort_TINY, results -> insertion_sort_VSMALL, results -> insertion_sort_SMALL, results -> insertion_sort_MIDDLE, results -> insertion_sort_LARGE, results -> insertion_sort_VLARGE, results -> insertion_sort_HUGE);
  return 0;
}

int* clone_array(int* test_data, int* other_array, unsigned long length)
{
  return (int*) memcpy(other_array, test_data, sizeof(int) * length);
}
/*
* Suggestion how to initialize the arrays which must be sorted with test data.
* 1. Create a array of size HUGE and initialize it with random data.
* 2. Copy from this array as many elements as needed into the seven target directories
*     (to make this efficiently, consider to use the function memcpy() of string.h).
*/
