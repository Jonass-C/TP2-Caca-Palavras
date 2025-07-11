#include <stdio.h>
#include <stdlib.h>
#include "Palavras.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int palavras_add(TPalavra *palavras, int qtdPalavras){
    
    for (int i = 0; i < qtdPalavras; i++){
        char palavra[50];
        scanf("%s", palavra);
        
        for(int j = 0; palavra[j] != '\0'; j++){
            palavra[j] = tolower(palavra[j]);
        }
        
        palavras[i] = palavra_criar(palavra);
        
        palavras[i].coordenadaInicial.i = 0;
        palavras[i].coordenadaInicial.j = 0;
        palavras[i].coordenadaFinal.i = 0;
        palavras[i].coordenadaFinal.j = 0;
    }
    
    return(0);
}

TPalavra palavra_criar(char *palavra){
    
    TPalavra aux;
    aux.palavra = malloc((strlen(palavra) + 1) * sizeof(char));
    
    strcpy(aux.palavra, palavra);
    
    return(aux);
}

void palavras_buscar_inicial(TPalavra *palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias *ocorrenciasLetras){
    
    for(int i = 0; i < qtdPalavras; i++){
        char primeiraLetra = palavras[i].palavra[0];
        
        for(int j = 0; j < 26; j++){
            if(primeiraLetra == ocorrenciasLetras[j].letra && ocorrenciasLetras[j].qtd > 0){
                int qtdCoordenadas = ocorrenciasLetras[j].qtd;
                
                palavras_buscar(palavras, matriz, &ocorrenciasLetras[j], qtdCoordenadas, i, primeiraLetra);
            }
        }
    }
}

void palavras_buscar(TPalavra *palavra, TMatriz *matriz, TOcorrencias *ocorrenciaLetra, int qtdCoordenadas, int indice, char primeiraLetra){
    
    for (int i = 0; i < qtdCoordenadas; i++) {
        int posInicialI = ocorrenciaLetra->coordenadaLetra[i].i;
        int posInicialJ = ocorrenciaLetra->coordenadaLetra[i].j;
        int qtdLetras = strlen(palavra[indice].palavra); // percorrer todas as letras
        
        bool verificar = true; // enquanto continuar true, é pq tem a letra na linha
        
        int posFinalI, posFinalJ;
        
        No *aux;
        
        // BUSCAR PALAVRA NA HORIZONTAL PARA FRENTE (DIREITA)
        if(palavra_verificar_coordenada(posInicialI, posInicialJ + (qtdLetras - 1), matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->direita;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
         // BUSCAR PALAVRA NA HORIZONTAL PRA TRÁS (INVERSO)
        if(palavra_verificar_coordenada(posInicialI, posInicialJ - (qtdLetras - 1), matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->esquerda;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA BAIXO
        if(palavra_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ, matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->abaixo;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA CIMA
        if(palavra_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ, matriz)){
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->cima;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À ESQUERDA
        if (palavra_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ - (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI + k;
                    posFinalJ = posInicialJ - k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->abaixo->esquerda;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À DIREITA
        if (palavra_verificar_coordenada(posInicialI + (qtdLetras - 1), posInicialJ + (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI + k;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->abaixo->direita;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À ESQUERDA
        if (palavra_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ - (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI - k;
                    posFinalJ = posInicialJ - k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->cima->esquerda;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À DIREITA
        if (palavra_verificar_coordenada(posInicialI - (qtdLetras - 1), posInicialJ + (qtdLetras - 1), matriz)) {
            
            aux = no_letra_inicial(matriz, posInicialI, posInicialJ);
            
            verificar = true;
            for(int k = 0; k < qtdLetras; k++){
                if(aux->letra == palavra[indice].palavra[k]){
                    posFinalI = posInicialI - k;
                    posFinalJ = posInicialJ + k;
                } 
                else{
                    verificar = false;
                    break;
                }

                aux = aux->cima->direita;
            }
            
            if(verificar) {
                palavra_armazenar_coordenada(palavra, indice, posInicialI, posInicialJ, posFinalI, posFinalJ);
            }
        }
    }
}

bool palavra_verificar_coordenada(int i, int j, TMatriz *matriz){
    
    return(i >= 0 && i < matriz->linhas && j >= 0 && j < matriz->colunas);
    
}

void palavra_armazenar_coordenada(TPalavra *palavra, int indice, int posInicialI, int posInicialJ, int posFinalI, int posFinalJ){
    
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