#ifndef GESTORTEMPOS_H_INCLUDED
#define GESTORTEMPOS_H_INCLUDED

typedef struct _gestorTempos* gestorTempos;

gestorTempos criaGestorTempos();

void adicionaAtletaGestor (gestorTempos g, char *nome, char genero, int numero, char *data_nascimento);

int verificaAtletaIgualGestor (gestorTempos g, int numero);

int procuraAtleta(gestorTempos g, int numAtleta1);

void adicionarEquipaGestor(gestorTempos g, char* id, int numAtleta1, int numAtleta2);

int verificaEquipaIgualGestor (gestorTempos g, char* id);

int verificaGeneroEquipa (gestorTempos g, int numAtleta1, int numAtleta2);

void destroiGestorTempos (gestorTempos g);

int existeMinimo(gestorTempos g, char* tipoProva);

void atualizarMinimoGestor(gestorTempos g, char* tipoProva, char* tempoReferencia);

void adicionarMinimoGestor(gestorTempos g, char* tipoProva, char* tempoReferencia);

void mostraTemposMinimosGestor(gestorTempos g);

atleta daAtleta(gestorTempos g, int numero);

equipa daEquipa(gestorTempos g, char* id);

char* daMelhorTempoGestor(gestorTempos g, int numAtleta, char* tipoProva);

char* mostraAtletasETemposMinimosGestor(gestorTempos g, char* tipoProva);

int tamanhoAtletasGestor(gestorTempos g);

iterador iteradorMinimoGestor(gestorTempos g);

iterador iteradorAtletasGestor(gestorTempos g);

iterador iteradorEquipasGestor(gestorTempos g);

#endif // GESTORTEMPOS_H_INCLUDED
