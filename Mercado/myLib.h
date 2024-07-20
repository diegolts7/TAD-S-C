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

void AdicionarProduto(int id, char nome[], char categoria[], int qtd);
produto *CriarProduto();
void MostrarProdutos();
void RemoverProduto(int id);
produto *BuscarProdutoID(int id);