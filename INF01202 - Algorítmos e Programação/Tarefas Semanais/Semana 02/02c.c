/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{
    int quantidadeChapas;
    float larguraChapas, comprimentoChapas, areaLata, custoLata;
    
    int quantidadeLatas;
    float custoTotal;

    printf ("Digite o número de chapas que deseja pintar:\n> ");
    scanf ("%d", &quantidadeChapas);

    printf ("\nDigite a largura de uma chapa:\n> ");
    scanf ("%f", &larguraChapas);

    printf ("\nDigite o comprimento de uma chapa:\n> ");
    scanf ("%f", &comprimentoChapas);

    printf ("\nDigite quantos metros quadrados uma lata de tinta pinta:\n> ");
    scanf ("%f", &areaLata);

    printf ("\nDigite o custo de uma lata de tinta (R$):\n> ");
    scanf ("%f", &custoLata);

    quantidadeLatas = ceil (quantidadeChapas * (larguraChapas * comprimentoChapas) / areaLata);
    custoTotal = (quantidadeLatas * custoLata);

    printf("\nVocê irá precisar de %d latas", quantidadeLatas);
    printf("\nO custo será de R$ %.2f", custoTotal);
}