#include <stdio.h>

typedef struct {
    float m;
    int e;
} FLOT;

FLOT SOMMEFL(float m1, int e1, float m2, int e2) {
    FLOT s;

    if (e1 == e2) {
        s.m = m1 + m2;
        s.e = e1;
    } else if (e1 > e2) {
        int t = e1 - e2;
        m1 *= pow(10, t);
        s.m = m1 + m2;
        s.e = e2;
    } else {
        int t = e2 - e1;
        m2 *= pow(10, t);
        s.m = m1 + m2;
        s.e = e1;
    }

    return s;
}

int main() {
    FLOT s = SOMMEFL(2, 5, 5, 1);
    printf("la valeur de s = %f * 10^%d\n", s.m, s.e);

    return 0;
}
