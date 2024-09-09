// Crie uma função que receba o valor de um produto e calcule o valor do desconto
// de ICMS com base nas faixas de preço do produto:
// ● Até R$ 1.000,00: Desconto de 5%
// ● De R$ 1.000,01 até R$ 5.000,00: Desconto de 10%
// ● Acima de R$ 5.000,00: Desconto de 15%
// Use a estrutura condicional aninhada para aplicar o desconto corretamente.

#include <stdio.h>

float calculodesconto(float valor)
{
    float desconto;
    if (valor <= 1000)
    {
        desconto = valor * 0.05;
    }
    else
    {
        if (valor >= 1000.01 && valor <= 5000)
        {
            desconto = valor * 0.1;
        }
        else
        {
            if (valor > 5000)
            {
                desconto = valor * 0.15;
            }
        }
    }
    return desconto;
}

int main()
{
    float produto;

    printf("Insira o valor do produto ");
    scanf("%f", &produto);

    printf("O valor de desconto de ICMS eh R$: %0.2f\n", calculodesconto(produto));
}