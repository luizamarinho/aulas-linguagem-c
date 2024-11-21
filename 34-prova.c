// Em um torneio esportivo, a pontuação de cada atleta é registrada. O treinador deseja identificar quais atletas conseguiram pontuação acima de 75
// para definir quem continua na competição.
// Crie uma função que, dado um vetor com as pontuações dos atletas, indique quais atletas continuam na competição.

#include <stdio.h>

#define MAX_ATLETAS 5 // temporariamente 5 para teste // 5 atletas, uma nota cada // um vetor de atles com a nota de cada atleta

int verificadorAtletas(int quantidade)
{
    if (quantidade > 75)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int atletas[MAX_ATLETAS];

    for (int i = 0; i < MAX_ATLETAS; i++)
    {
        printf("Insira a pontuacao do atleta %d\n", (i + 1));
        scanf("%d", &atletas[i]);
    }

    for (int i = 0; i < MAX_ATLETAS; i++)
    {
        if (verificadorAtletas(atletas[i]) == 1)
        {
            printf("O atleta %d continua na competicao\n", (i + 1));
        };
    }
}