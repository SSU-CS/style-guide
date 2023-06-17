/** *******************************************************************************
 * @remark program times several sorting algorithms on data sets of various sizes *
 *                                                                                *
 * @remark this version includes code for straight selection insertion sorts      *
 * stubbs are provided for other sorting algoritms, including                     *
 *     hybrid quicksort, merge sort and heap sort                                 *
 *                                                                                *
 * @author Henry M. Walker                                                        *
 * @remark Assignment  Comparison of Sorting Algorithms                           *
 * @file  sort-comparisons.c                                                      *
 * @date  August 15, 2022                                                         *
 *                                                                                *
 * @remark References                                                             *
 * @remark Dynamic Programming:  Anany Levitin, "The Design and                   *
 *         and Analysis of Algorithms", Second Edition,                           *
 *         Sections 3.1 (Selectino Sort), 4.1 (Insertion Sort),                   *
 *                  5.1 (Mergesort), 5.2 (Quicksort),  6.4 (Heapsort)             *
 *                                                                                *
 * @remark People participating with Problem/Progra Discussions:                  *
 *         Marcia Watts                                                           *
 *                                                                                *
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>   // for malloc, free, srand, rand
#include <time.h>     // for time

/** *******************************************************************************
 * structure to identify both the name of a sorting algorithm and                 *
 * a pointer to the function that performs the sort                               *
 * the main function utilizes this struct to define an array of                   *
 * the sorting algorithms to be timed by this program.                            *
 *********************************************************************************/
typedef struct sorts {
  char * name;                     /**< the name of a sorting algorithm as text  */
  void (*sortProc) (int [ ], int); /**< the procedure name of a sorting function */
} sorts;

/* * * * * * * * * * sorting procedures, with helper, as needed  * * * * * * * * */

/** *******************************************************************************
 * straight selection sort                                                        *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
  ********************************************************************************/

void selectionSort (int a [ ], int n) {
   int i, j, smallIndex;
   int temp;
   // put largest remaining element in a[i]
   for (i = n-1; i >= 0; i--) {
      // find largest in a[i..n-1]
      smallIndex = i;
      for (j = i-1; j >= 0; j--) {
         if (a[smallIndex] < a[j])
            smallIndex = j;
     }
     // swap smallest to a[i]
     temp = a[smallIndex];
     a[smallIndex] = a[i];
     a[i] = temp;
   }
}

/** *******************************************************************************
 * insertion sort                                                                 *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
  ********************************************************************************/

void insertionSort (int a [], int n) {
// method to sort using the insertion sort
// parameters:  a, the array to be sorted
//              length, the size of the a array
   for (int k = 1; k < n; k++) {
      int item = a[k];
      int i = k-1;
      while ((i >= 0) && a[i] > item){
         a[i+1] = a[i];
         i--;
      }
      a[i+1] = item;
   }
}

/* * * * hybrid quicksort with improved partition and  helper functions *  * * * */

/** *******************************************************************************
 * Improved Partition function                                                    *
 * uses a[left] as pivot value in processing                                      *
 *    algoithmic elements                                                         *
 *       random pivot utilized                                                    *
 *       swaps only when required by finding misplaced large and small elements   *
 * @param  a  the array to be processed                                           *
 * @param  size  the size of the array                                            *
 * @param  left:  the lower index for items to be processed                       *
 * @param  right  the upper index for items to be processed                       *
 * @post   elements of a are rearranged, so that                                  *
 *             items between left and index mid are <= a[mid]                     *
 *             items between dex mid and right are >= a[mid]                      *
 * @returns  mid                                                                  *
 *********************************************************************************/

/* --------improvedParttion ------- */
int impPartition (int a[ ], int size, int left, int right) {
 
  int pivot = a[left];
  // to be implemented
  return (left+right)/2;  // return average as dummy value to allow compiling
  }

