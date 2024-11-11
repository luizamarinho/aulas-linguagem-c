#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 10 // define o numero maximo de usuarios para 10

#define TAM_MAX_NOME 150  // define o tamanho maximo dos nomes pra 150
#define TAM_MAX_SENHA 100 // define o tamanho maximo da senha pra 100

#define TAM_MAX_LINHA (TAM_MAX_NOME + TAM_MAX_SENHA + 2) // 150 caracteres por linha + \n e \0

// remove espacos em branco no final de uma string // percorre a string procurando por espaços, no momento que encontra um caracter diferente de espaço, finaliza a string na posição seguinte
void trim(char *texto, int tamanho)
{
    for (int i = tamanho - 2; i >= 0; i--)
    {
        if (texto[i] != ' ')
        {
            texto[i + 1] = '\0';
            return;
        }
    }
}

void criptografar(char linha[TAM_MAX_LINHA])
{
    // pega o complemento de cada ascii garantindo que o resultado
    // seja um caractere legivel
    for (int i = 0; i < TAM_MAX_LINHA - 2; i++)
    {
        linha[i] = ((126 - 32) - (linha[i] - 32)) + 32;
    }
}

void descriptografar(char linha[TAM_MAX_LINHA])
{
    // mesma coisa que criptografar, pois o complemento do complemento
    // resulta no valor original
    for (int i = 0; i < TAM_MAX_LINHA - 2; i++)
    {
        linha[i] = ((126 - 32) - (linha[i] - 32)) + 32;
    }
}

int ler_arquivo(char dados[MAX_USUARIOS][TAM_MAX_LINHA])
{
    FILE *arquivo = fopen("base_de_dados.txt", "r");
    if (arquivo != NULL)
    {
        for (int i = 0; i < MAX_USUARIOS; i++)
        {
            fgets(dados[i], TAM_MAX_LINHA, arquivo);
            descriptografar(dados[i]);
        }

        fclose(arquivo);
        return 1;
    }

    // inicializar
    for (int i = 0; i < MAX_USUARIOS; i++)
    {
        for (int j = 0; j < TAM_MAX_LINHA - 2; j++)
        {
            dados[i][j] = ' ';
        }
        dados[i][TAM_MAX_LINHA - 2] = '\n';
        dados[i][TAM_MAX_LINHA - 1] = '\0';
    }

    return 0;
}

int salvar_arquivo(char dados[MAX_USUARIOS][TAM_MAX_LINHA])
{
    FILE *arquivo = fopen("base_de_dados.txt", "w");
    if (arquivo == NULL)
    {
        return 0;
    }

    for (int i = 0; i < MAX_USUARIOS; i++)
    {
        char copia[TAM_MAX_LINHA];

        for (int j = 0; j < TAM_MAX_LINHA; j++)
        {
            copia[j] = dados[i][j];
        }

        criptografar(copia);

        copia[TAM_MAX_LINHA - 2] = '\n';
        copia[TAM_MAX_LINHA - 1] = '\0';

        fprintf(arquivo, "%s", copia);
    }

    fclose(arquivo);
    return 1;
}

void sobrescrever_usuario(char dados[MAX_USUARIOS][TAM_MAX_LINHA], int posicao, char nome[TAM_MAX_NOME + 1], char senha[TAM_MAX_SENHA + 1])
{
    int branco = 0;

    // copia conteudo da string completando com espaco a direita
    for (int i = 0; i < TAM_MAX_NOME; i++)
    {
        if (nome[i] == '\0' || nome[i] == '\n' || branco == 1)
        {
            dados[posicao][i] = ' ';
            branco = 1;
        }
        else
        {
            dados[posicao][i] = nome[i];
        }
    }

    branco = 0;

    // copia conteudo da string completando com espaco a direita
    // deslocando para nao substituir o que acabamos de escrever
    for (int i = 0; i < TAM_MAX_SENHA; i++)
    {
        if (senha[i] == '\0' || senha[i] == '\n' || branco == 1)
        {
            dados[posicao][TAM_MAX_NOME + i] = ' ';
            branco = 1;
        }
        else
        {
            dados[posicao][TAM_MAX_NOME + i] = senha[i];
        }
    }
}

int incluir_usuario(char dados[MAX_USUARIOS][TAM_MAX_LINHA], char nome[TAM_MAX_NOME + 1], char senha[TAM_MAX_SENHA + 1])
{
    for (int i = 0; i < MAX_USUARIOS; i++)
    {
        if (dados[i][0] == ' ') // usuario vazio
        {
            sobrescrever_usuario(dados, i, nome, senha);
            return 1;
        }
    }

    return 0;
}

void excluir_usuario(char dados[MAX_USUARIOS][TAM_MAX_LINHA], int posicao)
{
    for (int i = 0; i < TAM_MAX_LINHA - 2; i++)
    {
        dados[posicao][i] = ' ';
    }
}

