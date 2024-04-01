/* LBYARCH x86 - to - C Interface Programming Project
        > ASPECTO, Don Laude
        > DE RAMOS, Ghrazielle Rei A.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void cFunction(long n, double* A, double* X, double* Y, double* cZ);
extern double zoperation1(double a, double x, double y);

void fillValues(int n, double* X, double* Y, double* cZ, double* asmZ) {
    for (int i = 0; i < n; i++) 
    {
        X[i] = rand() % 20;
        Y[i] = rand() % 20;
        cZ[i] = 0.0f;
        asmZ[i] = 0.0f;
    }
}

int main() {
    srand(time(NULL));
    int exp, n, incIndex, correct = 1;
    double incC, incASM, A = 2.0;

    exp = 28;
    n = 1 << exp;

    // Array Variables
    double* X, * Y, * cZ, * asmZ;
    
    // Clock Timer Variables
    clock_t startC, startAsm, endC, endAsm;
    double timeC = 0, timeAsm = 0;

    X = (double*)malloc(n * sizeof(double));
    Y = (double*)malloc(n * sizeof(double));
    cZ = (double*)malloc(n * sizeof(double));
    asmZ = (double*)malloc(n * sizeof(double));

    printf("\n\n   Size = %d (2^%d)", n, exp);
    fillValues(n, X, Y, cZ, asmZ);

    /* EXECTUTION TIME */
        int loop = 30; // Run 30 times for each version
    
        for (int j = 0; j < loop; j++)
        {
            // C Function
            startC = clock();
            cFunction(n, &A, X, Y, cZ);
            endC = clock();
            timeC += ((double)(endC - startC)) * 1e3 / CLOCKS_PER_SEC;

            // Assembly Function
            startAsm = clock();
            for (int i = 0; i < n; i++)
            {
                asmZ[i] = zoperation1(A, X[i], Y[i]);

                // For Incorrect Ouput (Uncomment to test)
                //asmZ[3] = 99.99;
            } 
            endAsm = clock();
            timeAsm += ((double)(endAsm - startAsm)) * 1e3 / CLOCKS_PER_SEC;
        }
    /* END OF EXECTUTION TIME */

    /* DISPLAY OF RESULTS (First 10 Elements) */
        printf("\n\n --------------------------");
        printf("\n **** VECTOR-Z RESULTS ****");
        printf("\n --------------------------");
        printf("\n     #      C      ASM");
        for (int i = 0; i < 10; i++)
            printf("\n    [%d]   %4.2f   %4.2f", i, cZ[i], asmZ[i]);
        printf("\n --------------------------");
    /* END OF RESULT DISPLAY */

    /* CORRECTNESS CHECKER  */
        for (int i = 0; i < n; i++)
        {
            if (cZ[i] != asmZ[i])
            {
                correct = 0;
                incIndex = i;
                incC = cZ[i];
                incASM = asmZ[i];
                i = n;
            }
        }
    /* END OF CORRECTNESS CHECKER */

    /* PRINT TIME & CORRECTNESS */
        printf("\n\n   AVERAGE EXECUTION TIME");
        printf("\n\n        C         ASM");
        printf("\n   %.4fms   %.4fms", timeC / loop, timeAsm / loop);
        printf("\n\n --------------------------");

        if (correct == 1)
        {
            printf("\n\n    !! CORRECT OUTPUT !!\n\n   x86-64 kernel output is\n   matching with C kernel!\n");
        }
        else
        {
            printf("\n   !! INCORRECT OUTPUT !!\n\n   Mismatch detected at:\n");
            printf("     #      C      ASM");
            printf("\n    [%d]   %4.2f   %4.2f", incIndex, incC, incASM);
        }
        printf("\n --------------------------\n\n\n");
    /* END OF PRINT */
        
    /* FREE USED MEMORY */
        free(X);
        free(Y);
        free(cZ);
        free(asmZ);

    return 0;
}