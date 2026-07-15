#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    float m;
    int e;
} FLOT;

FLOT FLOTTANT(float m, int e) {
    FLOT x;
    x.m = m;
    x.e = e;

    /* Guard clause to prevent infinite loops on zero values */
    if (x.m == 0.0f) {
        x.e = 0;
        return x;
    }

    /* Use absolute values for loop condition checks */
    if (fabsf(x.m) < 1.0f) {
        while (fabsf(x.m) < 0.09f) {
            x.m = x.m * 10.0f;
            x.e = x.e - 1;
        }
        return x;
    } else {
        while (fabsf(x.m) >= 1.0f) {
            x.m = x.m / 10.0f;
            x.e = x.e + 1;
        }
        return x;
    }
}
