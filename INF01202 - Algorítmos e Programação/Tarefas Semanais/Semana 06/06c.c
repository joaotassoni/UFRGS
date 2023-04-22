/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <string.h>

#define ATLETAS 6
#define TNOME 20

int main ()
{
    char nomeAtleta[ATLETAS][TNOME];
    int gols[ATLETAS];
    int goleador = 0;

    for (int x = 0; x < ATLETAS; x++)
    {
        printf ("Digite o nome do atleta: ");
        fflush (stdin); // limpa o buffer do teclado
        fgets (nomeAtleta[x], TNOME, stdin); // lê o nome do atleta (até 20 caracteres)

        nomeAtleta[x][strcspn (nomeAtleta[x], "\n")] = '\0'; // substitui o caractere de quebra de linha que o fgets recebe por um caractere de fim de string 

        printf ("Digite os gols do atleta: ");
        scanf ("%d", &gols[x]);

        if (gols[x] > gols[goleador]) // caso o número de gols do atleta atual seja maior do que o goleador definido, substitui a posição do goleador no vetor
            goleador = x;
    }

    printf ("\nGoleador foi %s com %d gols", nomeAtleta[goleador], gols[goleador]);
}