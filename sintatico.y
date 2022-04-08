
/*  Arquivos de cabecalho  */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.c"  //Incluir o programa todo.
#include "estrut.c"  //Incluir o programa todo. /* Exemplo de Link Edit: extern char atomo[100]; */


void erro(char *);
int yyerror(char *);
int conta = 0;          /* Contar número de variaveis           */
int rotulo = 0;         /* Marcar locais dentro do código       */
char tipo;           //tipo[4]
char cat;            //MODIFIED: /* Insere uma categoria a variavel      TODO:MODIFICAR PARA VET[4] PRO TIPO PEDIDO   */
int auxIndex;
%}

%start programa  /*  SIMBOLO INICIAL - SIMBOLO DE PARTIDA  */


%token T_PROGRAMA /*  SIMBOLOS TERMINAIS - TOKENS  */
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_IGUAL
%token T_MAIOR
%token T_MENOR
%token T_E
%token T_OU
%token T_V
%token T_F
%token T_NUMERO
%token T_NAO
%token T_ABRE
%token T_FECHA
%token T_INTEIRO
%token T_LOGICO
%token T_ABRE_COL
%token T_FECHA_COL

%token T_REPITA  
%token T_ATE     
%token T_FIMREPITA


%left T_E       T_OU  /*  DEFINICAO DE PRECEDENCIA - EVITAR CONFLITO DE ERRO DE DESLOCAMENTO  */
%left T_IGUAL   
%left T_MAIOR   T_MENOR
%left T_MAIS    T_MENOS
%left T_VEZES   T_DIV  /*  REGRAS SÃO LIDAS - TEM SEU VALOR DE PRIORIDADE - DE BAIXO PRA CIMA  */ 

/*  GRAMATICA DE CONTEXTO  */
%%
programa
    :   cabecalho variaveis /*  Estrutura Geral de um programa.  */
            { 
                mostra_tabela(); 
                fprintf(yyout, "\tAMEN\t%d\n", conta);  
                empilha(conta); 
            }   /*  Cada variavel que for declarada gerará um AMEN */ 
        T_INICIO lista_comandos T_FIM                     
            { 
                fprintf(yyout, "\tDMEN\t%d\n", desempilha());  
                fprintf(yyout, "\tFIMP\n");  
            }
    ;

cabecalho
    :   T_PROGRAMA T_IDENTIF
            { fprintf(yyout, "\tINPP\n");  }
    ;

variaveis
    :   /* Nenhuma */
    |   declaracao_variaveis
    ;

declaracao_variaveis
    :   tipo    lista_variaveis    declaracao_variaveis
    |   tipo    lista_variaveis
    ;

tipo
    :   T_INTEIRO   { tipo = 'i';} /* TODO: [x] MODIFICAR PARA INT */ /* DONE:Tratar apenas quando mostrar na tela */
    |   T_LOGICO    { tipo = 'l';} /* TODO: [x] MODIFICAR PARA lOG */ /* DONE:Tratar apenas quando mostrar na tela */
    ;

variavel
    :   T_IDENTIF { strcpy(elem_tab.id, atomo); }     /* Preenchendo elemento da tabela com o nome encontrado */
            tamanho        
    ; 

tamanho
    :   {
            int pos = atoi(atomo);//TODO: cadastrar variavel simples DONE:
            elem_tab.categoria = 'v';     /* v = indica que é uma variavel   */
            elem_tab.endereco = conta;    /* Incrementa conta quando encontrar variaveis          */
            conta++;
            elem_tab.tamanho = 1;
            
        }
    |   T_ABRE_COL T_NUMERO 
            {
                /*TODO:cadastrar vetor*/
                int count = atoi(atomo);
                elem_tab.categoria = 'a';       /* a = indica que é um array   */
                elem_tab.endereco = conta;   /* Incrementa conta quando encontrar variaveis          */
                conta += count; 
                elem_tab.tamanho = count;
                elem_tab.tipo = tipo;
                
            } T_FECHA_COL
    ;

indice
    : {
        char t = desempilha(); //desempilho o tipo
        if(t != 'i') //if(!(strcmp(t, 'INT')))
                erro("Incompatibilidade de tipos");
        empilha(t);
    }
    |   T_ABRE_COL expr  T_FECHA_COL //trata variavel com colchetes
        {
            //não sei o que faço
        }
    ;

