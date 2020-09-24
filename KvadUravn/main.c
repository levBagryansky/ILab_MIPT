#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions_kvadratUravn.c"
#include "tests.c"

int main(){
    int nRoots;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
                                                                                                                                                                                                                                                    printf ("Hello, world\n\n");
    printf("Enter coefficients a, b and c: \n");
    scanf ("%lg %lg %lg", &a, &b, &c);

    nRoots = choseFunction(a, b, c, &x1, &x2);
    switch(nRoots){
        case 0:  printf("There is not any roots \n");
                break;

        case 1:  printf("x = %lg \n", x1);
                break;

        case 2:  printf("x1 = %lg and x2 = %lg \n", x1, x2);
                break;
        case INFINIT_ROOT: printf("There is infinite roots");
                break;

    }

//-----------------------------------------------------------------------------

    printf("There are %i mistakes in findDiscr function\n", findDiscrTest());
    printf("There are %i mistakes in solveSQW function\n", solveSQW_test());
    printf("There are %i mistakes in solveLN function\n", solveLN_test());

}
