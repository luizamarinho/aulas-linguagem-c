// Desenvolva uma função que receba um número inteiro e determine se ele é par
// ou ímpar. Exiba uma mensagem correspondente para cada caso

#include <stdio.h>

int ehpar(int valor)
{
    if (valor % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int numero;

    printf("Insira um numero inteiro ");
    scanf("%d", &numero);

    if (ehpar(numero) == 1)
    {
        printf("O numero inserido eh par\n");
    }
    else
    {
        printf("O numero inserido eh impar\n");
    }
}