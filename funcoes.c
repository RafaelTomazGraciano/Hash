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
    if(isIn(hash, elem)){
        return;
    }

    int i = hashFunction(elem);

    no *novo = (no *) malloc(sizeof(no));

    if(novo == NULL){
        perror("Erro ao alocar memoria");
    }

    novo->chave = elem;
    novo->proximo = hash[i].inicio;
    hash[i].inicio = novo;
    hash[i].tam++;
}

bool isEmpty(lista *hash){
    for(int i = 0; i < TAMANHO_HASH; i++){
        if(hash[i].tam != 0){
            return false;
        }
    }
    return true;
}

int len(lista *hash){
    int cont = 0;
    for(int i = 0; i < TAMANHO_HASH; i++){
        cont += hash[i].tam;
    }
    return cont;
}

bool isIn(lista *hash, int elem){
    int i = hashFunction(elem);
    no *aux = hash[i].inicio;

    while (aux != NULL) {
        if (aux->chave == elem) {
            return true;
        }
        aux = aux->proximo;
    }
    return false; 
}

bool IsNotIn(lista *hash, int elem){
    int i = hashFunction(elem);
    no *aux = hash[i].inicio;

    while (aux != NULL) {
        if (aux->chave == elem) {
            return false;
        }
        aux = aux->proximo;
    }
    return true; 
}

bool isDisjoint(lista *hash1, lista *hash2){
    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;

        while (aux != NULL) {
            if (isIn(hash2, aux->chave)) {
                return false; 
            }
            aux = aux->proximo;
        }
    }

    return true; 
}

void Remove(lista *hash, int elem){
    int i = hashFunction(elem);
    no *aux = hash[i].inicio;
    no *ant = NULL;

    while (aux != NULL) {
        if (aux->chave == elem) {
            if (ant == NULL) {
                hash[i].inicio = aux->proximo;
            } else {
                ant->proximo = aux->proximo;
            }
            
            free(aux);
            hash[i].tam--;
            return; 
        }
        ant = aux;
        aux = aux->proximo;
    }
}

int pop(lista *hash){
    while(true){
        int numero = rand() % 1000;
        if(isIn(hash, numero)){
            Remove(hash, numero);
            return numero;
        }
    }
}

void clear(lista *hash){
    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *atual = hash[i].inicio;
        while (atual != NULL) {
            no *remover = atual;
            atual = atual->proximo;
            free(remover);
        }
        hash[i].inicio = NULL; 
        hash[i].tam = 0; 
    }
}

lista* Union(lista *hash1, lista *hash2){
    lista *hashUniao = (lista *) malloc(TAMANHO_HASH * sizeof(lista));
    if (hashUniao == NULL) {
        perror("Erro ao alocar memoria");
    }
    initializeHash(hashUniao);

    for (int i = 0; i < TAMANHO_HASH; i++){
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            add(hashUniao, aux->chave);
            aux = aux->proximo;
        }
    }

    for (int i = 0; i < TAMANHO_HASH; i++){
        no *aux = hash2[i].inicio;
        while (aux != NULL) {
            add(hashUniao, aux->chave);
            aux = aux->proximo;
        }
    }
    return hashUniao;
}

lista *intersection(lista *hash1, lista *hash2){
    lista *hashInterseccao = (lista *) malloc(TAMANHO_HASH * sizeof(lista));
    if (hashInterseccao == NULL) {
        perror("Erro ao alocar memoria");
    }
    initializeHash(hashInterseccao);

    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            if (isIn(hash2, aux->chave)) {
                add(hashInterseccao, aux->chave);
            }
            aux = aux->proximo;
        }
    }
    return hashInterseccao;
}

lista *difference(lista *hash1, lista *hash2){
    lista *hashDiferenca = (lista *) malloc(TAMANHO_HASH * sizeof(lista));
    if (hashDiferenca == NULL) {
        perror("Erro ao alocar memoria");
    }
    initializeHash(hashDiferenca);

    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            if (IsNotIn(hash2, aux->chave)) {
                add(hashDiferenca, aux->chave);
            }
            aux = aux->proximo;
        }
    }
    return hashDiferenca;
}

lista *synmetric_difference(lista *hash1, lista *hash2){
    lista *hashDifSimetrica = (lista *) malloc(TAMANHO_HASH * sizeof(lista));
    if (hashDifSimetrica == NULL) {
        perror("Erro ao alocar memoria");
    }
    initializeHash(hashDifSimetrica);

    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            if (IsNotIn(hash2, aux->chave)) {
                add(hashDifSimetrica, aux->chave);
            }
            aux = aux->proximo;
        }
    }

    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash2[i].inicio;
        while (aux != NULL) {
            if (IsNotIn(hash1, aux->chave)) {
                add(hashDifSimetrica, aux->chave);
            }
            aux = aux->proximo;
        }
    }
    return hashDifSimetrica;
}

bool isSubSet(lista *hash1, lista *hash2){
    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            if (IsNotIn(hash2, aux->chave)) {
                return false;
            }
            aux = aux->proximo;
        }
    }
    return true;
}

bool isSuperSet(lista *hash1, lista *hash2){
    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash2[i].inicio;
        while (aux != NULL) {
            if (!isIn(hash1, aux->chave)) {
                return false;
            }
            aux = aux->proximo;
        }
    }
    return true;
}

void copy(lista *hash1, lista *hash2){
    initializeHash(hash2);

    for (int i = 0; i < TAMANHO_HASH; i++) {
        no *aux = hash1[i].inicio;
        while (aux != NULL) {
            add(hash2, aux->chave);
            aux = aux->proximo;
        }
    }
}

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