/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdbool.h>

int main ()
{
    int n;
    int x = 2, y = 0;
    bool primo;

    do // loop para verificar o valor n lido e repetir a leitura caso inválida
    {
        printf ("Digite um valor maior ou igual a 1:\n> ");
        scanf ("%d", &n);

        if (n < 1)
            printf ("\nValor invalido!\n");
    } while (n < 1);

    printf ("\nNúmeros primos entre 0 e n:");

    while (x < n) // loop para percorrer todos os valores de 2 até n
    {
        primo = true; // inicializa a variável que diz se o número atual é primo



        for (y = 2; y < x / 2; y++) // percorre os valores até a metade do número atual
        {
            if (x % y == 0) // verifica se número atual é divisível por qualquer número menor que sua metade
                primo = false;
        }

        if (primo == true) // se o número atual for primo, exibe o mesmo na tela
            printf (" %d", x);
        x++;
    }  
    
}