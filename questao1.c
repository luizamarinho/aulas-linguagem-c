// Crie um programa que peça ao usuário para inserir frases e as salve em um arquivo chamado frases.txt.
// O programa deve permitir que o usuário continue inserindo frases até que ele insira a palavra "sair".

#include <string.h> // biblioteca de strings
#include <stdio.h>  // biblioteca padrão de C

#define tamanho 201

int main()
{
    FILE *file;
    char buffer[tamanho];
    int alternativa = 1;

    file = fopen("frases.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para a escrita.\n");
        return 1;
    }

    while (alternativa == 1)
    {
        printf("Escolha uma opcao: \n 1-Inserir uma frase.\n 2-SAIR\n\n");

        // scanf("%d", &alternativa);
        fgets(buffer, tamanho, stdin);
        sscanf(buffer, "%d", &alternativa);

        if (alternativa == 1)
        {
            printf("Insira a frase desejada (max 200 caracteres)\n");
            fgets(buffer, tamanho, stdin);

            fprintf(file, "%s", buffer);
            // printf("len %ld\n", strlen(buffer));
        }
    }

    fclose(file);
}