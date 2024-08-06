#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
  char nome[30], sexo;
  int idade;
  struct Pessoa *prox;
} pessoa;

pessoa *criarPessoa();
pessoa *inserirPessoaFinal(pessoa *lista, char nome[], char sexo, int idade);
void imprimirPessoas(pessoa *lista);
pessoa *deletaPessoa(pessoa *lista);
void buscarPessoa(pessoa *lista, char nomePessoa[]);