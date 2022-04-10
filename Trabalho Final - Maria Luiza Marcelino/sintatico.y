/*      Teoria de Linguagens e Compiladores

Maria Luiza Silva Marcelino - 2017.1.08.009
Data - 24/03/2022

*/
/*  Arquivos de cabecalho  */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.c"  
#include "estrut.c"  


void erro(char *);
int yyerror(char *);
int conta = 0;          
int rotulo = 0;         
char tipo;              
char cat;            
int endereco;
int auxIndex;
%}

%start programa  

/*  TOKENS  */
%token T_PROGRAMA 
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
%token T_ABREC
%token T_FECHAC

%token T_REPITA  // Atividade prática 1
%token T_ATE     //Atividade prática 2
%token T_FIMREPITA


%left T_E       T_OU  
%left T_IGUAL   
%left T_MAIOR   T_MENOR
%left T_MAIS    T_MENOS
%left T_VEZES   T_DIV  
%left T_ABRE    T_ABREC
/*  GRAMATICA DE CONTEXTO  */
%%
programa
    :   cabecalho variaveis 
            { 
                mostra_tabela(); 
                fprintf(yyout, "\tAMEM\t%d\n", conta);  
                empilha(conta); 
            }    
        T_INICIO lista_comandos T_FIM                     
            { 
                fprintf(yyout, "\tDMEM\t%d\n", desempilha());  
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

variavel 
    :   T_IDENTIF {strcpy(elem_tab.id, atomo);}     //preenche a tabela com o nome encontrado
            tamanho      
    ; 

lista_variaveis
    :   lista_variaveis variavel 
            {
                elem_tab.endereco = conta;
                elem_tab.tipo = tipo;
                if (!auxIndex)
                    {
                        elem_tab.categoria = 'v';    
                        elem_tab.tamanho = 1;
                        conta++;
                    }
                else 
                    {
                        elem_tab.categoria = 'a';    
                        elem_tab.tamanho = auxIndex;
                        conta = conta + auxIndex;
                    }
                insere_simbolo(elem_tab);       
            } 
    |   variavel 
            {
                elem_tab.endereco = conta;    
                elem_tab.tipo = tipo;
                if (!auxIndex)
                    {             
                        elem_tab.categoria = 'v';    
                        elem_tab.tamanho = 1;
                        conta++;
                    }
                else 
                    {   
                        
                        elem_tab.categoria = 'a';    
                        elem_tab.tamanho = auxIndex;
                        conta = conta + auxIndex;
                    }
                insere_simbolo(elem_tab);       
            }
    ;

tamanho 
    : { auxIndex = 0; }  
    | T_ABREC T_NUMERO T_FECHAC { auxIndex = atoi(atomo); }  
    ;
declaracao_variaveis
    :   tipo    lista_variaveis    declaracao_variaveis
    |   tipo    lista_variaveis
    ;

tipo
    :   T_INTEIRO   { tipo = 'i';}
    |   T_LOGICO    { tipo = 'l';}
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
                int pos = busca_simbolo(atomo);
                if (pos == -1) erro("Variavel não declarada");
                empilha(pos);
                //fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco); // acho que nao é aqui  
            } 
            colchetes {

            }
    ;
colchetes
   :   {
       fprintf(yyout, "\tLEIA\n");
       int pos = desempilha();
       fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco); //endereço de variavel sem ser vetor
   }
    | T_ABREC expr T_FECHAC
        {
            fprintf(yyout, "\tLEIA\n");
            char t = desempilha();
            if(t != 'i')
                erro("Incompatibilidade de tipos"); //verifica se o vetor é inteiro
            int pos = desempilha();
            fprintf(yyout, "\tARZV\t%d\n", TabSimb[pos].endereco);    //endereço de variavel vetor
        }
    ;


escrita
    :   T_ESCREVA expr
            { 
                desempilha();
                fprintf(yyout, "\tESCR\n"); 
            }
    ;

repeticao
    :   T_ENQTO 
            { 
                rotulo++; //cria rotulo AQUI
                fprintf(yyout, "L%d\tNADA\n", rotulo);  
                empilha(rotulo);  
            } 
        expr T_FACA
            {
                char t = desempilha();           
                    if (t != 'l')
                        erro("Incompatibilidade de tipos!");
                rotulo++;
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo); //desvia se falso
                empilha(rotulo);
            }  
        lista_comandos   T_FIMENQTO
            {
                int r1 = desempilha(); 
                int r2 = desempilha(); 
                fprintf(yyout, "\tDSVS\tL%d\n", r2);    //desvia se verdadeiro
                fprintf(yyout, "L%d\tNADA\n", r1);  
            }
    |   T_REPITA lista_comandos T_ATE expr      T_FIMREPITA 
    ;

