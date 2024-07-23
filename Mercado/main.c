#include <stdio.h>
#include <string.h>
#include "myLib.h"

int main()
{
    int parada = 0;
    do
    {

        int opcao = 0;

        printf("\n1. Adicionar um produto\n2. Remover um produto\n3. Mostrar produtos\n4. Pesquisar produtos\n5. Sair\n");
        getchar();
        printf("O que você deseja : ");
        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 5)
        {
            printf("Digite uma opção válida : ");
            scanf("%d", &opcao);
        }

        system("clear");

        if (opcao == 1)
        {
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

            AdicionarProduto(id, nome, categoria, quantidade);
        }
        else if (opcao == 2)
        {
            int idProdutoRemovido = 0;
            printf("Digite o id do produto a ser removido : ");
            scanf("%d", &idProdutoRemovido);

            RemoverProduto(idProdutoRemovido);
        }
        else if (opcao == 3)
        {
            MostrarProdutos();
        }
        else if (opcao == 4)
        {
            Buscar();
        }
        else
        {
            parada = 1;
            continue;
        }

    } while (parada != 1);

    /*AdicionarProduto(2031, "Uva", "Alimento", 3);
    AdicionarProduto(2042, "Maca", "Alimento", 9);
    AdicionarProduto(2045, "Couve", "Alimento", 5);
    RemoverProduto(2042);*/
    return 0;
}