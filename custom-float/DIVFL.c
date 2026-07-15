#include <stdio.h>

typedef struct {
    float m;
    int e;
} FLOT;

FLOT DIVFL(float m1, int e1, float m2, int e2) {
    FLOT div;

        div.m = m1 / m2;
        div.e = e1 - e2;


    return div;
}

int main() {
    FLOT div = DIVFL(2, 6, 5, 2);
    printf("la valeur de div = %f * 10^%d\n", div.m, div.e);

    return 0;
}
