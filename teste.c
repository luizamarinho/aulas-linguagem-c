#include <stdio.h>
#include <string.h>

int main()
{
    char entrada[] = " teste 123 45 6 ";
    int quant_palavras = 0;

    for (int i = 0; i < strlen(entrada); i++)
    {

        if ((i == 0 && entrada[i] != ' ') || (entrada[i] != ' ' && entrada[i - 1] == ' '))
        {
            quant_palavras++;
        }
    }
    printf("%d\n", quant_palavras);
}
