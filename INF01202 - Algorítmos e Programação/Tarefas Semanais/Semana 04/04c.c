/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    int n;
    float valor, maior, menor;

    printf ("Informe a quantidade de valores considerados:\n> ");
	scanf ("%d",&n);
	
	if (n < 0){
		printf ("\nO valor deve ser inteiro e positivo!\n\n");
		return 0;
	}

    for (int x = 0; x < n; x++)
    {
        printf ("Informe um valor:\n> ");
        scanf ("%f", &valor);

        if (x == 0)
            maior = menor = valor; // inicializa as variáveis na primeira execução do loop
        if (valor > maior)
            maior = valor;
        if (valor < menor)
            menor = valor;
    }

    printf("\nO maior valor digitado foi: %.2f", maior);
    printf("\nO menor valor digitado foi: %.2f", menor);

}