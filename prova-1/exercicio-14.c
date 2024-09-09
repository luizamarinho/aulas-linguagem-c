// Elabore um programa que exiba uma mensagem de boas-vindas baseada no
// turno do dia. O usuário deve informar o turno usando um número (1 para manhã, 2
// para tarde, 3 para noite). O programa deve exibir uma mensagem apropriada para
// cada turno e um erro para entradas inválidas.

#include <stdio.h>

int main()
{
    int turno;

    printf("Informe o turno (1-manha/2-tarde/3-noite): ");
    scanf("%d", &turno);

    switch (turno)
    {
    case 1:
        printf("Bom dia!\n");
        break;
    case 2:
        printf("Boa tarde!\n");
        break;
    case 3:
        printf("Boa noite!\n");
        break;
    default:
        printf("Valor incorreto\n");
    }
}