/** *******************************************************************************
 * Quicksort helper function                                                      *
 *    algoithmic elements                                                         *
 *       quicksort used when array segments > variable breakQuicksortToInsertion  *
 *       insertion sort used for small array segments                             *
 * @param  a  the array to be processed                                           *
 * @param  size  the size of the array                                            *
 * @param  left  the lower index for items to be processed                        *
 * @param  right the upper index for items to be processed                        *
 * @post  sorts elements of a between left and right                              *
 *********************************************************************************/
void hybridQuicksortHelper (int a [ ], int size, int left, int right) {

  // to be implemented
}

/** *******************************************************************************
 * hybrid quicksort, main function                                                *
 *    algoithmic elements                                                         *
 *       random pivot used in partition function                                  *
 *       insertion used for small array segments                                  *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
  ********************************************************************************/
void hybridQuicksort (int a [ ], int n) {
  hybridQuicksortHelper (a, n, 0, n-1);
}

/* * * * * * * *  merge sort and helper functions * * * * * * * * */


/** *******************************************************************************
 * merge sort helper function                                                     *
 * @param  aInit  source array for merging                                        *
 * @param  aRes   target array for merging                                        *
 * @param  aInitLength  the size of the array segment to be merged                *
 * @param  start1  the first index of the first array segment to be merged        *
 * @param  start2  the first index of the second  array segment to be merged      *
 * @param  end2 the last index of the second array segment to be merged           *
 * @post  elements  aInit[start1]..aInit[start1+mergeSize] merged with            *
 *              aInit[start2]..Init[end2]                                         *
 *               with the result placed in aRes                                   *
 * Note:  it may be that start2 >= aInit.length, in which case, only the          *
 *        valid part of aInit[start1] is copied                                   *
 *********************************************************************************/
void merge (int aInit [ ], int aRes [ ], int aInitLength,
                int start1, int start2, int end2) {
  // to be implemented
}	

/** *******************************************************************************
 * merge sort helper function                                                     *
 * @param  initArr  the array to be sorted                                        *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *********************************************************************************/
void mergeSort (int initArr [ ], int n) {

  // to be implemented 

}

/* * * * * * * * heap sort and helper functions * * * * * * * * */


/** *******************************************************************************
 * percDown function                                                              *
 * @param  array  the array to be made into a heap, starting at hold              *
 * @param  hole:  base of subtree for start of processing                         *
 * @param  size  the size of the array                                            *
 * @pre   all nodes in left and right subtrees of the hole node are heaps         *
 * @post  all nodes in the tree from the hole node downward form a hea            *
 *********************************************************************************/
void percDown(int array [ ], int hole, int size) {
    
  // to be implemented 

}

/** *******************************************************************************
 * heap sort, main function                                                       *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *********************************************************************************/

void heapSort (int a [ ], int n) {
    // Build Heap
    for (int i=n/2 ; i>=0 ; i-- ) {
        percDown(a, i, n);
    }

    for (int i=n-1 ; i>0 ; i-- ) {
      int tmp = a[0];
      a[0] = a[i];
      a[i] = tmp   ; // deleteMax
      percDown( a, 0, i); // Maintain heap ordering property
    }
}

/* * * * * * * * * * * * procedures to check sorting correctness  * * * * * * * * */

/** *******************************************************************************
 * check all array elements have values 0, 2, 4, . . ., 2(n-1)                    *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * returns  "ok" if array contains required elements; "NO" if not                 *
 *********************************************************************************/
char * checkAscValues (int a [ ], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] != 2*i) {
      printf ("%4d %4d", i, a[i]);
      return "NO";
    }
  }
  return "ok";
}

/** *******************************************************************************
 * check all array elements are in non-descending order                           *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * returns  "ok" if array elements in non-descending order; "NO" otherwise        *
 *********************************************************************************/
char * checkAscending (int a [ ], int n) {
  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1])
      return "NO";
  }
  return "ok";
}

