#include <stdio.h>

typedef struct {
    float m;
    int e;
} FLOT;

FLOT MULFL(float m1, int e1, float m2, int e2) {
    FLOT M;

        M.m = m1 * m2;
        M.e = e1 + e2;


    return M;
}

int main() {
    FLOT M = MULFL(2, 6, 5, 2);
    printf("la valeur de M = %f * 10^%d\n", M.m, M.e);

    return 0;
}
