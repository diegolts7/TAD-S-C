#include <stdio.h>
#include "myLib.h"

int main()
{

    AdicionarProduto(2031, "Uva", "Alimento", 3);
    AdicionarProduto(2042, "Maca", "Alimento", 9);
    AdicionarProduto(2045, "Couve", "Alimento", 5);
    RemoverProduto(2042);
    return 0;
}