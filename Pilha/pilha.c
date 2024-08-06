#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

node *ultimo = NULL;

node *Empilhar(node *lista, int num)
{

    node *novoNo = (node *)malloc(sizeof(node));
    novoNo->dado = num;

    if (lista == NULL)
    {
        lista = novoNo;
        novoNo->anter = NULL;
        novoNo->prox = NULL;
        ultimo = novoNo;
    }
    else
    {
        node *aux = ultimo;
        aux->prox = novoNo;
        novoNo->anter = aux;
        novoNo->prox = NULL;
        ultimo = novoNo;
    }

    return lista;
}

void Imprimir()
{
    system("clear");
    node *aux = ultimo;

    while (aux != NULL)
    {
        printf("Nó: %d\n", aux->dado);
        aux = aux->anter;
    }
}

node *Desempilhar(node *lista)
{
    node *aux = lista;
    if (aux != NULL && aux->prox == NULL)
    {
        free(aux);
        lista = NULL;
    }
    else
    {
        node *refer = ultimo;
        ultimo = refer->anter;
        ultimo->prox = NULL;
        free(refer);
    }

    return lista;
}