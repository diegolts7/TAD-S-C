#include <stdio.h>
#include "myLib.h"

int main(void)
{
    dimensionaMatriz(3, 3, 3);
    int vet[9];
    zeraMatriz(vet, 9);
    imprimeMatriz(vet, 3, 3);
    adicionaElementos(vet, 7, 1, 1);

    imprimeMatriz(vet, 3, 3);
    printf("%d\n", buscarElemento(vet, 1, 1));
    int vet2[9], vet3[9];
    zeraMatriz(vet2, 9);
    imprimeMatriz(vet2, 3, 3);
    somaMatriz(vet, vet2, vet3, 9);
    printf("\n");
    imprimeMatriz(vet3, 3, 3);
    return 0;
}
