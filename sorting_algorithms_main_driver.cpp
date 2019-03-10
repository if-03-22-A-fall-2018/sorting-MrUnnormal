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

int main(int argc, char const *argv[])
{
  int huge[HUGE];
  int very_large[VERY_LARGE];
  int large[LARGE];
  int middle[MIDDLE];
  int small[SMALL];
  int very_small[VERY_SMALL];
  int tiny[TINY];

  init_random(huge, HUGE);
  clone_array(huge, very_large, VERY_LARGE);
  clone_array(huge, large, LARGE);
  clone_array(huge, middle, MIDDLE);
  clone_array(huge, small, SMALL);
  clone_array(huge, very_small, VERY_SMALL);
  clone_array(huge, tiny, TINY);
  return 0;
}

int* clone_array(int* huge_Array, int* other_array, unsigned long length)
{
  for(unsigned long i = 0; i < length; i++)
  {
    other_array[i] = huge_Array[i];
  }
  return other_array;
}
/*
* Suggestion how to initialize the arrays which must be sorted with test data.
* 1. Create a array of size HUGE and initialize it with random data.
* 2. Copy from this array as many elements as needed into the seven target directories
*     (to make this efficiently, consider to use the function memcpy() of string.h).
*/
