#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "prova.h"

struct _prova     // minimos
{
    char *tipoProva;
    char *tempo;
};

prova criaProva(char* tipoProva, char* tempo) {
    prova p;
    p=(prova)malloc(sizeof(struct _prova));
    if (p == NULL)
        return NULL;

    p->tipoProva=malloc(sizeof(char)* (strlen(tipoProva)+1));
    strcpy(p->tipoProva, tipoProva);

    p->tempo=malloc(sizeof(char)* (strlen(tempo)+1));
    strcpy(p->tempo, tempo);

    return p;
}

char* daTipoProva (prova p) {
    return p->tipoProva;
}

char* daTempo (prova p) {
    return p->tempo;
}

