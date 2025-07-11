#ifndef MATRIZ_H
#define MATRIZ_H
#include "Coordenada.h"

typedef struct No{
    struct No *direita, *esquerda, *abaixo, *cima;
    int i, j;
    char letra;
} No;

typedef struct {
    int linhas;
    int colunas;
    No **cabecaLinhas;
    No **cabecaColunas;
} TMatriz;

TMatriz *matriz_criar(int linhas, int colunas);
int matriz_preencher(TMatriz *matriz);
void matriz_imprimir(TMatriz *matriz);
int matriz_apagar(TMatriz *matriz);
No *no_letra_inicial(TMatriz *matriz, int posI, int posJ);

#endif