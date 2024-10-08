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

void AdicionarProduto(int id, int quantidade, char nome[], char categoria[], int isBeforeStart);
void pegarDadosProduto();
produto *CriarProduto();
void MostrarProdutos();
void RemoverProduto(int id);
produto *BuscarProdutoID(int id);
void limparBuffer();
void BuscarProdutoNome(char nome[]);
void Buscar();
void AtualizarProduto();
void MostrarUnicoProduto(produto *item);
void escreverCSV(char *arquivo);
void lerCSV(char *arquivo);