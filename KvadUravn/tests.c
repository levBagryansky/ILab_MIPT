#include <stdio.h>
#include "functions_kvadratUravn.c"
#include <stdlib.h>

int findDiscrTest();
int solveSQW_test();
int solveLN_test();


int findDiscrTest()
{
    int num_of_mistakes = 0;
    double a, b, c, d;
    a = 0; b = 0; c = 0;
    d = findDiscr(a, b, c);
    if(d < -PRECISION || d > PRECISION)
    {
        printf("Expected 0, but there is %fl\n", d);
        num_of_mistakes += 1;
    }

    d = findDiscr(2, -5, -3);
    if( d - 49 <= PRECISION and 49 - d <= PRECISION)
    {

    }
    else
    {
        printf("Expected 7 but there is %fl \n", d);
        num_of_mistakes += 1;
    }
    return num_of_mistakes;
}

int solveSQW_test()
{
    int num_of_mistakes = 0;
    double x1 = 0; double x2 = 0;

    if(solveSQW(5, 5, 5, 0, 0) != 0)
    {
        printf("The mistake in solveSQW function\n");
        num_of_mistakes += 1;
    }

    if(solveSQW(4, -13, 6, &x1, &x2) != 2 ||
     (abs(x1 - 2.228) > PRECISION) || (abs(x2 - 10.772) > PRECISION))
    {
        printf("The mistake in solveSQW function\n");
        num_of_mistakes += 1;
    }

    return num_of_mistakes;
}

int solveLN_test()
{
    int num_of_mistakes = 0;
    double x1 = 0; double x2 = 0;

    if(solveLN(8, 4, &x1, &x2) != 1 || (abs(x1 - (-0.5)) > PRECISION))
    {
        printf("The mistake in solveLN function\n");
        num_of_mistakes += 1;
    }

    if(solveLN(0, 0, &x1, &x2) != INFINIT_ROOT)
    {
        printf("The mistake in solveLN function\n");
        num_of_mistakes += 1;
    }

    if(solveLN(0, 4, &x1, &x2) != 0)
    {
        printf("The mistake in solveLN function\n");
        num_of_mistakes += 1;
    }

    return num_of_mistakes;
}
