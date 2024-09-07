//  Crie uma função que receba um número inteiro de 1 a 10 e retorne 1 se o número
// for primo. Caso contrário, não retorne nada. Você não pode usar laços de repetição,
// por essa razão, limite a verificação a um conjunto pequeno de números para
// verificar se são primos. Um número primo é divisível apenas por 1 e por ele mesmo.

#include <stdio.h>

int ehprimo(int valor)
{

    if (valor > 2 && valor % 2 == 0)
    {
        return 0;
    }

    if (valor > 3 && valor % 3 == 0)
    {
        return 0;
    }

    if (valor > 5 && valor % 5 == 0)
    {
        return 0;
    }

    if (valor > 7 && valor % 7 == 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int numero;
    int resultado;

    printf("Insira um numero inteiro de 1 a 10 ");
    scanf("%d", &numero);

    resultado = ehprimo(numero);

    if (resultado == 1)
    {
        printf("1\n");
    }
}