#include <stdio.h>
#include <string.h>
#include "mercado.h"

int main()
{
    int parada = 0;
    do
    {

        int opcao = 0;

        system("clear");

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

        switch (opcao)
        {
        case 1:

            AdicionarProduto();
            break;

        case 2:

            int idProdutoRemovido = 0;
            MostrarProdutos();
            printf("\n\nDigite o id do produto a ser removido : ");
            scanf("%d", &idProdutoRemovido);
            RemoverProduto(idProdutoRemovido);
            break;

        case 3:

            MostrarProdutos();
            printf("\n\n");
            system("read -p 'Pressione Enter para continuar...' var");
            break;

        case 4:
            Buscar();
            break;

        default:
            parada = 1;
        }

    } while (parada != 1);

    return 0;
}