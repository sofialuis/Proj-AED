#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compara(char* nomeAtleta1, int numero1,  char* nomeAtleta2, int numero2)
{
    // String compare the two strings
    int result = strcmp(nomeAtleta1, nomeAtleta2);

    // If they're the same, find the largest key
    if(result == 0)
    {
        if(numero1 < numero2)
            return -1;
        else
            return 1;
    }

    //Otherwise, return the result
    return result;
}

void quickSort(char* vNomes[], char* vTempos[], int* vIds, int esq, int dir, int max_nome, int max_tempo)
{
    int i = esq;
    int j = dir;
    int mid = (i+j)/2;
    char* p=vNomes[mid];
    do
    {
        while (compara(vNomes[i], vIds[i], p, vIds[mid])< 0)
            i++;

        while (compara(p, vIds[mid], vNomes[i], vIds[i]) < 0)
            j--;

        if (i <= j)
        {
            char tempNomes[max_nome];

            strcpy(tempNomes, vNomes[i]);
            strcpy(vNomes[i], vNomes[j]);
            strcpy(vNomes[j], tempNomes);

            char tempTempos[max_tempo];

            strcpy(tempTempos, vTempos[i]);
            strcpy(vTempos[i], vTempos[j]);
            strcpy(vTempos[j], tempTempos);

            int tempId = vIds[i];
            vIds[i] = vIds[j];
            vIds[j] = tempId;

            i++;
            j--;
        }
        if(esq<j)
            quickSort(vNomes, vTempos, vIds, esq, dir, max_nome, max_tempo);
        if(i<dir)
            quickSort(vNomes, vTempos, vIds, esq, dir, max_nome, max_tempo);
    } while (i<=j);
}
