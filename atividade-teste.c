#include <stdio.h>

#define TAM_MAX_NOME 50
#define TAM_MAX_DISCIPLINA 50
#define QTD_MAX_DISCIPLINAS 3
#define QTD_MAX_ALUNOS 4

float calculoMedia(float notas[QTD_MAX_DISCIPLINAS])
{
    float media = 0;
    float soma = 0;

    for (int i = 0; i < QTD_MAX_DISCIPLINAS; i++)
    {
        soma = soma + notas[i];
    }

    media = soma / QTD_MAX_DISCIPLINAS;

    return media;
}

int main()
{
    float notas[QTD_MAX_ALUNOS][QTD_MAX_DISCIPLINAS];
    float nota_minima;
    char alunos[QTD_MAX_ALUNOS][TAM_MAX_NOME];
    char disciplinas[QTD_MAX_DISCIPLINAS][TAM_MAX_DISCIPLINA];

    for (int i = 0; i < QTD_MAX_DISCIPLINAS; i++)
    {
        printf("Insira a disciplina\n");
        scanf("%s", disciplinas[i]);
    }

    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
    {
        printf("Insira o nome do(a) aluno(a)\n");
        scanf("%s", alunos[i]);
        for (int j = 0; j < QTD_MAX_DISCIPLINAS; j++)
        {
            printf("Insira a nota do(a) aluno(a)\n");
            scanf("%f", &notas[i][j]);
        }
    }

    printf("Insira a nota mínima para aprovação\n");
    scanf("%f", &nota_minima);
    printf("\n");

    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
    {
        float media_notas = calculoMedia(notas[i]);

        printf("Aluno %s\n", alunos[i]);

        for (int j = 0; j < QTD_MAX_DISCIPLINAS; j++)
        {

            printf("Nota %.1f na disciplina %s\n", notas[i][j], disciplinas[j]);
        }

        printf("A media do aluno eh %.1f\n", media_notas);

        if (media_notas < nota_minima)
        {
            printf("o aluno %s foi reprovado\n", alunos[i]);
        }
        else
        {
            printf("o aluno %s foi aprovado\n", alunos[i]);
        }
        printf("\n");
    }
}