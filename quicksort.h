#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

int compara(char* nomeAtleta1, int numero1,  char* nomeAtleta2, int numero2);

void quickSort(char* vNomes[], char* vTempos[], int* vIds, int esq, int dir, int max_nome, int max_tempo);

#endif // QUICKSORT_H_INCLUDED
