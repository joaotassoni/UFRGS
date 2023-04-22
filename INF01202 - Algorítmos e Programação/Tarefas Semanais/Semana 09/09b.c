/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

int menor2 (int numero1, int numero2); // protótipos das funções
int menor3 (int numero1, int numero2, int numero3);

int main ()
{
    int n1, n2, n3, mn;

    printf ("Digite o numero 1: ") ; // lê os nýumeros
    scanf ("%d", &n1);
    printf ("\nDigite o numero 2: ");
    scanf ("%d", &n2);
    printf ("\nDigite o numero 3: ");
    scanf ("%d", &n3);

    mn = menor3 (n1, n2, n3); // chama a função e recebe o retorno em uma variável

    printf ("O menor número digitado foi %d", mn); // exibe na tela o menor número digitado
}

int menor2 (int numero1, int numero2)
{
    if (numero1 < numero2) // compara 2 números e retorna o menor deles
        return numero1;
    else
        return numero2;
}

int menor3 (int numero1, int numero2, int numero3)
{
    int menorNumero;

    menorNumero = menor2 (numero1, numero2); // compara os números 1 e 2
    if (menor2 (numero2, numero3) < menorNumero) // compara o resultado anterior com o menor entre os números 2 e 3
        menorNumero = menor2 (numero2, numero3);
    
    return menorNumero; // retorna o menor número dos 3 inseridos
}