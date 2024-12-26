#include "funcoes.h"

int main(){
    srand(time(NULL));
    
    lista hash1[TAMANHO_HASH];
    initializeHash(hash1);
    lista hash2[TAMANHO_HASH];
    initializeHash(hash2);

    printf("------------------ INICIO ------------------\n\n");

    print(hash1);

    printf("is empty: %d\n", isEmpty(hash1));

    printf("len: %d\n", len(hash1));

    printf("\n------------------ ADICIONA AO HASH ------------------\n\n");

    for(int i = 0; i < 150; i++){
        int numero = rand() % 1000;
        add(hash1, numero);
    }
    add(hash1, 101);

    for(int i = 0; i < 150; i++){
        int numero = rand() % 1000;
        add(hash2, numero);
    }

    printf("\n------------------ HASH 1 ------------------\n\n");

    print(hash1);
    printf("is empty: %d\n", isEmpty(hash1));
    printf("len: %d\n", len(hash1));
    printf("is not in: %d\n", IsNotIn(hash1, 101));
    printf("pop: %d\n",pop(hash1));

    printf("\n------------------ HASH 2 ------------------\n\n");

    print(hash2);
    printf("is empty: %d\n", isEmpty(hash2));
    printf("len: %d\n", len(hash2));
    printf("is not in: %d\n", IsNotIn(hash2, 101));
    printf("pop: %d\n",pop(hash2));

    printf("\n------------------ ISDISJOINT ------------------\n\n");

    printf("isDisjoint: %d\n", isDisjoint(hash1, hash2));

    printf("\n------------------ HASH 1 APOS REMOCAO 101 ------------------\n\n");

    Remove(hash1,101);
    print(hash1);

    printf("\n------------------ HASH UNIAO ------------------\n\n");

    lista *hashUniao = Union(hash1, hash2);
    print(hashUniao);

    printf("\n------------------ HASH INTERSECCAO ------------------\n\n");

    lista *hashInterseccao = intersection(hash1, hash2);
    print(hashInterseccao);

    printf("\n------------------ HASH DIFERENCA ------------------\n\n");

    lista *hashDiferenca = difference(hash1, hash2);
    print(hashDiferenca);

    printf("\n------------------ HASH DIFERENCA SIMETRICA ------------------\n\n");

    lista *hashDifSimetrica = synmetric_difference(hash1, hash2);
    print(hashDifSimetrica);

    printf("\n------------------ SUB E SUPERSET ------------------\n\n");

    printf("subset: %d\n",isSubSet(hash1, hash2));
    printf("superset: %d\n",isSuperSet(hash1, hash2));

    printf("\n------------------ COPIA ------------------\n\n");

    copy(hash1, hash2);
    print(hash2);

    printf("\n------------------ CLEAR ------------------\n\n");

    clear(hash1);
    clear(hash2);
    clear(hashUniao);
    clear(hashInterseccao);
    clear(hashDiferenca);
    clear(hashDifSimetrica);

    print(hash1);

    printf("\n------------------ FIM ------------------\n\n");

    free(hashUniao);
    free(hashInterseccao);
    free(hashDiferenca);
    free(hashDifSimetrica);

    return 0;
}