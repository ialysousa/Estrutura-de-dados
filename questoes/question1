#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    char nome[10];
    Ponto centro;
    float raio;
} Circulo;

Circulo *criaCirculo(char *nome, float x, float y, float raio) {

    Circulo *c;
    c = (Circulo*) malloc(sizeof(Circulo));;

    if (c == NULL) {
        printf("Impossível criar círculo");
        exit(1);
    }

    memcpy(c->nome, nome, 10);
    c->raio = raio;
    c->centro.x =  x;
    c->centro.y = y;

    return c;
}

float tem(Circulo *c1, Circulo *c2) {
    float x = pow((c2->centro.x - c1->centro.x), 2);
    float y = pow((c2->centro.y - c1->centro.y), 2);

    float result =  sqrtf(x + y);

    if (result + c2->raio <= c1->raio){
        return 1;
    }
    return 0;
}

int *merge(int *v1, int n1, int *v2, int n2) {
    int *v3;
    v3 = malloc(sizeof(int) * (n1 + n2));

    for (int i = 0; i < n1; i++) {
        v3[i] = v1[i];
    }
    for (int j = 0; j < n2; j++) {
        v3[n1 + j] = v2[j];
    }
    return v3;
}

int main() {
    Circulo *c1, *c2, *c3;
    c1 = criaCirculo("Circulo01", 3.0, 4.0, 2.0);
    c2 = criaCirculo("Circulo02", 3.0, 3.0, 1.0);
    c3 = criaCirculo("Circulo03", 1.0, 5.0, 1.0);

    printf("%.0f\n", tem(c1, c2));
    printf("%.0f\n", tem(c1, c3));

    free(c1);
    free(c2);
    free(c3);
}
