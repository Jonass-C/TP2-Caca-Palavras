#include <stdio.h>
#include <stdlib.h>
#include "Palavras.h"
#include <string.h>
#include <ctype.h>

int palavras_add(TPalavra **palavras, int qtdPalavras){
    
    for (int i = 0; i < qtdPalavras; i++){
        char palavra[50];
        scanf("%s", palavra);
        
        for(int j = 0; palavra[j] != '\0'; j++){
            palavra[j] = tolower(palavra[j]);
        }
        
        palavras[i] = malloc(sizeof(TPalavra));
        
        *(palavras[i]) = palavra_criar(palavra);
        
        palavras[i]->coordInicial.i = 0;
        palavras[i]->coordInicial.j = 0;
        palavras[i]->coordFinal.i = 0;
        palavras[i]->coordFinal.j = 0;
    }
    
    return(0);
}

TPalavra palavra_criar(char *palavra){
    
    TPalavra aux;
    aux.palavra = malloc((strlen(palavra) + 1) * sizeof(char));
    
    strcpy(aux.palavra, palavra);
    
    return(aux);
}

void palavras_buscar_inicial(TPalavra **palavras, TMatriz *matriz, int qtdPalavras, TOcorrencias **ocorrencias){
    
    // IMPLEMENTAR LÓGICA
    
}

void palavras_imprimir(TPalavra **palavras, int qtdPalavras) /*PROVISÓRIA*/{
    
    printf("\nPALAVRAS DIGITADAS");
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%s", palavras[i]->palavra);
    }
    
    printf("\n");
}

void palavras_imprimir_solucao(TPalavra **palavras, int qtdPalavras){
    
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%d %d %d %d %s", palavras[i]->coordInicial.i, palavras[i]->coordInicial.j, palavras[i]->coordFinal.i, palavras[i]->coordFinal.j, palavras[i]->palavra);
    }
    
    printf("\n");
}

int palavras_apagar(TPalavra **palavras, int qtdPalavras){
    
    for(int i = 0; i < qtdPalavras; i++){
        free(palavras[i]->palavra);
        free(palavras[i]);
        
        palavras[i] = NULL;
    }
    
    return(1);
}

