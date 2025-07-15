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
void matriz_adicionar_nos(TMatriz *matriz);
int matriz_preencher_nos(TMatriz *matriz);
int matriz_apagar(TMatriz *matriz);
No *no_letra_inicial(TMatriz *matriz, TCoordenada posicao);

#endif