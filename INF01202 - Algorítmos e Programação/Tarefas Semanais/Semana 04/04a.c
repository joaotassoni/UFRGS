/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int main ()
{

    int codigo, quantidade;
    float valor, valorTotal;

    printf ("Digite o código do item desejado:\n> ");
    scanf ("%d", &codigo);

    if (codigo == 100) // verifica o código lido e define o preço do produto
            valor = 13;
    else if (codigo == 101)
            valor = 17;
    else if (codigo == 104)
            valor = 18;
    else if (codigo == 105)
            valor = 21;
    else if (codigo == 110)
            valor = 24;
    else if (codigo == 120)
            valor = 4;
    else // se o código for inválido, encerra a execução do programa
    {
        printf ("Código Invalido!");
        return 0;
    }

    printf ("\nDigite a quantidade do item desejado:\n> ");
    scanf ("%d", &quantidade);

    valorTotal = (valor * quantidade); // calcula o preço total

    printf ("\nValor a ser pago: R$%.2f", valorTotal);

}