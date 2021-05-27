#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tempo.h"
#include "quicksort.h"
#include "iterador.h"
#include "participacao.h"
#include "prova.h"
#include "atleta.h"
#include "equipa.h"
#include "gestorTempos.h"

#define MAX_NOME 100
#define MAX_TEMPO 9

void interpretador(gestorTempos g);
void getCmd(char* linha, char* cmd);
void cmdAtleta(gestorTempos g, char* lin, char* cmd);
void cmdEquipa(gestorTempos g, char* linha, char* cmd);
void cmdMinimo(gestorTempos g, char* linha, char* cmd);
void cmdMinimos(gestorTempos g, char* linha, char* cmd);
void cmdEvento(gestorTempos g, char* linha, char* cmd);
void cmdMelhor(gestorTempos g, char* linha, char* cmd);
void cmdTempos(gestorTempos g, char* linha, char* cmd);
void cmdApurados(gestorTempos g, char * linha, char * cmd);
void cmdProva(gestorTempos g, char * linha, char * cmd);


int main()
{
    gestorTempos g=criaGestorTempos();
    interpretador(g);
    return 0;
}
void interpretador(gestorTempos g)
{

    char linha[100], cmd[10];
    int fim=0;

    do
    {

        getCmd(linha, cmd);
        if(strcmp(cmd, "SAIR")==0)
        {
            printf("Programa terminou\n");
            destroiGestorTempos(g);
            fim=1; //sai do ciclo
        }
        else if(strcmp(cmd, "ATLETA")==0)
        {
            cmdAtleta(g, linha, cmd);
        }
        else if(strcmp(cmd, "EQUIPA")==0)
        {
            cmdEquipa(g, linha, cmd);
        }
        else if(strcmp(cmd, "MINIMO")==0)
        {
            cmdMinimo(g, linha, cmd);
        }
        else if(strcmp(cmd, "MINIMOS")==0)
        {
            cmdMinimos(g, linha, cmd);
        }
        else if(strcmp(cmd, "EVENTO")==0)
        {
            cmdEvento(g, linha, cmd);
        }
        else if(strcmp(cmd, "MELHOR")==0)
        {
            cmdMelhor(g, linha, cmd);
        }
        else if(strcmp(cmd, "TEMPOS")==0)
        {
            cmdTempos(g, linha, cmd);
        }
        else if(strcmp(cmd, "APURADOS")==0)
        {
            cmdApurados(g, linha, cmd);
        }
        else if(strcmp(cmd, "PROVA")==0)
        {
            cmdProva(g, linha, cmd);
        }
        else
            printf("Comando inexistente.\n");

    }
    while (fim!=1); //Se o fim=0 � sinal que foi pedido para sair do programa
}


void getCmd(char *linha, char *cmd)
{

    char aux[50];
    int i;

    printf("> ");
    fgets(linha, 100, stdin); //Le o input completo
    sscanf(linha, "%s %s", cmd, aux);
    for (i=0; i<strlen(cmd); i++)  //Coloca a string do comando em maiusculas
    {
        cmd[i]=toupper(linha[i]);
    }
    cmd[strlen(cmd)]='\0';
}

void cmdAtleta(gestorTempos g, char * linha, char * cmd)
{
    char nome[MAX_NOME], genero, data_nascimento[12];
    int numero;

    if (sscanf(linha, "%s %d %c", cmd, &numero, &genero) == 3 && (genero=='M' || genero=='F') )
    {
        scanf("%[^\n]s",nome);
        getchar(); //limpa o buffer
        scanf("%s", data_nascimento);
        getchar(); //limpa o buffer
        if (verificaAtletaIgualGestor (g, numero)==1)
        {
            printf("Atleta ja existente\n");
        }
        else
        {
            adicionaAtletaGestor (g, nome, genero, numero, data_nascimento);
            printf("Atleta registado\n");
        }
    }
    else
    {
        printf("Comando errado\n");
    }
}

void cmdEquipa(gestorTempos g, char * linha, char * cmd)
{
    char id[4];
    int numAtleta1 = 0, numAtleta2 = 0;

    if (sscanf(linha, "%s %s %d %d", cmd, id, &numAtleta1, &numAtleta2) == 4 )
    {
        if (verificaAtletaIgualGestor(g, numAtleta1)==1 && verificaAtletaIgualGestor(g, numAtleta2)==1 )
        {
            if (verificaEquipaIgualGestor (g, id)==0)
            {
                if ( verificaGeneroEquipa (g, numAtleta1, numAtleta2)==1)
                {
                    adicionarEquipaGestor(g, id, numAtleta1, numAtleta2);
                    printf("Equipa registada\n");
                }

                else
                {
                    printf("Equipa invalida\n");
                }
            }
            else
            {
                printf("Equipa ja existente\n");
            }
        }
        else
        {
            printf("Atleta nao registado\n");
        }
    }
    else
    {
        printf("Comando errado\n");
    }
}

