/*
INF01202 - Algorítmos e Programação - 2020/1

Aluno: João Pedro Tassoni
Turma: I
*/

#include <stdio.h>

float contaMinutos (int h, int m, int s); // declara o protótipo da função

int main ()
{
    int horas, minutos, segundos;
    float minutosDecorridos;


    printf ("Informe a hora: ");
    scanf ("%d", &horas);
    printf ("Informe os minutos: ");
    scanf ("%d", &minutos);
    printf ("Informe os segundos: ");
    scanf ("%d", &segundos);

    minutosDecorridos = contaMinutos (horas, minutos, segundos);

    if (minutosDecorridos < 0)
        printf ("Horário invalido!");
    else 
        printf ("Total de minutos decorridos: %.2f", minutosDecorridos);
}

float contaMinutos (int h, int m, int s)
{
    if (((h > 24) || (m > 60) || (s > 60)) || ((h < 0) || (m < 0) || (s < 0)))
        return -1; // verifica se os valores recebidos são válidos

    float somaMinutos = ((h * 60.0) + (m) + (s / 60.0)); // converte os valores para minutos e os soma 
    return somaMinutos; // devolve o valor da soma
}