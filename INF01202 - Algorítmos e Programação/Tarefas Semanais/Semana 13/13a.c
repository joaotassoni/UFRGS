#include <stdio.h>
#include <string.h>

#define TAMLIN 1000
#define TAMNAQ 20
#define TAMPAL 10

void dados (char nomeArquivo[], char palavra[]);
void le_arquivo (char nomeArquivo[], char palavra[]);
void inicializa_vetor (char v[], int tam);

int main ()
{
    char nomeArquivo[TAMNAQ], palavra[TAMPAL];
    
    dados (nomeArquivo, palavra);
    le_arquivo (nomeArquivo, palavra);
}

void dados (char nomeArquivo[], char palavra[])
{
    printf ("Informe o nome do arquivo a ser aberto:\n> "); // realiza a leitura do nome do arquivo
    fgets (nomeArquivo, TAMNAQ, stdin);

    nomeArquivo[strcspn (nomeArquivo, "\n")] = '\0'; // adiciona um caractere de quebra de linha ao fim da string

    printf ("Informe a palavra que você quer buscar no arquivo:\n> "); // realiza a leitura da palavra a ser buscada
    fgets (palavra, TAMPAL, stdin);

    palavra[strcspn (palavra, "\n")] = '\0'; // adiciona um caractere de quebra de linha ao fim da string
}

void le_arquivo (char nomeArquivo[], char palavra[]) // função que abre o arquivo, lê os dados e separa os vetores
{    
    char linha[TAMLIN];
    int nlinha = 1;
    
    inicializa_vetor (linha, TAMLIN);

    FILE *arq;
    arq = fopen (nomeArquivo, "rt"); // abre o arquivo para leitura

    if (arq == NULL) // verifica falha na abertura do arquivo e encerra a execução da função
    {
        printf ("Falha ao abrir o arquivo!");
        return;
    }

    while (fgets (linha, TAMLIN, arq) != NULL) // fgets puxa uma linha do arquivo para a variável "linha", enquanto não encontrar o fim do arquivo
    {
        if (strstr (linha, palavra) != NULL) // se encontrar uma correspondência à "palavra" dentro de "linha" 
            printf ("\nlinha: %d - texto: %s", nlinha, linha); // printa na tela o número da linha e o texto
        inicializa_vetor (linha, TAMLIN); // limpa o vetor "linha" para receber uma nova leitura
        nlinha++; // incrementa o contador de número de linhas
    }
    
   fclose (arq);
}

void inicializa_vetor (char v[], int tam) // função para preencher as strings criadas
{
    for (int x = 0; x < tam; x++) // inicializa o vetor vazio
        v[x] = '\0';
}