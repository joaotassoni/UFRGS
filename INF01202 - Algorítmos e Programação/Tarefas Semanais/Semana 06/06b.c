/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define CAVALOS 5
#define TNOME 15

int main ()
{
    char nomeCavalo[CAVALOS + 1][TNOME];
    int d, dmp;
    int posicaoCavalo[CAVALOS + 1];

    bool finalizou = false;
    

    for (int x = 0; x <= CAVALOS; x ++) // inicializa a posição dos cavalos em 0 
    {
        posicaoCavalo[x] = 0;
    }

    printf ("Informe o comprimento da pista (em m):\n> ");
    scanf ("%d", &d);

    printf ("Informe a distância maxima do passo de um cavalo (em m):\n> ");
    scanf ("%d", &dmp);

    for (int x = 0; x < CAVALOS; x++) // recebe os nomes dos cavalos
    {
        printf ("Informe o nome do cavalo %d:\n> ", x+1);
        fflush (stdin); // limpa o buffer do teclado
        fgets (nomeCavalo[x], TNOME, stdin);

        nomeCavalo[x][strcspn (nomeCavalo[x], "\n")] = '\0'; // substitui o caractere de quebra de linha que o fgets recebe por um caractere de fim de string 
    }

    dmp--;

    do // loop para atualizar a posição dos cavalos
    {
        for (int x = 0; x < CAVALOS; x++)
        {
            srand((clock () * x)); // inicializa o sorteador com o valor dos clocks do computador desde o início do código
            posicaoCavalo[x] += ((rand () % (dmp))+1);// sorteia um número entre 0 e DMP

            if (posicaoCavalo[x] >= d) // caso algum cavalo cruze a linha de chegada, encerra o loop
                {
                    x = CAVALOS;
                    finalizou = true;
                }
        }
    } while (finalizou == false); // mantém o loop enquanto nenhum cavalo finalizar a corrida
    
    do // algorítmo bubblesort para organizar o pódio
    {
        finalizou = true;
        for (int x = 0; x < CAVALOS - 1; x++)
            if (posicaoCavalo[x + 1] > posicaoCavalo[x]) { // se o número da posição+1 for maior que o número da posição 
                posicaoCavalo[CAVALOS] = posicaoCavalo[x];  // variável auxiliar recebe a distância percorrida desta posição
                strcpy (nomeCavalo[CAVALOS], nomeCavalo[x]); // variável auxiliar recebe o nome desta posição

                posicaoCavalo[x] = posicaoCavalo[x + 1]; // a distância percorrida na posição é substituida pela distância percorrida da posição+1
                strcpy (nomeCavalo[x], nomeCavalo[x + 1]); // o nome na posição é substituido pelo nome na posição+1

                posicaoCavalo[x + 1] = posicaoCavalo[CAVALOS]; // a distância percorrida na posição+1 é substituida pela distância percorrida salva na variável auxiliar
                strcpy (nomeCavalo[x + 1], nomeCavalo[CAVALOS]); // o nome na posição+1 é substituido pelo nome salvo na variável auxiliar
                
                finalizou = false;
            }
    } while (finalizou == false); // continua rodando até que sinal true (ou seja, a condição para entrar no if não se cumpra, indicando que a varredura terminou)

    printf ("\ncavalo - distância percorrida\n\n"); // imprime na tela o pódio
    for (int x = 0; x < CAVALOS; x++)
    {
        printf ("%s - %dm\n", nomeCavalo[x], posicaoCavalo[x]);
    } 
    
}