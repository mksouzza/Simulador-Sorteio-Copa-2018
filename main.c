#include "Simulador.h"

int main()
{
    srand(30);
    inicializaTela("SORTEIO DE GRUPOS DA COPA 2018"); //cabe�alho da tela
    menu(); //chamada da fun��o menu no main (primeira tela que ser� vista)
    finalizaTela();
    return 0;
}
