#include <stdio.h>

float func_media(float n1, float n2, float n3)
{
    float media;
    float exame;
    media = (n1 + n2 + n3) / 3;

    if (media < 3.0)
    {
        printf("Reprovado \n");
    }
    else if (media >= 3.0 && media < 7.0)
    {
        exame = 12 - media;
        printf("Exame precisando de %0.1f \n", exame);
    }
    else
    {
        printf("Aprovado \n");
    }

    return 0;
}

int main()
{
    float nota1, nota2, nota3;

    printf("Insira 3 notas \n");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    func_media(nota1, nota2, nota3);

    return 0;
}
