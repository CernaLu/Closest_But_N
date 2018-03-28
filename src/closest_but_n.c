/*
 * This program reads an ASCII file
 * of N numbers, which must be provided in
 * ascending order, and determines
 * the number which is the closest-but-n
 * to a user-provided input x.
 * 
 * The algorithm is a binary search of
 * O[ log(N) ]  in the best case, and of
 * O[ n ] int the worst case, if n >= N/2
 * 
 * L. Cerna &  M. Heinen
 * cernalue@gmail.com
 * marco@marco-heinen.de
 *
 * Universidad de Guanajuato,
 * March 2018
 *
 */

#include "libraries.h"

#define VERBOSITY 0


int main(int argc, char **argv)
{
unsigned long int N, n, index;
double *array;
double x, c;

parse_inputfile(argc, argv, &array, &N, &n, &x);

if(VERBOSITY)
  {
  printf("\n\nFound %ld numbers in file '%s'\n\n", N, argv[1]);
  printf("Looking for the closest but %ld to %g\n\n", n, x);
  }

index = index_of_closest_but_n(array, n, x, 0, N-1);
c = array[index];

if(VERBOSITY)
  {
  printf("\n\nThe closest-but-%ld to %g "
         "among the numbers in '%s' is:\n\n"
         "%g\n\n", n, x, argv[1], c);
  }
else
  {
  printf("%g\n", c);
  }

free(array);
return(1);
}





unsigned long int index_of_closest_but_n(double *a, unsigned long int n, double x,\
                                         unsigned long int lo, unsigned long int hi)
{
unsigned long int m, overlaplo, overlaphi;

if(hi - lo < n)
  {
  printf("\n\nERROR: Function 'index_of_closest_but_n()' received invalid arguments.\n\n");
  exit(0);
  } 

/* Closest (but 0) among 3: */ 
if( (n==0) && (hi-lo==2) )
  {
  if( ((fabs(a[lo] - x)) < (fabs(a[lo+1] - x))) && ((fabs(a[lo] - x)) < (fabs(a[lo+2] - x))) )
    {
    return(lo);
    }
  if( ((fabs(a[lo+1] - x)) < (fabs(a[lo] - x))) && ((fabs(a[lo+1] - x)) < (fabs(a[lo+2] - x))) )
    {
    return(lo+1);
    }
  return(hi);
  }


if( (hi - lo + 1) / 2  < n+1 ) /* split no more (happens if hi - lo < 2*n + 1) */
  {
  return( index_of_furthest_but_n(a, hi - lo - n, x, lo, hi) );  
  }

/* Split into two overlapping sets, with max{n+1, 2} elements in the overlap: */
m = max(2, n+1);
overlaplo = (hi + lo)/2 - m/2;
overlaphi = (hi + lo)/2 + m/2;
if(0 == m%2)
  {
  overlaplo++;
  }

if(fabs(a[overlaplo] - x) < fabs(a[overlaphi] - x))
  {
  return(index_of_closest_but_n(a, n, x, lo, overlaphi));
  }
return(index_of_closest_but_n(a, n, x, overlaplo, hi));
}






unsigned long int index_of_furthest_but_n(double *a, unsigned long int n, double x,\
                                          unsigned long int lo, unsigned long int hi)
{
/*
 * The furthest is always one of the two extreme ends of the array
 * The furthest but 1 is one of the extreme ends, after the furthest has been removed
 * ...
 *
 * This function is O[N - n].
 *
 */
unsigned long int m, index;

if(hi - lo < n)
  {
  printf("\n\nERROR: Function 'index_of_furthest_but_n()' received invalid arguments.\n\n");
  exit(0);
  } 

for(m = 0; m <= n; m++)
  {
  if(fabs(a[lo] - x) > fabs(a[hi] - x)) 
    {
    index = lo;
    lo++;
    }
  else
    {
    index = hi;
    hi--;
    }
  }

return(index);
}






unsigned long int max(unsigned long int a, unsigned long int b)
{
if(a>b)
  {
  return(a);
  }
return(b);
}





void allocate_doublearray(double **a, unsigned long int N)
{
*a = malloc(N * sizeof(double));
if(NULL == *a)
  {
  printf("\n\nFailed to allocate %ld bytes.\n\n", N * sizeof(double));
  }
}




void copy_doublearray(double *src, double *dst, unsigned long int N)
{
unsigned long int i;

for(i = 0; i < N; i++)
  {
  dst[i] = src[i];
  }

}

