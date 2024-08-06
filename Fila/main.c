#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    pessoa *listaPessoas = NULL;
    listaPessoas = inserirPessoaFinal(listaPessoas, "diego", 'm', 21);
    listaPessoas = inserirPessoaFinal(listaPessoas, "mary", 'f', 23);
    listaPessoas = inserirPessoaFinal(listaPessoas, "chico", 'm', 25);
    listaPessoas = deletaPessoa(listaPessoas);
    imprimirPessoas(listaPessoas);

    return 0;
}