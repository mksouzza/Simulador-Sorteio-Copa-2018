#include "Simulador.h"

int menu()///MENU DO SIMULADOR
{
    //CRIAÇÃO DOS POTES E GRUPOS
    FILE *log;
    ListaSel *pote1 = NULL;
    ListaSel *pote2 = NULL;
    ListaSel *pote3 = NULL;
    ListaSel *pote4 = NULL;
    ListaSel *grupoA = NULL;
    ListaSel *grupoB = NULL;
    ListaSel *grupoC = NULL;
    ListaSel *grupoD = NULL;
    ListaSel *grupoE = NULL;
    ListaSel *grupoF = NULL;
    ListaSel *grupoG = NULL;
    ListaSel *grupoH = NULL;
    ListaSel *probab = NULL;
    int teclado=0,op=32;
    int m=1;

    while(m)
    {
        limpa_tela(PRETO); //essa função deixa a tela preta (apaga o que tinha antes pra poder colocar coisa nova, vulgo o que tem abaixo)
        tprintf(47,30,BRANCO,PRETO,"------>                    <------");
        tprintf(54,30,AZUL_CLARO,PRETO,"SORTEIO DA COPA 2018"); //A função tprintf é da biblioteca gáfica, pra usar ela: tprintf(coordenada x, coordenada y, cor da letra, cor de fundo, "O QUE QUISER ESCREVER");
        tprintf(49,32,BRANCO,PRETO,"INSTRUCOES");
        tprintf(49,34,BRANCO,PRETO,"CADASTRAR CLASSIFICADOS");
        tprintf(49,36,BRANCO,PRETO,"SORTEAR GRUPOS");
        tprintf(49,38,BRANCO,PRETO,"LOG DO SORTEIO");
        tprintf(49,40,BRANCO,PRETO,"QUAL A PROBABILIDADE?");
        tprintf(49,42,BRANCO,PRETO,"SAIR");
        tprintf(47,44,BRANCO,PRETO,"----------------------------------");
        tprintf(81,op,BRANCO,PRETO,"<-----");
        tprintf(40,op,BRANCO,PRETO,"----->");
        teclado = tgetch(); //tgetch(); é uma função que lê o teclado, vem junto da biblioteca gráfica

        switch (teclado)
        {
        ///Apertou para cima
        case CIMA:
            if(op == 32) op = 42; //op tá verificando só a coordenada y
            else op = op-2;
            break;
        ///Apertou para baixo
        case BAIXO:
            if(op == 32) op = 34;
            else op = op+2;
            if(op == 44) op = 32;
            break;
        ///Apertou ENTER
        case ENTER:
            if(op == 32) instrucoes(); //se apertar enter ele vai pra intruções
            if(op == 34) cadastrar(&pote1,&pote2,&pote3,&pote4,&grupoA);
            if(op == 36) sortear(&pote1,&pote2,&pote3,&pote4,&grupoA,&grupoB,&grupoC,&grupoD,&grupoE,&grupoF,&grupoG,&grupoH);
            if(op == 38) logdosorteio(&log);
            if(op == 40) probabilidade(&probab);
            if(op == 42) {
                log = fopen("log.txt","w");
                fclose(log);
                exit(0);
            } //sai do programa
            break;
        }

    }
    return 0;
}

void instrucoes() ///FUNÇÃO QUE VAI MOSTRAR AS INSTRUÇÕES NA TELA
{
    limpa_tela(PRETO);
    int m = 2;
    while(m)
    {
        tprintf(55,2,AZUL_CLARO,PRETO,"COMO FUNCIONA?");
        tprintf(2,4,AMARELO_CLARO,PRETO,"CADASTRO DA PROBABILIDADE: ");
        tprintf(2,6,BRANCO,PRETO,"PRIMEIRO DIGITE O NOME DO PAIS - LETRAS MAIUSCULAS E MINUSCULAS -");
        tprintf(2,8,BRANCO,PRETO,"EM SEGUIDA DIGITE A SIGLA DA CONFEDERACAO - APESNAS LETRAS MAIUSCULAS -");
        tprintf(2,10,BRANCO,PRETO,"E POR ULTIMO DIGITE O NUMERO DO PAIS NO RANKING DA FIFA");
        tprintf(88,6,VERDE_CLARO,PRETO,"EXEMPLO:");
        tprintf(97,6,BRANCO,PRETO,"NOME DO PAIS: Brasil");
        tprintf(97,8,BRANCO,PRETO,"CONFEDERACAO: CONMEBOL");
        tprintf(97,10,BRANCO,PRETO,"RANK: 2");
        tprintf(2,14,AMARELO_CLARO,PRETO,"CADASTRO DO SORTEIO:");
        tprintf(2,16,BRANCO,PRETO,"AO CLICAR EM CADASTRAR SELECOES AS MESMAS SERAM CADASTRADAS AUTOMATICAMENTE");
        tprintf(2,18,BRANCO,PRETO,"APERTE ENTER PARA VOLTAR AO MENU E PODER REALIZAR O SORTEIO");
        tprintf(2,22,AMARELO_CLARO,PRETO,"SORTEIO:");
        tprintf(2,24,BRANCO,PRETO,"CLIQUE EM SORTEAR GRUPOS E ESCOLHA ENTRE SORTEIO POR TEMPO OU SORTEIO AUTOMATICO");
        tprintf(2,26,BRANCO,PRETO,"O SORTEIO POR TEMPO SORTEARA UM GRUPO DE CADA VEZ, A CADA 1 SEGUNDO ELE MOSTRA NA TELA UM NOVO GRUPO SORTEADO");
        tprintf(2,28,BRANCO,PRETO,"O SORTEIO AUTOMATICO IMEDIATAMENTE MOSTRA NA TELA TODOS OS GRUPOS SORTEADOS");
        tprintf(2,32,AMARELO_CLARO,PRETO,"LOG DO SORTEIO:");
        tprintf(2,34,BRANCO,PRETO,"MOSTRA A ORDEM EM QUE OS GRUPOS FORAM SORTEADOS E GUARDADOS EM ARQUIVO DE TEXTO");
        tprintf(2,38,AMARELO_CLARO,PRETO,"PROBABILIDADE:");
        tprintf(2,40,BRANCO,PRETO,"ESCOLHA DE 2 A 4 SELECOES PARA PODER CALCULAR A PROBABILIDADE DE ESTAREM NO MESMO GRUPO");
        tprintf(2,42,BRANCO,PRETO,"APOS ESCOLHER O NUMERO DE SELECOES A SEREM CADASTRADAS REGISTRE SEUS NOMES, CONFEDERACOES E RANKINGS");
        tprintf(2,44,BRANCO,PRETO,"O PROGRAMA CALCULARA A CHANCE DAS MESMAS CAIREM NO MESMO GRUPO");
        tprintf(2,48,AMARELO_CLARO,PRETO,"INFORMACOES GERAIS:");
        tprintf(2,50,BRANCO,PRETO,"AS TECLAS PRINCIPAIS PARA O PROGRAMA SAO: DIRECIONAL PARA CIMA, DIRECIONAL PARA BAIXO E ENTER");
        tprintf(2,52,BRANCO,PRETO,"NUMERAIS E LETRAS SO SERAO USADOS PARA O CADASTRO DAS PROBABILIDADES");
        tprintf(2,54,BRANCO,PRETO,"PARA ENTRAR EM QUALQUER TELA E NECESSARIO APERTAR ENTER, ");
        tprintf(2,56,BRANCO,PRETO,"ASSIM COMO PARA SAIR DAS MESMAS QUANDO ENCERRADAS AS SUAS RESPECTIVAS ATIVIDADES");
        tprintf(47,76,BRANCO,PRETO,"APERTE ENTER PARA SAIR DA TELA!");
        lertecla(); //Chama a função ler tecla duas vezes pra poder parar na tela de intruções
        lertecla(); //e só sair quando apertar alguma tecla
        menu();
    }
}
void delay(unsigned int mseconds)///DELAY EM MILISSEGUNDOS
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int lertecla()///LÊ AS TECLAS CIMA, BAIXO E ENTER
{
    while(1)
    {
        if(lerTecla(CIMA))
        {
            delay(250);
            return 1;
        }

        if(lerTecla(BAIXO))
        {
            delay(250);
            return 2;
        }

        if(lerTecla(ENTER))
        {
            delay(250);
            return 5;
        }
    }
    return -1;
}

