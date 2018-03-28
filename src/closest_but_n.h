#ifndef __23d78h_CLOSESTBUTN_H
#define __23d78h_CLOSESTBUTN_H


unsigned long int index_of_closest_but_n(double *a, unsigned long int n, double x,\
                                         unsigned long int lo, unsigned long int hi);

unsigned long int index_of_furthest_but_n(double *a, unsigned long int n, double x,\
                                          unsigned long int lo, unsigned long int hi);

unsigned long int max(unsigned long int a, unsigned long int b);

void allocate_doublearray(double **a, unsigned long int N);

void copy_doublearray(double *src, double *dst, unsigned long int N);


#endif
