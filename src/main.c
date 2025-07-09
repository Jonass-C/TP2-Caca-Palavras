#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Ocorrencias.h"
#include "Palavras.h"

int main(int argc, char** argv) {
    
    // pedir ao usuário o n° de linhas e colunas
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    
    // criar matriz vazia com células cabeças de linhas e colunas
    TMatriz *matriz = matriz_criar(linhas, colunas);
    
    // pedir ao usuário para preencher a matriz
    matriz_preencher(matriz);
    
    // imprimir a matriz
    matriz_imprimir(matriz);
    
    // armazenando as posições em que cada letra aparece
    TOcorrencias ocorrenciasLetras[26];
    ocorrencias_calcular(ocorrenciasLetras, matriz);
    
    // vendo as ocorrencias
    ocorrencias_imprimir(ocorrenciasLetras);
    printf("\n");

    // pedir ao usuário a qtd de palavras na matriz
    int qtdPalavras;
    scanf("%d", &qtdPalavras);
    
    TPalavra palavras[qtdPalavras];
    
    // pedir ao usuário para digitar as palavras e armazená-las
    palavras_add(palavras, qtdPalavras);
    
    // impressão das palavras digitadas
    palavras_imprimir(palavras, qtdPalavras);
    
    // teste da verificação da primeira letra de cada palavra
    palavras_buscar_inicial(palavras, matriz, qtdPalavras, ocorrenciasLetras);
    
    // buscar palavra completa e printar coordenadas
    // busca é feita pela palavra_buscar(), printar coordenadas é palavras_imprimir_solucao()
    
    // formatar corretamente o main
    
    return (EXIT_SUCCESS);
}
/*
int main(){
    // COLAR CÓDIGOS NA MAIN, POSTERIORMENTE
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    
    TMatriz *matriz = matriz_criar(linhas, colunas);
    matriz_preencher(matriz);
    
    TOcorrencias ocorrenciasLetras[26];
    ocorrencias_calcular(ocorrenciasLetras, matriz);
    
    int qtdPalavras;
    scanf("%d", &qtdPalavras);
    
    TPalavra palavras[qtdPalavras];
    palavras_add(palavras, qtdPalavras);
    
    palavras_buscar_inicial(palavras, matriz, qtdPalavras, ocorrenciasLetras);
    palavras_imprimir_solucao(palavras, qtdPalavras);
    
    matriz_apagar(matriz);
    ocorrencias_apagar(ocorrenciasLetras);
}
*/