void cmdEvento(gestorTempos g, char* linha, char* cmd)
{
    char nome[MAX_NOME], tipoProva[13], tempo[MAX_TEMPO];
    int i=0, j=0, nmr_provas=0, nmr_de_atletas=0, nmr_de_equipas=0;
    int minuto=0, segundo=0, milisegundo=0;
    int erro_atleta=0, erro_equipa=0, nmr_atleta=0;
    char idEquipa[3];
    int distancia = 0;
    char genero, tipo[3];

    if (sscanf(linha,"%s %[^\n]s", cmd, nome) == 2)
    {
        scanf("%d", &nmr_provas);
        getchar(); //limpa o buffer

        for(i=0; i<nmr_provas; i++)
        {
            scanf("%[^\n]s", tipoProva);
            getchar(); //limpa o buffer
            sscanf(tipoProva, "%s %d %c", tipo, &distancia, &genero);
            if((strcmp(tipo, "C1") == 0 || strcmp(tipo, "C2") == 0 || strcmp(tipo, "K1") == 0 || strcmp(tipo, "K2") == 0)
                && (distancia == 500 || distancia == 1000) && (genero == 'M' || genero == 'F'))
            {

                if(tipo[1]=='1')
                {
                    scanf("%d", &nmr_de_atletas);
                    getchar(); //limpa o buffer

                    for(j=0; j<nmr_de_atletas; j++)
                    {
                        scanf("%d",&nmr_atleta);
                        getchar(); //limpa o buffer
                        scanf("%s",tempo);
                        getchar(); //limpa o buffer

                        sscanf(tempo, "%d:%d.%d", &minuto, &segundo, &milisegundo);

                        if (verificaAtletaIgualGestor(g, nmr_atleta) == 1)
                        {
                            atleta a = daAtleta(g, nmr_atleta);
                            adicionaParticipacao(a, tipoProva, tempo, nome, minuto, segundo, milisegundo);
                        }
                        else
                        {
                            erro_atleta +=1;
                        }
                    }
                }
                if(tipo[1]=='2')
                {
                    scanf(" %d", &nmr_de_equipas);
                    getchar(); //limpa o buffer

                    for(j=0; j<nmr_de_equipas; j++)
                    {

                        scanf("%s",idEquipa);
                        getchar(); //limpa o buffer
                        scanf("%s",tempo);
                        getchar(); //limpa o buffer

                        if (verificaEquipaIgualGestor(g, idEquipa) == 1)
                        {
                            equipa e = daEquipa(g, idEquipa);

                            //adiciona participacao atleta 1
                            atleta a1 = daAtleta(g, daNumAtleta1(e));
                            adicionaParticipacao(a1, tipoProva, tempo, nome, minuto, segundo, milisegundo);

                            //adiciona participacao atleta 2
                            atleta a2 = daAtleta(g, daNumAtleta2(e));
                            adicionaParticipacao(a2, tipoProva, tempo, nome, minuto, segundo, milisegundo);
                        }
                        else
                        {
                            erro_equipa +=1;
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Comando errado\n");
    }

    if(erro_atleta!=0)
    {
        printf("Evento registado com erros\n");
        printf("Atletas nao registados: %d\n",erro_atleta);
        if(erro_equipa!=0)
        {
            printf("Equipa nao registados: %d\n",erro_equipa);
        }
    }
    else if (erro_equipa!=0)
    {
        printf("Evento registado com erros\n");
        printf("Equipas nao registadas: %d\n",erro_equipa);
    }
    else if(erro_atleta==0 && erro_equipa==0)
    {
        printf("Evento registado\n");
    }
    else
    {
        printf("ERRO!");
    }
}

void cmdMelhor(gestorTempos g, char* linha, char* cmd)
{
    char tipoProva[13];
    int numAtleta=0;
    char genero;
    int distancia;
    char tipo[3];

    if (sscanf(linha,"%s %d", cmd, &numAtleta) == 2)
    {
        scanf("%[^\n]s", tipoProva);
        getchar();

        sscanf(tipoProva, "%s %d %c", tipo, &distancia, &genero);
        if((strcmp(tipo, "C1") == 0 || strcmp(tipo, "C2") == 0 || strcmp(tipo, "K1") == 0 || strcmp(tipo, "K2") == 0)
                && (distancia == 500 || distancia == 1000) && (genero == 'M' || genero == 'F'))
        {

            if (verificaAtletaIgualGestor (g, numAtleta)==0)
            {
                printf("Atleta nao registado\n");
            }
            else
            {
                atleta at = daAtleta(g, numAtleta);
                participacao p = daParticipacao (at, tipoProva);
                printf("Melhor tempo: %s %s\n",daMelhorTempoProvaParticipacaoString(p), daNomeEvento(p));
            }

        }
        else
        {
            printf("Prova invalida\n");
        }

    }
    else
        printf("Comando errado\n");
}


void cmdTempos(gestorTempos g, char* linha, char* cmd)
{
    char tipo[3];
    char tipoProva[13];
    int numAtleta=0, distancia=0;
    char genero;
    if (sscanf(linha,"%s %d", cmd, &numAtleta) == 2)
    {
        scanf("%[^\n]s", tipoProva);
        sscanf(tipoProva, "%s %d %c", tipo, &distancia, &genero);
        if((strcmp(tipo, "C1") == 0 || strcmp(tipo, "C2") == 0 || strcmp(tipo, "K1") == 0 || strcmp(tipo, "K2") == 0)
                && (distancia == 500 || distancia == 1000) && (genero == 'M' || genero == 'F'))
        {

            if (verificaAtletaIgualGestor (g, numAtleta)==0)
            {
                printf("Atleta nao registado\n");
            }
            else
            {
                atleta at = daAtleta(g, numAtleta);
                participacao p = daParticipacao (at, tipoProva);
                iterador it = iteradorTemposParticipacao(p);
                while(temSeguinteIterador(it))
                {
                    char* tempo = seguinteIterador(it);
                    printf("%s\n", tempo);
                }
                destroiIterador(it);
            }

        }
        else
        {
            printf("Prova invalida\n");
        }
    }
    else
        printf("Comando errado\n");
}

void cmdMinimo(gestorTempos g, char* linha, char* cmd)
{
    char tipo[3];
    int distancia;
    char genero;
    char tempoReferencia[MAX_TEMPO];
    char tipoProva[13];

    if (sscanf(linha, "%s %s %d %c", cmd, tipo, &distancia, &genero) == 4)
    {
        scanf("%s",tempoReferencia);
        getchar(); //limpa o buffer

        sscanf(linha, "%s %[^\n]s", cmd, tipoProva);

        if ((strcmp(tipo,"C1")==0 || strcmp(tipo,"C2")==0 || strcmp(tipo,"K1")==0 || strcmp(tipo,"K2")==0) && (distancia==500 || distancia==1000) && (genero=='F' || genero=='M'))
        {
            if (existeMinimo(g, tipoProva))
            {
                atualizarMinimoGestor(g, tipoProva, tempoReferencia);
                printf("Tempo de referencia atualizado\n");
            }
            else
            {
                adicionarMinimoGestor(g, tipoProva, tempoReferencia);
                printf("Tempo de referencia atribuido\n");

            }
        }
        else
        {
            printf("Prova invalida\n");
        }
    }
    else
    {
        printf("Comando errado\n");
    }
}

void cmdMinimos(gestorTempos g, char* linha, char* cmd)
{
    if (sscanf(linha, "%s", cmd) == 1)
    {
        mostraTemposMinimosGestor(g);
    }
    else
    {
        printf("Comando errado\n");
    }
}

void cmdApurados(gestorTempos g, char * linha, char * cmd)
{
    char tipoProva[13], tipo[3];
    char genero;
    int existeAtletas=0;

    char *temporarioNomes[tamanhoAtletasGestor(g)];
    char *temporarioTempo[tamanhoAtletasGestor(g)];
    //usado para o caso de empates
    int temporarioIds[tamanhoAtletasGestor(g)];
    int indice = 0;
    int min = 0;
    int max = 0;
    int distancia = 0;

    char* tempoReferenciaProva=NULL;
    int minuto, segundo, milisegundo;
    tempo tempoRef;


    if (sscanf(linha, "%s %[^\n]s", cmd, tipoProva) == 2)
    {
        sscanf(tipoProva, "%s %d %c", tipo, &distancia, &genero);

        if((strcmp(tipo, "C1") == 0 || strcmp(tipo, "C2") == 0 || strcmp(tipo, "K1") == 0 || strcmp(tipo, "K2") == 0)
                && (distancia == 500 || distancia == 1000) && (genero == 'M' || genero == 'F'))
        {
            if(existeMinimo(g, tipoProva))
            {
                iterador itMinimo = iteradorMinimoGestor(g);
                while(temSeguinteIterador(itMinimo))
                {
                    prova p = seguinteIterador(itMinimo);
                    if(strcmp(daTipoProva(p),tipoProva)==0)
                    {

                        strcpy(tempoReferenciaProva, daTempo(p));
                        sscanf(tempoReferenciaProva, "%d:%d.%d", &minuto, &segundo, &milisegundo);
                        tempoRef= criaTempo(minuto, segundo, milisegundo);
                        break;
                    }
                }
                destroiIterador(itMinimo);

                iterador itAtletas = iteradorAtletasGestor(g);
                while(temSeguinteIterador(itAtletas))
                {
                    atleta a = seguinteIterador(itAtletas);

                    iterador itParticipacoes = iteradorParticipacoesAtleta(a);
                    while(temSeguinteIterador(itParticipacoes))
                    {
                        participacao p = seguinteIterador(itParticipacoes);
                        tempo tempoParticipacao = daMelhorTempoProvaParticipacao(p);
                        if(strcmp(daTipoProvaParticipacao(p), tipoProva) == 0)
                        {
                            if(comparaTempos(tempoRef, daMinutoTempo(tempoParticipacao), daSegundoTempo(tempoParticipacao), daMilisegundoTempo(tempoParticipacao)))
                            {
                                existeAtletas = 1;
                                strcpy(temporarioNomes[indice], daNomeAtleta(a));
                                strcpy(temporarioTempo[indice], daMelhorTempoProvaParticipacaoString(p));
                                temporarioIds[indice] = daNumeroAtleta(a);
                                indice++;
                                max++;
                            }

                            break;
                        }
                    }
                    destroiIterador(itParticipacoes);
                }
                destroiIterador(itAtletas);

                if(existeAtletas == 1)
                {
                    quickSort(temporarioNomes, temporarioTempo, temporarioIds, min, max-1, MAX_NOME, MAX_TEMPO);

                    for(int k = 0; k <= max; k++)
                    {
                        printf("%s %s\n", temporarioNomes[k], temporarioTempo[k]);
                    }

                }
                else
                {
                    printf("Sem atletas\n");
                }
            }
            else
            {
                printf("Prova sem tempo minimo\n");
            }

        }
        else printf("Prova invalida\n");
    }
    else
        printf("Comando errado\n");
}

void cmdProva(gestorTempos g, char * linha, char * cmd)
{
    char tipoProva[13], tipo[3];
    char genero;
    int distancia=0;
    int existeAtletas=0;

    if (sscanf(linha, "%s %[^\n]s", cmd, tipoProva) == 2)
    {
        sscanf(tipoProva, "%s %d %c", tipo, &distancia, &genero);

        if((strcmp(tipo, "C1") == 0 || strcmp(tipo, "C2") == 0 || strcmp(tipo, "K1") == 0 || strcmp(tipo, "K2") == 0)
                && (distancia == 500 || distancia == 1000) && (genero == 'M' || genero == 'F'))
        {
            iterador itAtletas = iteradorAtletasGestor(g);
            while(temSeguinteIterador(itAtletas))
            {
                atleta a = seguinteIterador(itAtletas);

                iterador itParticipacoes = iteradorParticipacoesAtleta(a);
                while(temSeguinteIterador(itParticipacoes))
                {
                    participacao p = seguinteIterador(itParticipacoes);

                    if(strcmp(daTipoProvaParticipacao(p), tipoProva) == 0)
                    {
                        existeAtletas = 1;
                        printf("%s %s\n", daNomeAtleta(a), daMelhorTempoProvaParticipacaoString(p));

                        break;
                    }
                }
                destroiIterador(itParticipacoes);
            }
            destroiIterador(itAtletas);

            if(existeAtletas == 0)
            {
                printf("Sem atletas\n");
            }
        }
        else printf("Prova invalida\n");
    }
    else
        printf("Comando errado\n");
}


void cmdTerminar(gestorTempos g, char * linha, char * cmd)
{
    printf("Programa terminou\n");
}