int buscar_usuario(char dados[MAX_USUARIOS][TAM_MAX_LINHA], char nome[TAM_MAX_NOME + 1])
{
    for (int i = 0; i < MAX_USUARIOS; i++)
    {
        int achou = 1;
        for (int j = 0; j < TAM_MAX_NOME; j++)
        {
            if (nome[j] == '\0')
            {
                if (dados[i][j] != ' ')
                {
                    achou = 0;
                }
                break;
            }

            if (dados[i][j] != nome[j])
            {
                achou = 0;
                break;
            }
        }
        if (achou)
        {
            return i;
        }
    }
    return -1;
}

int exibir_usuario(char dados[MAX_USUARIOS][TAM_MAX_LINHA], int posicao)
{
    if (dados[posicao][0] == ' ')
    {
        return 0;
    }
    else
    {
        char nome[TAM_MAX_NOME + 1];
        char senha[TAM_MAX_SENHA + 1];

        for (int i = 0; i < TAM_MAX_NOME; i++)
        {
            nome[i] = dados[posicao][i];
        }
        nome[TAM_MAX_NOME] = '\0';
        trim(nome, TAM_MAX_NOME + 1);

        for (int i = 0; i < TAM_MAX_SENHA; i++)
        {
            senha[i] = dados[posicao][TAM_MAX_NOME + i];
        }
        senha[TAM_MAX_SENHA] = '\0';
        trim(senha, TAM_MAX_SENHA + 1);

        printf("%d) Nome: %s | Senha: ********\n", (posicao + 1), nome);

        return 1;
    }
}

int main()
{
    char dados[MAX_USUARIOS][TAM_MAX_LINHA];
    ler_arquivo(dados);

    int alternativa;

    do
    {
        printf("SISTEMA DE GERENCIAMENTO DE USUARIOS\n");
        printf("1 - Incluir novo usuario\n");
        printf("2 - Alterar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Listar usuarios\n");
        printf("5 - Sair\n");
        printf("\n");
        printf("Opcao: ");

        scanf("%d", &alternativa);

        int sucesso = 0;

        if (alternativa == 1)
        {
            char nome[TAM_MAX_NOME + 1];
            char senha[TAM_MAX_SENHA + 1];

            printf("Insira o nome do usuario (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_NOME);
            scanf("%s", nome);
            printf("\n");

            if (buscar_usuario(dados, nome) == -1)
            {
                printf("Insira a senha do usuario (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_SENHA);
                scanf("%s", senha);
                printf("\n");

                if (incluir_usuario(dados, nome, senha) == 0)
                {
                    printf("Nao foi possivel inserir. Numero maximo de usuarios atingido.\n");
                }
                else
                {
                    sucesso = 1;
                }
            }
            else
            {
                printf("O usuário ja existe. Utilize a opcao 2 para altera-lo.\n");
            }
        }
        else if (alternativa == 2)
        {

            char nome[TAM_MAX_NOME + 1];
            char senha[TAM_MAX_SENHA + 1];

            printf("Insira o nome do usuario a ser alterado (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_NOME);
            scanf("%s", nome);
            printf("\n");

            int posicao = buscar_usuario(dados, nome);

            if (posicao != -1)
            {
                do
                {
                    printf("Insira o novo nome do usuario (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_NOME);
                    scanf("%s", nome);
                    printf("\n");

                    int posicao_novo_nome = buscar_usuario(dados, nome);
                    if (posicao_novo_nome == -1 || posicao_novo_nome == posicao)
                    {
                        break;
                    }
                    else
                    {
                        printf("Este nome de usuario ja esta em uso. Escolha outro.\n");
                    }
                } while (1);

                printf("Insira a nova senha do usuario (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_SENHA);
                scanf("%s", senha);
                printf("\n");

                sobrescrever_usuario(dados, posicao, nome, senha);

                sucesso = 1;
            }
            else
            {
                printf("Usuario nao encontrado. Utilize a opcao 1 para cadastra-lo.\n");
            }
        }
        else if (alternativa == 3)
        {

            char nome[TAM_MAX_NOME + 1];

            printf("Insira o nome do usuario a ser excluido (max %d caracteres, nao pode ter espacos):\n", TAM_MAX_NOME);
            scanf("%s", nome);
            printf("\n");

            int posicao = buscar_usuario(dados, nome);

            if (posicao != -1)
            {
                excluir_usuario(dados, posicao);
                sucesso = 1;
            }
            else
            {
                printf("Usuario nao encontrado. Confira o nome e tente novamente.\n");
            }
        }
        else if (alternativa == 4)
        {
            int vazio = 1;
            for (int i = 0; i < MAX_USUARIOS; i++)
            {
                if (exibir_usuario(dados, i) != 0)
                {
                    vazio = 0;
                }
            }

            if (vazio == 1)
            {
                printf("Nenhum usuario cadastrado. Utilize a opcao 1 para cadastrar um novo.\n");
            }
        }

        salvar_arquivo(dados);

        if (sucesso)
        {
            printf("\nOperacao realizada com sucesso\n");
        }

        if (alternativa != 5)
        {
            printf("\n\n");
        }
    } while (alternativa != 5);

    return 0;
}