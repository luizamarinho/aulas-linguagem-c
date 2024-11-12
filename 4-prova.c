// Um professor precisa calcular a média final dos alunos e verificar quem foi aprovado ou reprovado.Cada aluno fez três provas e
// a média é calculada pela soma das três notas dividida por três.A média mínima para aprovação é 6
// Crie uma função que, dado um vetor de notas de cada aluno, calcule a média e exiba uma mensagem informando se o aluno foi aprovado ou reprovado.

#include <stdio.h>

#define QUANT_PROVAS 3

float calcularMedia(float valores[QUANT_PROVAS])
{
    float soma = 0;

    for (int i = 0; i < QUANT_PROVAS; i++)
    {
        soma = soma + valores[i];
    }

    return soma / QUANT_PROVAS;
}

int main()
{

    float notas[QUANT_PROVAS];

    for (int i = 0; i < QUANT_PROVAS; i++)
    {
        printf("Insira a nota da prova %d\n", (i + 1));
        scanf("%f", &notas[i]);
    }

    float resultado = calcularMedia(notas);

    if (resultado >= 6)
    {
        printf("O aluno foi aprovado\n");
    }
    else
    {
        printf("O aluno foi reprovado\n");
    }
}