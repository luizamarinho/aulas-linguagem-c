// Escreva um programa que apresente um menu com as seguintes opções:
// 1. Converter de Celsius para Fahrenheit.
// 2. Converter de Fahrenheit para Celsius.
// 3. Sair.
// O programa deve continuar exibindo o menu até que o usuário escolha a opção de
// sair. (0.2 ponto)
// Entrada: escolha da opção e o valor da temperatura.
// Saída: temperatura convertida.

#include <stdio.h>

int main()
{
    int opcao;
    float temperatura;
    float tFinal;

    printf("1. Converter Celsius para Fahrenheit.\n2. Converter Fahrenheit para Celsius.\n3. Sair.\n");
    scanf("%d", &opcao);
    printf("Insira a temperatura ");
    scanf("%f", &temperatura);

    if (opcao == 1)
    {
        // converter de celsius para fahrenheit
        tFinal = (temperatura * (9 / 5)) + 32;
    }
    else if (opcao == 2)
    {
        // converter de fahrenheit para celsius

        tFinal = (temperatura - 32) * (5 / 9);
    }
    else if (opcao == 3)
    {
        // parar programa
    }

    printf("%.1f\n", tFinal);
}