#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

ponto *CriarPonto(float x, float y)
{
    ponto *novoPonto = (ponto *)malloc(sizeof(ponto));

    if (novoPonto == NULL)
    {
        printf("Memoria insuficente!\n");
        exit(1);
    }

    novoPonto->x = x;
    novoPonto->y = y;
    return novoPonto;
}

void LiberaPonto(ponto *p)
{
    free(p);
}

void Acessa(ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

void Atribui(ponto *p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float Distancia(ponto *p1, ponto *p2)
{
    return sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
}