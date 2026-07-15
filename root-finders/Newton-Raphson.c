#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * sin(x) - x;
}

double f1(double x) {
    return 2 * cos(x) - 1;
}

int main() {
    double x0 = 1.0;
    double x;
    double precision = 1e-6;
    int max_iterations = 100;

    int n = 0;
    while (n < max_iterations) {
        x = x0 - (f(x0) / f1(x0));

        if (fabs(f(x)) < precision) {
            printf("La solution approchée est : %lf\n", x);
            break;
        }

        x0 = x;
        n++;
    }

    if (n == max_iterations) {
        printf("La méthode n'a pas convergé dans le nombre d'itérations spécifié.\n");
    }

    return 0;
}
