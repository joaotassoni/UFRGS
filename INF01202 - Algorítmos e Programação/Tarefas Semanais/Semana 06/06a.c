/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define TAMANHO 5

int main ()
{
    int arr1[TAMANHO], arr2[TAMANHO], arr3[2 * TAMANHO];

    for (int x = 0; x < TAMANHO; x++) // loop para leitura dos elementos de arr1
    {
        printf ("Digite o elemento %d de arr1:\n> ", x);
        scanf ("%d", &arr1[x]);
    }

    for (int x = 0; x < TAMANHO; x++) // loop para leitura dos elementos de arr2
    {
        printf ("Digite o elemento %d de arr2:\n> ", x);
        scanf ("%d", &arr2[x]);
    }

    for (int x = 0; x < TAMANHO; x++) // loop para associação de arr1 e arr2 à arr3
    {
        arr3[x + TAMANHO]= arr1[x];
        arr3[x] = arr2[x];
    }

    printf ("Valores de arr3:");

    for (int x = 0; x < (2 * TAMANHO); x++) // loop para exibir arr3
    {
        printf (" %d", arr3[x]);
    }
}