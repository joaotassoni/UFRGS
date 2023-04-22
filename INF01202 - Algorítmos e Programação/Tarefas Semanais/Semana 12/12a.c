/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <string.h>

#define TNOME 20

int main () {
    char nome[TNOME];
    FILE *arq;

    int inteiro;
    float flutuante;
    char caractere;

    printf ("Digite o nome do arquivo:\n> ");
    fflush (stdin);
    fgets (nome, TNOME, stdin); // faz a leitura do nome

    nome[strcspn (nome, "\n")] = '\0'; // substitui o caractere de quebra de linha que o fgets recebe por um caractere de fim de string 

    arq = fopen (nome, "rb"); // abre o arquivo para leitura
    
    if (arq != NULL)
    {
        printf ("\n\nAbrindo arquivo!");

        fread(&inteiro, sizeof(int), 1, arq); // lê o int no arquivo
        fread(&flutuante, sizeof(float), 1, arq); // lê o float no arquivo
        fread(&caractere, sizeof(char), 1, arq); // lê o char no arquivo
    
        printf ("\ninteiro = %d", inteiro); // escreve na tela os dados lidos do arquivo
        printf ("\nflutuante = %.4f", flutuante);
        printf ("\ncaractere = %c", caractere);
    }
    else
    {
        fclose (arq);  // fecha o arquivo 

        printf ("\n\nCriando arquivo!\n");
        arq = fopen (nome, "wb"); // abre o arquivo para escrita (se não existe, cria um)

        printf ("Digite um inteiro:\n> ");
        scanf ("%d", &inteiro); // lê um int

        printf ("Digite um flutuante:\n> ");
        scanf ("%f", &flutuante); // lê um float
        
        fflush(stdin); // limpa o buffer do teclado

        printf ("Digite um caractere:\n> ");
        scanf(" %c",&caractere); // lê um char

        fwrite(&inteiro, sizeof(inteiro), 1, arq);
        fwrite(&flutuante, sizeof(flutuante), 1, arq);
        fwrite(&caractere, sizeof(caractere), 1, arq); // escreve no arquivo as leituras anteriores    
    } 

    fclose (arq); // fecha o arquivo
}