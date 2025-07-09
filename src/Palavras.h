#ifndef PALAVRAS_H
#define PALAVRAS_H
#include "Matriz.h"
#include "Ocorrencias.h"

typedef struct {
    char *palavra;
    TCoordenada coordenadaInicial;
    TCoordenada coordenadaFinal;
} TPalavra;

int palavras_add(TPalavra *palavras, int qtdPalavras);
TPalavra palavra_criar(char *palavra);
void palavras_buscar_inicial(TPalavra *palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias *ocorrenciasLetras);
//void palavras_buscar(...);
void palavras_imprimir(TPalavra *palavras, int qtdPalavras); //PROVISÓRIA
void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras);

#endif