#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tempo.h"

struct _tempo  //vai servir para listar todos os tempos para os comparar
{
    int minuto;
    int segundo;
    int milisegundo;
};


tempo criaTempo(int minuto, int segundo, int milisegundo) {
   tempo t = (tempo)malloc(sizeof(struct _tempo));
    if(t == NULL)
    {
        return NULL;
    }

    t->minuto=minuto;
    t->segundo=segundo;
    t->milisegundo = milisegundo;
    return t;
}

int daMinutoTempo(tempo t) {
    return t->minuto;
}

int daSegundoTempo(tempo t) {
    return t->segundo;
}

int daMilisegundoTempo(tempo t) {
    return t->milisegundo;
}

void destroiTempo(tempo t) {
    free(t);
}

int comparaTempos(tempo t, int minuto, int segundo, int milisegundo)    // se o tempo que temos na estrutura é melhor
{
    if (daMinutoTempo(t)>minuto)
    {
        return 1;
    }
    else if (daMinutoTempo(t)==minuto && daSegundoTempo(t)>segundo)
    {
        return 1;
    }
    else if (daMinutoTempo(t)==minuto && daSegundoTempo(t)==segundo && daMilisegundoTempo(t)>milisegundo)
    {
        return 1;
    }
    return 0; // se retornar 0 o melhor tempo está na variavel melhorTempoProva
}
