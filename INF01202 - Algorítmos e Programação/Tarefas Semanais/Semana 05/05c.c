/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <math.h>

int main ()
{
    int m, numero, proximo = 0;

    printf ("Digite o número M:\n> ");
    scanf ("%d", &m);

    do 
    {
        printf ("\nDigite um número inteiro diferente de 0:\n> ");
        scanf ("%d", &numero);

        if (proximo == 0) // verifica se o loop está na primeira execução
        {
            proximo = numero;
        }  
        else if (numero == 0) // verifica se o loop está na última execução
        {
        }
        else if (abs (numero-m) < abs (proximo - m)) // verifica se o número digitado é mais próximo de M do que o que está armazenado na variável
        {
            proximo = numero;
        } 
    } while (numero != 0); // encerra o loop quando o usuário digita '0'

    printf ("O número mais proximo de %d digitado foi %d!", m, proximo);
}