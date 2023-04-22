/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdbool.h>

#define N 5

int main ()
{
    int matriz[N][N] = // Inicializa a matriz com os valores definidos no exemplo
    {
        {0, 33, -1, -1, 15},
        {33, 0, 60, 20, 32},
        {-1, 60, 0, 50, -1},
        {-1, 20, 50, 0, 50},
        {15, 32, -1, 50, 0}
    };

    int vetor[N];
    bool possivel = true;

    printf ("Informe um trajeto: \n");
    
    for (int x = 0; x < N; x++)  // loop para ler o trajeto
    {
        printf ("Cidade %d: ", x+1);
        scanf ("%d", &vetor[x]);
    }

    for (int x = 0; x < N-1; x++) // loop para verificar a matriz com os valores do trajeto lidos
    {
        if (matriz[vetor[x]][vetor[x+1]] < 0) // verifica se algum trajeto é impossível verificando as posições da matriz
            possivel = false;
    }

    if (possivel == true)
        printf ("O trajeto é possivel!");
    if (possivel == false)
        printf ("O trajeto não é possivel!");
}