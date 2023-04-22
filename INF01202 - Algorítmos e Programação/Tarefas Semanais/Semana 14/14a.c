/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

#define N 5 // número de elementos do vetor

int func (int vetor[], int nelementos) {

    nelementos--; // Decrementa o número de elementos
    if (nelementos >= 0) { // Se o número de elementos for maior ou igual a 0

        if (vetor[nelementos] % 2 == 0) // verifica se o número é par
            return (1 + func(vetor, nelementos)); // retorna 1 + a função (parra para o próximo valor incrementando a saída)
        else
            return func (vetor, nelementos); // retorna somente a função (passa para o próximo valor sem incrementar a saída)
    }
    else
        return 0; // encerra a execução
}

int main () {
    int vetor[N];
    
    for (int x = 0; x < N; x++) { // faz a leitura dos elementos do vetor
        printf ("\nDigite o elemento %d do vetor:\n> ", x);
        scanf ("%d", &vetor[x]);
    }

    printf("\n\n%d número(s) pare(s) digitado(s)!", func(vetor, N)); // imprime na tela o número de números pares do vetor
}