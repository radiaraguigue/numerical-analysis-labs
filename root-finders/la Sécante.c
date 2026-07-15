#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * sin(x) - x;
}

int main() {
    double x0 = 1.0;
    double x1 = 2.0;
    double x;
    double precision = 1e-6;
    int max_iterations = 100;

    int n = 0;
    while (n < max_iterations) {
        x = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        if (fabs(f(x)) < precision) {
            printf("La solution approchée est : %lf\n", x);
            break;
        }

        x0 = x1;
        x1 = x;
        n++;
    }

    if (n == max_iterations) {
        printf("La méthode n'a pas convergé dans le nombre d'itérations spécifié.\n");
    }

    return 0;
}
