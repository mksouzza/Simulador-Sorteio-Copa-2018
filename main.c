#include "Simulador.h"

int main()
{
    srand(30);
    inicializaTela("SORTEIO DE GRUPOS DA COPA 2018"); //cabeçalho da tela
    menu(); //chamada da função menu no main (primeira tela que será vista)
    finalizaTela();
    return 0;
}