void criaselecao(ListaSel **cadastro, char pais[50], char confederacao[10], int ranking) //REGISTRA DADOS DO CADASTRO
{
    if(*cadastro==NULL)
    {
        ListaSel *nov = malloc(sizeof(ListaSel));
        strcpy(nov->select.pais, pais);
        strcpy(nov->select.confederacao, confederacao);
        nov->select.ranking = ranking;
        nov->nextselecao = NULL;
        *cadastro = nov;
        return;
    }
    ListaSel *and = *cadastro;
    while(and->nextselecao!= NULL)
    {
        and=and->nextselecao;
    }
    ListaSel *nov = malloc(sizeof(ListaSel));
    strcpy(nov->select.pais, pais);
    strcpy(nov->select.confederacao, confederacao);
    nov->select.ranking = ranking;
    nov->nextselecao = NULL;
    and->nextselecao = nov;
    return;
}

void cadastrar(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA) //tela para cadastro das seleções
{
    limpa_tela(PRETO);
    int m = 3;
    while(m)
    {
        limpa_tela(PRETO);
        ///POTE 1
        criaselecao(grupoA,"Russia","UEFA",0); //cria uma seleção através da função criaselecao(local onde será criada, nome do país, confederação, ranking)
        criaselecao(pote1,"Alemanha","UEFA",1);
        criaselecao(pote1,"Brasil","CONMEBOL",2);
        criaselecao(pote1,"Portugal","UEFA",3);
        criaselecao(pote1,"Argentina","CONMEBOL",4);
        criaselecao(pote1,"Belgica","UEFA",5);
        criaselecao(pote1,"Polonia","UEFA",6);
        criaselecao(pote1,"Franca","UEFA",7);
        ///POTE 2
        criaselecao(pote2,"Espanha","UEFA",8);
        criaselecao(pote2,"Peru","CONMEBOL",10);
        criaselecao(pote2,"Suica","UEFA",11);
        criaselecao(pote2,"Inglaterra","UEFA",12);
        criaselecao(pote2,"Colombia","CONMEBOL",13);
        criaselecao(pote2,"Mexico","CONCACAF",16);
        criaselecao(pote2,"Uruguai","CONMEBOL",17);
        criaselecao(pote2,"Croacia","UEFA",18);
        ///POTE 3
        criaselecao(pote3,"Dinamarca","UEFA",19);
        criaselecao(pote3,"Islandia","UEFA",21);
        criaselecao(pote3,"Costa Rica","CONCACAF",22);
        criaselecao(pote3,"Suecia","UEFA",25);
        criaselecao(pote3,"Tunisia","CAF",28);
        criaselecao(pote3,"Egito","CAF",30);
        criaselecao(pote3,"Senegal","CAF",32);
        criaselecao(pote3,"Ira","AFC",34);
        ///POTE 4
        criaselecao(pote4,"Servia","UEFA",38);
        criaselecao(pote4,"Nigeria","CAF",41);
        criaselecao(pote4,"Australia","AFC",43);
        criaselecao(pote4,"Japao","AFC",44);
        criaselecao(pote4,"Marrocos","CAF",48);
        criaselecao(pote4,"Panama","CONCACAF",49);
        criaselecao(pote4,"Coreia do Sul","AFC",62);
        criaselecao(pote4,"A. Saudita","AFC",63);
        tprintf(39,38,BRANCO,PRETO,"TODAS AS SELECOES FORAM REGISTRADAS COM SUCESSO!");
        lertecla(); //Chama a função ler tecla duas vezes pra poder parar na tela atual
        lertecla();
        break;
    }
}

