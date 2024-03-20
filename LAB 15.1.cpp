#include <stdio.h>
#include <math.h>

double f(double x);
double RootOfFunction(double xl, double xr, double epsilon);

int main() {
    double root;
    root = RootOfFunction(-1, 10, 0.1);
    printf("Root = %.1f", root);
    return 0;
}

double f(double x) {
    return 2 * x - 5;
}

double RootOfFunction(double xl, double xr, double epsilon) {
    double xm, fxl, fxm, error;

    do {
        xm = (xl + xr) / 2;
        fxl = f(xl);
        fxm = f(xm);

        if (fxl * fxm < 0)
            xr = xm;
        else
            xl = xm;

        error = fabs(xr - xl);
        printf("%.1f %.1f %.1f\n", xl, xm, xr);
    } while (error > epsilon);

    return xm;
}
