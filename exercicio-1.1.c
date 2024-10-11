// Faça um programa que preencha um vetor com nove números
// inteiros, calcule e mostre os números primos e suas
// respectivas posições.

#include <stdio.h>

// sintaxe:
// #define <FIND> <REPLACE>
#define TAMANHO 9

int ehprimo(int numero)
{
    if (numero == 1)
    {
        return 0;
    }
    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return 0; // retorna 0 se o valor for divisivel por algum número que não seja 1 nem ele mesmo,ou seja, não pode ser primo
        }
    }

    return 1;
}

int main()
{
    int vetor[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Insira um numero inteiro ");
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < TAMANHO; i++)
    {
        if (ehprimo(vetor[i]) == 1)
        {
            printf("O numero %d na posicao %d eh primo\n", vetor[i], i);
        }
    }
}