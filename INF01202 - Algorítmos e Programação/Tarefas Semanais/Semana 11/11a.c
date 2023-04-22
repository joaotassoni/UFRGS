/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <string.h>

#define JOGADORES 5

typedef struct 
{
    char nome[20];
    int pontuacao;
} jogador;

void bubblesort (jogador v[], int tamanho); // protótipo das funções
void exibePontuacoes (jogador vetor[], int tamanho);

int main ()
{
    jogador info[JOGADORES];

    for (int x = 0; x < JOGADORES; x++)
    {
        printf ("\nDigite o nome do jogador %d:\n> ", x+1); // lê a string com o nome do jogador correspondente
        fflush (stdin);
        fgets (info[x].nome, 20, stdin);
        
        printf ("\nDigite a pontuacao do jogador %d:\n> ", x+1); // lê o valor da pontuação do jogador correspondente
        scanf ("%d", &info[x].pontuacao);
    }

    bubblesort (info, JOGADORES);
    
    printf ("\nPontuacoes:\n");
    exibePontuacoes (info, JOGADORES);
}

void bubblesort (jogador v[], int tamanho) // função que ordena um vetor de inteiros do menor para o maior
{ 
    int sinal, aux;
    char nomeaux[20];
    
    do {
        sinal = 0;
        for (int x = 0; x < tamanho - 1; x++)
            if (v[x + 1].pontuacao > v[x].pontuacao) { // se o número da posição+1 for maior que o número da posição 
                aux = v[x].pontuacao;  // variável auxiliar recebe a pontuação desta posição
                strcpy (nomeaux, v[x].nome); // variável auxiliar recebe o nome desta posição

                v[x].pontuacao = v[x + 1].pontuacao; // a pontuação na posição é substituida pela pontuação da posição+1
                strcpy (v[x].nome, v[x + 1].nome); // o nome na posição é substituido pelo nome na posição+1

                v[x + 1].pontuacao = aux; // a pontuação na posição+1 é substituida pela pontuação salva na variável auxiliar
                strcpy (v[x + 1].nome, nomeaux); // o nome na posição+1 é substituido pelo nome salvo na variável auxiliar
                
                sinal = 1; // sinal recebe 1
            }
    } while (sinal == 1); // continua rodando até que sinal seja diferente de 1 (ou seja, a condição para entrar no if não se cumpra, indicando que a varredura terminou)
}

void exibePontuacoes (jogador vetor[], int tamanho) // função que exibe na tela os dados de um vetor do tipo jogador
{
    for(int x = tamanho-1; x >= 0; x--) {
        printf ("\n%s - %d", vetor[x].nome, vetor[x].pontuacao);
    }
}