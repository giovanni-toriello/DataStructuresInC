#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include <math.h>

struct p {
    float x;
    float y;
};

punto creaPunto(float ascissa, float ordinata) {
    struct p *punto = malloc(sizeof(struct p));
    if (punto != NULL) {
        punto->x = ascissa;
        punto->y = ordinata;
    }
    return punto;
}

float ascissa(punto p) {
    return p->x;
}

float ordinata(punto p) {
    return p->y;
}

void stampa(punto p) {
    printf("\nAscissa: %f\n", ascissa(p));
    printf("Ordinata: %f\n", ordinata(p));
}

float distanza(punto p1, punto p2) {
    float dx = p1->x - p2->x;
    float sx = p1->y - p2->y;
    return sqrt((dx * dx) + (sx * sx));
}

punto input_punto() {
    float ascissa;
    float ordinata;
    printf("Inserisce ascissa:");
    scanf("%f", &ascissa);
    printf("Inserisce ordinata:");
    scanf("%f", &ordinata);
    return creaPunto(ascissa, ordinata);
}

int eq(punto p1, punto p2) {
    float x = p1->x + p1->y;
    float y = p2->y + p2->x;
    return x == y;
}