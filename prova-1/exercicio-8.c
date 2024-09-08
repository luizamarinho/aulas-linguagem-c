// Elabore uma função que calcule o imposto sobre um salário com base no valor
// recebido. Se o salário for maior que R$ 5.000,00, o imposto será de 20%. Caso
// contrário, o imposto será de 10%. A função deve exibir o valor do imposto a ser
// pago.

#include <stdio.h>

float calculoimposto(float valor)
{

    float imposto;

    if (valor > 5000)
    {
        imposto = valor * 0.2;
    }
    else if (valor <= 5000)
    {
        imposto = valor * 0.1;
    }
    return imposto;
}

int main()
{
    float salario;

    printf("Insira o salario ");
    scanf("%f", &salario);
    printf("O valor de imposto a ser pago eh R$: %0.2f\n", calculoimposto(salario));
}