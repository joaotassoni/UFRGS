/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define NCARTAS 52

#define COPAS 1
#define OUROS 2
#define PAUS 3
#define ESPADAS 4

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

typedef struct
{
  int numero;
  int naipe;  
} carta;

void inicializa_baralho (carta baralho[NCARTAS]);
void imprime_cartas (carta baralho[], int tamanho);

int main ()
{
    carta baralho[NCARTAS];

    inicializa_baralho (baralho);
    imprime_cartas (baralho, NCARTAS);
}

void inicializa_baralho (carta baralho[NCARTAS]) // cria as baralho do baralho com número e naupe
{
    int z = 0; // controla a posição no vetor baralho

    for (int x = 1; x <= 4; x++) // controla os naipes
    {
        for (int y = 1; y <= 13; y++) // controla os valores das cartas
        {
            baralho[z].numero = y;
            baralho[z].naipe = x;         
            z++;
        }
    }
}

void imprime_cartas (carta v[], int tamanho) // exibe as cartas na tela
    {
    int x;

    for (x = 0; x < tamanho; x++) 
    { 
        if (v[x].naipe ==  COPAS) // imprime o símbolo do naipe na tela
            printf ("♥");
        else if (v[x].naipe == OUROS)
            printf ("♦");
        else if (v[x].naipe == PAUS)
            printf ("♣");
        else if (v[x].naipe == ESPADAS)
            printf ("♠");
        
        
        if (v[x].numero == ACE)
            printf("A "); // se o numero da carta for 1, exibe o ace (A)
         else if (v[x].numero == JACK)
            printf("J "); // se o número da carta for 11, exibe o jack (J) na tela
        else if (v[x].numero == QUEEN)
            printf("Q "); // se o número da carta for 12, exibe a queen (Q) na tela
        else if (v[x].numero == KING)
            printf("K "); // se o número da carta for 13, exibe o king (K) na tela
        else 
            printf ("%d ", v[x].numero); // se o número corresponder a uma carta numérica, exibe este número na tela
    }
}