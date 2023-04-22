/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main () 
{
    int numero, soma;

    printf ("Digite o número de 3 digitos:\n> ");
    scanf ("%d", &numero);

    soma = (numero / 100) + ((numero / 10) - (numero / 100) * 10)+ ((numero)- (numero / 10) * 10);

    printf ("\nA soma dos digitos deu %d!", soma);
}