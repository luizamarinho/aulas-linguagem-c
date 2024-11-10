// Escreva um programa que leia o conteúdo de um arquivo chamado dados.txt e o exiba na tela.
// Caso o arquivo não exista, o programa deve exibir uma mensagem de erro.

#include <stdio.h>
#include <string.h>

#define tamanho 201

int main()
{

    FILE *file;
    char buffer[tamanho];

    // file = fopen("dados.txt", "a");
    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura\n");
        return 1;
    }

    while (fgets(buffer, tamanho, file) != NULL)
    {
        printf("%s", buffer);
    }
    // printf("testando se funcionou\n");
    fclose(file);
}