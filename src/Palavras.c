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
                TCoordenada coordenadasOcorrencias[ocorrenciasLetras[j].qtd];
                
                printf("\nLETRA %c \n", ocorrenciasLetras[j].letra); /* apenas para testes */
                for(int k = 0; k < ocorrenciasLetras[j].qtd; k++){
                    coordenadasOcorrencias[k].i = ocorrenciasLetras[j].coordenadaLetra[k].i;
                    coordenadasOcorrencias[k].j = ocorrenciasLetras[j].coordenadaLetra[k].j;
                    
                    printf("(%d, %d) ", coordenadasOcorrencias[k].i, coordenadasOcorrencias[k].j); /* apenas para testes */
                }
                
                // chamar palavras_buscar(...);
            }
        }
    }
}

void palavras_imprimir(TPalavra *palavras, int qtdPalavras) /*PROVISÓRIA*/{
    
    printf("\nPALAVRAS DIGITADAS");
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%s", palavras[i].palavra);
    }
    
    printf("\n");
}

void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras){
    
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%d %d %d %d %s", palavras[i].coordenadaInicial.i, palavras[i].coordenadaInicial.j, palavras[i].coordenadaFinal.i, palavras[i].coordenadaFinal.j, palavras[i].palavra);
    }
    
    printf("\n");
}