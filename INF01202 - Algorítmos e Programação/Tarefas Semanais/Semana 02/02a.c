/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    float peso, altura, imc;

    printf ("Digite seu peso:\n> ");
    scanf ("%f", &peso);

    printf ("\nDigite sua altura:\n> ");
    scanf ("%f", &altura);

    imc = (peso / (altura * altura));

    printf ("\nSeu IMC é: %.2f", imc);
}