// Escreva um programa que apresente um menu com as seguintes opções:
// 1. Calcular o fatorial de um número.
// 2. Sair.
// O programa deve solicitar ao usuário um número inteiro e calcular o seu fatorial. O
// menu deve continuar sendo exibido até que o usuário escolha a opção de sair. (0.2
// ponto)
// Entrada: escolha da opção e um número inteiro.
// Saída: fatorial do número

#include <stdio.h>

int main()
{
    int numero;
    int fatorial = 1;
    int indice;
    int opcao;
    int continuar = 0; // 0 para sim, 1 para não

    while (continuar == 0) // laço de repetição que testa se o usuário deseja ou não continuar (roda até que ele selecione sair)
    {
        printf("Escolha uma opcao\n1. Calcular o fatorial de um numero.\n2. Sair.\n");
        scanf("%d", &opcao);

        if (opcao == 1) // se selecionar 1, executa o comando para gerar o fatorial de um numero
        {
            printf("Informe um numero inteiro e positivo\n");
            scanf("%d", &numero);
            indice = numero;

            while (numero >= 1) // percorre o comando subtraindo 1 depois de cada execução até que ele seja menor que 1
            {
                fatorial = fatorial * numero;
                numero = numero - 1;
            }
            printf("O fatorial de %d eh %d\n", indice, fatorial);
        }
        else if (opcao == 2) // se selecionar 2, para o programa
        {
            continuar = 1;
        }
    }
}