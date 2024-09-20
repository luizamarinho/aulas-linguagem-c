// Escreva um programa que apresente um menu com as seguintes opções:
// 1. Gerar a tabuada de um número.
// 2. Sair.
// O programa deve solicitar ao usuário o número desejado e exibir a tabuada (de 1 a
// 10). O menu deve continuar sendo exibido até que o usuário escolha a opção de
// sair. (0.2 ponto)
// Entrada: escolha da opção e um número.
// Saída: tabuada do número.

#include <stdio.h>

int main()
{
    int opcao;
    int tabuada;
    int indice = 1;
    int continuar = 0; // 0 para sim, 1 para não

    while (continuar == 0) // laço de repetição que testa se o usuário deseja ou não continuar (roda até que ele selecione sair)
    {
        printf("Escolha uma opcao\n1. Gerar a tabuada de um numero.\n2. Sair.\n");
        scanf("%d", &opcao);
        if (opcao == 1) // se selecionar 1, executa o comando para gerar uma tabuada
        {
            printf("Insira a tabuada que deseja "); // solicita a tabuada que o usuário deseja
            scanf("%d", &tabuada);

            while (indice <= 10) // laço de repetição que mostra a tabuada percorrendo de 1 ao 10
            {
                printf("%d x %d = %d\n", indice, tabuada, (indice * tabuada));
                indice++;
            }
        }
        else if (opcao == 2) // se selecionar 2, para o programa
        {
            continuar = 1;
        }
    }
}