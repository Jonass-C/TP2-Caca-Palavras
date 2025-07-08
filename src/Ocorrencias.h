#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H

#include "Matriz.h"

typedef struct {
    int i;
    int j;
} TCoordenada;

typedef struct {
    char letra;
    int qtd;
    TCoordenada *coordLetra;
} TOcorrencias;

void ocorrencias_calcular(TOcorrencias **ocorrencias, TMatriz *matriz); 
void ocorrencias_adicionar(TOcorrencias **ocorrencias, TMatriz *matriz); 
void ocorrencias_imprimir(TOcorrencias **ocorrencias);
int ocorrencias_apagar(TOcorrencias **ocorrencias); 

#endif /* OCORRENCIAS_H */