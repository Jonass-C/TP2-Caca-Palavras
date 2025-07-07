
#include <stdio.h>
#include <stdlib.h>

#include "Matriz.h"
#include "Ocorrencias.h"
#include "Palavras.h"

int main(int argc, char** argv) {
    
    // pedir ao usuário o n° de linhas e colunas
    int m, n;
    scanf("%d %d", &m, &n);
    
    // criar matriz vazia com células cabeças de linhas e colunas
    TMatriz *matriz = matriz_criar(m, n);
    
    // pedir ao usuário para preencher a matriz
    matriz_preencher(matriz);
    
    // imprimir a matriz
    matriz_imprimir(matriz);
    
    // armazenando as posições em que cada letra aparece
    TOcorrencias *ocorrenciasLetras[26];
    ocorrencias_calcular(ocorrenciasLetras, matriz);
    
    // vendo as ocorrencias
    ocorrencias_imprimir(ocorrenciasLetras);

    // pedir ao usuário a qtd de palavras na matriz
    // pedir ao usuário para digitar as palavras
    // armazenar as palavras digitadas
    
    return (EXIT_SUCCESS);
}

