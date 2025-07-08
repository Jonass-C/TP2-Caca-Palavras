#include <stdio.h>
#include <stdlib.h>
#include "Ocorrencias.h"

void ocorrencias_calcular(TOcorrencias **ocorrencias, TMatriz *matriz){
    
    for(int i = 0; i < 26; i++){
        ocorrencias[i] = (TOcorrencias*) malloc(sizeof(TOcorrencias));
        ocorrencias[i]->letra = 'a' + i;
        ocorrencias[i]->qtd = 0;
        ocorrencias[i]->coordLetra = NULL;
    }
    
    ocorrencias_adicionar(ocorrencias, matriz);
}

void ocorrencias_adicionar(TOcorrencias **ocorrencias, TMatriz *matriz){ 
    
    No *aux;
    
    for(int i = 0; i < 26; i++){
        
        for(int m = 0; m < matriz->linhas; m++){
            
            aux = matriz->cabecaLinhas[m]->direita;
            
            for(int n = 0; n < matriz->colunas; n++){
                
                if(aux->letra == ocorrencias[i]->letra){
                    ocorrencias[i]->qtd++;
                    ocorrencias[i]->coordLetra = (TCoordenada*) realloc(ocorrencias[i]->coordLetra, ocorrencias[i]->qtd * sizeof(TCoordenada));
                    ocorrencias[i]->coordLetra[ocorrencias[i]->qtd - 1].i = aux->i;
                    ocorrencias[i]->coordLetra[ocorrencias[i]->qtd - 1].j = aux->j;
                }
                
                aux = aux->direita;
            }
        }
    }
}

void ocorrencias_imprimir(TOcorrencias **ocorrencias){
    
    printf("\nLETRAS DA MATRIZ");
    for(int i = 0; i < 26; i++){
        if(ocorrencias[i]->qtd > 0){
            printf("\n%c - ", ocorrencias[i]->letra);
            for(int j = 0; j < ocorrencias[i]->qtd; j++){
                printf("(%d, %d)", ocorrencias[i]->coordLetra[j].i, ocorrencias[i]->coordLetra[j].j);
            }
        }
    }
    printf("\n");
}

int ocorrencias_apagar(TOcorrencias **ocorrencias){
    
    for(int i = 0; i < 26; i++){
        free(ocorrencias[i]->coordLetra);
        free(ocorrencias[i]);
    }
    
    return(1);
}