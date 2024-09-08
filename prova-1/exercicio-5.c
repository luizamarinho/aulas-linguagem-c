// Crie uma função que receba a idade de uma pessoa e verifique se ela é maior de
// idade (18 anos ou mais). A função deve exibir uma mensagem diferente para os
// casos em que a pessoa é maior ou menor de idade

#include <stdio.h>

int ehmaior(int i)
{

    if (i >= 18)
    {

        return 1;
    }

    return 0;
}

int main()
{
    int idade;

    printf("Insira a idade ");
    scanf("%d", &idade);

    ehmaior(idade);

    if (ehmaior(idade) == 1)
    {
        printf("Eh maior de idade\n");
    }
    else
        printf("Eh menor de idade\n");
}