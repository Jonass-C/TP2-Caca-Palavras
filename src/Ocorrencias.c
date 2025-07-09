#include <stdio.h>
#include <stdlib.h>
#include "Ocorrencias.h"

void ocorrencias_calcular(TOcorrencias *ocorrenciasLetras, TMatriz *matriz){
    
    for(int i = 0; i < 26; i++){
        ocorrenciasLetras[i].letra = 'a' + i;
        ocorrenciasLetras[i].qtd = 0;
        ocorrenciasLetras[i].coordenadaLetra = NULL;
    }
    
    ocorrencias_adicionar(ocorrenciasLetras, matriz);
}

void ocorrencias_adicionar(TOcorrencias *ocorrenciasLetras, TMatriz *matriz){ 
    
    No *aux;
    
    for(int i = 0; i < 26; i++){
        
        for(int m = 0; m < matriz->linhas; m++){
            aux = matriz->cabecaLinhas[m]->direita;
            
            for(int n = 0; n < matriz->colunas; n++){
                if(aux->letra == ocorrenciasLetras[i].letra){
                    ocorrenciasLetras[i].qtd++;
                    ocorrenciasLetras[i].coordenadaLetra = realloc(ocorrenciasLetras[i].coordenadaLetra, ocorrenciasLetras[i].qtd * sizeof(TCoordenada));
                    ocorrenciasLetras[i].coordenadaLetra[ocorrenciasLetras[i].qtd - 1].i = aux->i;
                    ocorrenciasLetras[i].coordenadaLetra[ocorrenciasLetras[i].qtd - 1].j = aux->j;
                }
                
                aux = aux->direita;
            }
        }
    }
}

void ocorrencias_imprimir(TOcorrencias *ocorrenciasLetras){
    
    printf("\nLETRAS DA MATRIZ");
    for(int i = 0; i < 26; i++){
        if(ocorrenciasLetras[i].qtd > 0){
            printf("\n%c - ", ocorrenciasLetras[i].letra);
            for(int j = 0; j < ocorrenciasLetras[i].qtd; j++){
                printf("(%d, %d)", ocorrenciasLetras[i].coordenadaLetra[j].i, ocorrenciasLetras[i].coordenadaLetra[j].j);
            }
        }
    }
    printf("\n");
}

int ocorrencias_apagar(TOcorrencias *ocorrenciasLetras){
    
    for(int i = 0; i < 26; i++){
        free(ocorrenciasLetras[i].coordenadaLetra);
        ocorrenciasLetras[i].coordenadaLetra = NULL;
    }
    
    return(1);
}