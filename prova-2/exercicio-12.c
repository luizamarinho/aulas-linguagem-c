// Escreva um programa que solicite ao usuário 6 números inteiros. Para cada
// número, verifique se ele é par ou ímpar. Se o número for par, verifique se é maior
// que 10 ou não. Se for ímpar, verifique se é menor que 50 ou não. (0.4 ponto)
// Entrada: 6 números inteiros.
// Saída: paridade do número e a classificação adicional.

#include <stdio.h>

int main()
{
    int numero;
    int indice = 1;
    int quantNumeros = 6;

    while (indice <= quantNumeros)
    {
        printf("Insira um numero inteiro ");
        scanf("%d", &numero);

        if (numero % 2 == 0)
        {
            printf("Eh par\n");
            if (numero > 10)
            {
                printf("Maior que 10\n");
            }
            else
            {
                printf("Menor que 10\n");
            }
        }
        else
        {
            printf("Eh impar\n");
            if (numero < 50)
            {
                printf("Menor que 50\n");
            }
            else
            {
                printf("Maior que 50");
            }
        }
        indice = indice + 1;
    }
}