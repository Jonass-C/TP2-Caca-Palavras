
#ifndef MATRIZ_H
#define MATRIZ_H

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

TMatriz *matriz_criar(int m, int n);
int matriz_preencher(TMatriz *matriz);
void matriz_imprimir(TMatriz *matriz);
int matriz_apagar(TMatriz *matriz);

#endif /* MATRIZ_H */
