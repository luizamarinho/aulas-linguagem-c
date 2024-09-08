// Crie uma função que receba três lados de um triângulo e verifique se esses lados
// formam um triângulo válido. Um triângulo é válido se a soma de dois de seus lados
// for sempre maior que o terceiro. Caso o triângulo seja válido, a função deverá
// retornar 1. Caso contrário, não deve retornar nada.

#include <stdio.h>

int ehvalido(int valor1, int valor2, int valor3)
{

    if (((valor1 + valor2) > valor3) && ((valor2 + valor3) > valor1) && ((valor1 + valor3) > valor2))
    {
        return 1;
    }
    return 0;
}

int main()
{

    int lado1;
    int lado2;
    int lado3;
    int resultado;

    printf("Insira os tres lados de um triangulo ");
    scanf("%d %d %d", &lado1, &lado2, &lado3);

    resultado = ehvalido(lado1, lado2, lado3);

    if (resultado == 1)
    {
        printf("1\n");
    }
}