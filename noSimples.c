/*
 * noSimples.c
 *
 *  Created on: 4 de Jan de 2013
 *      Author: fernanda
 */


#include <stdlib.h>
# include "noSimples.h"

/* Tipo do TAD noSimples */
struct _noSimples{
	void * elem;
	struct _noSimples * seguinte;
};

/* Prototipos das funcoes associadas a um aluno - TAD noSimples */

/* Criacao de um no simples */
noSimples criaNoSimples(void * e, noSimples seg){
	noSimples aux = (noSimples) malloc(sizeof(struct _noSimples));
	if (aux == NULL)
		return NULL;
	aux->elem = e;
	aux-> seguinte = seg;
	return aux;
}

/* Destruicao do no Simples */
void destroiNoSimples(noSimples n){
	free(n);
}

/* Destruicao do no Simples e do seu elemento */
void destroiElemENoSimples(noSimples n, void (*destroi)(void *)){
	destroi(n->elem);
	free(n);
}

/* Atribuicao de elemento e ao no simples */
void atribuiElemNoSimples(noSimples n, void * e){
	n->elem = e;
}

/* Atribuicao de seguinte seg ao no simples */
void atribuiSegNoSimples(noSimples n, noSimples seg){
	n->seguinte = seg;
}

/* Consulta do elemento do no simples n */
void * elemNoSimples(noSimples n){
	return n->elem;
}

/* Consulta do seguinte do n0 simples n */
noSimples segNoSimples(noSimples n){
	return n->seguinte;
}



