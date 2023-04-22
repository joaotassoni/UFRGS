/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define TAMANHO 5

int testaIntersec (int t, int v1[], int v2[], int v3[]);

int main ()
{
    int vetores[3][TAMANHO];
    int tam = TAMANHO, interseccao = 0;
    
    printf ("v1:\n"); // realiza a leitura do vetor 1
    for (int x = 0; x < tam; x++) 
    {
        scanf ("%d", &vetores[0][x]);     
    }
    
    printf ("\nv2:\n"); // realiza a leitura do vetor 2
    for (int x = 0; x < tam; x++)
    {
        scanf ("%d", &vetores[1][x]);     
    }

    interseccao = testaIntersec (tam, vetores[0], vetores[1], vetores[2]); // chama a função

    printf ("\nv3:"); // imprime na tela os valores do vetor 3
    for (int x = 0; x < interseccao; x++) {
        printf (" %d", vetores[2][x]);
    }
    printf ("\nA intersecção dos conjuntos possui %d elementos!", interseccao);
}

int testaIntersec (int t, int v1[], int v2[], int v3[])
{
    int z = 0;

    for (int x = 0; x < t; x++) // loop percorre todas as posições de v1 e v2
    {
        for (int y = 0; y < t; y++)
        {
            if (v1[x] == v2[y]) // compara v1 e v2 nas posições determinadas
            {
                v3[z] = v1[x]; // manda a intersecção para v3 e contabiliza a mesma
                z++;
            }
        }
    }

    return z;
}