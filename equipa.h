#ifndef EQUIPA_H_INCLUDED
#define EQUIPA_H_INCLUDED


typedef struct _equipa* equipa;
equipa criaEquipa(char *id, int numAtleta1, int numAtleta2);
void destroiEquipa (equipa e);
char *daIDEquipa(equipa e);
int daNumAtleta1 (equipa e);
int daNumAtleta2 (equipa e);

#endif // EQUIPA_H_INCLUDED
