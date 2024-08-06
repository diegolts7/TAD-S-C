#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int dado;
    struct Node *anter;
    struct Node *prox;
} node;

node *Empilhar(node *lista, int num);
node *Desempilhar(node *lista);
void Imprimir();

