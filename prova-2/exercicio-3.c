// Escreva um programa em C que solicite ao usuário as notas de 5 alunos e suas
// respectivas pesos, calcule a média ponderada de cada aluno e ao final exiba a
// média final da turma.

#include <stdio.h>

int main()
{

    float nota;
    float peso;
    float media;
    float somaN = 0;
    float somaP = 0;
    float mediaTurma = 0;
    float somaTurma = 0;
    int indiceNotas = 1;
    int indiceAlunos = 1;
    int numeroAlunos = 2;

    while (indiceAlunos <= numeroAlunos)
    {

        while (indiceNotas <= 2)
        {
            printf("Insira a nota e o peso ");
            scanf("%f %f", &nota, &peso);
            somaN = somaN + (nota * peso); // multiplica todas as notas pelos pesos e depois soma
            somaP = somaP + peso;          // soma todos os pesos
            indiceNotas++;
        }
        media = somaN / somaP; // divide a soma de todas as notas (* pesos) pela soma de todos os pesos
        printf("A média ponderada eh %.2f\n", media);
        indiceNotas = 1;
        somaN = 0;
        somaP = 0;
        somaTurma = somaTurma + media;
        indiceAlunos++;
    }
    mediaTurma = somaTurma / numeroAlunos; // soma todas as medias da turma e divide pela quantidade de alunos
    printf("a media da turma eh %.2f\n", mediaTurma);
}