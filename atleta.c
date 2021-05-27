#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tempo.h"
#include "iterador.h"
#include "dicionario.h"
#include "participacao.h"
#include "atleta.h"
#define NUM_PARTICIPACOES 3

struct _atleta {
    int numero;
    char genero;
    char* nome;
    char* data;
    dicionario participacao;

};

atleta criaAtleta( int numero, char genero, char *nome, char *data) {
    atleta a;
    a=(atleta)malloc(sizeof(struct _atleta));
    if (a == NULL)
        return NULL;

    a->nome = malloc(sizeof(char)* (strlen(nome)+1));
    strcpy(a->nome, nome);

    a->data = malloc(sizeof(int)* (strlen(data)+1));
    strcpy(a->data, data);

    a->numero=numero;
    a->genero=genero;

    a->participacao = criaDicionario(NUM_PARTICIPACOES, 1);
    if (a->participacao==NULL){
        free(a);
        return NULL;
    }

    return a;
}

void destroiAtleta(atleta a) {

    destroiDicionario(a->participacao);
    free(a);
}

int daNumeroAtleta(atleta a) {
    return a->numero;
}

char daGeneroAtleta (atleta a) {
    return a->genero;
}

char* daNomeAtleta(atleta a) {
    return a->nome;
}

char* daDataAtleta(atleta a) {
    return a->data;
}


dicionario daDicParticipacaoAtleta (atleta a) {
    return a->participacao;
}

void adicionaParticipacao (atleta a, char* tipoProva, char* tempoProva, char* nomeEvento, int minuto, int segundo, int milisegundo)
{
    participacao p = criaParticipacao (tipoProva, tempoProva, minuto, segundo, milisegundo, nomeEvento);//p de participacao
    if(adicionaElemDicionario(daDicParticipacaoAtleta (a), (void*) tipoProva, (void*) p) == 0) {
        participacao p = (participacao)elementoDicionario(daDicParticipacaoAtleta(a), tipoProva);

        adicionaTempo(p, tempoProva);
        atualizarMelhorTempo(p, minuto, segundo, milisegundo, nomeEvento);
    }
}

participacao daParticipacao (atleta a, char* tipoProva)
{
    return (participacao)elementoDicionario (a->participacao, (void*) tipoProva);

}

iterador iteradorParticipacoesAtleta(atleta a)
{
    return iteradorDicionario(a->participacao);
}






