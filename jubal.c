/*
This file is for messin' around.
*/
#include <_stdlib.h>
#include <stdio.h>
#include <stdlib.h>

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
    long i, j;
    for (i = 0; i < n; i++) {
        // We want v[i] to be the ith vector, v[i][j] to be it's jth coordinate.
        *(v + i) = (long *)(v + n) + d*i;
    }

    for (i = 0; i < n; i++) for (j = 0; j < d; j ++) v[i][j] = mrand48();

    // Define a query vector. If the last m coordinates are not provided,
    // set those coordinates to zero in the query vector.

    // Return all the indexes in descending order of their dot product with the
    // query vector.

    // Return the indexes of the top k vectors in the space by dot product with
    // the query vector.


    free(v);

    printf("Now, let's all go home.\n");
    return EXIT_SUCCESS;
}
