#include <stdio.h>

float multiplica_valor(float entrada)
{
    entrada = 6;
    return entrada * 5;
}

void multiplica_referencia(float *endereco_entrada)
{
    // float a = *endereco_entrada;

    *endereco_entrada = (*endereco_entrada) * 5;
}

int main()
{
    float numero1 = 10;
    float teste1 = multiplica_valor(numero1);
    printf("teste 1: %f\n", teste1);
    printf("teste 1b: %f\n", numero1);

    float numero2 = 30;
    multiplica_referencia(&numero2);
    printf("teste 2: %f\n", numero2);
}
