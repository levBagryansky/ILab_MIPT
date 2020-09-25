#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions_kvadratUravn.c"

int main(){
    int nRoots;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("Enter coefficients a, b and c: \n");
    scanf ("%lg %lg %lg", &a, &b, &c);

    nRoots = choseFunction(a, b, c, &x1, &x2);
    writeAnswer(nRoots, x1, x2);

    return 0;
}
