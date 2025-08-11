#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H
#include "Matriz.h"

typedef struct {
    char letra;
    int qtd;
    TCoordenada *coordenadaLetra;
} TOcorrencias;

void ocorrencias_inicializar(TOcorrencias *ocorrenciasLetras);
void ocorrencias_calcular(TOcorrencias *ocorrenciasLetras, TMatriz *matriz);
int ocorrencias_apagar(TOcorrencias *ocorrenciasLetras);

#endif