#include <stdio.h>

int main()
{
    int alternativa;

    printf("Insira a opcao que deseja:\n1-Incluir novo usuario.\n2-Editar usuario existente.\n3-Excluir usuario existente.\n4-Listar usuários existentes.\n");
    scanf("%d", &alternativa);

    if (alternativa == 1)
    {
        incluirUsuario();
    }
    else if (alternativa == 2)
    {
        editarUsuario();
    }
    else if (alternativa == 3)
    {
        excluirUsuario();
    }
    else if (alternativa == 4)
    {
        listarUsuarios();
    }
}