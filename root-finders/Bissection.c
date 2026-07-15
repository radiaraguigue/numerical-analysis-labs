#include <stdio.h>
#include <math.h>

int main() {
    double a = 1, b = 6;
    double fa = 2 * sin(a) - a;
    double fb = 2 * sin(b) - b;
    double eps = 0.0001;
    int nb = 0;
    printf("nb | x | f(x)\n");
    printf("-------------------------\n");

    if (fa * fb < 0) {
        while ((b - a) > eps) {
            nb++;
            double x = (a + b) / 2;
            double fx = 2 * sin(x) - x;
            if (fa * fx < 0) {
                b = x;
            } else {
                a = x;
            }
            printf("%2d | %.5f | %.5f\n", nb, x, fx);
        }
    }

    return 0;
}
