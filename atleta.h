#ifndef ATLETA_H_INCLUDED
#define ATLETA_H_INCLUDED

typedef struct _atleta* atleta;

atleta criaAtleta( int numero, char genero, char *nome, char *data);

void destroiAtleta(atleta a);

int daNumeroAtleta(atleta a);

char daGeneroAtleta (atleta a);

char *daNomeAtleta(atleta a);

char *daDataAtleta(atleta a);

void adicionaParticipacao (atleta a, char* tipoProva, char* tempoProva, char* nomeEvento, int minuto, int segundo, int milisegundo);

participacao daParticipacao (atleta a, char* tipoProva);

iterador iteradorParticipacoesAtleta(atleta a);

#endif // ATLETA_H_INCLUDED
