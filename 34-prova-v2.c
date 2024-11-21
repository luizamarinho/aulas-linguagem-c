#include <stdio.h>

#define QUANT_ATLETAS 5

void calcularAtletas(float pont_atletas[QUANT_ATLETAS])
{
    for (int i = 0; i < QUANT_ATLETAS; i++)
    {
        if (pont_atletas[i] > 75)
        {
            printf("O atleta %d segue na competicao com nota %.2f\n", (i + 1), pont_atletas[i]);
        }
    }
}

int main()
{

    float pont_atletas[QUANT_ATLETAS];

    for (int i = 0; i < QUANT_ATLETAS; i++)
    {
        printf("Insira a pontuacao do atleta %d\n", (i + 1));
        scanf("%f", &pont_atletas[i]);
    }

    calcularAtletas(pont_atletas);
}