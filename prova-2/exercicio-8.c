// Escreva um programa que sorteie um número entre 1 e 100 e permita ao usuário
// tentar adivinhar o número. O programa deve dar dicas se o número sorteado é
// maior ou menor que o palpite do usuário. O usuário tem no máximo 7 tentativas
// para acertar. No final, informe se o usuário acertou ou não. (0.3 ponto)
// Entrada: palpites do usuário.
// Saída: dicas (maior/menor) e resultado final (acertou ou esgotou tentativas).

// rand * (final - inicial) + inicial
// rand * (final - 0) + 0
// rand * final

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func_adivinha(int valor)
{
    int tentativa = 1;
    int palpite;
    while (tentativa <= 7)
    {
        printf("Insira o palpite (%d/7)", tentativa);
        scanf("%d", &palpite);

        if (palpite == valor)
        {
            return 1; // se acertar o programa retorna o valor e para de executar
        }
        else if (palpite > valor)
        {
            printf("Palpite muito alto\n");
        }
        else if (palpite < valor)
        {
            printf("Palpite muito baixo\n");
        }
        tentativa++;
    }
    return 0; // se acabarem as tentativas o programa retorna 0 e para de executar
}

int main()
{
    int numero = time(0);
    srand(numero); // impede do código repetir o mesmo número toda vez que for gerado, usando o horário como seed

    int aleatorio = (rand() % 100) + 1; // gera um número aleatorio entre 1 e 100

    printf("%d\n", aleatorio); // código comentado para mostrar o número aleatório em caso de testes

    if (func_adivinha(aleatorio) == 1)
    {
        printf("Parabéns, você acertou!\n");
    }
    else
    {
        printf("Você não tem mais tentativas\n");
    }
}