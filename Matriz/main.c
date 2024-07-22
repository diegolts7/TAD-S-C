#include <stdio.h>
#include "myLib.h"

const int tamanho = 3;
const int tamVetor = tamanho * tamanho;
int main(void)
{
    dimensionaMatriz(3, 3, tamanho);
    int vet[tamVetor];
    zeraMatriz(vet, tamVetor);
    imprimeMatriz(vet, 3, 3);
    adicionaElementos(vet, 7, 1, 1);

    imprimeMatriz(vet, 3, 3);
    printf("%d\n", buscarElemento(vet, 1, 1));
    int vet2[tamVetor], vet3[tamVetor];
    zeraMatriz(vet2, tamVetor);
    imprimeMatriz(vet2, 3, 3);
    somaMatriz(vet, vet2, vet3, tamVetor);
    printf("\n");
    imprimeMatriz(vet3, 3, 3);
    return 0;
}
