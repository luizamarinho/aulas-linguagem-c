// Elabore uma função que receba o salário bruto de uma pessoa e calcule o valor
// da contribuição ao INSS com base na tabela de INSS de 2024. Utilize as faixas e
// alíquotas progressivas para calcular o valor da contribuição:
// ● Até R$ 1.320,00: 7,5%
// ● De R$ 1.320,01 até R$ 2.571,29: 9%
// ● De R$ 2.571,30 até R$ 3.856,94: 12%
// ● De R$ 3.856,95 até R$ 7.507,49: 14%
// Use a estrutura condicional aninhada para calcular o desconto corretamente.

#include <stdio.h>

float calculoimposto(float valor)
{
    float imposto;

    if (valor <= 1320.00)
    {
        imposto = valor * 0.075;
    }
    else
    {
        if (valor >= 1320.01 && valor <= 2571.29)
        {
            imposto = valor * 0.09;
        }
        else
        {
            if (valor >= 2571.30 && valor <= 3856.94)
            {
                imposto = valor * 0.12;
            }
            else
            {
                if (valor >= 3856.95 && valor <= 7507.49)
                {
                    imposto = valor * 0.14;
                }
            }
        }
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