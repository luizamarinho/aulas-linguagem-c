//  Desenvolva uma função que receba o valor venal de um imóvel e calcule o valor
// do IPTU com base na tabela abaixo:
// ● Até R$ 100.000,00: Alíquota de 1%
// ● De R$ 100.000,01 até R$ 300.000,00: Alíquota de 1,5%
// ● De R$ 300.000,01 até R$ 500.000,00: Alíquota de 2%
// ● Acima de R$ 500.000,00: Alíquota de 2,5%
// Use a estrutura condicional aninhada para aplicar a alíquota corretamente.

#include <stdio.h>

float calculoimposto(float valor)
{
    float imposto;
    if (valor <= 100000)
    {
        imposto = valor * 0.01;
    }
    else
    {
        if (valor >= 100000.01 && valor <= 300000)
        {
            imposto = valor * 0.015;
        }
        else
        {
            if (valor >= 300000.01 && valor <= 500000)
            {
                imposto = valor * 0.02;
            }
            else
            {
                if (valor > 500000)
                {
                    imposto = valor * 0.25;
                }
            }
        }
    }
    return imposto;
}

int main()
{
    float imovel;

    printf("Insira o valor venal do imovel ");
    scanf("%f", &imovel);

    printf("O valor do IPTU eh R$: %0.2f\n", calculoimposto(imovel));
}