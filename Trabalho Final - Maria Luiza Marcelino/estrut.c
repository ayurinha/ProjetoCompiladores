/*      Teoria de Linguagens e Compiladores

Maria Luiza Silva Marcelino - 2017.1.08.009
Data - 24/03/2022

*/

#include <stdio.h>
#include <string.h>

#define TAM_TAB 100
#define TAM_PIL 100

//Pilha Semantica
int Pilha[TAM_PIL];
int topo = -1;

//Tabela de Simbolos

struct elem_tab_simbolos{
    char id[100];
    int endereco;
    char tipo; // INT / logico
    char categoria; // VAR / vetor de variavel
    int tamanho; // quantidade de posicoes ocupadas na memoria
} TabSimb[TAM_TAB], elem_tab;
int pos_tab = 0; //primeira posição que vai armazenar

//Rotina da pilha semantica
void empilha(int valor){
    if (topo == TAM_PIL)
        erro("Pilha cheia!");
    Pilha[++topo] = valor;
}

int desempilha(){
    if(topo == -1) erro("Pilha vazia!");
    return Pilha[topo--];
}

// Rotina da Tabela de Simbolos

int busca_simbolo (char *id){
    int i = pos_tab - 1; //  retorna -1 se mao encontrar o id
    for (; strcmp(TabSimb[i].id, id)&& i >= 0; i--){
        ;
    }
    return i;
}

void insere_simbolo(struct elem_tab_simbolos elem){
    int i;
    if (pos_tab == TAM_TAB)
        erro("Tabela de Simbolos cheia!");
    i = busca_simbolo(elem.id);
    if (i != -1)
        erro("Identificador duplicado!");
    TabSimb[pos_tab++] = elem;
}


char *varVet(char varCharada){
    char *aux = (varCharada == 'v')   ?   "VAR" : "VET";
    return aux;
}

char *tipVar(char tipCharada){
    char *aux = (tipCharada == 'i')   ?   "INT" : "LOG";
    return aux;
}

void mostra_tabela(){
    int i;
    puts("Tabela de Simbolos.");
    for (i = 0; i < 64; i++)
        printf("-");
    printf("\n%3s | %30s | %s | %s | %s | %s \n", "#","ID", "END", "TIP", "CAT", "TAM");
    for (i = 0; i < 64; i++)
        printf("-");
    for (i = 0; i < pos_tab; i++)
        printf("\n%3d | %30s | %3d | %3s | %3s | %3d ", 
                i, TabSimb[i].id, TabSimb[i].endereco, tipVar(TabSimb[i].tipo), 
                varVet(TabSimb[i].categoria), TabSimb[i].tamanho
              );
    puts("\n");
}

