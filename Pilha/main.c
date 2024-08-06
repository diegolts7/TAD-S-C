#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    node *Lista = NULL;
    char str[] = "diego";
    Lista = Empilhar(Lista, 2);
    Lista = Empilhar(Lista, 6);
    Imprimir();

    return 0;
}