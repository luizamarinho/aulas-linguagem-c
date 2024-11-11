#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar a tela de forma portável
void limparTela()
{
#ifdef _WIN32 // Se o sistema for Windows
    system("cls");
#else // Para sistemas Unix (Linux, macOS, etc.)
    system("clear");
#endif
}

int menuPrincipal()
{
    int opcao;

    limparTela(); // Chama a função para limpar a tela
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");
    printf("1 - Incluir novo usuario\n");
    printf("2 - Alterar usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Listar usuarios\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Opcao: ");

    scanf("%i", &opcao);
    getchar(); // Limpa o buffer de entrada após a leitura do inteiro

    return opcao;
}

int salvaUsuario(char nomeUsuario[100], char senhaUsuario[100])
{
    FILE *file;

    file = fopen("BancoDeDadosAEP.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1; // Retorna erro caso o arquivo não possa ser aberto
    }

    fprintf(file, "%s\n", nomeUsuario);
    fprintf(file, "%s\n", senhaUsuario);

    fclose(file);
    return 0; // Retorna sucesso
}

void menuIncluirUsuario()
{
    char nome[100], senha[100];

    limparTela(); // Chama a função para limpar a tela
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");

    printf("Escreva o nome: \n");
    fgets(nome, sizeof(nome), stdin); // Lê a string com espaços
    nome[strcspn(nome, "\n")] = 0;    // Remove a nova linha, se presente

    printf("Digite sua senha: \n");
    fgets(senha, sizeof(senha), stdin); // Lê a senha com espaços
    senha[strcspn(senha, "\n")] = 0;    // Remove a nova linha, se presente

    if (salvaUsuario(nome, senha) == 0)
    {
        printf("Dados armazenados com sucesso!\n");
    }
    else
    {
        printf("Erro ao salvar os dados!\n");
    }
}

int alterarUsuario(int indice, char nomeNovo[100], char senhaNova[100])
{
    FILE *file = fopen("BancoDeDadosAEP.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return 1;
    }

    FILE *newFile = fopen("temp.txt", "w");
    if (newFile == NULL)
    {
        printf("Erro ao abrir o arquivo temporário para escrita.\n");
        fclose(file);
        return 1;
    }

    rewind(file);

    char anterior[100];
    int cont = 0;

    // Copia os dados até o usuário que será alterado
    while (cont++ != indice)
    {
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
    }

    // Escreve os dados alterados
    fprintf(newFile, "%s\n", nomeNovo);
    fprintf(newFile, "%s\n", senhaNova);

    // Copia o restante dos dados
    while (fgets(anterior, sizeof(anterior), file) != NULL)
    {
        fprintf(newFile, "%s", anterior);
    }

    fclose(file);
    fclose(newFile);

    // Substitui o arquivo original pelo temporário
    remove("BancoDeDadosAEP.txt");
    rename("temp.txt", "BancoDeDadosAEP.txt");

    return 0; // Retorna sucesso
}

void menuAlterarUsuario()
{
    FILE *fileLeitura = fopen("BancoDeDadosAEP.txt", "r");

    if (fileLeitura == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char nomeAntigo[100], senhaAntiga[100], nomeNovo[100], senhaNova[100];
    char nomeEncontrado[100], senhaEncontrada[100];
    int numeroRegistro = -1;

    limparTela(); // Chama a função para limpar a tela
    printf("SISTEMA DE INCLUSAO DE USUARIOS\n\n");

    printf("Escreva o nome do usuário que deseja alterar: \n");
    fgets(nomeAntigo, sizeof(nomeAntigo), stdin); // Lê a string com espaços
    nomeAntigo[strcspn(nomeAntigo, "\n")] = 0;    // Remove a nova linha, se presente

    printf("Para confirmar, digite a senha anterior: \n");
    fgets(senhaAntiga, sizeof(senhaAntiga), stdin); // Lê a senha com espaços
    senhaAntiga[strcspn(senhaAntiga, "\n")] = 0;    // Remove a nova linha, se presente

    while (fscanf(fileLeitura, "%[^\n]s", nomeEncontrado) != EOF)
    {
        fseek(fileLeitura, 2, SEEK_CUR); // Pula a quebra de linha
        fscanf(fileLeitura, "%[^\n]s", senhaEncontrada);
        fseek(fileLeitura, 2, SEEK_CUR); // Pula a quebra de linha

        numeroRegistro++;

        if (strcmp(nomeAntigo, nomeEncontrado) == 0 && strcmp(senhaAntiga, senhaEncontrada) == 0)
        {
            break;
        }
    }

    fclose(fileLeitura);

    if (numeroRegistro == -1)
    {
        printf("Usuário não encontrado ou senha incorreta.\n");
        return;
    }

    printf("Altere o nome do usuário: \n");
    fgets(nomeNovo, sizeof(nomeNovo), stdin); // Lê a string com espaços
    nomeNovo[strcspn(nomeNovo, "\n")] = 0;    // Remove a nova linha, se presente

    printf("Alterar a senha: \n");
    fgets(senhaNova, sizeof(senhaNova), stdin); // Lê a senha com espaços
    senhaNova[strcspn(senhaNova, "\n")] = 0;    // Remove a nova linha, se presente

    if (alterarUsuario(numeroRegistro, nomeNovo, senhaNova) == 0)
    {
        printf("\nUsuario alterado com sucesso!\n");
    }
    else
    {
        printf("\nErro ao alterar o usuário.\n");
    }
}

int alterarUsuario(int indice, char nomeNovo[100], char senhaNova[100])
{
    FILE *file = fopen("BancoDeDadosAEP.txt", "r+");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return 1;
    }

    FILE *newFile = fopen("temp.txt", "w");
    if (newFile == NULL)
    {
        printf("Erro ao abrir o arquivo temporário para escrita.\n");
        fclose(file);
        return 1;
    }

    rewind(file);

    char anterior[100];
    int cont = 0;

    // Copia os dados até o usuário que será alterado
    while (cont++ != indice)
    {
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
        fgets(anterior, sizeof(anterior), file);
        fprintf(newFile, "%s", anterior);
    }

    // Escreve os dados alterados
    fprintf(newFile, "%s\n", nomeNovo);
    fprintf(newFile, "%s\n", senhaNova);

    // Copia o restante dos dados
    while (fgets(anterior, sizeof(anterior), file) != NULL)
    {
        fprintf(newFile, "%s", anterior);
    }

    fclose(file);
    fclose(newFile);

    // Substitui o arquivo original pelo temporário
    remove("BancoDeDadosAEP.txt");
    rename("temp.txt", "BancoDeDadosAEP.txt");

    return 0; // Retorna sucesso
}

int main()
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
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

        system("pause");
    }

    return 0;
}
