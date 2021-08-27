#include <stdio.h>
#include <math.h>
const double epsilon = 1e-5;
int compare(double val);
int main( )

{
double a = 0, b=0, c=0, discriminant=0, koren=0, nsuccess=0, x1=0, x2=0;

printf("Solve square equation Ax^2+Bx+C=0 \n ") ;
printf("Type A, B, C \n \n") ;

nsuccess = (scanf("%lg %lg %lg", &a, &b, &c));
if (nsuccess == 3)
{
    if (b != 0)
    {
        switch (compare (a/b))
        {
            case 1 :
            {
                x1 = (-c) / b;
                printf("Only one root = %lg (the equation is linear or close to it because a<<b)", x1);
                break;
            }
            case 0 :
            {
                discriminant = b * b - 4 * a * c;
                if (discriminant < 0)
                {
                    printf("The equation has not roots");
                }

                else
                {
                    koren = sqrt(discriminant);
                    x1 =((-b) + koren) / (2 * a);
                    x2 =((-b) - koren) / (2 * a);
                    if (x1 == x2)
                    {
                        printf("Only one root = %lg (Discriminant = 0)",x1);
                    }

                    else
                    {
                        printf("Two Roots = %lg and %lg", x1, x2);
                        break;
                    }
                }

            }
        }
     }
     else
     {
        if (a != 0)
        {
            if (c == 0)
            {
                printf("Only one root, it is zero! (x=0)");
            }
            else
            {
                if ((c/a) < 0)
                {
                    x1 = sqrt(-(c/a));
                    x2 = -(sqrt(-(c/a)));
                    printf("The equation has two roots that differ only in the sign: %lg and %lg", x1, x2);
                }
                else
                {
                    printf("The equation has no roots!");
                }
            }
        }
        else
        {
            if(c == 0)
            {
                printf("The equation has infinity number of roots, because A and B and C are zero!");
            }
            else
            {
                printf("The equation has no roots! A = 0 and B = 0!");
            }
        }
    }
}

else
{
    printf ("Wrong symbols! Use only numbers!");
}
return 0;
}


int compare(double val)
{
    return ((fabs(val) - 0)<epsilon);
}

