/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMARQ 200
#define TAMNOM 15
#define TAMNUM 10
#define TAMEXB 8

void le_arquivo (char nomeArquivo[], char v[]);
void escreve_arquivo (char nomeArquivo[], char v[]);
void separa_numeros (char pares[], char impares[]);
void inicializa_vetor (char v[], int tam);

int main () 
{
    char nomeArquivo[TAMNOM], str_in[TAMARQ], str_out[TAMARQ];
    
    inicializa_vetor (str_in, TAMARQ); // inicializa os vetores
    inicializa_vetor (str_out, TAMARQ); // inicializa os vetores
    
    printf ("Informe o nome do arquivo a ser aberto:\n> "); // lê o nome do arquivo
    fflush (stdin);
    fgets (nomeArquivo, TAMNOM, stdin);

    nomeArquivo[strcspn (nomeArquivo, "\n")] = '\0'; // remove a quebra de linha do nome lido

    le_arquivo (nomeArquivo, str_in);
    separa_numeros (str_in, str_out);
    escreve_arquivo ("areas.txt", str_out); // escreve as áreas calculadas em um arquivo "áreas.txt"
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

void separa_numeros (char str_in[], char str_out[]) // função que separa os números de uma string em uma string com os pares e outra com os ímpares
{   
    float num = 0;
    int x = 0, y = 0;
    char snum[TAMNUM], aux[TAMNUM];

    inicializa_vetor (snum, TAMNUM);
    inicializa_vetor (aux, TAMNUM);
    
    while (str_in[x] != '\0') // verifica o caractere de fim de string na posição
    {
        if ((str_in[x] == '\n') || (str_in[x] == ';') || ((str_in[x] == ' '))) // verifica o caractere e pula quebra de linha, ponto e vírgula e espaço (só incrementa o contador)
            x++;
        else
        {
            do  // loop para passar o número para uma variável auxiliar e converter em um número
            {
                aux[y] = str_in[x];
                y++;
                x++;
            } while ((str_in[x] != '\n') && (str_in[x] != '\0') && (str_in[x] != ';'));
            y = 0;

            if (num == 0)
                num = atof(aux); // converte a string auxiliar em flutuante
            else 
            {
                num = num * atof(aux); // faz a multiplição do valor armazenado anteriormente e do recém convertido (calcula a área)
                
                inicializa_vetor (aux, TAMNUM); // limpa o vetor auxiliar
                
                gcvt (num, TAMEXB, aux); // converte a área calculada de flutuante para string
                strcat (str_out, aux); // concatena a string da área na string de saída
                strcat (str_out, "\n"); // concatena uma quebra de linha na string de saída

                inicializa_vetor (aux, TAMNUM); // limpa o vetor auxiliar
                num = 0; // limpa a variável de cálculo
            }            
        }
    }
    str_out [strlen (str_out) - 1] = '\0'; // adiciona um caractere de fim de string (removendo a quebra de linha que "sobra")
}

void inicializa_vetor (char v[], int tam) // função para preencher as strings criadas
{
    for (int x = 0; x < tam; x++) // inicializa o vetor vazio
        v[x] = '\0';
}