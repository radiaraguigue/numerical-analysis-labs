#include <stdio.h>

typedef struct {
    float m;
    int e;
} FLOT;

FLOT DIFFL(float m1, int e1, float m2, int e2) {
    FLOT dif;

    if (e1 == e2) {
        dif.m = m1 - m2;
        dif.e = e1;
    } else if (e1 > e2) {
        int t = e1 - e2;
        m1 *= pow(10, t);
        dif.m = m1 - m2;
        dif.e = e2;
    } else {
        int t = e2 - e1;
        m2 *= pow(10, t);
        dif.m = m1 - m2;
        dif.e = e1;
    }

    return dif;
}

int main() {
    FLOT dif = DIFFL(2, 4, 5, 4);
    printf("la valeur de dif = %f * 10^%d\n", dif.m, dif.e);

    return 0;
}
