#include <stdio.h>

// vetor de strings para nome e outro para disciplina
// array de strings = string[] = char[][]
// matriz de floats para notas

// char[] = string

#define TAM_MAX_NOME 50
#define QTD_MAX_DISCIPLINAS 3
#define QTD_MAX_ALUNOS 4

int main()
{
    // char disciplinas[QTD_MAX_DISCIPLINAS][TAM_MAX_NOME];
    // disciplinas[0];

    float notas[QTD_MAX_ALUNOS][QTD_MAX_DISCIPLINAS];
    float nota_minima;
    char alunos[QTD_MAX_ALUNOS][TAM_MAX_NOME];

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

    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
    {
        for (int j = 0; j < QTD_MAX_DISCIPLINAS; j++)
        {
            printf("aluno %s nota %0.1f\n", alunos[i], notas[i][j]);
        }
    }

    // adicionar disciplinas da mesma forma q adicionei os nomes
    // criar função pra calcular a media e retornar status (aprovado/reprovado)

    // printf("Insira a nota mínima para aprovação\n");
    // scanf("%f", &nota_minima);
}