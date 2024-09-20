// Escreva um programa que solicite dois números inteiros positivos ao usuário: um
// valor inicial e um valor final. O programa deve então exibir todos os números primos
// dentro desse intervalo. Se não houver números primos no intervalo, o programa
// deve informar isso. (0.3 ponto)
// Entrada: dois números inteiros positivos (inicial e final).
// Saída: números primos no intervalo ou uma mensagem informando que não há
// números primos

#include <stdio.h>

int ehprimo(int valor)
{
    int indice2 = 2;
    while (indice2 < valor) // laço de repetição que percorre todos os valores anteriores ao valor informado
    {
        if (valor % indice2 == 0)
        {
            return 0; // retorna 0 se o valor for divisivel por algum número que não seja 1 nem ele mesmo,ou seja, não pode ser primo
        }
        indice2 = indice2 + 1;
    }
    return 1; // retorna 1 se não for divisível por nenhum valor (além de 1 e ele mesmo, que não são testados)
}

int main()
{
    int inicial;
    int final;
    printf("Insira um valor inicial e um valor final ");
    scanf("%d %d", &inicial, &final);
    int primos = 0;
    int indice = inicial;

    while (indice <= final) // percorre do valor inicial ao valor final
    {

        int resultado = ehprimo(indice); // chama a função que retorna se o número é primo ou não e armazena em uma variável
        if (indice != 1)
        {
            if (resultado == 1) // testa se o retorno da função é igual a 1, ou seja, é um valor primo
            {
                printf("%d ", indice); // se for primo, imprime o valor na tela
                primos = primos + 1;
            }
        }

        indice = indice + 1;
    }
    if (primos == 0)
    {
        printf("Não há números primos dentro desse intervalo\n");
    }
    printf("\n");
    return 0;
}
