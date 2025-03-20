/*
This file is for messin' around.
*/
#include <_stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long dot_product(long *u, long *v, long d);

int main(void) {
    // Define the dimension of the space.
    long d;
    d = 100;

    // Define the number of vectors.
    long n;
    n = 10000;

    // # Generate n random vectors, where each coordinate is a long int.

    long **v; // The pointer to the memory that will hold the vectors.
    v = (long **)malloc(n*sizeof(long *) + n*d*sizeof(long));

    // We want v[i] to be the ith vector, v[i][j] to be it's jth coordinate.
    long i, j;
    for (i = 0; i < n; i++) *(v + i) = (long *)(v + n) + d*i;

    long bound = (long)floor(sqrt(LONG_MAX/d));

    // Generate random vectors.
    for (i = 0; i < n; i++) {
        for (j = 0; j < d; j++) v[i][j] = mrand48() % bound;
    }

    // Define a query vector. If the last m coordinates are not provided,
    // set those coordinates to zero in the query vector.
    long q[d];
    for (j = 0; j < d; j++) q[j] = mrand48() % bound;

    // 1. Return the index of the top vector by dot product with the query
    //    vector.

    // O(nd)

    long max_p, max_idx, tmp;
    max_p = -bound;
    for (i = 0; i < n; i++) {
        tmp = dot_product(v[i], q, d);
        if (tmp > max_p) {
            max_p = tmp;
            max_idx = i;
        }
    }

    printf("The first eight coordinates of the query vector are\n[ ");
    for (i = 0; i < 8; i++) printf("%ld ", q[i]);
    printf("]\n");

    printf(
        "The first eight coordinates of the vector with the maximum "
        "projection onto the query vector are\n[ "
    );
    for (i = 0; i < 8; i++) printf("%ld ", v[max_idx][i]);
    printf("]\n");

    printf(
        "The scalar value of the projection of this maximum onto the query "
        "vector is %ld.\n",
        max_p
    );


    // Return the indexes of the top k vectors in the space by dot product with
    // the query vector.

    // Return all the indexes in descending order of their dot product with the
    // query vector.

    free(v);

    printf("Now, let's all go home.\n");
    return EXIT_SUCCESS;
}


long dot_product(long *u, long *v, long d) {
    long i, a = 0;
    for (i = 0; i < d; i++) a += u[i]*v[i];
    return a;
}
