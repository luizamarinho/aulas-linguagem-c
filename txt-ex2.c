#include <stdio.h>

int main()
{

    FILE *file;
    char line[100];

    file = fopen("example.txt", "a");

    fprintf(file, "Linha extra adicionada.\n");

    fclose(file);

    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura. \n");
        return 1;
    }

    printf("Conteudo do arquivo:\n");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}
