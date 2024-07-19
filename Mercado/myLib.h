#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    int id;
    char nome[50];
    char categoria[50];
    int quantidade;
    struct Produto *anter;
    struct Produto *prox;

} produto;

produto *AdicionarProduto(produto *lista, int id, char nome[], char categoria[], int qtd);
produto *CriarProduto();
void MostrarProdutos(produto *lista);