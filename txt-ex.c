#include <stdio.h>

int main()
{
    FILE *file;
    char line[100];

    file = fopen("example.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para a escrita. \n");
        return 1;
    }

    fprintf(file, "Linha 1: Hello, World! \n");
    fprintf(file, "Linha 2: Este eh um exemplo de escrita em arquivo. \n");
    fprintf(file, "Linha 3: Linguagem C eh poderosa. \n");

    fclose(file);

    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    printf("Conteudo do arquivo:\n");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}