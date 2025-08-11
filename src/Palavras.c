#include "Palavras.h"

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

void palavras_buscar_inicial(TPalavra *palavras, int qtdPalavras, TOcorrencias *ocorrenciasLetras, TMatriz *matriz){
    
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
    
    int qtdLetras = strlen(palavra[indice].palavra);
    TCoordenada posInicial, posFinal;
    No *aux;
    
    for (int i = 0; i < qtdCoordenadas; i++) {
        
        posInicial.i = ocorrenciaLetra->coordenadaLetra[i].i;
        posInicial.j = ocorrenciaLetra->coordenadaLetra[i].j;
        
        // BUSCAR PALAVRA NA HORIZONTAL PARA FRENTE (DIREITA)
        if(palavras_verificar_coordenada(posInicial.i, posInicial.j + (qtdLetras - 1), matriz)){
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 1);
        }
        
         // BUSCAR PALAVRA NA HORIZONTAL PRA TRÁS (ESQUERDA)
        if(palavras_verificar_coordenada(posInicial.i, posInicial.j - (qtdLetras - 1), matriz)){
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 2);
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA BAIXO
        if(palavras_verificar_coordenada(posInicial.i + (qtdLetras - 1), posInicial.j, matriz)){
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 3);
        }
        
        // BUSCAR PALAVRA NA VERTICAL PARA CIMA
        if(palavras_verificar_coordenada(posInicial.i - (qtdLetras - 1), posInicial.j, matriz)){
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 4);
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À ESQUERDA
        if (palavras_verificar_coordenada(posInicial.i + (qtdLetras - 1), posInicial.j - (qtdLetras - 1), matriz)) {
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 5);
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA BAIXO À DIREITA
        if (palavras_verificar_coordenada(posInicial.i + (qtdLetras - 1), posInicial.j + (qtdLetras - 1), matriz)) {
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 6);
        }
        
        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À ESQUERDA
        if (palavras_verificar_coordenada(posInicial.i - (qtdLetras - 1), posInicial.j - (qtdLetras - 1), matriz)) {
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 7);
        }

        // BUSCAR PALAVRA NA DIAGONAL PARA CIMA À DIREITA
        if (palavras_verificar_coordenada(posInicial.i - (qtdLetras - 1), posInicial.j + (qtdLetras - 1), matriz)) {
            aux = no_letra_inicial(matriz, posInicial);
            palavras_percorrer_direcoes(aux, palavra, qtdLetras, indice, posInicial, &posFinal, 8);
        }
    }
}

bool palavras_verificar_coordenada(int i, int j, TMatriz *matriz){
    
    return(i >= 0 && i < matriz->linhas && j >= 0 && j < matriz->colunas);
    
}

void palavras_percorrer_direcoes(No *aux, TPalavra *palavra, int qtdLetras, int indice, TCoordenada posInicial, TCoordenada *posFinal, int opcao){
    
    bool verificar = true;
    int auxFinalI = posFinal->i;
    int auxFinalJ = posFinal->j;
    
    for(int k = 0; k < qtdLetras; k++){
        if(aux->letra == palavra[indice].palavra[k]){
            switch(opcao){
                case 1: auxFinalI = posInicial.i;
                        auxFinalJ = posInicial.j + k;
                        aux = aux->direita;
                        break;
                case 2: auxFinalI = posInicial.i;
                        auxFinalJ = posInicial.j - k;
                        aux = aux->esquerda;
                        break;
                case 3: auxFinalI = posInicial.i + k;
                        auxFinalJ = posInicial.j;
                        aux = aux->abaixo;
                        break;
                case 4: auxFinalI = posInicial.i - k;
                        auxFinalJ = posInicial.j;
                        aux = aux->cima;
                        break;
                case 5: auxFinalI = posInicial.i + k;
                        auxFinalJ = posInicial.j - k;
                        aux = aux->abaixo ? aux->abaixo->esquerda : NULL;
                        break;
                case 6: auxFinalI = posInicial.i + k;
                        auxFinalJ = posInicial.j + k;
                        aux = aux->abaixo ? aux->abaixo->direita : NULL;
                        break;
                case 7: auxFinalI = posInicial.i - k;
                        auxFinalJ = posInicial.j - k;
                        aux = aux->cima ? aux->cima->esquerda : NULL;
                        break;
                case 8: auxFinalI = posInicial.i - k;
                        auxFinalJ = posInicial.j + k;
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
        posFinal->i = auxFinalI;
        posFinal->j = auxFinalJ;
        
        palavra[indice].coordenadaInicial.i = posInicial.i;
        palavra[indice].coordenadaInicial.j = posInicial.j;
        palavra[indice].coordenadaFinal.i = posFinal->i;
        palavra[indice].coordenadaFinal.j = posFinal->j;
    }
}

void palavras_imprimir_solucao(TPalavra *palavras, int qtdPalavras){
    
    for(int i = 0; i < qtdPalavras; i++){
        printf("\n%d %d %d %d %s", palavras[i].coordenadaInicial.i, palavras[i].coordenadaInicial.j, palavras[i].coordenadaFinal.i, palavras[i].coordenadaFinal.j, palavras[i].palavra);
    }
    
    printf("\n");
}