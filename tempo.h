#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

typedef struct _tempo* tempo;

tempo criaTempo(int minuto, int segundo, int milisegundo);

int daMinutoTempo(tempo t);

int daSegundoTempo(tempo t);

int daMilisegundoTempo(tempo t);

void destroiTempo(tempo t);

int comparaTempos(tempo t, int minuto, int segundo, int milisegundo);

#endif // TEMPO_H_INCLUDED
