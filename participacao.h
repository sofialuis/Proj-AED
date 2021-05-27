#ifndef PARTICIPACAO_H_INCLUDED
#define PARTICIPACAO_H_INCLUDED

typedef struct _participacao* participacao;

participacao criaParticipacao(char* tipoProva,  char* tempoProva, int minuto, int segundo, int milisegundo, char* nomeEvento);

void destroiParticipacao(participacao p);

char* daTipoProvaParticipacao(participacao p);

void adicionaTempo(participacao p, char* tempo);

void atualizarMelhorTempo(participacao p, int minuto, int segundo, int milisegundo, char* nomeEvento);

char* daMelhorTempoProvaParticipacaoString(participacao p);

char* daNomeEvento(participacao p);

iterador iteradorTemposParticipacao(participacao p);

tempo daMelhorTempoProvaParticipacao(participacao p);

#endif // PARTICIPACAO_H_INCLUDED
