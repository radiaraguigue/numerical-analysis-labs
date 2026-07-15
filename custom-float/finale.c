#include <stdio.h>


typedef struct {
    float m;
    int e;
} FLOT;

FLOT FLOTTANT(float m, int e) {
    FLOT x;
    x.m = m;
    x.e = e;
      if (x.m < 1) {
        while (x.m< 0.09) {
            x.m = x.m * 10;
            x.e = x.e - 1;
        } return x;

    } else {
        while (x.m >= 1) {
            x.m = x.m / 10;
            x.e = x.e + 1;
                          }return x;
          }
}
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
  s=FLOTTANT(s.m, s.e);
    return s;}
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
dif=FLOTTANT(dif.m, dif.e);
    return dif;
}
FLOT MULFL(float m1, int e1, float m2, int e2) {
    FLOT M;
if (m1==0 || m2==0 ){printf("\n"); }
        else {
        M.m = m1 * m2;
        M.e = e1 + e2;

M=FLOTTANT(M.m, M.e);
    return M;}
}
FLOT DIVFL(float m1, int e1, float m2, int e2) {
    FLOT div;
    if (m2 == 0) {
        printf("Division par zéro, Opération invalide.\n");

        div.m = 0;
        div.e = 0;
        return div;
    }
else {
        div.m = m1 / m2;
        div.e = e1 - e2;

div=FLOTTANT(div.m, div.e);
    return div;}
}
int main() {
    FLOT n1, n2, resultat;
    char operateur;

    printf("Entrez m1 et e1 pour le nombre n1: ");
    scanf("%f %d", &n1.m, &n1.e);
    printf("Entrez m2 et e2 pour le nombre n2: ");
    scanf("%f %d", &n2.m, &n2.e);

    printf("Entrez l'opérateur (+, -, *, /) : ");
    scanf(" %c", &operateur);


    switch (operateur) {
        case '+':
            resultat = SOMMEFL(n1.m, n1.e, n2.m, n2.e);
            break;
        case '-':
            resultat = DIFFL(n1.m, n1.e, n2.m, n2.e);
            break;
        case '*':
            resultat = MULFL(n1.m, n1.e, n2.m, n2.e);
            break;
        case '/':
            resultat = DIVFL(n1.m, n1.e, n2.m, n2.e);
            break;
        default:
            printf("Opérateur invalide\n");
            return 1;
    }


    printf("Le résultat est : %f * 10^%d\n", resultat.m, resultat.e);

    return 0;
}
