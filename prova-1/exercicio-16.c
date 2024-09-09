// Desenvolva um programa que classifique o desempenho acadêmico de um
// aluno com base em sua nota final. A nota deve ser informada pelo usuário e
// classificada da seguinte forma:
// ● A (nota >= 9.0)
// ● B (nota >= 7.0 e < 9.0)
// ● C (nota >= 5.0 e < 7.0)
// ● D (nota < 5.0)
// O programa deve exibir a classificação correspondente. Se a nota estiver fora do
// intervalo de 0 a 10, o programa deve informar um erro.

#include <stdio.h>

int main()
{
    float nota;

    printf("Informe a nota final(0 a 10) ");
    scanf("%f", &nota);

    if (nota >= 9)
    {
        printf("A classificacao eh A\n");
    }
    else if (nota >= 7 && nota < 9)
    {
        printf("A classificacao eh B\n");
    }
    else if (nota >= 5 && nota < 7)
    {
        printf("A classificacao eh C\n");
    }
    else if (nota < 5)
    {
        printf("A classificacao eh D\n");
    }
    else
    {
        printf("Erro");
    }
}