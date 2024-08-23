#include <stdio.h>

float calculo(float salario)
{
	float percentual;

	printf("Escreva o percentual de aumento ");
	scanf("%f", &percentual);

	float valor = salario * (percentual / 100);

	return valor;
}

int main()
{
	float aumento, salario, novo_salario;

	printf("Insira o salario ");
	scanf("%f", &salario);

	aumento = calculo(salario);
	novo_salario = salario + aumento;

	printf("O aumento foi de %.2f e o novo salario eh %.2f", aumento, novo_salario);
}
