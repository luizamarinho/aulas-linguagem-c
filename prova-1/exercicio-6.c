// Elabore uma função que receba a nota de um aluno (de 0 a 10) e classifique se
// ele foi aprovado ou reprovado. A aprovação ocorre se a nota for 7 ou superior, e
// reprovação caso contrário. A função deve exibir mensagens para os dois casos.

#include <stdio.h>

float foiaprovado(float valor)
{

    if (valor >= 7)
    {
        return 1;
    }

    return 0;
}

int main()
{
    float nota;

    printf("Insira a nota de 0 a 10 ");
    scanf("%f", &nota);

    if (foiaprovado(nota) == 1)
    {
        printf("O aluno foi aprovado\n");
    }
    else
    {
        printf("O aluno foi reprovado\n");
    }
}