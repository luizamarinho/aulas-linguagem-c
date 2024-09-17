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

    printf("Insira o valor inicial do investimento ");
    scanf("%f", &valor_inicial);
    printf("Insira a porcentagem da taxa anual de juros ");
    scanf("%f", &juros);
    printf("Insira o número de anos que o dinheiro será investido ");
    scanf("%d", &anos);
}