posicao
    :   {
            fprintf(yyout, "\tLEIA\n");
            int pos = desempilha();
            fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco);  /* (endereço da variavel na estrutura) */
        }
    |   T_ABRE_COL expr
            {
                int t = desempilha();
                int p = desempilha();
                if(t == 'l')
                    erro("Tipo do indice deve ser inteiro");
                if(TabSimb[p].categoria != 'a')
                    erro("A variavel nao é um vetor");
                empilha(p);
            }
        T_FECHA_COL
    ;

lista_variaveis
    :   lista_variaveis variavel
            {
                elem_tab.tipo = tipo;
                insere_simbolo(elem_tab);       /* Inserir o simbolo na tabela de simbolos              */
            }
    |   variavel
            {
                elem_tab.tipo = tipo;
                insere_simbolo(elem_tab);       /* Inserir o simbolo na tabela de simbolos              */
            }
    ;

lista_comandos
    :
    |   comando    lista_comandos
    ;

comando
    :   leitura
    |   escrita
    |   repeticao
    |   selecao
    |   atribuicao
    ;

leitura
    :   T_LEIA    T_IDENTIF
            {
                int pos = busca_simbolo(atomo); /* Busca o nome na tabela de Simbolo associado ao T_IDENTIF guardado na variavel 'atomo' */
                if (pos == -1) erro("Variavel não declarada");
                empilha(pos);
                printf("Chegou no leia");
            }
        colchetes {
            printf("Chegou no colchetes");
            int pos = desempilha();
            fprintf(yyout, "\tARZV\t%d\n", TabSimb[pos].endereco);
            }
    ;

colchetes
    : {
            fprintf(yyout, "\tLEIA\n");
            int pos = desempilha();
            fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco);  
        }
    | T_ABRE_COL expr T_FECHA_COL
        {
            char t = desempilha();
            int pos = desempilha(); //desempilha posiçao
            if(t != 'i') 
                erro("Incompatibilidade de tipos");
            fprintf(yyout, "\tLEIA\n"); 
        }
;
escrita
    :   T_ESCREVA expr
            { fprintf(yyout, "\tESCR\n"); }
    ;

repeticao
    :   T_ENQTO 
            { 
                rotulo++; /*  Cria um rotulo adicionando 1 a variavel  */
                fprintf(yyout, "L%d\tNADA\n", rotulo);  /*  Marca UM lugar NO CODIGO com o VALOR do ROTULO CRIADO acima  */
                empilha(rotulo);  /*  Empilha o valor do rotulo como um lugar a ser retornado futuramente  */
            } /* %d (endereço da variavel na estrutura) */ //Marca o desvio Se Verdadeiro
        expr T_FACA
            {
                rotulo++;
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo); /* Desvia se Falso */ 
                empilha(rotulo);
            }  
        lista_comandos   T_FIMENQTO
            {
                int r1 = desempilha(); /* Rotulo de Saida da Repeticao */
                int r2 = desempilha(); /* Rotulo de Entrada da Repeticao */
                fprintf(yyout, "\tDSVS\tL%d\n", r2);    /* Desvia se Verdadeiro */
                fprintf(yyout, "L%d\tNADA\n", r1);      /* Marca desvio Se Falso */
            }
    |   T_REPITA 
            {
                rotulo++;                                   /*  Cria um rotulo adicionando 1 a variavel  */
                fprintf(yyout, "L%d\tNADA\n", rotulo);      /*  Marca UM lugar NO CODIGO para VOLTAR caso REPITA for DSVF */
                empilha(rotulo);                            /*  Empilha o valor do rotulo SINALIZANDO o LUGAR para VOLTAR */
            }
            lista_comandos T_ATE expr
                {
                    char t = desempilha();                  /* Tipo do identificador */
                    if(t != 'l')                            /* Verificação de tipos coerentes */
                        erro("Incompatibilidade de tipos");
                    int r = desempilha();                   /* Busca o rotulo da repeticao */
                    fprintf(yyout, "\tDSVF\tL%d\n", r);     /* Volta ao rotulo caso Falso */
                }
        T_FIMREPITA /* Atividade 2 - REPITA-ATE-FIMREPITA + Atividade 3 Semantico do comando Repita*/ 
    ;


