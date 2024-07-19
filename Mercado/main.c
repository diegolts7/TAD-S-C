#include <stdio.h>
#include "myLib.h"

int main()
{
    produto *MinhaLista = NULL;

    MinhaLista = AdicionarProduto(MinhaLista, 2031, "Uva", "Alimento", 3);
    MinhaLista = AdicionarProduto(MinhaLista, 2042, "Maca", "Alimento", 9);
    MostrarProdutos(MinhaLista);
    return 0;
}