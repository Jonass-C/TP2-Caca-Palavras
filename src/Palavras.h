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

int palavras_add(TPalavra *palavras, int qtdPalavras);
TPalavra palavra_criar(char *palavra);
void palavras_buscar_inicial(TPalavra *palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias *ocorrenciasLetras);
void palavras_buscar(TPalavra *palavra, TMatriz *matriz, TOcorrencias *ocorrenciaLetra, int qtdCoordenadas, int indice, char primeiraLetra);
bool palavra_verificar_coordenada(int i, int j, TMatriz *matriz);
void palavra_armazenar_coordenada(TPalavra *palavra, int indice, int posInicialI, int posInicialJ, int posFinalI, int posFinalJ);
void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras);

#endif