// Elabore uma função que receba três lados de um triângulo e verifique se ele é um
// triângulo retângulo. Um triângulo é retângulo se o quadrado da hipotenusa (o maior
// lado) for igual à soma dos quadrados dos outros dois lados. Caso o triângulo seja
// retângulo, a função deverá informar ao usuário que o triângulo é retângulo, caso
// contrário, não deverá fazer nada.

#include <stdio.h>

float ehretangulo(float q_hipotenusa, float q_cateto1, float q_cateto2)
{
    float soma;

    soma = q_cateto1 + q_cateto2;

    if (q_hipotenusa == soma)
    {
        return 1;
    }

    return 0;
}

int main()
{
    float lado1, lado2, lado3;
    float hipotenusa;
    float quadrado_h;
    float cateto1;
    float cateto2;
    float quadrado_c1;
    float quadrado_c2;
    float func_retangulo;

    printf("Insira os tres lados de um triangulo ");
    scanf("%f %f %f", &lado1, &lado2, &lado3);

    if (lado1 > lado2 && lado1 > lado3)
    {
        hipotenusa = lado1;
        cateto1 = lado2;
        cateto2 = lado3;
    }
    else if (lado2 > lado3 && lado2 > lado1)
    {
        hipotenusa = lado2;
        cateto1 = lado1;
        cateto2 = lado2;
    }
    else if (lado3 > lado1 && lado3 > lado2)
    {
        hipotenusa = lado3;
        cateto1 = lado1;
        cateto2 = lado2;
    }

    quadrado_h = hipotenusa * hipotenusa;
    quadrado_c1 = cateto1 * cateto1;
    quadrado_c2 = cateto2 * cateto2;

    func_retangulo = ehretangulo(quadrado_h, quadrado_c1, quadrado_c2);

    if (func_retangulo == 1)
    {
        printf("O triangulo eh retangulo\n");
    }
}