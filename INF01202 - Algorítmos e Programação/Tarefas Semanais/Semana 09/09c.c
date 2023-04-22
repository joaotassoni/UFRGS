/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdbool.h>

bool localizador (int x1, int y1, int x2, int y2, int x3, int y3);

int main ()
{
    int pontos[3][2];

    for (int x = 0; x < 3; x++) // loop que realiza a leitura das coordenadas
    {
        printf ("Digite a coordenada x do ponto %d: ", x+1);
        scanf ("%d", &pontos[x][0]);
        printf ("Digite a coordenada y do ponto %d: ", x+1);
        scanf ("%d", &pontos[x][1]);
    }

    if (localizador (pontos[0][0], pontos[0][1], pontos[1][0], pontos[1][1], pontos[2][0], pontos[2][1]) == 1)
        printf ("O ponto 3 ESTÁ dentro do retangulo!"); // chama a função e verifica seu retorno para saber se o ponto está ou não no retângulo
    else
        printf ("O ponto 3 NÃO ESTÁ dentro do retangulo!");
}

bool localizador (int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ((x3 >= x1) && (y3 >= y1) && (x3 <= x2) && (y3 <= y2)) // verifica as coordenadas para saber se x1<x3<x2 e y1<y3<y2, localizando  p3 em relação a p1 e p2
        return 1;
    else
        return 0;
}