void sortear(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) //tela de sorteio
{
    limpa_tela(PRETO);
    int m = 4;
    int teclado = 0, op = 38;

    FILE *log = fopen("log.txt","w+");
    fclose(log);

    while(m)
    {
        limpa_tela(PRETO);
        tprintf(48,36,BRANCO,PRETO,"Escolha a forma de sorteio:");
        tprintf(56,38,VERDE_CLARO,PRETO," POR TEMPO");
        tprintf(54,40,AMARELO_CLARO,PRETO,"AUTOMATICAMENTE");
        tprintf(73,op,BRANCO,PRETO,"<-----");
        tprintf(43,op,BRANCO,PRETO,"----->");
        teclado = tgetch();
        switch(teclado)
        {
        case CIMA:
            if(op==38) op=40;
            else op = op-2;
            break;

        case BAIXO:
            if(op==40) op=38;
            else op = op+2;
            break;

        case ENTER:
            if(op == 38) overtime(pote1,pote2,pote3,pote4,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
            if(op == 40) automaticamente(pote1,pote2,pote3,pote4,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
            menu();
        }
    }
}

void cadastrar2(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA)
{
    ///POTE 1
    criaselecao(grupoA,"Russia","UEFA",0); //cria uma seleção através da função criaselecao(local onde será criada, nome do país, confederação, ranking)
    criaselecao(pote1,"Alemanha","UEFA",1);
    criaselecao(pote1,"Brasil","CONMEBOL",2);
    criaselecao(pote1,"Portugal","UEFA",3);
    criaselecao(pote1,"Argentina","CONMEBOL",4);
    criaselecao(pote1,"Belgica","UEFA",5);
    criaselecao(pote1,"Polonia","UEFA",6);
    criaselecao(pote1,"Franca","UEFA",7);
    ///POTE 2
    criaselecao(pote2,"Espanha","UEFA",8);
    criaselecao(pote2,"Peru","CONMEBOL",10);
    criaselecao(pote2,"Suica","UEFA",11);
    criaselecao(pote2,"Inglaterra","UEFA",12);
    criaselecao(pote2,"Colombia","CONMEBOL",13);
    criaselecao(pote2,"Mexico","CONCACAF",16);
    criaselecao(pote2,"Uruguai","CONMEBOL",17);
    criaselecao(pote2,"Croacia","UEFA",18);
    ///POTE 3
    criaselecao(pote3,"Dinamarca","UEFA",19);
    criaselecao(pote3,"Islandia","UEFA",21);
    criaselecao(pote3,"Costa Rica","CONCACAF",22);
    criaselecao(pote3,"Suecia","UEFA",25);
    criaselecao(pote3,"Tunisia","CAF",28);
    criaselecao(pote3,"Egito","CAF",30);
    criaselecao(pote3,"Senegal","CAF",32);
    criaselecao(pote3,"Ira","AFC",34);
    ///POTE 4
    criaselecao(pote4,"Servia","UEFA",38);
    criaselecao(pote4,"Nigeria","CAF",41);
    criaselecao(pote4,"Australia","AFC",43);
    criaselecao(pote4,"Japao","AFC",44);
    criaselecao(pote4,"Marrocos","CAF",48);
    criaselecao(pote4,"Panama","CONCACAF",49);
    criaselecao(pote4,"Coreia do Sul","AFC",62);
    criaselecao(pote4,"Arabia Saudita","AFC",63);
}

void sortear2(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) //tela de sorteio
{
    int i;
    for(i=1; i<8; i++)
    {
        sorteiagrupos2(pote1,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos2(pote2,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos2(pote3,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos2(pote4,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
}

void registratxt(char * texto) //registra o sorteio no file
{
    FILE *log = fopen("log.txt","a");
    fprintf(log,"%s\n",texto);
    fclose(log);
}

void logdosorteio() //printa o file na tela
{
    int x=2,y=2,i;
    FILE* Log;
    limpa_tela(PRETO);

    char aux[100];
    Log = fopen("log.txt","r");

    while(fgets(aux, 99, Log) != NULL)
    {
        for (i = 0; i < 100; i++)
        {
            if(aux[i] == '\n')
            {
                aux[i]='\0';
                break;
            }
        }
        tprintf(x,y,BRANCO,PRETO,"%s",aux);
        y=y+2;
    }
    lertecla();
    lertecla();
}

void probabilidade(ListaSel **probab)
{
    limpa_tela(PRETO);
    float chance = 0;
    int m = 1, i = 0, ranq = 0, n = 0,y=2,j;
    char nome[50];
    char conf[10];
    while(m)
    {
        for(i=0; i<64; i++)
        {
            tprintf(14,y,VERDE_CLARO,PRETO,"|");
            y=y+1;
        }
        y=2;
        for(i=0; i<64; i++)
        {
            tprintf(36,y,VERDE_CLARO,PRETO,"|");
            y=y+1;
        }
        y=2;
        for(i=0; i<64; i++)
        {
            tprintf(56,y,VERDE_CLARO,PRETO,"|");
            y=y+1;
        }
        tprintf(2,2,BRANCO,PRETO,"Russia");
        tprintf(2,4,BRANCO,PRETO,"UEFA");
        tprintf(2,6,BRANCO,PRETO,"0");
        tprintf(2,8,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,10,BRANCO,PRETO,"Alemanha");
        tprintf(2,12,BRANCO,PRETO,"UEFA");
        tprintf(2,14,BRANCO,PRETO,"1");
        tprintf(2,16,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,18,BRANCO,PRETO,"Brasil");
        tprintf(2,20,BRANCO,PRETO,"CONMEBOL");
        tprintf(2,22,BRANCO,PRETO,"2");
        tprintf(0,24,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,26,BRANCO,PRETO,"Portugal");
        tprintf(2,28,BRANCO,PRETO,"UEFA");
        tprintf(2,30,BRANCO,PRETO,"3");
        tprintf(2,32,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,34,BRANCO,PRETO,"Argentina");
        tprintf(2,36,BRANCO,PRETO,"CONMEBOL");
        tprintf(2,38,BRANCO,PRETO,"4");
        tprintf(2,40,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,42,BRANCO,PRETO,"Belgica");
        tprintf(2,44,BRANCO,PRETO,"UEFA");
        tprintf(2,46,BRANCO,PRETO,"5");
        tprintf(2,48,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,50,BRANCO,PRETO,"Polonia");
        tprintf(2,52,BRANCO,PRETO,"UEFA");
        tprintf(2,54,BRANCO,PRETO,"6");
        tprintf(2,56,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
        tprintf(2,58,BRANCO,PRETO,"Franca");
        tprintf(2,60,BRANCO,PRETO,"UEFA");
        tprintf(2,62,BRANCO,PRETO,"7");
///--------------------------------------------
        tprintf(22,2,BRANCO,PRETO,"Espanha");
        tprintf(22,4,BRANCO,PRETO,"UEFA");
        tprintf(22,6,BRANCO,PRETO,"8");
        tprintf(22,10,BRANCO,PRETO,"Peru");
        tprintf(22,12,BRANCO,PRETO,"CONMEBOL");
        tprintf(22,14,BRANCO,PRETO,"10");
        tprintf(22,18,BRANCO,PRETO,"Suica");
        tprintf(22,20,BRANCO,PRETO,"CONMEBOL");
        tprintf(22,22,BRANCO,PRETO,"11");
        tprintf(22,26,BRANCO,PRETO,"Inglaterra");
        tprintf(22,28,BRANCO,PRETO,"UEFA");
        tprintf(22,30,BRANCO,PRETO,"12");
        tprintf(22,34,BRANCO,PRETO,"Colombia");
        tprintf(22,36,BRANCO,PRETO,"CONMEBOL");
        tprintf(22,38,BRANCO,PRETO,"13");
        tprintf(22,42,BRANCO,PRETO,"Mexico");
        tprintf(22,44,BRANCO,PRETO,"CONCACAF");
        tprintf(22,46,BRANCO,PRETO,"16");
        tprintf(22,50,BRANCO,PRETO,"Uruguai");
        tprintf(22,52,BRANCO,PRETO,"CONMEBOL");
        tprintf(22,54,BRANCO,PRETO,"17");
        tprintf(22,58,BRANCO,PRETO,"Croacia");
        tprintf(22,60,BRANCO,PRETO,"UEFA");
        tprintf(22,62,BRANCO,PRETO,"18");
///------------------------------------------------
        tprintf(42,2,BRANCO,PRETO,"Dinamarca");
        tprintf(42,4,BRANCO,PRETO,"UEFA");
        tprintf(42,6,BRANCO,PRETO,"19");
        tprintf(42,10,BRANCO,PRETO,"Islandia");
        tprintf(42,12,BRANCO,PRETO,"UEFA");
        tprintf(42,14,BRANCO,PRETO,"21");
        tprintf(42,18,BRANCO,PRETO,"Costa Rica");
        tprintf(42,20,BRANCO,PRETO,"CONCACAF");
        tprintf(42,22,BRANCO,PRETO,"22");
        tprintf(42,26,BRANCO,PRETO,"Suecia");
        tprintf(42,28,BRANCO,PRETO,"UEFA");
        tprintf(42,30,BRANCO,PRETO,"25");
        tprintf(42,34,BRANCO,PRETO,"Tunisia");
        tprintf(42,36,BRANCO,PRETO,"CAF");
        tprintf(42,38,BRANCO,PRETO,"28");
        tprintf(42,42,BRANCO,PRETO,"Egito");
        tprintf(42,44,BRANCO,PRETO,"CAF");
        tprintf(42,46,BRANCO,PRETO,"30");
        tprintf(42,50,BRANCO,PRETO,"Senegal");
        tprintf(42,52,BRANCO,PRETO,"CAF");
        tprintf(42,54,BRANCO,PRETO,"32");
        tprintf(42,58,BRANCO,PRETO,"Ira");
        tprintf(42,60,BRANCO,PRETO,"AFC");
        tprintf(42,62,BRANCO,PRETO,"34");
///----------------------------------------------
        tprintf(62,2,BRANCO,PRETO,"Servia");
        tprintf(62,4,BRANCO,PRETO,"UEFA");
        tprintf(62,6,BRANCO,PRETO,"38");
        tprintf(62,10,BRANCO,PRETO,"Nigeria");
        tprintf(62,12,BRANCO,PRETO,"CAF");
        tprintf(62,14,BRANCO,PRETO,"41");
        tprintf(62,18,BRANCO,PRETO,"Australia");
        tprintf(62,20,BRANCO,PRETO,"AFC");
        tprintf(62,22,BRANCO,PRETO,"43");
        tprintf(62,26,BRANCO,PRETO,"Japao");
        tprintf(62,28,BRANCO,PRETO,"AFC");
        tprintf(62,30,BRANCO,PRETO,"44");
        tprintf(62,34,BRANCO,PRETO,"Marrocos");
        tprintf(62,36,BRANCO,PRETO,"CAF");
        tprintf(62,38,BRANCO,PRETO,"48");
        tprintf(62,42,BRANCO,PRETO,"Panama");
        tprintf(62,44,BRANCO,PRETO,"CONCACAF");
        tprintf(62,46,BRANCO,PRETO,"49");
        tprintf(62,50,BRANCO,PRETO,"Coreia do Sul");
        tprintf(62,52,BRANCO,PRETO,"AFC");
        tprintf(62,54,BRANCO,PRETO,"62");
        tprintf(62,58,BRANCO,PRETO,"A.Saudita");
        tprintf(62,60,BRANCO,PRETO,"AFC");
        tprintf(62,62,BRANCO,PRETO,"63");
///----------------------------------------------
        do
        {
            tprintf(2,72,BRANCO,PRETO,"                    ");
            tprintf(1,72,BRANCO,PRETO,"Quantos paises quer comparar?");
            tscanf(31,72,BRANCO,PRETO,"%d",&n);
        }
        while(n<2||n>4);
        i=0;
        do
        {
            limpa_tela(PRETO);
            y=2;
            for(j=0; j<64; j++)
            {
                tprintf(14,y,VERDE_CLARO,PRETO,"|");
                y=y+1;
            }
            y=2;
            for(j=0; j<64; j++)
            {
                tprintf(36,y,VERDE_CLARO,PRETO,"|");
                y=y+1;
            }
            y=2;
            for(j=0; j<64; j++)
            {
                tprintf(56,y,VERDE_CLARO,PRETO,"|");
                y=y+1;
            }
            tprintf(2,2,BRANCO,PRETO,"Russia");
            tprintf(2,4,BRANCO,PRETO,"UEFA");
            tprintf(2,6,BRANCO,PRETO,"0");
            tprintf(2,8,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,10,BRANCO,PRETO,"Alemanha");
            tprintf(2,12,BRANCO,PRETO,"UEFA");
            tprintf(2,14,BRANCO,PRETO,"1");
            tprintf(2,16,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,18,BRANCO,PRETO,"Brasil");
            tprintf(2,20,BRANCO,PRETO,"CONMEBOL");
            tprintf(2,22,BRANCO,PRETO,"2");
            tprintf(0,24,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,26,BRANCO,PRETO,"Portugal");
            tprintf(2,28,BRANCO,PRETO,"UEFA");
            tprintf(2,30,BRANCO,PRETO,"3");
            tprintf(2,32,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,34,BRANCO,PRETO,"Argentina");
            tprintf(2,36,BRANCO,PRETO,"CONMEBOL");
            tprintf(2,38,BRANCO,PRETO,"4");
            tprintf(2,40,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,42,BRANCO,PRETO,"Belgica");
            tprintf(2,44,BRANCO,PRETO,"UEFA");
            tprintf(2,46,BRANCO,PRETO,"5");
            tprintf(2,48,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,50,BRANCO,PRETO,"Polonia");
            tprintf(2,52,BRANCO,PRETO,"UEFA");
            tprintf(2,54,BRANCO,PRETO,"6");
            tprintf(2,56,VERDE_CLARO,PRETO,"------------------------------------------------------------------------");
            tprintf(2,58,BRANCO,PRETO,"Franca");
            tprintf(2,60,BRANCO,PRETO,"UEFA");
            tprintf(2,62,BRANCO,PRETO,"7");
///--------------------------------------------
            tprintf(22,2,BRANCO,PRETO,"Espanha");
            tprintf(22,4,BRANCO,PRETO,"UEFA");
            tprintf(22,6,BRANCO,PRETO,"8");
            tprintf(22,10,BRANCO,PRETO,"Peru");
            tprintf(22,12,BRANCO,PRETO,"CONMEBOL");
            tprintf(22,14,BRANCO,PRETO,"10");
            tprintf(22,18,BRANCO,PRETO,"Suica");
            tprintf(22,20,BRANCO,PRETO,"CONMEBOL");
            tprintf(22,22,BRANCO,PRETO,"11");
            tprintf(22,26,BRANCO,PRETO,"Inglaterra");
            tprintf(22,28,BRANCO,PRETO,"UEFA");
            tprintf(22,30,BRANCO,PRETO,"12");
            tprintf(22,34,BRANCO,PRETO,"Colombia");
            tprintf(22,36,BRANCO,PRETO,"CONMEBOL");
            tprintf(22,38,BRANCO,PRETO,"13");
            tprintf(22,42,BRANCO,PRETO,"Mexico");
            tprintf(22,44,BRANCO,PRETO,"CONCACAF");
            tprintf(22,46,BRANCO,PRETO,"16");
            tprintf(22,50,BRANCO,PRETO,"Uruguai");
            tprintf(22,52,BRANCO,PRETO,"CONMEBOL");
            tprintf(22,54,BRANCO,PRETO,"17");
            tprintf(22,58,BRANCO,PRETO,"Croacia");
            tprintf(22,60,BRANCO,PRETO,"UEFA");
            tprintf(22,62,BRANCO,PRETO,"18");
///------------------------------------------------
            tprintf(42,2,BRANCO,PRETO,"Dinamarca");
            tprintf(42,4,BRANCO,PRETO,"UEFA");
            tprintf(42,6,BRANCO,PRETO,"19");
            tprintf(42,10,BRANCO,PRETO,"Islandia");
            tprintf(42,12,BRANCO,PRETO,"UEFA");
            tprintf(42,14,BRANCO,PRETO,"21");
            tprintf(42,18,BRANCO,PRETO,"Costa Rica");
            tprintf(42,20,BRANCO,PRETO,"CONCACAF");
            tprintf(42,22,BRANCO,PRETO,"22");
            tprintf(42,26,BRANCO,PRETO,"Suecia");
            tprintf(42,28,BRANCO,PRETO,"UEFA");
            tprintf(42,30,BRANCO,PRETO,"25");
            tprintf(42,34,BRANCO,PRETO,"Tunisia");
            tprintf(42,36,BRANCO,PRETO,"CAF");
            tprintf(42,38,BRANCO,PRETO,"28");
            tprintf(42,42,BRANCO,PRETO,"Egito");
            tprintf(42,44,BRANCO,PRETO,"CAF");
            tprintf(42,46,BRANCO,PRETO,"30");
            tprintf(42,50,BRANCO,PRETO,"Senegal");
            tprintf(42,52,BRANCO,PRETO,"CAF");
            tprintf(42,54,BRANCO,PRETO,"32");
            tprintf(42,58,BRANCO,PRETO,"Ira");
            tprintf(42,60,BRANCO,PRETO,"AFC");
            tprintf(42,62,BRANCO,PRETO,"34");
///----------------------------------------------
            tprintf(62,2,BRANCO,PRETO,"Servia");
            tprintf(62,4,BRANCO,PRETO,"UEFA");
            tprintf(62,6,BRANCO,PRETO,"38");
            tprintf(62,10,BRANCO,PRETO,"Nigeria");
            tprintf(62,12,BRANCO,PRETO,"CAF");
            tprintf(62,14,BRANCO,PRETO,"41");
            tprintf(62,18,BRANCO,PRETO,"Australia");
            tprintf(62,20,BRANCO,PRETO,"AFC");
            tprintf(62,22,BRANCO,PRETO,"43");
            tprintf(62,26,BRANCO,PRETO,"Japao");
            tprintf(62,28,BRANCO,PRETO,"AFC");
            tprintf(62,30,BRANCO,PRETO,"44");
            tprintf(62,34,BRANCO,PRETO,"Marrocos");
            tprintf(62,36,BRANCO,PRETO,"CAF");
            tprintf(62,38,BRANCO,PRETO,"48");
            tprintf(62,42,BRANCO,PRETO,"Panama");
            tprintf(62,44,BRANCO,PRETO,"CONCACAF");
            tprintf(62,46,BRANCO,PRETO,"49");
            tprintf(62,50,BRANCO,PRETO,"Coreia do Sul");
            tprintf(62,52,BRANCO,PRETO,"AFC");
            tprintf(62,54,BRANCO,PRETO,"62");
            tprintf(62,58,BRANCO,PRETO,"A.Saudita");
            tprintf(62,60,BRANCO,PRETO,"AFC");
            tprintf(62,62,BRANCO,PRETO,"63");
///----------------------------------------------
            tprintf(14,72,BRANCO,PRETO,"                    ");
            tprintf(1,72,BRANCO,PRETO,"NOME DO PAIS:");
            tscanf(15,72,BRANCO,PRETO,"%s",nome);
            tprintf(14,74,BRANCO,PRETO,"                    ");
            tprintf(1,74,BRANCO,PRETO,"CONFEDERACAO:");
            tscanf(15,74,BRANCO,PRETO,"%s",conf);
            tprintf(7,76,BRANCO,PRETO,"                    ");
            tprintf(1,76,BRANCO,PRETO,"RANK:");
            tscanf(6,76,BRANCO,PRETO,"%d",&ranq);
            criaselecao(probab,nome,conf,ranq);
            i++;
        }
        while(i<n);
        chance = PC_pensa(probab);
        limpa_tela(PRETO);
        tprintf(30,40,BRANCO,PRETO,"A Probabilidade das Selecoes Cairem no Mesmo Grupo e de: %.3f%%",chance);
        lertecla();
        lertecla();
        menu();
    }
}

int tamanho(ListaSel *pote) //verifica o tamanho do pote (quantas selecoes existem dentro)
{
    if(pote == NULL) return -1;
    int tam=0;
    ListaSel *and = pote;
    while(and!=NULL)
    {
        and = and->nextselecao;
        tam ++;
    }
    return tam;
}

int sorteiagrupos(ListaSel **pote, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) //sorteia uma seleção
{
    ListaSel *aux = NULL;
    aux = tirarselecao(pote, rand()%tamanho(*pote));
    colocaEmGrupo(aux,grupo,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);

    return 0;
}

int sorteiagrupos2(ListaSel **pote, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) //sorteia uma seleção
{
    ListaSel *aux = NULL;
    aux = tirarselecao(pote, rand()%tamanho(*pote));
    colocaEmGrupo2(aux,grupo,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);

    return 0;
}

int colocaEmGrupo(ListaSel *selecao, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH)
{
    int i;
    ListaSel **grupos[8] = {NULL};
    grupos[0] = grupoA;
    grupos[1] = grupoB;
    grupos[2] = grupoC;
    grupos[3] = grupoD;
    grupos[4] = grupoE;
    grupos[5] = grupoF;
    grupos[6] = grupoG;
    grupos[7] = grupoH;
    for(i=0; i<8; i++)
    {

        if(validagrupo(grupos[(i+grupo)%8], &selecao))
        {
            criaselecao(grupos[(i+grupo)%8],selecao->select.pais,selecao->select.confederacao,selecao->select.ranking);//cria a seleção dentro do grupo
            registratxt(selecao->select.pais);
            return 1;
        }
    }
    return 0;
}

int colocaEmGrupo2(ListaSel *selecao, int grupo, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH)
{
    int i;
    ListaSel **grupos[8] = {NULL};
    grupos[0] = grupoA;
    grupos[1] = grupoB;
    grupos[2] = grupoC;
    grupos[3] = grupoD;
    grupos[4] = grupoE;
    grupos[5] = grupoF;
    grupos[6] = grupoG;
    grupos[7] = grupoH;
    for(i=0; i<8; i++)
    {

        if(validagrupo(grupos[(i+grupo)%8], &selecao))
        {
            criaselecao(grupos[(i+grupo)%8],selecao->select.pais,selecao->select.confederacao,selecao->select.ranking);//cria a seleção dentro do grupo
            return 1;
        }
    }
    return 0;
}

int validagrupo(ListaSel **grupo, ListaSel **time)
{

    int tam2 = tamanho(*grupo);
    if(tam2>=4)
        return 0;

    int count=0;
    ListaSel *and  = *grupo;

    if(strcmp("UEFA",(*time)->select.confederacao)!=0)
        return 1;

    while(and!=NULL)
    {
        if(strcmp("UEFA",and->select.confederacao)==0)
            count++;
        and = and->nextselecao;
    }
    if(count>1)
    {

        return 0;
    }

    else
        return 1;
}

ListaSel *tirarselecao(ListaSel **pais, int posicao)//tira uma selecao da posição em que está no pote
{
    int i;
    if(*pais == NULL) return NULL;
    if (posicao == 0)
    {
        ListaSel *temp = *pais;
        *pais = (*pais)->nextselecao;
        temp->nextselecao = NULL;
        return temp;
    }
    if(posicao>0&&posicao<tamanho(*pais))
    {
        ListaSel *and = *pais;
        for(i=0; i<posicao-1; i++) and = and->nextselecao;
        ListaSel *temp = and->nextselecao;
        if((and->nextselecao)->nextselecao == NULL) and->nextselecao = NULL;
        else and->nextselecao = (and->nextselecao)->nextselecao;
        temp->nextselecao = NULL;
        return temp;
    }
    else return NULL;
}

ListaSel *mostraselecao(ListaSel *pais, int posicao)
{
    ListaSel *temp = NULL;
    ListaSel *aux = pais;
    int i;
    if(aux == NULL)
        return NULL;
    if(posicao<tamanho(pais))
    {
        ListaSel *and = pais;
        for(i=0; i<posicao; i++) and = and->nextselecao;
        aux = and;
        criaselecao(&temp,aux->select.pais,aux->select.confederacao,aux->select.ranking);
        return temp;
    }
    else return NULL;
}

float PC_pensa(ListaSel **times)
{
    float chance = 0;
    float x=0;
    int i = 0;
    for(i = 0; i < 10000; i++)
    {
        chance = (float) possibilidades(times);
        x = chance + x;
    }
    return x/100;
}
int possibilidades(ListaSel **probab)
{
    int chance = 0;

    ListaSel *pote1  = NULL;
    ListaSel *pote2  = NULL;
    ListaSel *pote3  = NULL;
    ListaSel *pote4  = NULL;

    ListaSel *grupoA = NULL;
    ListaSel *grupoB = NULL;
    ListaSel *grupoC = NULL;
    ListaSel *grupoD = NULL;
    ListaSel *grupoE = NULL;
    ListaSel *grupoF = NULL;
    ListaSel *grupoG = NULL;
    ListaSel *grupoH = NULL;

    cadastrar2(&pote1,&pote2,&pote3,&pote4,&grupoA);
    sortear2(&pote1,&pote2,&pote3,&pote4,&grupoA,&grupoB,&grupoC,&grupoD,&grupoE,&grupoF,&grupoG,&grupoH);


    int plus;

    plus = comparagrupos(&grupoA,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoB,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoC,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoD,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoE,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoF,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoG,probab);
    chance = chance + plus;
    plus = comparagrupos(&grupoH,probab);
    chance = chance + plus;

    return chance;
}

int comparagrupos(ListaSel **grupo,ListaSel **prob)
{

    int tam = tamanho(*prob);
    int tam2 = tamanho(*grupo);
    int i;
    int j;
    int count=0;
    ListaSel *aux  = NULL;
    ListaSel *aux2 = NULL;

    for(i=0 ; i < tam ; i++)
    {
        aux = mostraselecao(*prob,i);
        for(j=0 ; j < tam2 ; j++)
        {
            aux2 = mostraselecao(*grupo,j);
            if(aux2->select.ranking == aux->select.ranking) count ++;
        }
    }
    if(count <= tamanho(*prob)-1) return 0;
    else return 1;
}

void automaticamente(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) ///PRINTA O SORTEIO JÁ FEITO
{
    ListaSel *aux = NULL;
    limpa_tela(PRETO);
    int y = 0, i = 0;
    y=13;
    ///POTE 1
    for(i=0; i<7; i++)
    {
        tprintf(33,9,AMARELO_CLARO,PRETO,"Pote 1:",aux->select.pais);
        tprintf(29,11,CINZA_CLARO,PRETO,"1-");
        tprintf(29,y,CINZA_CLARO,PRETO,"%d-",i+2);
        aux = mostraselecao(*grupoA,0);
        tprintf(33,11,BRANCO,PRETO,"%s",aux->select.pais);
        aux = mostraselecao(*pote1,i);
        tprintf(33,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///POTE 2
    y = 11;
    for(i=0; i<8; i++)
    {
        tprintf(48,9,AMARELO_CLARO,PRETO,"Pote 2:",aux->select.pais);
        aux = mostraselecao(*pote2,i);
        tprintf(48,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    y = 11;
    ///POTE 3
    for(i=0; i<8; i++)
    {
        tprintf(63,9,AMARELO_CLARO,PRETO,"Pote 3:",aux->select.pais);
        aux = mostraselecao(*pote3,i);
        tprintf(63,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    y = 11;
    ///POTE 4
    for(i=0; i<8; i++)
    {
        tprintf(78,9,AMARELO_CLARO,PRETO,"Pote 4:",aux->select.pais);
        aux = mostraselecao(*pote4,i);
        tprintf(78,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
///------------------------------------SORTEIO----------------------------------------------------
    for(i=1; i<8; i++)
    {
        sorteiagrupos(pote1,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }


    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote2,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote3,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote4,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
///-------------------------------------------------------------------------------------------------

    ///GRUPO A
    y=41;

    for(i=0; i<4; i++)
    {
        tprintf(1,39,VERDE_CLARO,PRETO,"Grupo A:",aux->select.pais);
        aux = mostraselecao(*grupoA,i);
        tprintf(1,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///Grupo B
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(16,39,VERDE_CLARO,PRETO,"Grupo B:",aux->select.pais);
        aux = mostraselecao(*grupoB,i);
        tprintf(16,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO C
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(32,39,VERDE_CLARO,PRETO,"Grupo C:",aux->select.pais);
        aux = mostraselecao(*grupoC,i);
        tprintf(32,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO D
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(47,39,VERDE_CLARO,PRETO,"Grupo D:",aux->select.pais);
        aux = mostraselecao(*grupoD,i);
        tprintf(47,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO E
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(62,39,VERDE_CLARO,PRETO,"Grupo E:",aux->select.pais);
        aux = mostraselecao(*grupoE,i);
        tprintf(62,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO F
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(77,39,VERDE_CLARO,PRETO,"Grupo F:",aux->select.pais);
        aux = mostraselecao(*grupoF,i);
        tprintf(77,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO G
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(93,39,VERDE_CLARO,PRETO,"Grupo G:",aux->select.pais);
        aux = mostraselecao(*grupoG,i);
        tprintf(93,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///GRUPO H
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(107,39,VERDE_CLARO,PRETO,"Grupo H:",aux->select.pais);
        aux = mostraselecao(*grupoH,i);
        tprintf(107,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    lertecla();
    lertecla();
}

void overtime(ListaSel **pote1, ListaSel **pote2, ListaSel **pote3, ListaSel **pote4, ListaSel **grupoA, ListaSel **grupoB, ListaSel **grupoC, ListaSel **grupoD, ListaSel **grupoE, ListaSel **grupoF, ListaSel **grupoG, ListaSel **grupoH) ///SORTEIA UMA SELECAO A CADA SEGUNDO, FAZ O POTE INTEIRO ANTES DE PASSAR PRO PROX
{
    ListaSel *aux = NULL;
    limpa_tela(PRETO);
    int y = 0, i = 0;
    y=13;
    ///POTE 1
    for(i=0; i<7; i++)
    {
        tprintf(33,9,AMARELO_CLARO,PRETO,"Pote 1:",aux->select.pais);
        tprintf(29,11,CINZA_CLARO,PRETO,"1-");
        tprintf(29,y,CINZA_CLARO,PRETO,"%d-",i+2);
        aux = mostraselecao(*grupoA,0);
        tprintf(33,11,BRANCO,PRETO,"%s",aux->select.pais);
        aux = mostraselecao(*pote1,i);
        tprintf(33,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    ///POTE 2
    y = 11;
    for(i=0; i<8; i++)
    {
        tprintf(48,9,AMARELO_CLARO,PRETO,"Pote 2:",aux->select.pais);
        aux = mostraselecao(*pote2,i);
        tprintf(48,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    y = 11;
    ///POTE 3
    for(i=0; i<8; i++)
    {
        tprintf(63,9,AMARELO_CLARO,PRETO,"Pote 3:",aux->select.pais);
        aux = mostraselecao(*pote3,i);
        tprintf(63,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    y = 11;
    ///POTE 4
    for(i=0; i<8; i++)
    {
        tprintf(78,9,AMARELO_CLARO,PRETO,"Pote 4:",aux->select.pais);
        aux = mostraselecao(*pote4,i);
        tprintf(78,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
///-----------------------------------------------------------------------------------------------------------------------------
    for(i=1; i<8; i++)
    {
        sorteiagrupos(pote1,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote2,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote3,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    for(i=0; i<8; i++)
    {
        sorteiagrupos(pote4,i,grupoA,grupoB,grupoC,grupoD,grupoE,grupoF,grupoG,grupoH);
    }
    ///PRIMEIRO POTE
    delay(1000);
    ///GRUPO A
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(1,39,VERDE_CLARO,PRETO,"Grupo A:",aux->select.pais);
        aux = mostraselecao(*grupoA,i);
        tprintf(1,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(1,y,BRANCO,PRETO,"%s ",aux->select.pais);
        y = y+2;
    }
    ///GRUPO B
    delay(1000);
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(16,39,VERDE_CLARO,PRETO,"Grupo B:",aux->select.pais);
        aux = mostraselecao(*grupoB,i);
        tprintf(16,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(16,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO C
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(32,39,VERDE_CLARO,PRETO,"Grupo C:",aux->select.pais);
        aux = mostraselecao(*grupoC,i);
        tprintf(32,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(32,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO D
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(47,39,VERDE_CLARO,PRETO,"Grupo D:",aux->select.pais);
        aux = mostraselecao(*grupoD,i);
        tprintf(47,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(47,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO E
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(62,39,VERDE_CLARO,PRETO,"Grupo E:",aux->select.pais);
        aux = mostraselecao(*grupoE,i);
        tprintf(62,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(62,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO F
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(77,39,VERDE_CLARO,PRETO,"Grupo F:",aux->select.pais);
        aux = mostraselecao(*grupoF,i);
        tprintf(77,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(77,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO G
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(93,39,VERDE_CLARO,PRETO,"Grupo G:",aux->select.pais);
        aux = mostraselecao(*grupoG,i);
        tprintf(93,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(93,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO H
    y=41;
    for(i=0; i<4; i++)
    {
        tprintf(107,39,VERDE_CLARO,PRETO,"Grupo H:",aux->select.pais);
        aux = mostraselecao(*grupoH,i);
        tprintf(107,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(107,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
///-------------------------------------------------------------------------------------
    delay(3000);
    limpa_tela(PRETO);
    ///GRUPO A
    y=24;
    for(i=0; i<4; i++)
    {
        tprintf(27,22,VERDE_CLARO,PRETO,"Grupo A:",aux->select.pais);
        aux = mostraselecao(*grupoA,i);
        tprintf(27,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(27,y,BRANCO,PRETO,"%s ",aux->select.pais);
        y = y+2;
    }
    ///GRUPO B
    delay(1000);
    y=24;
    for(i=0; i<4; i++)
    {
        tprintf(47,22,VERDE_CLARO,PRETO,"Grupo B:",aux->select.pais);
        aux = mostraselecao(*grupoB,i);
        tprintf(47,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(47,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO C
    y=24;
    for(i=0; i<4; i++)
    {
        tprintf(67,22,VERDE_CLARO,PRETO,"Grupo C:",aux->select.pais);
        aux = mostraselecao(*grupoC,i);
        tprintf(67,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(67,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO D
    y=24;
    for(i=0; i<4; i++)
    {
        tprintf(87,22,VERDE_CLARO,PRETO,"Grupo D:",aux->select.pais);
        aux = mostraselecao(*grupoD,i);
        tprintf(87,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(87,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
///------------------------------------------------------------------------------
    delay(1000);
    ///GRUPO E
    y=46;
    for(i=0; i<4; i++)
    {
        tprintf(27,44,VERDE_CLARO,PRETO,"Grupo E:",aux->select.pais);
        aux = mostraselecao(*grupoE,i);
        tprintf(27,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(27,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO F
    y=46;
    for(i=0; i<4; i++)
    {
        tprintf(47,44,VERDE_CLARO,PRETO,"Grupo F:",aux->select.pais);
        aux = mostraselecao(*grupoF,i);
        tprintf(47,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(47,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO G
    y=46;
    for(i=0; i<4; i++)
    {
        tprintf(67,44,VERDE_CLARO,PRETO,"Grupo G:",aux->select.pais);
        aux = mostraselecao(*grupoG,i);
        tprintf(67,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(67,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    delay(1000);
    ///GRUPO H
    y=46;
    for(i=0; i<4; i++)
    {
        tprintf(87,44,VERDE_CLARO,PRETO,"Grupo H:",aux->select.pais);
        aux = mostraselecao(*grupoH,i);
        tprintf(87,y,BRANCO,PRETO,"      ",aux->select.pais);
        tprintf(87,y,BRANCO,PRETO,"%s",aux->select.pais);
        y = y+2;
    }
    lertecla();
    lertecla();
    menu();
}
