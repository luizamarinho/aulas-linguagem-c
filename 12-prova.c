// Uma livraria deseja controlar a quantidade de livros em estoque e realizar promoções baseadas no número de vendas.
// Caso um livro tenha vendido mais de 100 unidades em um mês, ele será colocado em promoção no mês seguinte.
// Crie uma função que, dado um vetor de vendas mensais de cada livro, identifique quais livros devem entrar em promoção.

#include <stdio.h>

#define MAX_PRODUTOS 5 // temporariamente 5

int verificadorPromo(int quantidade)
{
    if (quantidade >= 100)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int vendas[MAX_PRODUTOS];
    int i;

    for (i = 0; i < MAX_PRODUTOS; i++)
    {
        printf("Insira a quantidade de unidades vendidas do livro %d\n", (i + 1));
        scanf("%d", &vendas[i]);
    }

    for (i = 0; i < MAX_PRODUTOS; i++)
    {
        if (verificadorPromo(vendas[i]) == 1)
        {
            printf("Livro %d deve entrar em promo\n", (i + 1));
        };
    }
}