/** *******************************************************************************
 * driver program for testing and timing sorting algorithms                       *
 **********************************************************************************/

int main ( ) {
  #define numAlgs 5
  sorts sortProcs [numAlgs] = {{"selection sort", selectionSort},
                               {"insertion sort", insertionSort},
                               {"hybrid qcksort", hybridQuicksort },
                               {"merge sort    ", mergeSort    },
                               {"heap sort     ", heapSort     }};

  //size variables
  int maxDataSetSize = 40960000;
  int algTimeLimit = 15; // do not print results after algorithm taks this long (in seconds)

  //arrays to determine which algorithms are to be run
  //   1 = run algorithm; 0 = do not run (alg has taken too long in past
  int algAscActive [numAlgs];
  int algRanActive [numAlgs];
  int algDesActive [numAlgs];

  // initially all algorithms active for ascending, random, and descendind data
  int numSort;
;
 for (numSort = 0; numSort < numAlgs; numSort++) {
      algAscActive[numSort] = 1;
      algRanActive[numSort] = 1;
      algDesActive[numSort] = 1;
    }      
 
  // randomize random number generator's seed
  srand (time ((time_t *) 0) );
  srandom (time ((time_t *) 0) );
  
  // print headings
  printf ("               Data Set                                Times\n");
  printf ("Algorithm        Size        Ascending Order       Random Order   Descending Order\n");

  int size;
  for (size = 10000; size <= maxDataSetSize; size *= 2) {
      // create and initialize control data set arrays
     int * asc = (int *) malloc (size * sizeof(int));   //array with ascending data
     int * ran = (int *) malloc (size * sizeof(int));   //array with random data
     int * des = (int *) malloc (size * sizeof(int));   // array with descending data

     int i;
     for (i = 0; i< size; i++) {
        asc[i] = 2*i;
        ran[i] = rand();
        des[i] = 2*(size - i - 1); 
     } 

     // timing variables
     clock_t start_time, end_time;
     double elapsed_time;

     /* loop to test successive sorting procedures */
     // copy to test arrays
     int * tempAsc = malloc (size * sizeof(int));
     int * tempRan = malloc (size * sizeof(int));
     int * tempDes = malloc (size * sizeof(int));

     // break output for this array sze
     printf ("\n");

     /* iterate through sorting algorithms */
     for (numSort = 0; numSort < numAlgs; numSort++) {

       for (i = 0; i< size; i++) {
         tempAsc[i] = asc[i];
         tempRan[i] = ran[i];
         tempDes[i] = des[i];
       }
     
       // timing for sorting algorithm
       printf ("%14s %8d", sortProcs[numSort].name, size);
       // run-time stack exceeded for qicksort for large ordered arrays
       if (!algAscActive[numSort]) {
         printf ("           ---  --");
       } else {
         // ascending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempAsc, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%14.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempAsc, size));
         algAscActive[numSort] = (elapsed_time <= algTimeLimit);
       }
       
       if (!algRanActive[numSort]) {
         printf ("            ---  --");
       } else {
        // random data
       start_time = clock ();
       sortProcs[numSort].sortProc (tempRan, size);
       end_time = clock();
       elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
       printf ("%15.1lf", elapsed_time);
       printf ("  %2s", checkAscending (tempRan, size));
         algRanActive[numSort] = (elapsed_time <= algTimeLimit);
       }
       
       // run-time stack exceeded for qicksort for large ordered arrays
       if (!algDesActive[numSort]) {
         printf ("            ---  --");
       } else {
         // descending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempDes, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%15.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempDes, size));
         algDesActive[numSort] = (elapsed_time <= algTimeLimit);
       }
       
       printf ("\n");

     }

     // clean up copies of test arrays
     free (tempAsc);
     free (tempRan);
     free (tempDes);

     // clean up original test arrays
     free (asc);
     free (ran);
     free (des);

  } // end of loop for testing procedures with different array sizes

  return 0;
}
