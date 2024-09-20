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
    int continuar = 0; // 0 para sim, 1 para nao

    while (continuar == 0)
    {
        printf("1. Converter Celsius para Fahrenheit.\n2. Converter Fahrenheit para Celsius.\n3. Sair.\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            // converter de celsius para fahrenheit
            printf("Insira a temperatura ");
            scanf("%f", &temperatura);
            tFinal = (temperatura * 1.8) + 32;
            printf("%.1f F\n", tFinal);
        }
        else if (opcao == 2)
        {
            // converter de fahrenheit para celsius
            printf("Insira a temperatura ");
            scanf("%f", &temperatura);
            tFinal = (temperatura - 32) / 1.8;
            printf("%.1f C\n", tFinal);
        }
        else if (opcao == 3)
        {
            continuar = 1;
        }
    }
}