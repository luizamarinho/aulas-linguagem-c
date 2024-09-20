// 14. Escreva um programa que apresente um menu com as seguintes opções:
// 1. Adição.
// 2. Subtração.
// 3. Multiplicação.
// 4. Divisão.
// 5. Sair.
// O programa deve solicitar dois números e realizar a operação escolhida. Deve
// continuar exibindo o menu até que o usuário escolha a opção de sair. (0.2 ponto)
// Entrada: escolha da operação e dois números.
// Saída: resultado da operação.

#include <stdio.h>

int main()
{
    int opcao;
    float valor1;
    float valor2;
    float resultado;
    int continuar = 0; // 0 para sim, 1 para nao

    while (continuar == 0) // laço de repetição que repete o comando para o usuário até que ele selecione "sair"
    {
        printf("Escolha a opcao: \n1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Sair\n");
        scanf("%d", &opcao);

        if (opcao <= 4) // condição que testa qual opção foi escolhida, solicita os valores e imprime o resultado
        {
            printf("Insira os valores ");
            scanf("%f %f", &valor1, &valor2);
            if (opcao == 1) // adição
            {
                resultado = valor1 + valor2;
            }
            else if (opcao == 2) // subtração
            {
                resultado = valor1 - valor2;
            }
            else if (opcao == 3) // multiplicação
            {
                resultado = valor1 * valor2;
            }
            else if (opcao == 4) // divisão
            {
                resultado = valor1 / valor2;
            }
            printf("O resultado eh %.1f\n", resultado);
        }

        if (opcao == 5) // opção para sair e parar o programa
        {
            continuar = 1;
        }
    }
}