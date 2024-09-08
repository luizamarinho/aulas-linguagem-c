// Crie uma função que receba o salário bruto de uma pessoa e calcule o valor do
// Imposto de Renda Retido na Fonte (IRRF) com base na tabela de IRRF de 2024.
// Utilize as alíquotas e deduções conforme a tabela abaixo:
// ● Até R$ 2.112,00: Isento
// ● De R$ 2.112,01 até R$ 2.826,65: Alíquota de 7,5% (dedução de R$ 158,40)
// ● De R$ 2.826,66 até R$ 3.751,05: Alíquota de 15% (dedução de R$ 370,40)
// ● De R$ 3.751,06 até R$ 4.664,68: Alíquota de 22,5% (dedução de R$ 651,73)
// ● Acima de R$ 4.664,68: Alíquota de 27,5% (dedução de R$ 884,96)
// Use a estrutura condicional aninhada para calcular o imposto corretamente.

#include <stdio.h>

float calculoimposto(float valor)
{
    float imposto;

    if (valor <= 2112.00)
    {
        imposto = 0;
    }
    else
    {
        if (valor >= 2112.01 && valor <= 2826.65)
        {
            imposto = (valor - 158.40) * 0.075;
        }
        else
        {
            if (valor >= 2826.66 && valor <= 3751.05)
            {
                imposto = (valor - 370.40) * 0.15;
            }
            else
            {
                if (valor >= 3751.06 && valor <= 4664.68)
                {
                    imposto = (valor - 651.73) * 0.225;
                }
                else
                {
                    if (valor >= 4664.68)
                    {
                        imposto = (valor - 884.96) * 0.275;
                    }
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