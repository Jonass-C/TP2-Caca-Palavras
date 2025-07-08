#ifndef PALAVRAS_H
#define PALAVRAS_H

#include "Matriz.h"
#include "Ocorrencias.h"

typedef struct {
    char *palavra;
    TCoordenada coordInicial;
    TCoordenada coordFinal;
} TPalavra;

int palavras_add(TPalavra **palavras, int qtdPalavras);
TPalavra palavra_criar(char *palavra);
void palavras_buscar_inicial(TPalavra **palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias **ocorrencias);
void palavras_imprimir(TPalavra **palavras, int qtdPalavras); //PROVISÓRIA
void palavras_imprimir_solucao(TPalavra **palavras, int qtdPalavras);
int palavras_apagar(TPalavra **palavras, int qtdPalavras);


#endif /* PALAVRAS_H */