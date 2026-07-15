#include <stdio.h>
#include <math.h>

double g(double x) {
    return 2 * sin(x);
}

int main() {
    double x0 = 1.0;
    double x;
    double precision = 1e-6;
    int max_iterations = 100;
    int n = 0;
    while (n < max_iterations) {
        x = g(x0);

        if (fabs(x - x0) < precision) {
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
