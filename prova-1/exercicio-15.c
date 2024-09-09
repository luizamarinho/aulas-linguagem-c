// Crie um programa que converta um valor monetário entre três moedas: real
// (BRL), dólar (USD) e euro (EUR). O usuário deve informar a moeda de origem, a
// moeda de destino e o valor a ser convertido. As taxas de conversão são as
// seguintes:
// ● 1 USD = 5.30 BRL
// ● 1 EUR = 6.20 BRL
// ● 1 BRL = 0.19 USD
// ● 1 BRL = 0.16 EUR
// O programa deve calcular e exibir o valor convertido. Se a moeda informada não for
// reconhecida, o programa deve exibir uma mensagem de erro.

#include <stdio.h>

int main()
{
    int moeda_o;
    int moeda_d;
    float valor;
    float valor_convertido;

    printf("Escolha a moeda de origem (1-BRL/2-USD/3-EUR): ");
    scanf("%d", &moeda_o);

    printf("Escolha a moeda de destino (1-BRL/2-USD/3-EUR): ");
    scanf("%d", &moeda_d);

    printf("Insira o valor a ser convertido ");
    scanf("%f", &valor);

    if (moeda_o == 2 && moeda_d == 1)
    { // dolar para real
        valor_convertido = valor * 5.30;
    }
    else if (moeda_o == 3 && moeda_d == 1)
    { // euro para real
        valor_convertido = valor * 6.20;
    }
    else if (moeda_o == 1 && moeda_d == 2)
    { // real para dolar
        valor_convertido = valor * 0.19;
    }
    else if (moeda_o == 1 && moeda_d == 3)
    { // real para euro
        valor_convertido = valor * 0.16;
    }
    else
    {
        printf("ERRO: a moeda não foi reconhecida\n");
    }

    printf("O valor convertido eh %0.2f\n", valor_convertido);
}