/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

void normaliza (int m_in[COLUNAS][LINHAS], float m_out[COLUNAS][LINHAS], int lin, int col);

int main ()
{

    int matrizInt[COLUNAS][LINHAS];
    float matrizFloat[COLUNAS][LINHAS];

    printf ("Digite os números da matriz de entrada seguidos de ENTER:\n"); // Faz a leitura da matriz de entrada
    for (int x = 0; x < COLUNAS; x++)
    {
        for (int y = 0; y < LINHAS; y++)
        {
            scanf("%d", &matrizInt[x][y]);
        }
        printf ("\n");
    }

    normaliza (matrizInt, matrizFloat, LINHAS, COLUNAS); // chama a função

    printf ("\nm_in:\n"); // exibe a matriz de entrada na saída
    for (int x = 0; x < COLUNAS; x++)
    {
        for (int y = 0; y < LINHAS; y++)
        {
            printf ("%d ", matrizInt[x][y]);
        }
        printf ("\n");
    }

    printf ("\nm_out:\n"); // exibe a matriz normalizada na saída
    for (int x = 0; x < COLUNAS; x++)
    {
        for (int y = 0; y < LINHAS; y++)
        {
            printf ("%.2f ", matrizFloat[x][y]);
        }
        printf ("\n");
    }

}

void normaliza (int m_in[COLUNAS][LINHAS], float m_out[COLUNAS][LINHAS], int lin, int col)
{
    int soma = 0;

    for (int x = 0; x < col; x++) // loop realiza a soma de todos os valores de m_in
    {
        for (int y = 0; y < lin; y++)
        {
            soma += m_in[x][y];
        }
    }

    for (int x = 0; x < col; x++) // loop normaliza os valores de m_in e passa para m_out
    {
        for (int y = 0; y < lin; y++)
        {
            m_out[x][y] = 1.0 * m_in[x][y] / soma;
        }
    }
}