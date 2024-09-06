#include <stdio.h>

int main()
{
    int numero;
    int indice;
    int resultado;

    printf("Informe um numero ");
    scanf("%d", &numero);

    indice = 1;

    while (indice <= 10)
    {
        resultado = numero * indice;

        printf("%d vezes %d é igual a %d \n", numero, indice, resultado);

        indice = indice + 1;
    }
}