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

void inicializa_baralho (carta baralho[]);
void salva_estado (carta baralho[], int tamanho);

int main ()
{
    carta baralho[NCARTAS];

    inicializa_baralho (baralho); // chama as funções
    salva_estado (baralho, NCARTAS);
}


void inicializa_baralho (carta baralho[]) // cria as baralho do baralho com número e naupe
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

void salva_estado (carta baralho[], int tamanho)
{
    char nome[TNOME];
    FILE *arq;

    printf ("Digite o nome do arquivo:\n> ");
    fflush (stdin);
    fgets (nome, TNOME, stdin); // faz a leitura do nome

    nome[strcspn (nome, "\n")] = '\0'; // substitui o caractere de quebra de linha que o fgets recebe por um caractere de fim de string 

    arq = fopen (nome, "wb"); // abre o arquivo para escrita
    
    if (arq != NULL)
    {
        fwrite (&tamanho, sizeof(int), 1, arq);
        for (int x = 0; x < NCARTAS; x++) // loop escreve no arquivo cada carta do baralho
        {
            fwrite (&baralho[x], sizeof(carta), 1, arq);
        }
        
        
        printf ("\nSalvo com sucesso!");
    } 

    fclose (arq); // fecha o arquivo
}