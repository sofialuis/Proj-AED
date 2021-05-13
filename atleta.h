#ifndef ATLETA_H_INCLUDED
#define ATLETA_H_INCLUDED

typedef struct _ticket* ticket;

atleta criaAtleta( int numero, char sexo, char *nome, char *data);

void destroiAtleta(atleta a);

int daNumeroAtleta(atleta a);

char daSexoAtleta (atleta a);

char daNomeAtleta(atleta a);

int daDataAtleta(atleta a);

#endif // ATLETA_H_INCLUDED
