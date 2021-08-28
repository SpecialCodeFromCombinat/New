#include <stdio.h>
#include <math.h>
const double EPSILON = 1e-5;
double SolveSquare(double a = 0, double b = 0, double c = 0, double x1 = 0, double x2 = 0, double diskriminant = 0, double koren = 0);
int is_equal(double left, double right);
double solve_typical_square(double a, double b, double c, double x1, double x2);
double solve_equation_with_zero_B(double a, double c, double x1, double x2);
int main( )
{
    double a = 0, b = 0, c = 0, diskriminant = 0, koren = 0, nsuccess = 0, x1 = 0, x2 = 0;

    printf("Solve square equation Ax^2+Bx+C=0 \n ") ;
    printf("Type A, B, C \n \n") ;

    nsuccess = (scanf("%lg %lg %lg", &a, &b, &c));
    if (nsuccess == 3)
    {
        SolveSquare (a, b, c, x1, x2, diskriminant, koren);
    }

    else
    {
        printf ("Wrong symbols! Use only numbers!");
    }
    return 0;
}


int is_equal(double left, double right)
{
    return ((fabs(left - right)) < EPSILON);
}

double SolveSquare(double a, double b, double c, double x1, double x2, double diskriminant, double koren)
{
    if (b != 0)
        {
            if(is_equal((a/b),0))
            {
                x1 = (-c) / b;
                printf("Only one root = %lg (the equation is linear or close to it because a<<b)", x1);
                return 1;
            }
            else
            {
                    solve_typical_square (a, b, c, x1, x2);
            }
         }
         else
         {
            solve_equation_with_zero_B (a, c, x1, x2);
         }
}

double solve_typical_square(double a, double b, double c, double x1, double x2)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        printf("The equation has not roots");
        return 0;
    }

    else
    {
        double koren = sqrt(discriminant);
        x1 =((-b) + koren) / (2 * a);
        x2 =((-b) - koren) / (2 * a);
        if (x1 == x2)
        {
            printf("Only one root = %lg (Discriminant = 0)",x1);
            return 1;
        }

        else
        {
            printf("Two Roots = %lg and %lg", x1, x2);
            return 2;
        }
    }
}



double solve_equation_with_zero_B(double a, double c, double x1, double x2)
{
    if (a != 0)
    {
        if (c == 0)
        {
            printf("Only one root, it is zero! (x=0)");
            return 1;
        }
        else
        {
            if ((c/a) < 0)
            {
                x1 = sqrt(-(c/a));
                x2 = -(sqrt(-(c/a)));
                printf("The equation has two roots that differ only in the sign: %lg and %lg", x1, x2);
                return 2;
            }
            else
            {
                printf("The equation has no roots!");
                return 0;
            }
        }
    }
    else
    {
        if(c == 0)
        {
            printf("The equation has infinity number of roots, because A and B and C are zero!");
            return (-1);
        }
        else
        {
            printf("The equation has no roots! A = 0 and B = 0!");
            return 0;
        }
    }
}


