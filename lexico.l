/* |---------------------------------------------------
 * |            UNIFAL - Universidade Federal de Alfenas.
 * |              BACHARElADO EM CIENCIA DA COMPUTACAO.
 * | Trabalho..: Vetor e verificacao de tipos
 * | Disciplina: Teoria de Linguagens e Compiladores
 * | Professor.: Luiz Eduardo da Silva
 * | Aluno.....: Helbert Sousa Reis
 * | Matricula.: 2015.1.08.026
 * | Data......: 10/03/2022
 * |---------------------------------------------------*/

/*  GERAR CODIGOS NUMERICOS TOKENS NO ARQUIVO SINTATICO  */
%{
   #include "sintatico.h"
   void erro(char *s);
   char atomo[100]; // Usado para guardar o nome de uma entidade
   int numLinha = 1; // Conta a linha para mostrar o local do erro
%}

/*  DESABILITAR EXIGENCIA DE CODIFICACAO YYWRAP*/
%option noyywrap

identificador  [a-zA-Z][a-zA-Z0-9]*
numero         [0-9]+
espaco         [ \t\r]+
novalinha      [\n]

/* Cria novo estado no automato */
%x coment      
/*  TOKENS  */
%%
programa    return T_PROGRAMA;      /*  SIMBOLOS PROGRAMA  */
inicio      return T_INICIO;
fimprograma return T_FIM;

leia        return T_LEIA;          /*  SIMBOLOS LEITURA/ESCRITA  */
escreva     return T_ESCREVA;

se          return T_SE;            /*  SIMBOLOS LOGICOS  */
entao       return T_ENTAO;
senao       return T_SENAO;
fimse       return T_FIMSE;

enquanto    return T_ENQTO;         /*  SIMBOLOS DE REPETICAO  */
faca        return T_FACA;
fimenquanto return T_FIMENQTO;

repita      return T_REPITA;        /*  Atividade Implementação do Analisador Sintatico  */
ate         return T_ATE;           /*  Adiciona a possibilidade de utilizar os comandos REPITA-ATE-FIMREPITA  -  Atividade prática 2  */
fimrepita   return T_FIMREPITA;

"+"         return T_MAIS;          /*  SIMBOLOS ARITMETICOS  */
"-"         return T_MENOS;
"*"         return T_VEZES;
div         return T_DIV;

e           return T_E;             /*  SIMBOLOS LÓGICOS  */
ou          return T_OU;
nao         return T_NAO;

">"         return T_MAIOR;         /*    SIMBOLOS RELACIONAIS  */
"<"         return T_MENOR;
"="         return T_IGUAL;

"<-"        return T_ATRIB;         /*    SIMBOLOS DE INSTRUCAO DE ATRIBUICAO  */
"("         return T_ABRE;          /*    SIMBOLO DE INSTRUCAO DE LIMITE DE EXPRESSAO*/
")"         return T_FECHA;
"["         return T_ABRE_COL;      /*    SIMBOLO DE INSTRUCAO DE LIMITE DE VETOR */
"]"         return T_FECHA_COL;     /*    SIMBOLO DE INSTRUCAO DE LIMITE DE VETOR */

inteiro     return T_INTEIRO;       /*    SIMBOLOS DE TIPOS  */
logico      return T_LOGICO;

V           return T_V;             /*    SIMBOLOS PARA VALORES LOGICOS  */
F           return T_F;



{identificador}   { strcpy(atomo, yytext); return T_IDENTIF; }  /* Guardar nome da variavel*/
{numero}          { strcpy(atomo, yytext); return T_NUMERO; }   /* Guardar valor da variavel*/ /*"["{numero}"]"   {  strcpy(atomo, yytext); return T_INDICE;} */
{espaco}          ;                 /* nao faz nada */
{novalinha}       ;{ numLinha++; }
"//".*            ;                 /* nao faz nada */
"/*"              BEGIN(coment);
<coment>"*/"      BEGIN(INITIAL);
<coment>.         ;                 /* nao faz nada */
<coment>\n        numLinha++;
.                 erro("LEXICO");   /* Rotina de tratamento de erro*/

%%
/*  PARA NAO CODIFICAR ESTA ROTINA ADICIONE A OPCAO NOYYWRAP*/
/* int yywrap(void) { return 1; } */

/*  CODIGO PRINCIPAL ESTARA NO SINTATICO*/
/* int main (void) {
   yylex();
   return 0;
} */

/*TODO: 
 * [] - Criar o formato de um vetor
 * [] - Criar o indice de um vetor
 * [] - Fazer o indice poder ser uma expressao
 */