#include "Ocorrencias.h"

void ocorrencias_inicializar(TOcorrencias *ocorrenciasLetras){

    for(int i = 0; i < 26; i++){
        ocorrenciasLetras[i].letra = 'a' + i;
        ocorrenciasLetras[i].qtd = 0;
        ocorrenciasLetras[i].coordenadaLetra = NULL;
    }
}

void ocorrencias_calcular(TOcorrencias *ocorrenciasLetras, TMatriz *matriz){
    
    ocorrencias_inicializar(ocorrenciasLetras);
    
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

int ocorrencias_apagar(TOcorrencias *ocorrenciasLetras){
    
    if(ocorrenciasLetras == NULL){
        return(0);
    }
    
    for(int i = 0; i < 26; i++){
        free(ocorrenciasLetras[i].coordenadaLetra);
        ocorrenciasLetras[i].coordenadaLetra = NULL;
        ocorrenciasLetras[i].qtd = 0;
    }
    
    return(1);
}