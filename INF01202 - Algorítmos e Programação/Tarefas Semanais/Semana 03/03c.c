/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    float ap1, ap2, tf;
    float mf;
    char conceito;

    printf ("Digite a nota da atividade prática 1:\n> ");
    scanf ("%f", &ap1);

    printf ("Digite a nota da atividade prática 2:\n> ");
    scanf ("%f", &ap2);

    printf ("Digite a nota do trabalho final:\n> ");
    scanf ("%f", &tf);

    mf = ((0.35*ap1) + (0.45*ap2) + (0.2*tf));

    if (mf < 6.0)
        conceito = 'D';
    else if (mf < 7.5)
        conceito = 'C';
    else if (mf < 9.0)
        conceito = 'B';
    else
        conceito = 'A';

    printf ("\nA nota final foi %.1f, e o aluno teve um conceito %c!", mf, conceito);
}