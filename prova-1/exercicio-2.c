// Crie uma função que verifique se um ano fornecido é bissexto. Retorne 1 se for
// bissexto, caso contrário, a função não deve retornar nada. Um ano é bissexto se for
// divisível por 4, exceto os divisíveis por 100, a menos que também sejam divisíveis
// por 400.

#include <stdio.h>

int ehbissexto(int teste)
{

    if (teste % 4 != 0)
    {
        // nao eh divisivel por 4, entao nao tem como ser bissexto
        return 0;
    }

    if (teste % 100 == 0 && teste % 400 != 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int ano;
    int resultado;

    printf("Insira um ano ");
    scanf("%d", &ano);

    if (ehbissexto(ano) == 1)
    {
        printf("%d\n", ehbissexto(ano));
    }
}