selecao
    :   T_SE    expr    T_ENTAO 
            {
                char t = desempilha();           
                    if (t != 'l')
                        erro ("Incompatibilidade de tipos!");
                rotulo++; 
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo);  
                empilha(rotulo); //rotulo do senao
            }
        lista_comandos T_SENAO 
            {
                int r = desempilha(rotulo);                 //guarda rotulo do senao falto
                rotulo++;                                   
                fprintf(yyout, "\tDSVS\tL%d\n", rotulo);    
                empilha(rotulo);                            
                fprintf(yyout, "L%d\tNADA\n", r);  }        
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
        if (TabSimb[pos].tipo != 'i') 
            erro ("Incompatibilidade de tipos");
        endereco = TabSimb[pos].endereco; //guardo o endereço do variavel pra usar ali no final depois

    } T_ATRIB expr
            {
                char t = desempilha(); //desempilha um tipo que vem a expr
                if(t != 'i')
                    erro("Só se pode atribuir valores inteiros");
                fprintf(yyout, "\tARZG\t%d\n", endereco); //gera arzg com o endereço da variavel normal
            }
    |   T_IDENTIF
    {
        int pos = busca_simbolo(atomo); 
        if (pos == -1) 
            erro("Variavel não declarada");
        if (TabSimb[pos].tipo != 'i') 
            erro ("Só se pode atribuir valores inteiros");
        endereco = TabSimb[pos].endereco; //guardo o endereço do variavel pra usar ali no final depois

    } T_ABREC expr T_FECHAC 
    {
        int t = desempilha(); //desempilha um tipo que vem a expr
        if(t != 'i') 
            erro("Incompatibilidade de tipos");
    }
    T_ATRIB expr
    {
        int t = desempilha(); //desempilha um tipo que vem a expr
        if(t != 'i') 
            erro("Incompatibilidade de tipos");
        fprintf(yyout, "\tARZV\t%d\n", endereco); //gera arzv com o endereço da variavel vetor
    }
    ;

indice
    : 
    | T_ABREC expr T_FECHAC
        {
            char t = desempilha(); //desempilha o tipo e ve se é inteiro
            if(t != 'i')
                erro("Incompatibilidade de tipos");
        }
    ;

expr  
    :   expr    T_VEZES    expr  /*  CALCULOS ARITMETICOS  */
            {
                char t1 = desempilha();            
                char t2 = desempilha();            
                if (t1 != 'i' || t2 != 'i')         
                    erro ("Incompatibilidade de tipos!");
                empilha('i');
                fprintf(yyout, "\tMULT\n");
            }
    |   expr    T_DIV      expr
            {   
                char t1 = desempilha();            
                char t2 = desempilha();             
                if (t1 != 'i' || t2 != 'i')         
                    erro ("Incompatibilidade de tipos!");
                empilha('i');
                fprintf(yyout, "\tDIVI\n");  
            }
    |   expr    T_MAIS     expr
            { 
                char t1 = desempilha();            
                char t2 = desempilha();           
                if (t1 != 'i' || t2 != 'i')        
                    erro ("Incompatibilidade de tipos!");
                empilha('i');
                fprintf(yyout, "\tSOMA\n");  
            }
    |   expr    T_MENOS    expr
            {
                char t1 = desempilha();             
                char t2 = desempilha();             
                if (t1 != 'i' || t2 != 'i')        
                    erro ("Incompatibilidade de tipos!");
                empilha('i');
                fprintf(yyout, "\tSUBT\n");  
            }
    |   expr    T_MAIOR    expr  /*  CALCULOS RELACIONAIS  */
            { 
                char t1 = desempilha();             
                char t2 = desempilha();             
                if (t1 != 'i' || t2 != 'i')         
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tCMMA\n");  
            }
    |   expr    T_MENOR    expr
            {
                char t1 = desempilha();             
                char t2 = desempilha();            
                if (t1 != 'i' || t2 != 'i')        
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tCMME\n");  
            }
    |   expr    T_IGUAL    expr
            { 
                char t1 = desempilha();             
                char t2 = desempilha();             
                if (t1 != 'i' || t2 != 'i')         
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tCMIG\n");  
            }
    |   expr    T_E        expr  /*  CALCULOS LOGICOS      */
            {
                char t1 = desempilha();             
                char t2 = desempilha();             
                if (t1 != 'l' || t2 != 'l')         
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tCONJ\n");  
            }
    |   expr    T_OU       expr
            {
                char t1 = desempilha();             
                char t2 = desempilha();             
                if (t1 != 'l' || t2 != 'l')         
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tDISJ\n");  
            }
    |   termo  //se vai pra termo se nao achar
    ;

termo
    :   T_IDENTIF //talvez o indice fique aqui 
            {
                int pos = busca_simbolo(atomo);
                if (pos == -1) 
                    erro("Variavel não declarada");
                empilha(TabSimb[pos].tipo);
                empilha(pos);

            } indice { //depois de fazer a verificaçao de tipos no indice vem pra ca pra gerar crvg ou crvv
                int pos = desempilha();
                if (TabSimb[pos].categoria == 'v') 
                    fprintf(yyout, "\tCRVG\t%d\n", TabSimb[pos].endereco); //gera crvg se é variavel
                if (TabSimb[pos].categoria == 'a') 
                    fprintf(yyout, "\tCRVV\t%d\n", TabSimb[pos].endereco); // gera crvv se é vetor
            } 
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
                    erro ("Incompatibilidade de tipos!");
                empilha('l');
                fprintf(yyout, "\tNEGA\n");  
            }
    |   T_ABRE  expr    T_FECHA
    ;

%%

void erro (char *s){
    printf("ERRO linha %d: %s\n", numLinha, s);
    exit(10);
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
    
    strcpy(nameIn, argv[0]); // Nome do programa sem extensão adicionado como nome do arquivo de entrada
    strcat(nameIn, ".simples"); // Adiciona a extensão simples
    strcpy(nameOut, argv[0]); // Nome do programa sem extensão adicionado como nome do arquivo de saida
    strcat(nameOut, ".mvs"); // Adiciona a extensão mvs da Maquina Simples

    yyin = fopen(nameIn, "rt");
    if(!yyin){
        puts("Programa fonte nao encontrado!");
        exit(10);
    }
    yyout = fopen(nameOut, "wt");

    if(!yyparse())
        puts("Programa ok!");// Caso o programa rodar imprime OK
}
