// Escreva um programa que peça ao usuário para inserir 10 números inteiros.O
// programa deve contar quantos números são pares e quantos são ímpares,
// e exibir esses valores no final.(0.3 ponto)
// Entrada : 10 números inteiros. Saída : quantidade de números pares e ímpares.

#include <stdio.h>

int main()
{
    int numero;
    int pares = 0;
    int impares = 0;
    int indice = 1;

    while (indice <= 10)
    {
        printf("Insira um numero inteiro ");
        scanf("%d", &numero);

        if (numero % 2 == 0)
        {
            pares = pares + 1;
        }
        else
        {
            impares = impares + 1;
        }
        indice = indice + 1;
    }
    printf("%.0d pares e %.0d impares\n", pares, impares);
}