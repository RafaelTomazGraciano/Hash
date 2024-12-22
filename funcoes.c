#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int hashFunction(int elem){
    return elem % TAMANHO_HASH;
}

void initializeHash(lista *hash){
    for(int i = 0; i < TAMANHO_HASH; i++){
        hash[i].inicio = NULL;
        hash[i].tam = 0;
    }
}

void add(lista *hash, int elem){
    int i = hashFunction(elem);

    no *novo = (no *) malloc(sizeof(no));

    if(novo == NULL){
        perror("Erro ao alocar memoria");
    }

    novo->chave = elem;
    novo->proximo = hash[i].inicio;
    hash[i].inicio = novo;
    hash[i].tam++;
    //NAO PODE TER ELEMENTOS REPETIDOS
}

/**/


void print(lista *hash){
    for(int i = 0; i < TAMANHO_HASH; i++){
        printf("Indice: %d = ", i);
        printf("Tam: %d: ", hash[i].tam);
        for(no *aux = hash[i].inicio; aux != NULL; aux = aux->proximo){
            printf("%d ", aux->chave);
        }
        printf("\n");
    }
}