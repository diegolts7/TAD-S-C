#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mercado.h"

produto *Lista = NULL;
produto *UltimoProduto = NULL;

produto *CriarProduto()
{
    produto *NovoProduto = (produto *)malloc(sizeof(produto));
    return NovoProduto;
}

void AdicionarProduto()
{
    produto *ProdutoNovo = CriarProduto();

    int id = 0, quantidade = 0;
    char categoria[50], nome[50];

    limparBuffer();

    printf("Digite o nome do produto : ");
    scanf("%[^\n]", nome);

    printf("Digite a categoria do produto :");
    scanf("%s", categoria);
    printf("Digite o quantidade do produto :");
    scanf("%d", &quantidade);
    printf("Digite o Id do produto :");
    scanf("%d", &id);

    ProdutoNovo->id = id;
    ProdutoNovo->quantidade = quantidade;
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

    system("read -p 'Produto adicionado com sucesso...' var");

    system("clear");
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
            char opcao = 0;

            system("clear");

            printf("-------------------------------------------------------------------------------------------\n\n");
            printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n\n", refer->nome, refer->categoria, refer->quantidade, refer->id);

            limparBuffer();

            printf("Confirme para excluir esse produto (y/n) : ");
            scanf("%c", &opcao);

            if (opcao == 'y' || opcao == 'Y')
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

                system("read -p 'Produto removido com sucesso...' var");

                system("clear");
            }
        }
        else
        {
            printf("Produto não encontrado!!\n\n");
            system("read -p 'Pressione Enter para continuar...' var");
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

void BuscarProdutoNome(char nome[])
{

    produto *aux = Lista;
    int cont = 0;

    while (aux != NULL)
    {

        if (strcmp(aux->nome, nome) == 0)
        {
            printf("\n\n-------------------------------------------------------------------------------------------\n\n");
            printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n\n", aux->nome, aux->categoria, aux->quantidade, aux->id);
            cont++;
        }
        aux = aux->prox;
    }
    if (cont == 0)
    {
        printf("\nSem produtos encontrados\n");
    }
}

void Buscar()
{

    int opcaoPesquisa = 0;

    printf("1. Nome\n2. Id\nPor qual opção deseja pesquisar: ");
    scanf("%d", &opcaoPesquisa);

    while (opcaoPesquisa < 1 || opcaoPesquisa > 2)
    {
        printf("Digite uma opção válida: ");
        scanf("%d", &opcaoPesquisa);
    }

    system("clear");

    if (opcaoPesquisa == 1)
    {

        char nome[50];

        limparBuffer();

        printf("Digite o nome do produto que deseja encontrar : ");
        scanf("%[^\n]", nome);

        BuscarProdutoNome(nome);
    }
    else
    {
        int id;

        printf("Digite o Id do produto que deseja encontrar : ");
        scanf("%d", &id);

        produto *resultadoPesquisaId = BuscarProdutoID(id);

        if (resultadoPesquisaId != NULL)
        {
            printf("\n\n-------------------------------------------------------------------------------------------\n\n");
            printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n\n", resultadoPesquisaId->nome, resultadoPesquisaId->categoria, resultadoPesquisaId->quantidade, resultadoPesquisaId->id);
        }
        else
        {
            printf("\nSem produtos encontrados!!!\n");
        }
    }
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}