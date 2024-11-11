#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 10        // define o numero maximo de usuarios para 10
#define TAM_MAX_LINHA (20 + 2) // 20 caracteres por linha + \n e \0

#define TAM_MAX_NOME 12 // define o tamanho maximo dos nomes pra 12
#define TAM_MAX_SENHA 8 // define o tamanho maximo da senha pra 8

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
    FILE *arquivo = fopen("dados2.txt", "r");
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
    FILE *arquivo = fopen("dados2.txt", "w");
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

        printf("Nome: %s. Senha: %s\n", nome, senha);

        return 1;
    }
}

int main()
{
    char dados[MAX_USUARIOS][TAM_MAX_LINHA];
    ler_arquivo(dados);

    printf("SISTEMA DE GERENCIAMENTO DE USUARIOS\n");
    printf("1 - Incluir novo usuario\n");
    printf("2 - Alterar usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Listar usuarios\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Opcao: ");

    if (buscar_usuario(dados, "luiza") == -1)
    {
        incluir_usuario(dados, "luiza\0    ", "123456\0 ");
    }

    int pos = buscar_usuario(dados, "luiza");

    printf("POS: %d\n", pos);
    exibir_usuario(dados, pos);

    salvar_arquivo(dados);

    return 0;
}