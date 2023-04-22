/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    float saldo;

    printf ("Digite seu saldo bancário:\n> ");
    scanf ("%f", &saldo);

    if (saldo < 0) 
        printf ("\nConta NEGATIVA!");
    else
        printf ("\nConta NORMAL!");
}