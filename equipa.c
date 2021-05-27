#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "equipa.h"

struct _equipa
{
    char* id;
    int numAtleta1;
    int numAtleta2;
};

equipa criaEquipa(char *id, int numAtleta1, int numAtleta2){
    equipa e = (equipa)malloc(sizeof(struct _equipa));
    if (e==NULL)
        return NULL;

    e->id = malloc(sizeof(char)* (strlen(id)+1));
    strcpy(e->id, id);
    e->numAtleta1=numAtleta1;
    e->numAtleta2=numAtleta2;

    return e;
}

void destroiEquipa (equipa e)
{
    free(e->id);
    free(e);
}

char *daIDEquipa(equipa e) {
    return e->id;
}

int daNumAtleta1 (equipa e) {
    return e->numAtleta1;
}

int daNumAtleta2 (equipa e) {
    return e->numAtleta2;
}

