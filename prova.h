#ifndef PROVA_H_INCLUDED
#define PROVA_H_INCLUDED

typedef struct _prova* prova;

prova criaProva(char* tipoProva, char* tempo);

char* daTipoProva (prova p);

char* daTempo (prova p);
#endif // PROVA_H_INCLUDED

