#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main(){
    srand(time(NULL));
    
    lista hash[TAMANHO_HASH];
    initializeHash(hash);

    for(int i = 0; i < 200; i++){
        int numero = rand() % 1000;
        add(hash, numero);
    }

    print(hash);

    return 0;
}