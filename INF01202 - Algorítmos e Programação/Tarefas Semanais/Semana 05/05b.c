/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    float meta, doacao, valorFinal = 0;
    int numeroDoacoes;

    printf ("Informe o valor a ser arrecadado:\n> ");
    scanf ("%f", &meta);

    do // loop enquanto o valor arrecadado for menor que a meta de arrecadação
    {
        printf ("\nInforme o valor da doação:\n> ");
        scanf ("%f", &doacao);

        if (doacao < 0)
        {
            printf("Valor invalido!\n");
        }
        else
        {
            valorFinal += doacao;
            numeroDoacoes++;
        }
        
    } while (valorFinal < meta);

    printf ("\nO valor final arrecadado foi de R$ %.2f", valorFinal);
    printf ("\nA média de cada doação foi de R$ %.2f", valorFinal/numeroDoacoes);
}