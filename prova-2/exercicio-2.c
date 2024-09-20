// Um número perfeito é aquele que é igual à soma de seus divisores próprios
// (excluindo ele mesmo). Escreva um programa que solicite ao usuário um número
// inteiro positivo e verifique se esse número é perfeito. O programa deve utilizar um
// laço para somar os divisores e, no final, informar se o número é perfeito ou não

#include <stdio.h>

int main()
{
    int numero;
    int indice = 1;
    int soma = 0;

    printf("Insira um numero ");
    scanf("%d", &numero);

    while (indice < numero) // laço de repetição para percorrer testando todos os divisores menores que numero (exceto ele mesmo)
    {

        if (numero % indice == 0)
        {
            soma = soma + indice; // soma os divisores do numero inserido
        }
        indice = indice + 1;
    }

    if (soma == numero) // se a soma dos divisores for igual ao numero é um numero perfeito
    {
        printf("%d eh um numero perfeito\n", numero);
    }
    else // se a soma dos divisores for diferente do numero não é um numero perfeito
    {
        printf("%d nao eh um numero perfeito\n", numero);
    }

    return 0;
}