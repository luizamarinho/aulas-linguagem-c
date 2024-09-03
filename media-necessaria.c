#include <stdio.h>

float func_media(float n1, float n2, float n3)
{
    float media;
    media = (n1 + n2 + n3) / 3;

    if (media < 3.0)
    {
        printf("Reprovado");
    }
    else if (media >= 3.0 && media < 7.0)
    {
        printf("Exame");
    }
    else
    {
        printf("Aprovado");
    }
}

int main()
{
    float nota1, nota2, nota3;

    printf("Insira 3 notas");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    func_media(nota1, nota2, nota3);

    return 0;
}
