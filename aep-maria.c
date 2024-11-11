#include <stdio.h>

int menuPrincipal()
{
    int opcao;

    system("cls");
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");
    printf("1 - Incluir novo usuario\n");
    printf("2 - Alterar usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Listar usuarios\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Opcao: ");

    scanf("%i", &opcao);

    return opcao;
}

void menuIncluirUsuario()
{
    char nome[100], senha[100];

    system("cls");
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");

    printf("Escreva o nome: \n");
    fflush(stdin);
    scanf("%[^\n]s", &nome);
    fflush(stdin);
    printf("Digite sua senha: \n");
    scanf("%[^\n]s", &senha);
    fflush(stdin);

    salvaUsuario(nome, senha);
    printf("Dados armazenados com sucesso!\n");
}

int salvaUsuario(char nomeUsuario[100], char senhaUsuario[100])
{
    FILE *file;

    file = fopen("BancoDeDadosAEP.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fflush(stdin);
    fprintf(file, "%s\n", nomeUsuario);
    fflush(stdin);
    fprintf(file, "%s\n", senhaUsuario);
    fflush(stdin);

    fclose(file);
}

void menuAlterarUsuario()
{
    FILE *fileLeitura = fopen("BancoDeDadosAEP.txt", "r");

    char nomeAntigo[100], senhaAntiga[100], nomeNovo[100], senhaNova[100];
    char nomeEncontrado[100], senhaEncontrada[100];
    int numeroRegistro = -1;

    system("cls");
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");

    printf("Escreva o nome do usuário que deseja alterar: \n");
    fflush(stdin);
    scanf("%[^\n]s", &nomeAntigo);
    fflush(stdin);
    printf("Para confirmar, digite a senha anterior: \n");
    scanf("%[^\n]s", &senhaAntiga);

    while (strcmp(nomeAntigo, nomeEncontrado) != 0 && strcmp(senhaAntiga, senhaEncontrada) != 0)
    {
        fflush(stdin);
        int retornoNome = fscanf(fileLeitura, "%[^\n]s", nomeEncontrado);
        fseek(fileLeitura, 2, SEEK_CUR); // Pula a quebra de linha

        fflush(stdin);
        int retornoSenha = fscanf(fileLeitura, "%[^\n]s", senhaEncontrada);
        fseek(fileLeitura, 2, SEEK_CUR); // Pula a quebra de linha

        numeroRegistro = numeroRegistro + 1;

        if (retornoNome == EOF || retornoSenha == EOF)
        {
            printf("Usuario nao encontrado.\n");
            fclose(fileLeitura);
            return;
        }
    }

    fflush(stdin);
    printf("Altere o nome do usuário: \n");
    scanf("%[^\n]s", &nomeNovo);
    fflush(stdin);
    printf("Alterar a senha: \n");
    scanf("%[^\n]s", &senhaNova);

    alterarUsuario(numeroRegistro, nomeNovo, senhaNova);
}

void alterarUsuario(int indice, char nomeNovo[100], char senhaNova[100])
{
    FILE *file = fopen("BancoDeDadosAEP.txt", "r+");
    FILE *newFile = fopen("temp.txt", "w");

    rewind(file);

    int cont = 0;
    char anterior[100];

    while (cont++ != indice)
    {
        fflush(stdin);
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
        fflush(stdin);
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
    }

    fflush(stdin);
    fprintf(newFile, "%s\n", nomeNovo);
    fflush(stdin);
    fprintf(newFile, "%s\n", senhaNova);

    fgets(anterior, sizeof(anterior), file);
    fgets(anterior, sizeof(anterior), file);

    while (fscanf(file, "%[^\n]s", anterior) != EOF && fseek(file, 2, SEEK_CUR) == 0)
    {
        fflush(stdin);
        fprintf(newFile, "%s\n", anterior);
        fflush(stdin);
    }

    fclose(file);
    fclose(newFile);

    remove("BancoDeDadosAEP.txt");
    rename("temp.txt", "BancoDeDadosAEP.txt");

    printf("\nUsuario alterado!\n");
}

void main()
{
    int opcao = -1;

    while (opcao != 0)
    {

        opcao = menuPrincipal();

        switch (opcao)
        {
        case 1:
            menuIncluirUsuario();
            break;
        case 2:
            menuAlterarUsuario();
            break;
        }

        system("pause");
    }

    // Saída
    return 0;
}