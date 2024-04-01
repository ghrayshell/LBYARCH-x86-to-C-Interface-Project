/* LBYARCH x86 - to - C Interface Programming Project
        > ASPECTO, Don Laude
        > DE RAMOS, Ghrazielle Rei A.
*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void cFunction(long n, double* A, double X[], double Y[], double Z[]) {

    for (int i = 0; i < n; i++) {
        Z[i] = (*A * X[i]) + Y[i];

        // printf("\n\na = %lf\nx = %lf\ny = %lf\nresult = %lf", A, X[i], Y[i], Z[i]);
    }
}