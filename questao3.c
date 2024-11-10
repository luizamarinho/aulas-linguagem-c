// Crie um programa que leia um arquivo de texto chamado texto.txt e conte quantas palavras ele contém.
// Considere que as palavras estão separadas por espaços.

#include <stdio.h>
#include <string.h>

#define tamanho 201

int main()
{

    FILE *file;
    char buffer[tamanho];
    int quant_palavras = 0;

    // file = fopen("texto.txt", "a");
    // if (file == NULL)
    // {
    //     printf("Erro ao abrir o arquivo para escrita.\n");
    //     return 1;
    // }    codigo para criar o arquivo

    file = fopen("texto.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 1;
    }

    while (fgets(buffer, tamanho, file) != NULL)
    {

        for (int i = 0; i < strlen(buffer); i++)
        {

            if ((i == 0 && buffer[i] != ' ') || (buffer[i] != ' ' && buffer[i - 1] == ' '))
            {
                quant_palavras++;
            }
        }
    }

    fclose(file);

    printf("%d\n", quant_palavras);
}
