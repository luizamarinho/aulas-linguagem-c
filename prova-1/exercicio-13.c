// Crie um programa que simule uma calculadora simples. O programa deve
// permitir ao usuário escolher entre quatro operações aritméticas: soma, subtração,
// multiplicação e divisão. O usuário deve informar a operação desejada e dois
// números. O programa deve realizar a operação selecionada e exibir o resultado.
// Caso a operação não seja reconhecida, o programa deve informar um erro.

#include <stdio.h>

int main()
{
    char operador;
    float numero1;
    float numero2;
    float resultado;

    printf("Insira o operador ");
    scanf("%c", &operador);

    printf("Insira os dois numeros ");
    scanf("%f %f", &numero1, &numero2);

    if (operador == '+')
    {
        resultado = numero1 + numero2;
    }
    else if (operador == '-')
    {
        resultado = numero1 - numero2;
    }
    else if (operador == '*')
    {
        resultado = numero1 * numero2;
    }
    else if (operador == '/')
    {
        resultado = numero1 / numero2;
    }
    else
    {
        printf("O operador eh invalido\n");
    }

    printf("%0.1f\n", resultado);
}