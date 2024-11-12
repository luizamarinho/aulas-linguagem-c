// Uma livraria deseja controlar a quantidade de livros em estoque e realizar promoções baseadas no número de vendas.
// Caso um livro tenha vendido mais de 100 unidades em um mês, ele será colocado em promoção no mês seguinte.
// Crie uma função que, dado um vetor de vendas mensais de cada livro, identifique quais livros devem entrar em promoção.

#include <stdio.h>

int main()
{
    int vendas[100];
    int i;

    for (i = 0; i < 100; i++)
    {
        vendas[i] = i;
    }
}