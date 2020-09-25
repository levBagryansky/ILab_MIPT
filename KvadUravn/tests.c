#include <stdio.h>
#include "functions_kvadratUravn.c"
#include <stdlib.h>

#define AllAnswers 1
int main()
{

    int num_of_mistakes = 0;
    double a, b, c, d;
    a = 0; b = 0; c = 0;
    d = findDiscr(a, b, c);
    if (d < -PRECISION || d > PRECISION)
    {
        printf("Expected 0, but there is %fl\n", d);
    }
    else
    {
        #ifdef AllAnswers
        printf("In test of findDiscr function expected 0 and answer 0. Fine.\n");
        #endif
    }

    d = findDiscr(2, -5, -3);
    if( d - 49 <= PRECISION and 49 - d <= PRECISION)
    {
        #ifdef AllAnswers
        printf("In test of findDiscr function expected 49 and answer near 49. Fine.\n");
        #endif
    }
    else
    {
        printf("Expected 7 but there is %fl \n", d);
        num_of_mistakes += 1;
    }
    printf("\n");
//-----------------------------------------------------------------------------

    double x1 = 0; double x2 = 0;

    if(solveSQW(5, 5, 5, 0, 0) != 0)
    {
        printf("The mistake in solveSQW function\n");
    }
    else
    {
        #ifdef AllAnswers
        printf("In test of solveSQW function expected 0 and answer 0. Fine.\n") ;
        #endif
    }

    if(solveSQW(4, -13, 6, &x1, &x2) != 2 ||
     (abs(x1 - 2.228) > PRECISION) || (abs(x2 - 10.772) > PRECISION))
    {
        printf("The mistake in solveSQW function as expected\n");
    }
    else
    {
        #ifdef AllAnswers
        printf("In solveSQW fine. Returned 2 and x1 near 2.228, x2 near 10.772 as expected\n");
        #endif
    }
    printf("\n");
//-----------------------------------------------------------------------------

    x1 = x2 = 0;
    if(solveLN(8, 4, &x1, &x2) != 1 || (abs(x1 - (-0.5)) > PRECISION))
    {
        printf("The mistake in solveLN function as expected\n");
    }
    else
    {
        #ifdef AllAnswers
        printf("In solveLN fine. Returned 1 and x1 near -0.5 as expected\n") ;
        #endif
    }

    if(solveLN(0, 0, &x1, &x2) != INFINIT_ROOT)
    {
        printf("The mistake in solveLN function as expected\n");
        num_of_mistakes += 1;
    }
    else
    {
        #ifdef AllAnswers
        printf("In solveLN fine. Returned INFIT_ROOT as expected\n") ;
        #endif
    }

    if(solveLN(0, 4, &x1, &x2) != 0)
    {
        printf("The mistake in solveLN function as expected\n");
    }
    else
    {
        #ifdef AllAnswers
        printf("In solveLN fine. Returned 0 roots as expected\n") ;
        #endif
    }

//-----------------------------------------------------------------------------

}
