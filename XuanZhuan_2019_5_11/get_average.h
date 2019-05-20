#ifndef GET_AVERAGE_H
#define GET_AVERAGE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <cmath>
#include "math.h"

 struct ave_struct
 {
    int flag;
    int set;
    int len;
    float *array;
 };

class GET_AVERAGE
{
public:
    struct ave_struct * init_list(int length);
    float insert_element(float element, struct ave_struct *node);
    float get_ave(struct ave_struct *node);
    float get_full_ave(struct ave_struct *node);
    int check_full_array(struct ave_struct *node, float reference, float range, int number);
    void poly_fit(int n, float *x, float *y, int poly_n, float *p);
    void gauss_solve(int n,float A[],float x[],float b[]);
    void least_squares(int n, float *x, float *y, float *p);
    void free_struct(struct ave_struct *node);
};

extern GET_AVERAGE get_average;
#endif
