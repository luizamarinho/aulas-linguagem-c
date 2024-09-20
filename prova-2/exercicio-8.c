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

int main()
{
    int numero = time(0);
    srand(numero);

    // chamando uma vez pra aquecer o rand e maximizar a entropia
    rand();

    float rand_max = RAND_MAX; // o RAND_MAX é int. A operação será feita de maneira inteira, então vai desprezar o número com virgula. Preciso que ele seja float para gerar o número dentro do intervalo 0-1

    float aleatorio_f = (rand() / rand_max) * 100; // o resultado da divisão está entre zero e 1. Posteriormente ele multiplica por 100 pra aumentar o intervalo para 0 - 100
    int aleatorio = aleatorio_f;                   // converte de float para int. despreza a casa decimal sem arredondar.

    printf("%d\n", aleatorio);
}