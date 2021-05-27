#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tempo.h"
#include "iterador.h"
#include "dicOrdenado.h"
#include "dicionario.h"
#include "participacao.h"
#include "atleta.h"
#include "equipa.h"
#include "prova.h"
#include "gestorTempos.h"

#define MAX_ATLETAS 900
#define MAX_EQUIPAS 900
#define MAX_PROVAS 8

struct _gestorTempos
{
    dicionario equipas;
    dicOrdenado atletas;
    dicionario minimos; //lista de provas com o tipo de prova e tempo de referencia
};

gestorTempos criaGestorTempos()
{
    gestorTempos g = (gestorTempos)malloc(sizeof(struct _gestorTempos));
    if(g == NULL)
    {
        return NULL;
    }
    g->equipas = criaDicionario(MAX_EQUIPAS, 1);
    if (g->equipas==NULL)
    {
        free(g);
        return NULL;
    }
    g->atletas = criaDicOrdenado(MAX_ATLETAS, 0);
    if (g->atletas==NULL)
    {
        free(g);
        return NULL;
    }
    g->minimos = criaDicionario(MAX_PROVAS, 1);
    if (g->minimos==NULL)
    {
        free(g);
        return NULL;
    }
    return g;
}

void destroiGestorTempos(gestorTempos g)
{
    destroiDicionario(g->equipas);
    destroiDicOrdenado(g->atletas);
    destroiDicionario(g->minimos);
    free(g);
}

void adicionaAtletaGestor (gestorTempos g, char *nome, char genero, int numero, char *data_nascimento)
{
    atleta a = criaAtleta (numero, genero, nome, data_nascimento);
    adicionaElemDicOrdenado(g->atletas,  (void *) &numero, (void *) a);
}

iterador iteradorMinimoGestor(gestorTempos g)
{
    return iteradorDicionario(g->minimos);
}

iterador iteradorAtletasGestor(gestorTempos g)
{
    return iteradorDicOrdenado(g->atletas);
}

iterador iteradorEquipasGestor(gestorTempos g)
{
    return iteradorDicionario(g->equipas);
}

int verificaAtletaIgualGestor (gestorTempos g, int numero)
{
    iterador it = iteradorAtletasGestor(g);
    while(temSeguinteIterador(it))
    {
        atleta a = seguinteIterador(it);
        if (daNumeroAtleta(a)==numero)
        {
            return 1;
        }
    }
    destroiIterador(it);
    return 0;
}

int procuraAtleta(gestorTempos g, int numAtleta)
{
    iterador it = iteradorAtletasGestor(g);
    while(temSeguinteIterador(it))
    {
        atleta a = seguinteIterador(it);
        if (daNumeroAtleta(a)== numAtleta)
        {
            return 1;
        }
    }
    destroiIterador(it);
    return 0;
}

int verificaEquipaIgualGestor (gestorTempos g, char* id)
{
    iterador it = iteradorEquipasGestor(g);
    while(temSeguinteIterador(it))
    {
        equipa e = seguinteIterador(it);
        if (strcmp(daIDEquipa(e), id)==0)
        {
            return 1;
        }
    }
    destroiIterador(it);
    return 0;
}

int verificaGeneroEquipa (gestorTempos g, int numAtleta1, int numAtleta2)
{
    char generoAtleta='0';

    iterador it = iteradorAtletasGestor(g);
    while(temSeguinteIterador(it))
    {
        atleta a = seguinteIterador(it);
        if (daNumeroAtleta(a)==numAtleta1 || daNumeroAtleta(a)==numAtleta2)
        {
            if(generoAtleta=='0')
            {
                generoAtleta=daGeneroAtleta(a);
            }
            else
            {
                if (generoAtleta==daGeneroAtleta(a))
                {
                    return 1;
                }
                break;
            }
        }
    }
    destroiIterador(it);
    return 0;

}

void adicionarEquipaGestor(gestorTempos g, char* id, int numAtleta1, int numAtleta2)
{
    equipa e=criaEquipa (id, numAtleta1, numAtleta2);
    adicionaElemDicionario(g->equipas, (void *) id, (void *) e);
}

int existeMinimo(gestorTempos g, char* tipoProva)
{
    iterador it = iteradorMinimoGestor(g);
    while(temSeguinteIterador(it))
    {
        prova p = seguinteIterador(it);
        if(!(strcmp(daTipoProva(p), tipoProva)))
            return 1;
    }
    destroiIterador(it);
    return 0;
}

prova daProva(gestorTempos g, char* tipoProva)
{
    return (prova)elementoDicionario(g->minimos, (void*) tipoProva);
}

void atualizarMinimoGestor(gestorTempos g, char* tipoProva, char* tempoReferencia)
{
    prova pr=daProva(g, tipoProva);
    strcpy(daTempo(pr),tempoReferencia);
}

void adicionarMinimoGestor(gestorTempos g, char* tipoProva, char* tempoReferencia)
{
    prova p=criaProva(tipoProva, tempoReferencia);
    adicionaElemDicionario(g->minimos, (void*)tipoProva, (void*)p);
}

void mostraTemposMinimosGestor(gestorTempos g)
{
    iterador it = iteradorMinimoGestor(g);
    while(temSeguinteIterador(it))  //Percorre todas as provas do gestor
    {
        prova p = seguinteIterador(it);
        printf("%s %s\n", daTipoProva (p), daTempo (p));
    }
    destroiIterador(it);
}

atleta daAtleta(gestorTempos g, int numero)
{
    atleta a;
    iterador it = iteradorAtletasGestor(g);
    while(temSeguinteIterador(it))
    {
        a = seguinteIterador(it);
        if (daNumeroAtleta(a)== numero)
        {
            break;
        }
    }
    destroiIterador(it);
    return a;
}

equipa daEquipa(gestorTempos g, char* id)
{
    equipa e;
    iterador it = iteradorEquipasGestor(g);
    while(temSeguinteIterador(it))
    {
        e = seguinteIterador(it);
        if (strcmp(daIDEquipa(e), id)==0)
        {
            break;
        }
    }
    destroiIterador(it);
    return e;
}

char* mostraAtletasETemposMinimosGestor(gestorTempos g, char* tipoProva)
{
    char* tempo;
    iterador it = iteradorMinimoGestor(g);
    while(temSeguinteIterador(it))  //Percorre todas as provas do gestor
    {
        prova p = seguinteIterador(it);
        if(strcmp(daTipoProva(p), tipoProva)==0)
        {
            tempo = daTempo (p);
            break;
        }
    }
    destroiIterador(it);
    return tempo;
}

int tamanhoAtletasGestor(gestorTempos g) {
    return tamanhoDicOrdenado(g->atletas);
}

