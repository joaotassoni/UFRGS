/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define TAMANHO 5

int main ()
{
    int v1[TAMANHO], v2[TAMANHO], m1[4][TAMANHO];

    printf ("Digite os valores de v1 seguidos de ENTER:\n");
    for (int x = 0; x < TAMANHO; x++) // loop para ler valores de v1
    {
        scanf ("%d", &v1[x]);
    }
    printf ("Digite os valores de v2 seguidos de ENTER:\n");
    for (int x = 0; x < TAMANHO; x++) // loop para ler valores de v2
    {
        scanf ("%d", &v2[x]);
    }

    for (int x = 0; x < TAMANHO; x++)
    {
        m1[0][x] = v1[x]; // passa os valores de v1 para a primeira linha de m1
        m1[1][x] = v2[x] * v2[x]; // passa os valores de v2 ao quadrado para a segunda linha de m1
        m1[2][x] = v1[x] * v2[x]; // passa o valor de v1*v2 na posição especificada para a terceira linha de m1
        
        if ((v1[x] % 2 == 0)&&(v2[x] % 2 == 0)) // preenche a quarta linha de m1 com um valor dependendo da condição (2 pares, 2 ímpares, outro)
            m1[3][x] = 0;
        else if ((v1[x] % 2 != 0)&&(v2[x] % 2 != 0))
            m1[3][x] = 1;
        else   
            m1[3][x] = 2;
    }

    printf ("\nMatriz:\n");

    for (int x = 0; x < 4; x++) // loop para exibir a matriz m1
    {
        for (int y = 0; y < TAMANHO; y++)
        {
            printf ("%d ", m1[x][y]);
        }
        printf ("\n");
    }
}