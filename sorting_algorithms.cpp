/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			sorting_algorithms.cpp
 * Author(s):		<your name>
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "sorting_algorithms.h"
#include <stdlib.h>

void 	init_random (int* array, unsigned long length)
{
  for(unsigned long i = 0; i < length; i++)
  {
    array[i] = random();
  }
}

void 	bubble_sort (int *array, unsigned long length)
{
  int last_unsorted = length - 1;
  bool elements_were_swapped = false;
  do
  {
      elements_were_swapped = false;
      for(int j = 0; j < last_unsorted; j++)
      {
        if(array[j] > array[j + 1])
        {
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
          elements_were_swapped = true;
        }
      }
      last_unsorted--;
  } while(elements_were_swapped);
}

void 	insertion_sort (int *array, unsigned long length)
{
   int i, key, j;
   for (i = 1; i < length; i++)
   {
       key = array[i];
       j = i-1;
       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}
