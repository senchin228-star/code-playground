#include <stdio.h>
#include <math.h>

double discrim(double a, double b, double c)
{
    return b*b - 4*a*c;
}

int main()
{
    double a, b, c, d;
    int n;
    n = scanf("%lf %lf %lf", &a, &b, &c);
    if (n != 3) {
        printf("Error: wrong input. \n");
        return 1;
    }
    if (a == 0) {
        printf("This is not quadratic equation!\n");
        return 2;
    }
    d = discrim(a, b, c);
    if  (d <  0) {
        printf("No roots\n");
        return 3;
    }
    d = sqrt(d);
    printf("first root: %.5f \n second root: %.5f", (-b+d)/(2*a), (-b-d)/(2*a));
    return 0;
}
