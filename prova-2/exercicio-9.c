// Escreva um programa que peça ao usuário para inserir as notas de 5 alunos.
// Para cada aluno, o programa deve calcular a média de duas provas. Se a média for
// maior ou igual a 7.0, o aluno é aprovado. Se a média estiver entre 5.0 e 6.9, o aluno
// vai para a recuperação, e se for menor que 5.0, o aluno é reprovado. (0.4 ponto)

#include <stdio.h>

int main()
{
    float nota;
    int indice = 1;
    int numeroAlunos = 5;
    int indiceNotas = 1;
    int quantNotas = 2;
    float somaN = 0;
    float media;

    while (indiceNotas <= quantNotas)
    {
        printf("Insira a nota \n");
        scanf("%f", &nota);
        somaN = somaN + nota;
        indiceNotas++;
    }

    media = somaN / quantNotas;
    printf("%.2f\n", media);
    if (media >= 7.0)
    {
        printf("Aluno aprovado\n");
    }
    else if (media >= 5.0 && media <= 6.9)
    {
        printf("Recuperação\n");
    }
    else if (media < 5.0)
    {
        printf("Aluno reprovado\n");
    }
}