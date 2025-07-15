#include <stdio.h>
#include <stdlib.h>
#include "Coordenada.h"
#include "Matriz.h"
#include "Ocorrencias.h"
#include "Palavras.h"

int main(int argc, char** argv) {
    
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    
    TMatriz *matriz = matriz_criar(linhas, colunas);
    matriz_preencher_nos(matriz);
    
    TOcorrencias ocorrenciasLetras[26];
    ocorrencias_calcular(ocorrenciasLetras, matriz);
    
    int qtdPalavras;
    scanf("%d", &qtdPalavras);
    
    TPalavra palavras[qtdPalavras];
    palavras_adicionar(palavras, qtdPalavras);
    
    palavras_buscar_inicial(palavras, qtdPalavras, ocorrenciasLetras, matriz);
    palavras_imprimir_solucao(palavras, qtdPalavras);
    
    matriz_apagar(matriz);
    ocorrencias_apagar(ocorrenciasLetras);
    
    return (EXIT_SUCCESS);
    
}