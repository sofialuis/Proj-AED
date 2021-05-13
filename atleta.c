#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "atleta.h"

struct _atleta {
    int numero;
    char sexo;
    char *nome;
    char *data;

};

atleta criaAtleta( int numero, char sexo, char *nome, char *data) {
    atleta a;
    a=(atleta)malloc(sizeof(struct _atleta));
    if (a == NULL)
        return NULL;

    a->nome = malloc(sizeof(char)* (strlen(nome)+1));
    strcpy(a->nome, nome);

    a->data = malloc(sizeof(int)* (strlen(data)+1));
    strcpy(a->data, data);

    a->numero=numero;
    a->sexo=sexo;

    return a;
}

void destroiAtleta(atleta a) {

    free(a->nome);
    free(a->data);
    free(a);
}

int daNumeroAtleta(atleta a) {
    return a->numero;
}

char daSexoAtleta (atleta a) {
    return a->sexo;
}

char daNomeAtleta(atleta a) {
    return a->nome;
}

int daDataAtleta(atleta a) {
    return a->data;
}





