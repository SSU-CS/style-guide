/** ***************************************************************************
 * @remark computation and timing of elements of the Fibonnaci sequence       *
 *  using the basic recurisve formula for the sequence                        *
 *  with and without dynamic prog.                                            *
 *                                                                            *
 * @author Henry M. Walker                                                    *
 * @file  fibonacci.c                                                         *
 * @date  August 14, 2022                                                     *
 *                                                                            *
 * @remark References                                                         *
 * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
 *         and Analysis of Algorithms", Second Edition,                       *
 *         Chapter 8:  Dynamic Programming                                    *
 * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
 *         and Analysis of Algorithms", Second Edition,                       *
 *         Section 2.5:  Example: Computing the nth Fibonacci Number          *
 *                                                                            *
 * @remark People participating with Problem/Progra Discussions:              *
 *         None                                                               *
 *                                                                            *
 *****************************************************************************/

#include <stdio.h>
#include <time.h>     // for time

/** ***************************************************************************
 * compute the nth fibonacci number directly,                                 *
 * using the recursive definition of the sequence                             *
 * @param  n:  the nth Fibonacci number to be computed                        *
 *              (starting the sequence at index 0)                            *
 * @pre   0 <= n                                                              *
 * @returns  the nth Fibonacci number                                         *
 *****************************************************************************/
int fibSeq1(int n) {
  if (n <= 1 ) {
    return 1;
  }
  else {
    return fibSeq1 (n-1) + fibSeq1 (n-2);
  }
}

/** ***************************************************************************
 * helper function to compute the nth fibonacci number,                       *
 * using the recursive definition and dynamic programming                     *
 * @param  n:  the nth Fibonacci number to be computed                        *
 *              (starting the sequence at index 0)                            *
 * @param  fibArr:  an initialize array, recording                            *
 *              Fibonacci numbers already computed                            *
 * @pre   0 <= n <= 1 + length of fibArr array                                *
 * @returns  the nth Fibonacci number                                         *
 *****************************************************************************/
int fibSeq2Helper (int n, int fibArr [ ]) {
  if (fibArr[n] != 0) {
    return fibArr[n];
  }
  if (n <= 1) {
    return fibArr[n] = 1;
  }
  else {
    return fibArr[n] = fibSeq2Helper (n-1, fibArr)
                       + fibSeq2Helper (n-2, fibArr);
  }
}

/** ***************************************************************************
 * compute the nth fibonacci number,                                          *
 * using the recursive definition and dynamic programming                     *
 * @param  n:  the nth Fibonacci number to be computed                        *
 *              (starting the sequence at index 0)                            *
 * @pre   0 <= n                                                              *
 * @returns  the nth Fibonacci number                                         *
 *****************************************************************************/
int fibSeq2 (int n) {
  //create an initialized local array for bookkeeping before recursing
  int arr [n+1];
  for (int i = 0; i <= n; i++) {
    arr[i] = 0;
  }
  return fibSeq2Helper (n, arr);
}

/** ***************************************************************************
 * main procedure controls computation, timing, and printing                  *
 *****************************************************************************/
int main ( ) {
  int reps = 100;  // number of times call repeated to help timings
  
  printf ("timing of two functions to compute the nth Fib number\n");
  printf ("    (each function call repeated %d times)\n", reps);
  printf ("               Approach 1          Approach 2\n");
  printf ("     n      Fib[n]     time    Fib[n]     time\n");

  // variables used for loops and timing
  int n;
  int value;
  clock_t start_time, end_time;
  double elapsed_time;

  for (n = 1; n <= 45; n += 4) {
    printf ("%6d", n);

    // time first approach
    start_time = clock ();
    for (int j = 0; j < reps; j++) {
      value = fibSeq1 (n);
    }
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    printf ("%11d   %6.1lf", value, elapsed_time);

    // time second approach
    start_time = clock ();
    for (int k = 0; k < reps; k++) {
      value = fibSeq2 (n);
    }
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    printf ("%11d   %6.1lf\n", value, elapsed_time);
  }
}
