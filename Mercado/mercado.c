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

    while (quantidade <= 0)
    {
        printf("Digite uma quantidade válida: ");
        scanf("%d", &quantidade);
    }

    printf("Digite o Id do produto :");
    scanf("%d", &id);

    while (id < 0)
    {
        printf("Digite um id válido: ");
        scanf("%d", &id);
    }

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
        MostrarUnicoProduto(aux);

        aux = aux->prox;
    }
}

void MostrarUnicoProduto(produto *item)
{
    printf("-------------------------------------------------------------------------------------------\n\n");
    printf("Nome: %s\nCategoria: %s\nQuantidade: %d\nId: %d\n\n", item->nome, item->categoria, item->quantidade, item->id);
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

            MostrarUnicoProduto(refer);

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
            MostrarUnicoProduto(aux);
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
            MostrarUnicoProduto(resultadoPesquisaId);
        }
        else
        {
            printf("\nSem produtos encontrados!!!\n");
        }
    }
}

void AtualizarProduto()
{
    int id = 0;

    MostrarProdutos();
    printf("Informe o id do produto que deseja atualizar: ");
    scanf("%d", &id);

    while (id < 0)
    {
        printf("Informe um id válido: ");
        scanf("%d", &id);
    }

    system("clear");

    produto *aux = BuscarProdutoID(id);

    if (aux != NULL)
    {

        int quantidade = 0;
        char categoria[50], nome[50];

        MostrarUnicoProduto(aux);

        limparBuffer();

        printf("Digite o novo nome do produto (digite n se não dejesa alterar essa opção) : ");
        scanf("%[^\n]", nome);

        if (strcmp(nome, "n") != 0)
        {
            strcpy(aux->nome, nome);
        }

        printf("Digite a categoria do produto (digite n se não dejesa alterar essa opção) :");
        scanf("%s", categoria);

        if (strcmp(categoria, "n") != 0)
        {
            printf("\n\n%d\n\n", strcmp(categoria, "n") != 0);
            strcpy(aux->categoria, categoria);
        }

        printf("Digite o quantidade do produto (digite 0 se não dejesa alterar essa opção) :");
        scanf("%d", &quantidade);

        if (quantidade > 0 || quantidade > 0)
        {
            aux->quantidade = quantidade;
        }

        system("clear");
        printf("Produto alterado com sucesso!!\n\n");
        MostrarUnicoProduto(aux);
        system("read -p 'Pressione Enter para continuar...' var");
    }
    else
    {
        system("read -p 'Produto não encontrador...' var");
    }
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}