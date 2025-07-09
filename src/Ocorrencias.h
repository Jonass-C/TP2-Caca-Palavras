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
    TCoordenada *coordenadaLetra;
} TOcorrencias;

void ocorrencias_calcular(TOcorrencias *ocorrenciasLetras, TMatriz *matriz); 
void ocorrencias_adicionar(TOcorrencias *ocorrenciasLetras, TMatriz *matriz); 
void ocorrencias_imprimir(TOcorrencias *ocorrenciasLetras);
int ocorrencias_apagar(TOcorrencias *ocorrenciasLetras); 

#endif