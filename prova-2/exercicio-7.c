// Crie um programa que peça ao usuário para inserir as notas de 5 alunos. Para
// cada aluno, o programa deve calcular a média. Se a média for maior ou igual a 7.0,
// o aluno é aprovado; caso contrário, ele é reprovado. Ao final, o programa deve exibir
// a média de cada aluno e se ele foi aprovado ou reprovado. (0.3 ponto)
// Entrada: 5 notas (uma por aluno).
// Saída: média de cada aluno e status de aprovação.

#include <stdio.h>

int main()
{
    int nota;
    int indice = 1;

    while (indice <= 5)
    {
        printf("Insira a nota ");
        scanf("%d", &nota);
        int media = nota; // por ser uma nota só, a média do aluno é igual a unica nota que foi recebida.
        printf("Média do aluno eh %d\n", media);
        if (media >= 7)
        {
            printf("Aluno aprovado\n");
        }
        else
        {
            printf("Aluno reprovado\n");
        }

        indice = indice + 1;
    }
}