#ifndef _Simulador_h
#define _Simulador_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tristto.h" //Chamada do arquivo .h da biblioteca gráfica

typedef struct Selecao       //Struct das seleções que serão cadastradas e colocadas nos potes e grupos
{
    char pais[50];
    char confederacao[10];
    int ranking;
    int nota;

}Selecao;

typedef struct ListaSel
{
    struct Selecao select;
    struct ListaSel *nextselecao;
}ListaSel;

void delay(unsigned int mseconds);
int menu();
void instrucoes();
void criaselecao(ListaSel **cadastro, char pais[50], char confederacao[10], int ranking);
void cadastrar(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA);
void sortear(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
void cadastrar2(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA);
void sortear2(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
void logdosorteio();
void registratxt(char * texto);
void probabilidade(ListaSel **probab);
int calculaprobabilidade(ListaSel *where);
int lertecla();
int tamanho(ListaSel *selecao);
int distribuipote1(ListaSel **pote1);
int sorteiagrupos(ListaSel **pote, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
int sorteiagrupos2(ListaSel **pote, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
int validagrupo(ListaSel **grupo, ListaSel **time);
ListaSel *tirarselecao(ListaSel **pais, int posicao);
ListaSel *mostraselecao(ListaSel *pais, int posicao);
int possibilidades(ListaSel **probab);
float PC_pensa(ListaSel **times);
int comparagrupos(ListaSel **grupo,ListaSel **prob);
int colocaEmGrupo(ListaSel *selecao, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
int colocaEmGrupo2(ListaSel *selecao, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
void overtime(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
void automaticamente(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH);
#endif // _Simulador_h
