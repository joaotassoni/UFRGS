/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    int numero1, numero2, somaPares=0;

    printf ("Digite o número 1:\n> ");
    scanf ("%d", &numero1);
    printf ("Digite o número 2:\n> ");
    scanf ("%d", &numero2);

    if (numero1 % 2 == 0) // verifica se os números digitados são pares (se sim, adiciona os mesmos na soma)
        somaPares += numero1;
    if (numero2 % 2 == 0)
        somaPares += numero2;

    for (int x = numero2; x < numero1; x++)
    {
        if (x %2 == 0) // adiciona os pares no caminho entre os números à soma
        {
            somaPares += x;
            x++;
        }
    }

    printf ("\nSoma dos valores pares entre estes numeros: %d", somaPares);

}