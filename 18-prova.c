#include <stdio.h>

#define QUANT_NOTAS 5

float calcularMedia(float valores[QUANT_NOTAS])
{
    float maior = 0;
    float menor = 1000;
    // int maior_indice = 0;

    for (int i = 0; i < QUANT_NOTAS; i++)
    {
        if (valores[i] > maior)
        {
            maior = valores[i];
            // maior_indice = i;
        }
        if (valores[i] < menor)
        {
            menor = valores[i];
        }
    }

    float soma = 0;

    for (int i = 0; i < QUANT_NOTAS; i++)
    {
        if (valores[i] != maior && valores[i] != menor)
        {
            soma = soma + valores[i];
        }
    }

    return soma / (QUANT_NOTAS - 2);
}

int main()
{

    float notas[QUANT_NOTAS];

    for (int i = 0; i < QUANT_NOTAS; i++)
    {
        printf("Insira a nota %d do candidato.\n", (i + 1));
        scanf("%f", &notas[i]);
    }

    float resultado = calcularMedia(notas);

    printf("A media de notas eh %.2f\n", resultado);
}