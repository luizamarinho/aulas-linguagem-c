// Uma loja de peças de automóveis deseja implementar um sistema de controle de estoque. A loja mantém o registro da quantidade de peças em um vetor onde cada posição representa um item diferente.
// No final do dia, os funcionários devem verificar quantas peças foram vendidas e atualizar o estoque.
// Crie uma função que, dado um vetor de estoque inicial e outro vetor de vendas, atualize o vetor de estoque subtraindo as vendas do estoque original.
// Caso alguma peça tenha sido totalmente vendida, exiba uma mensagem informando.

#include <stdio.h>

#define MAX_PRODUTOS 5

int calculoVendas(int inicial, int vendida)
{
    int final = inicial - vendida;
    return final;
}

int main()
{
    int quant_inicial[MAX_PRODUTOS]; // tipo: array de int com MAX_PRODUTOS (5) elementos
    int quant_vendida[MAX_PRODUTOS];
    int quant_final[MAX_PRODUTOS];

    for (int i = 0; i < MAX_PRODUTOS; i++)
    {

        printf("Insira a quantidade inicial do produto %d\n", (i + 1));
        scanf("%d", &quant_inicial[i]);
        printf("Insira a quantidade vendida do produto %d\n", (i + 1));
        scanf("%d", &quant_vendida[i]);

        quant_final[i] = calculoVendas(quant_inicial[i], quant_vendida[i]);

        if (quant_inicial[i] < quant_vendida[i])
        {
            printf("Erro: a quantidade de vendas eh maior que o estoque\n");
        }
        else if (quant_final[i] == 0)
        {
            printf("O produto foi totalmente vendido\n");
        }
        else
        {
            printf("A quantidade atualizada do produto %d no estoque eh %d\n", (i + 1), quant_final[i]);
        }
    }

    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        printf("A quantidade atualizada do produto %d eh %d\n", (i + 1), quant_final[i]);
    }
}