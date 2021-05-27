#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tempo.h"
#include "iterador.h"
#include "sequencia.h"
#include "participacao.h"

struct _participacao
{
    char* tipoProva;
    tempo melhorTempoProva; //melhor tempo que o atleta fez neste tipo de prova
    char* melhorNomeEvento; // nome do evento em que conseguiu o melhor tempo
    sequencia tempos; // tempos do atleta neste tipo de prova

};

participacao criaParticipacao(char* tipoProva, char* tempoProva, int minuto, int segundo, int milisegundo, char* nomeEvento)
{
    participacao p;
    p=(participacao)malloc(sizeof(struct _participacao));
    if (p == NULL)
        return NULL;

    p->tipoProva = malloc(sizeof(char)* (strlen(tipoProva)+1));
    strcpy(p->tipoProva, tipoProva);

    p->melhorTempoProva=criaTempo(minuto, segundo, milisegundo);
    if (p->melhorTempoProva==NULL)
    {
        free(p);
        return NULL;
    }
    p->melhorNomeEvento = malloc(sizeof(char)* (strlen(nomeEvento)+1));
    strcpy(p->melhorNomeEvento, nomeEvento);

    p->tempos = criaSequencia(2); // valor sem significado
    if (p->tempos==NULL)
    {
        free(p);
        return NULL;
    }
    adicionaTempo(p, tempoProva);
    return p;
}

void destroiParticipacao(participacao p)
{
    destroiTempo(p->melhorTempoProva);
    destroiSequencia(p->tempos);
    free(p);
}

char* daTipoProvaParticipacao(participacao p)
{
    return p->tipoProva;
}

tempo daMelhorTempoProvaParticipacao(participacao p)
{
    return p->melhorTempoProva;
}

char* daMelhorTempoProvaParticipacaoString(participacao p)
{
    char* tempo = NULL;
    sprintf(tempo, "%d:%d.%d", daMinutoTempo(p->melhorTempoProva), daSegundoTempo(p->melhorTempoProva), daMilisegundoTempo(p->melhorTempoProva));
    return tempo;
}

char* daNomeEvento(participacao p)
{
    return p->melhorNomeEvento;
}

void adicionaTempo(participacao p, char* tempo)
{
    adicionaPosSequencia(p->tempos, tempo, tamanhoSequencia(p->tempos));
}

void atualizarMelhorTempo(participacao p, int minuto, int segundo, int milisegundo, char* nomeEvento)
{
    if(comparaTempos(daMelhorTempoProvaParticipacao(p), minuto, segundo, milisegundo) == 1)
    {
        p->melhorTempoProva = criaTempo(minuto, segundo, milisegundo);
        p->melhorNomeEvento = nomeEvento;
    }

}

iterador iteradorTemposParticipacao(participacao p)
{
    return iteradorSequencia (p->tempos);
}


