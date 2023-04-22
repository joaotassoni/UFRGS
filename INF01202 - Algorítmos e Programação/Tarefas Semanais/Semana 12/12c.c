/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <string.h>

#define TNOME 20

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

void imprime_cartas (carta baralho[NCARTAS], int tamanho);
int carrega_estado (carta baralho[], int tamanho);

int main ()
{
    carta baralho[NCARTAS];
    int tamanho = carrega_estado (baralho, NCARTAS);

    if (tamanho == -1) // verifica a leitura do arquivo
        printf ("Leitura inválida!");
    else // imprime o baralho na tela
        imprime_cartas (baralho, tamanho);

}

int carrega_estado (carta baralho[], int tamanho)
{
    char nome[TNOME];
    FILE *arq;

    printf ("Digite o nome do arquivo:\n> ");
    fflush (stdin); // limpa o buffer do teclado
    fgets (nome, TNOME, stdin); // faz a leitura do nome

    nome[strcspn (nome, "\n")] = '\0'; // substitui o caractere de quebra de linha que o fgets recebe por um caractere de fim de string 

    arq = fopen (nome, "rb"); // abre o arquivo para leitura
    
    if (arq != NULL)
    {        
        fread(&tamanho, sizeof(int), 1, arq); // lê o tamanho
        for (int x = 0; x < NCARTAS; x ++) // loop lê cada carta individual do baralho
        {
            fread(&baralho[x], sizeof(carta),  1, arq);
        }

        fclose (arq); // fecha o arquivo

        printf ("\nLido com sucesso!\n");
        return (tamanho);
    }
    else
    {
        fclose (arq); // fecha o arquivo
        return -1;
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