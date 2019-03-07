/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			stopwatch.cpp
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "stopwatch.h"
#include <time.h>

clock_t end;
clock_t start;

void 	start_stopwatch ()
{
  start = clock();
  end = 0;
}

void 	stop_stopwatch ()
{
  end = clock();
}

float 	elapsed_time ()
{
  if(end == 0)
  {
    stop_stopwatch();
  }
  return float(end - start) / CLOCKS_PER_SEC;
}
