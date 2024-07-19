#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib.h"

produto *UltimoProduto = NULL;

produto *CriarProduto()
{
    produto *NovoProduto = (produto *)malloc(sizeof(produto));
    return NovoProduto;
}

produto *AdicionarProduto(produto *lista, int id, char nome[], char categoria[], int qtd)
{
    produto *ProdutoNovo = CriarProduto();

    ProdutoNovo->id = id;
    ProdutoNovo->quantidade = qtd;
    strcpy(ProdutoNovo->nome, nome);
    strcpy(ProdutoNovo->categoria, categoria);

    if (lista == NULL)
    {
        lista = ProdutoNovo;
        ProdutoNovo->anter = NULL;
        ProdutoNovo->prox = NULL;
        UltimoProduto = ProdutoNovo;
    }
    else
    {
        produto *aux = UltimoProduto;
        aux->prox = ProdutoNovo;
        ProdutoNovo->anter = aux;
        ProdutoNovo->prox = NULL;
        UltimoProduto = ProdutoNovo;
    }

    return lista;
}

void MostrarProdutos(produto *lista)
{
    produto *aux = lista;

    if (aux != NULL)
    {
        MostrarProdutos(aux->prox);
        printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n", aux->nome, aux->categoria, aux->quantidade, aux->id);
        printf("\n\n");
    }
}