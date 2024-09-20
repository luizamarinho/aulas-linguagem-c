// Escreva um programa que solicite dois números inteiros positivos ao usuário: um
// valor inicial e um valor final. O programa deve então exibir todos os números primos
// dentro desse intervalo. Se não houver números primos no intervalo, o programa
// deve informar isso. (0.3 ponto)
// Entrada: dois números inteiros positivos (inicial e final).
// Saída: números primos no intervalo ou uma mensagem informando que não há
// números primos

#include <stdio.h>

int ehprimo(int valor)
{
    int indice2 = 2;
    while (indice2 < valor)
    {
        if (valor % indice2 == 0)
        {
            return 0;
        }
        indice2 = indice2 + 1;
    }
    return 1;
}

int main()
{
    int inicial;
    int final;
    printf("Insira um valor inicial e um valor final ");
    scanf("%d %d", &inicial, &final);
    int primos = 0;
    int indice = inicial;

    while (indice <= final)
    {

        int resultado = ehprimo(indice);
        if (indice != 1)
        {
            if (resultado == 1)
            {
                printf("%d ", indice);
                primos = primos + 1;
            }
        }

        indice = indice + 1;
    }
    if (primos == 0)
    {
        printf("Não há números primos dentro desse intervalo\n");
    }
    printf("\n");
    return 0;
}
