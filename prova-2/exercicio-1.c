// Escreva um programa em C que solicite ao usuário o valor inicial de um
// investimento, a taxa de juros anual (em porcentagem) e o número de anos que o
// dinheiro será investido. O programa deve calcular o valor final do investimento ao
// final de cada ano, aplicando os juros compostos, e mostrar uma tabela com o valor
// acumulado ano a ano

#include <stdio.h>

int main()
{
    float valor_inicial;
    float juros;
    int anos;
    float rendimento;
    int indice = 1;

    printf("Insira o valor inicial do investimento ");
    scanf("%f", &valor_inicial);
    printf("Insira a porcentagem da taxa anual de juros ");
    scanf("%f", &juros);
    printf("Insira o número de anos que o dinheiro será investido ");
    scanf("%d", &anos);

    float montante = valor_inicial;

    while (indice <= anos)
    {

        rendimento = montante * (juros / 100);
        montante = montante + rendimento;
        printf("O valor total do investimento ao final do ano %d é %.2f\n", indice, montante);
        indice = indice + 1;
    }

    return 0;
}