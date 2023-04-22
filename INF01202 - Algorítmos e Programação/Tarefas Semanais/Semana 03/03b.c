/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    float peso1, peso2, peso3, pesoRef;
    int pessoas = 0;

    printf ("Digite o peso da primeira pessoa:\n> ");
    scanf ("%f",&peso1);
    printf ("\nDigite o peso da segunda pessoa:\n> ");
    scanf ("%f",&peso2);
    printf ("\nDigite o peso terceira pessoa:\n> ");
    scanf ("%f",&peso3);
    printf ("\nDigite o peso de referência:\n> ");
    scanf ("%f",&pesoRef);

    if (peso1 >= pesoRef)
        pessoas++;
    if (peso2 >= pesoRef)
        pessoas++;
    if (peso3 >= pesoRef)
        pessoas++;
    
    if (pessoas == 0)
        printf ("\nNenhuma pessoa possui um peso igual ou superior ao peso de referência!");
    else if (pessoas == 1)
        printf ("\n%d pessoa possui um peso igual ou superior ao peso de referência!", pessoas);
    else
        printf ("\n%d pessoas possuem um peso igual ou superior ao peso de referência!", pessoas);    
}