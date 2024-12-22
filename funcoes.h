#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_HASH 101

typedef struct no{
    int chave;
    struct no *proximo;
}no;

typedef struct lista
{
    no *inicio;
    int tam;
}lista;

int hashFunction(int elem);

void initializeHash(lista *hash);

void add(lista *hash, int elem);

bool isEmpty(lista *hash);

int len(lista *hash);

bool isIn(lista *hash, int elem);

bool IsNotIn(lista *hash, int elem);

bool isDisjoint(lista *hash1, lista *hash2);

void remover(lista *hash, int elem);

int pop(lista *hash);

void clear(lista *hash);

int Union(lista *hash1, lista *hash2);

int intersection(lista *hash1, lista *hash2);

int difference(lista *hash1, int *hahs2);

int synmetric_difference(lista *hash1, lista *hash2);

bool isSubSet(lista *hash1, lista *hash2);

bool isSuperSet(lista *hash1, lista *hash2);

void copy(lista *hash1, lista *hash2);

void print(lista *hash);