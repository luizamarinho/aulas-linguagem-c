#include <stdio.h>

int main()
{
    FILE *file;     // cria uma variável para guardar uma referência para o arquivo (txt) | FILE é um tipo/struct
    char line[100]; // string de até 99 elementos

    file = fopen("example.txt", "w"); // abre o arquivo para escrita (se houver um arquivo ele será sobrescrito)
    if (file == NULL)                 // primeira coisa a ser feita ao tentar abrir um arquivo: confirma se o arquivo não deu erro.
    {
        printf("Erro ao abrir o arquivo para a escrita. \n");
        return 1; // early exit. Para a execução do programa.
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