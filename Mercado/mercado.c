#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib.h"

produto *Lista = NULL;
produto *UltimoProduto = NULL;

produto *CriarProduto()
{
    produto *NovoProduto = (produto *)malloc(sizeof(produto));
    return NovoProduto;
}

void AdicionarProduto(int id, char nome[], char categoria[], int qtd)
{
    produto *ProdutoNovo = CriarProduto();

    ProdutoNovo->id = id;
    ProdutoNovo->quantidade = qtd;
    strcpy(ProdutoNovo->nome, nome);
    strcpy(ProdutoNovo->categoria, categoria);

    if (Lista == NULL)
    {
        Lista = ProdutoNovo;
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

    system("clear");
    MostrarProdutos();
}

void MostrarProdutos()
{
    produto *aux = Lista;

    printf("𝗟𝗶𝘀𝘁𝗮 𝗱𝗲 𝗣𝗿𝗼𝗱𝘂𝘁𝗼𝘀\n");

    while (aux != NULL)
    {
        printf("-------------------------------------------------------------------------------------------\n\n");
        printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n\n", aux->nome, aux->categoria, aux->quantidade, aux->id);

        aux = aux->prox;
    }
}

void RemoverProduto(int id)
{
    produto *aux = Lista;

    if (aux == NULL)
    {
        printf("A lista está vázia!!");
    }
    else
    {
        produto *refer = BuscarProdutoID(id);

        if (refer != NULL)
        {
            if (aux->prox == NULL)
            {
                free(refer);
                Lista = NULL;
                UltimoProduto = NULL;
            }
            else
            {
                if (refer->anter == NULL)
                {
                    produto *proximo = refer->prox;

                    proximo->anter = NULL;
                    Lista = proximo;
                    free(refer);
                }
                else if (refer->prox == NULL)
                {
                    produto *anterior = refer->anter;

                    anterior->prox = NULL;
                    UltimoProduto = anterior;
                    free(refer);
                }
                else
                {
                    produto *anterior = refer->anter;
                    produto *proximo = refer->prox;
                    anterior->prox = proximo;
                    proximo->anter = anterior;
                    free(refer);
                }
            }

            system("clear");
            MostrarProdutos();
        }
        else
        {
            printf("Produto não encontrado!!");
        }
    }
}

produto *BuscarProdutoID(int id)
{
    produto *aux = Lista;

    while (aux != NULL)
    {

        if (aux->id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
