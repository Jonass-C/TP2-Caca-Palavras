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
void palavras_buscar_inicial(TPalavra *palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias *ocorrenciasLetras);
void palavras_verificar_direcoes(TPalavra *palavra, int indice, TMatriz *matriz, TOcorrencias *ocorrenciaLetra, int qtdCoordenadas);
bool palavras_verificar_coordenada(int i, int j, TMatriz *matriz);
bool palavras_percorrer_direcoes(No *aux, TPalavra *palavra, int qtdLetras, int indice, int posInicialI, int posInicialJ, int *posFinalI, int *posFinalJ, int opcao);
void palavras_armazenar_coordenada(TPalavra *palavra, int indice, int posInicialI, int posInicialJ, int posFinalI, int posFinalJ);
void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras);

#endif