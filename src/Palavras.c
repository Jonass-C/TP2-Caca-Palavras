#include <stdio.h>
#include <stdlib.h>
#include "Palavras.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int palavras_adicionar(TPalavra *palavras, int qtdPalavras){
    
    for (int i = 0; i < qtdPalavras; i++){
        char palavra[50];
        scanf("%s", palavra);
        
        for(int j = 0; palavra[j] != '\0'; j++){
            palavra[j] = tolower(palavra[j]);
        }
        
        palavras[i].palavra = malloc(strlen(palavra) + 1);
        strcpy(palavras[i].palavra, palavra);
        
        palavras[i].coordenadaInicial.i = 0;
        palavras[i].coordenadaInicial.j = 0;
        palavras[i].coordenadaFinal.i = 0;
        palavras[i].coordenadaFinal.j = 0;
    }
    
    return(0);
}

void palavras_buscar_inicial(TPalavra *palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias *ocorrenciasLetras){
    
    for(int i = 0; i < qtdPalavras; i++){
        char primeiraLetra = palavras[i].palavra[0];
        
        for(int j = 0; j < 26; j++){
            if(primeiraLetra == ocorrenciasLetras[j].letra && ocorrenciasLetras[j].qtd > 0){
                int qtdCoordenadas = ocorrenciasLetras[j].qtd;
                
                palavras_verificar_direcoes(palavras, i, matriz, &ocorrenciasLetras[j], qtdCoordenadas);
            }
        }
    }
}

void palavras_verificar_direcoes(TPalavra *palavra, int indice, TMatriz *matriz, TOcorrencias *ocorrenciaLetra, int qtdCoordenadas){
    
    for (int i = 0; i < qtdCoordenadas; i++) {
        int posInicialI = ocorrenciaLetra->coordenadaLetra[i].i;
        int posInicialJ = ocorrenciaLetra->coordenadaLetra[i].j;
        int qtdLetras = strlen(palavra[indice].palavra);
        
        int posFinalI, posFinalJ;
        
        No *aux;
        
        // BUSCAR PALAVRA NA HORIZONTAL PARA FRENTE (DIREITA)
        if(palavras_verificar_coordenada(posInicialI, posInicialJ + (qtdLetras - 1), matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 1)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
         // BUSCAR PALAVRA NA HORIZONTAL PRA TRÁS (ESQUERDA)
        if(palavras_verificar_coordenada(posInicialI, posInicialJ - (qtdLetras - 1), matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 2)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA BAIXO
        if(palavras_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ, matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 3)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA CIMA
        if(palavras_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ, matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 4)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À ESQUERDA
        if (palavras_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ - (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 5)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À DIREITA
        if (palavras_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ + (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 6)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À ESQUERDA
        if (palavras_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ - (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 7)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À DIREITA
        if (palavras_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ + (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            if(palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicialI, posInicialJ, &posFinalI, &posFinalJ, 8)) {
                palavras_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
    }
}

bool palavras_verificar_coordenada(int i, int j, TMatriz *matriz){
    
    return(i >= 0 && i < matriz->linhas && j >= 0 && j < matriz->colunas);
    
}

bool palavras_percorrer_direcoes(No *aux, TPalavra *palavra, int qtdLetras, int indice, int posInicialI, int posInicialJ, int *posFinalI, int *posFinalJ, int opcao){
    
    bool verificar = true;
    int auxFinalI = posFinalI;
    int auxFinalJ = posFinalJ;
    
    for(int k = 0; k < qtdLetras; k++){
        if(aux->letra == palavra[indice].palavra[k]){
            switch(opcao){
                case 1: auxFinalI = posInicialI;
                        auxFinalJ = posInicialJ + k;
                        aux = aux->direita;
                        break;
                case 2: auxFinalI = posInicialI;
                        auxFinalJ = posInicialJ - k;
                        aux = aux->esquerda;
                        break;
                case 3: auxFinalI = posInicialI + k;
                        auxFinalJ = posInicialJ;
                        aux = aux->abaixo;
                        break;
                case 4: auxFinalI = posInicialI - k;
                        auxFinalJ = posInicialJ;
                        aux = aux->cima;
                        break;
                case 5: auxFinalI = posInicialI + k;
                        auxFinalJ = posInicialJ - k;
                        aux = aux->abaixo ? aux->abaixo->esquerda : NULL;
                        break;
                case 6: auxFinalI = posInicialI + k;
                        auxFinalJ = posInicialJ + k;
                        aux = aux->abaixo ? aux->abaixo->direita : NULL;
                        break;
                case 7: auxFinalI = posInicialI - k;
                        auxFinalJ = posInicialJ - k;
                        aux = aux->cima ? aux->cima->esquerda : NULL;
                        break;
                case 8: auxFinalI = posInicialI - k;
                        auxFinalJ = posInicialJ + k;
                        aux = aux->cima ? aux->cima->direita : NULL;
                        break;
            }
        }
        else{
            verificar = false;
            break;
        }
    }
    
    if(verificar){
        *posFinalI = auxFinalI;
        *posFinalJ = auxFinalJ;
    }
    
    return(verificar);
}

void palavras_armazenar_coordenada(TPalavra *palavra, int indice, int posInicialI, int posInicialJ, int posFinalI, int posFinalJ){
    
    palavra[indice].coordenadaInicial.i = posInicialI;
    palavra[indice].coordenadaInicial.j = posInicialJ;
    palavra[indice].coordenadaFinal.i = posFinalI;
    palavra[indice].coordenadaFinal.j = posFinalJ;
    
}

void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras){
    
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%d %d %d %d %s", palavras[i].coordenadaInicial.i, palavras[i].coordenadaInicial.j, palavras[i].coordenadaFinal.i, palavras[i].coordenadaFinal.j, palavras[i].palavra);
    }
    
    printf("\n");
}