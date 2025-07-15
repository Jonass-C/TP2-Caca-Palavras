#ifndef PALAVRAS_H
#define PALAVRAS_H
#include "Coordenada.h"
#include "Matriz.h"
#include "Ocorrencias.h"
#include <stdbool.h>

typedef struct {
    char *palavra;
    TCoordenada coordenadaInicial;
    TCoordenada coordenadaFinal;
} TPalavra;

int palavras_adicionar(TPalavra *palavras, int qtdPalavras);
void palavras_buscar_inicial(TPalavra *palavras, int qtdPalavras, TOcorrencias *ocorrenciasLetras, TMatriz *matriz);
void palavras_verificar_direcoes(TPalavra *palavra, int indice, TMatriz *matriz, TOcorrencias *ocorrenciaLetra, int qtdCoordenadas);
bool palavras_verificar_coordenada(int i, int j, TMatriz *matriz);
void palavras_percorrer_direcoes(No *aux, TPalavra *palavra, int qtdLetras, int indice, TCoordenada posInicial, TCoordenada *posFinal, int opcao);
void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras);

#endif