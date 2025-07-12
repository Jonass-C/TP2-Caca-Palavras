#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include <ctype.h>

TMatriz *matriz_criar(int linhas, int colunas){
    
    if(linhas <= 0 || colunas <= 0){
        printf("Valores inválidos.");
        return(0);
    }
    
    TMatriz *matriz = (TMatriz*) malloc(sizeof(TMatriz));
    
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    
    matriz->cabecaLinhas = malloc(linhas * sizeof(No*));
    matriz->cabecaColunas = malloc(colunas * sizeof(No*));
    
    matriz_adicionar_nos(matriz);
    
    return(matriz);
}

void matriz_adicionar_nos(TMatriz *matriz){
    
    for(int i = 0; i < matriz->linhas; i++){
        matriz->cabecaLinhas[i] = malloc(sizeof(No));
        matriz->cabecaLinhas[i]->i = i;
        matriz->cabecaLinhas[i]->j = -1;
        matriz->cabecaLinhas[i]->abaixo = NULL;
        matriz->cabecaLinhas[i]->cima = NULL;
        matriz->cabecaLinhas[i]->direita = NULL;
        matriz->cabecaLinhas[i]->esquerda = NULL;
    }
    
    for(int j = 0; j < matriz->colunas; j++){
        matriz->cabecaColunas[j] = malloc(sizeof(No));
        matriz->cabecaColunas[j]->i = -1;
        matriz->cabecaColunas[j]->j = j;
        matriz->cabecaColunas[j]->abaixo = NULL;
        matriz->cabecaColunas[j]->cima = NULL;
        matriz->cabecaColunas[j]->direita = NULL;
        matriz->cabecaColunas[j]->esquerda = NULL;
    }
    
    No *anterior, *linhaAcima;
    
    for(int i = 0; i < matriz->linhas; i++){
        anterior = matriz->cabecaLinhas[i];
        
        if(i > 0){
            linhaAcima = matriz->cabecaLinhas[i-1];
        }
        
        for(int j = 0; j < matriz->colunas; j++){
            No *aux;
            aux = malloc(sizeof(No));
            
            aux->i = i;
            aux->j = j;
            aux->letra = '\0';
            aux->esquerda = anterior;
            aux->direita = anterior->direita;
            
            if(i > 0){
                linhaAcima = linhaAcima->direita;
                
                aux->cima = linhaAcima;
                linhaAcima->abaixo = aux;
            }
            
            if(i == 0){
                aux->cima = matriz->cabecaColunas[j];
                matriz->cabecaColunas[j]->abaixo = aux;
            }
            
            anterior->direita = aux;
            
            anterior = aux;
        }
    }
}

int matriz_preencher_nos(TMatriz *matriz){
    
    if(matriz == NULL || matriz->cabecaLinhas == NULL || matriz->cabecaColunas == NULL){
        return(0);
    }
    
    No *aux;
    
    for(int i = 0; i < matriz->linhas; i++){
        aux = matriz->cabecaLinhas[i]->direita;
        
        for(int j = 0; j < matriz->colunas; j++){
            scanf(" %c", &aux->letra);
            aux->letra = tolower(aux->letra);
            
            aux = aux->direita;
        }
    }
    printf("\n");
    return(1);
}

int matriz_apagar(TMatriz *matriz) {
    
    if(matriz == NULL){
        return(0);
    }
    
    No *aux, *proximo;
    
    for(int i = 0; i < matriz->linhas; i++){
        proximo = matriz->cabecaLinhas[i]->direita;
        
        for(int j = 0; j < matriz->colunas; j++){
            aux = proximo;
            proximo = proximo->direita;
            free(aux);
        }
    }
    
    for(int i = 0; i < matriz->linhas; i++){
        free(matriz->cabecaLinhas[i]);
    }
    
    for(int j = 0; j < matriz->colunas; j++){
        free(matriz->cabecaColunas[j]);
    }
    
    free(matriz->cabecaLinhas);
    free(matriz->cabecaColunas);
    free(matriz);
    matriz = NULL;
    return(1);
}

No *no_letra_inicial(TMatriz *matriz, int posI, int posJ){
    
    No *aux;
    aux = matriz->cabecaLinhas[posI];
    
    int j = -1;
    while(j != posJ){
        aux = aux->direita;
        j++;
     }
    
    return(aux);
}