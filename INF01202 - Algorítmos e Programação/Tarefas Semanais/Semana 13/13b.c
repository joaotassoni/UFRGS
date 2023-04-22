/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOM 20
#define TAMNUM 20
#define TAMARQ 100

void le_arquivo (char nomeArquivo[], char v[]);
void escreve_arquivo (char nomeArquivo[], char v[]);
void separa_vetores (char str[], char pares[], char impares[]);
void inicializa_vetor (char v[], int tam);

int main () 
{
    char nomeArquivo[TAMNOM], str[TAMARQ];
    char pares[TAMARQ / 2], impares[TAMARQ / 2];
    
    inicializa_vetor (pares, TAMARQ / 2);// inicializa os vetores
    inicializa_vetor (impares, TAMARQ / 2);
    
    printf ("Informe o nome do arquivo a ser aberto:\n> ");
    fflush (stdin);
    fgets (nomeArquivo, TAMNOM, stdin);

    nomeArquivo[strcspn (nomeArquivo, "\n")] = '\0'; // remove a quebra de linha do nome lido

    le_arquivo (nomeArquivo, str);
    separa_vetores (str, pares, impares);

    escreve_arquivo ("pares.txt", pares); // passa os vetores para um arquivo de texto
    escreve_arquivo ("impares.txt", impares);
}

void le_arquivo (char nomeArquivo[], char v[]) // função que abre o arquivo, lê os dados e separa os vetores
{    
    char c;
    int x = 0;
    
    inicializa_vetor (v, TAMARQ);

    FILE *arq;
    arq = fopen (nomeArquivo, "rt"); // abre o arquivo para leitura

    if (arq == NULL) // verifica falha na abertura do arquivo e encerra a execução da função
    {
        printf ("Falha ao abrir o arquivo!");
        return;
    }

    while (!feof (arq)) // lê todos os caracteres do arquivo e armazena em uma string
    {
        fscanf (arq, "%c", &c);
        v[x] = c;     
        x++;
    }
    v[x - 1] = '\0'; // adiciona um caractere de fim de string

    fclose (arq);
}
 
void escreve_arquivo (char nomeArquivo[], char v[]) // passa uma string para um arquivo
{
    FILE *arq;

    arq = fopen (nomeArquivo, "wt"); // abre o arquivo para escrita

    fprintf (arq, "%s", v); // passa a string para o arquivo
    fclose (arq);
}

void separa_vetores (char str[], char pares[], char impares[]) // função que separa os números de uma string em uma string com os pares e outra com os ímpares
{
    int num, x = 0, y = 0;
    char snum[TAMNUM], aux[TAMNUM];

    inicializa_vetor (snum, TAMNUM);
    inicializa_vetor (aux, TAMNUM);
    
    while (str[x] != '\0') // verifica o caractere de fim de string na posição
    {
        if (str[x] == '\n') // verifica a quebra de linha e só incrementa o contador
            x++;
        else
        {
            do  // loop para passar o número para uma variável auxiliar e converter em um número
            {
                aux[y] = str[x];
                y++;
                x++;
            } while ((str[x] != '\n') && (str[x] != '\0'));
            y = 0;

            num = atoi(aux); // converte a string auxiliar em inteiro
            
            if (num % 2 == 0) // verifica se o número é par
            {
                strcat (pares, itoa (num, snum, 10)); // converte em string e concatena na string pares
                strcat (pares, "\n"); // concatena um espaço na string pares
            }
            else // se não for...
            {
                strcat (impares, itoa (num, snum, 10)); // converte em string e concatena na string ímpares
                strcat (impares, "\n"); // concatena um espaço na string ímpares
            }
        }
    }
    pares[strlen (pares) - 1] = '\0'; // adiciona um caractere de fim de string (removendo a quebra de linha que "sobra")
    impares[strlen (impares) - 1] = '\0';
}

void inicializa_vetor (char v[], int tam) // função para preencher as strings criadas
{
    for (int x = 0; x < tam; x++) // inicializa o vetor vazio
        v[x] = '\0';
}