selecao
    :   T_SE    expr    T_ENTAO 
            {
                char t = desempilha();              /* Desempilha o tipo do identificador */
                    if (t != 'l')
                        erro ("Incompatibilidade de tipos");
                rotulo++; 
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo);  
                empilha(rotulo);                    /*  Rotulo do SENAO  */
            }
        lista_comandos T_SENAO 
            {
                int r = desempilha();                 /* Guarda rotulo do SENAO FALSO*/
                rotulo++;                                   /* Cria rotulo do Desvia Sempre */
                fprintf(yyout, "\tDSVS\tL%d\n", rotulo);    /* Marca com Rotulo Desvia Sempre */
                empilha(rotulo);                            /*  Empilha lugar do Desvia Sempre */
                fprintf(yyout, "L%d\tNADA\n", r);  }        /* Usa rotulo SenaoFalso para marcar lugar no codigo */ 
        lista_comandos T_FIMSE
            {
                int r = desempilha();
                fprintf(yyout, "L%d\tNADA\n", r);
            }
    ;

atribuicao
    :   T_IDENTIF
            {
                int pos = busca_simbolo(atomo); 
                if (pos == -1) 
                    erro("Variavel não declarada");
                empilha(pos);
            }
        posicao T_ATRIB   expr
            {
                int t = desempilha();
                int pos = desempilha();
                fprintf(yyout, "\tARZV\t%d\n", TabSimb[pos].endereco);  
            
            }

    ;

expr  
    :   expr    T_VEZES    expr  /*  CALCULOS ARITMETICOS  */
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tMULT\n");
            }
    |   expr    T_DIV      expr
            {   
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tDIVI\n");  
            }
    |   expr    T_MAIS     expr
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos é esse");
                empilha('i');
                fprintf(yyout, "\tSOMA\n");  
                printf("saiu da expressao");
            }
    |   expr    T_MENOS    expr
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tSUBT\n");  
            }
    |   expr    T_MAIOR    expr  /*  CALCULOS RELACIONAIS  */
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMMA\n");  
            }
    |   expr    T_MENOR    expr
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMME\n");  
            }
    |   expr    T_IGUAL    expr
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMIG\n");  
            }
    |   expr    T_E        expr  /*  CALCULOS LOGICOS      */
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'l' || t2 != 'l')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCONJ\n");  
            }
    |   expr    T_OU       expr
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'l' || t2 != 'l')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tDISJ\n");  
            }
    |   termo  /*  TERMO : não possui estrura expr-operador-expr    */
    ;

termo
    :   T_IDENTIF //nao chama indice aqui
            {
                int pos = busca_simbolo(atomo);     
                if (pos == -1) 
                    erro("Variavel não declarada");
                fprintf(yyout, "\tCRVG\t%d\n", TabSimb[pos].endereco);
                empilha(pos);
                empilha(TabSimb[pos].tipo); //aqui empila tipo também
            } indice 
    |   T_NUMERO
            { 
                empilha('i');
                fprintf(yyout, "\tCRCT\t%s\n", atomo);  
            }       
    |   T_V
            { 
                empilha('l');
                fprintf(yyout, "\tCRCT\t1\n");  
            }
    |   T_F
            { 
                empilha('l');
                fprintf(yyout, "\tCRCT\t0\n");  
            }
    |   T_NAO   termo
            {
                char t = desempilha();
                if (t != 'l')
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tNEGA\n");  
            }
    |   T_ABRE  expr    T_FECHA 
    ;

%%

void erro (char *s){
    printf("ERRO: %s\n", s);
}

int yyerror (char *s){
    erro(s);
}


 int main(int argc, char *argv[]){ // Adicionar feature de leitura por parametro //argv[0] = nome do executavel
    char *p, nameIn[100], nameOut[100];
    argv++; // incrementando pós nome do executavel
    if(argc < 2){ // indo para o parametro passado em linha de comando
        puts("\nCompilador Simples");
        puts("\tUSO: ./simples <nomefonte>[.simples]\n\n"); // Imprimir como usar na tela.
        exit(10);
    }
    p = strstr(argv[0], ".simples"); 
    if (p) *p = 0; // Se tiver extensão apaga a extensão
    
    strcpy(nameIn, argv[0]); //arquivo de entrada
    strcat(nameIn, ".simples"); //extensão simples
    strcpy(nameOut, argv[0]); //arquivo de saida
    strcat(nameOut, ".mvs"); //extensão mvs da Maquina Simples

    yyin = fopen(nameIn, "rt");
    if(!yyin){
        puts("Programa fonte nao encontrado!");
        exit(10);
    }
    yyout = fopen(nameOut, "wt");

    if(!yyparse())
        puts("Programa Ok!");//se não houver erro
}