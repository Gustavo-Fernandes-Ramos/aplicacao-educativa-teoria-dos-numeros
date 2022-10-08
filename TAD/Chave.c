#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Booleano.h"
#include "ListaDuplamLigadaCh.h"
#include "../calculadoraTNModel/calculadoraTNModel.c"

#define ghostChave 0

typedef struct Chave{
    Lista id;
    int n;  int x;
} Chave;

typedef Lista Pilha;

typedef Chave ChaveCod, ChaveDecod;

void menuChave();
Chave criarChaveVazia();
bool verificarChaveVazia(Chave);
Chave copiarChave(Chave, Chave);
void mostrarChave(Chave);

bool validarChaveCod(ChaveCod);

//funcoes para obter a chave no formato de string do terminal e transformar no tipo chave
Lista converterStringParaLista(unsigned char *);
Chave converterListaParaChave(Lista);

int main(){
    Chave c; Lista L;
    menuChave();
    unsigned char stringChave[100];
    gets(stringChave);
    L = converterStringParaLista(stringChave);
    c = converterListaParaChave(L);
    mostrarChave(c);
    return 0;
}

void menuChave(){
    printf("=========================================\n");
    printf("| (1) - definir chave publica           |\n");
    printf("| (2) - definir chave publica e privada |\n");
    printf("=========================================\n");
    printf("formato:  [nome] = (n, e)\n");
    printf("digite aqui: ");
}

bool verificarChaveVazia(Chave k){
    bool vazia;
    if(k.n == ghostChave) vazia = TRUE;
    else vazia = FALSE;
    return vazia;
}

Chave criarChaveVazia(){
    Chave k;
    k.n = ghostChave;
    k.x = ghostChave;
    k.id = criarLista();
    return k;
}

Chave copiarChave(Chave orig, Chave copia){
    copia.id = copiarLista(copia.id, orig.id);
    copia.n = orig.n;
    copia.x = orig.x;
    return copia;
}
//estudar para saber como validar a chave de codificacao
bool validarChaveCod(ChaveCod c){
    bool r = FALSE;
    if(c.x > 0 && c.n > 1){
        if(mdc(c.x, c.n) == 1) r = TRUE;
    }
    return r;
}

void mostrarChave(Chave c){

    if(c.n != ghostChave){
        mostrarListaInicio(c.id);
        printf(" = (%d, %d) ", c.n, c.x);

    }else printf("chave invalida");
}

Chave converterListaParaChave(Lista L){
    Chave c, cRet;    Lista copia, pilha;
    unsigned char ch;
    bool repete, nomeValido, chaveValida = FALSE;

    c = criarChaveVazia();  cRet = criarChaveVazia();

    copia = criarLista();   copia = copiarLista(L, copia);

    if(!listaVazia(copia)){
        nomeValido = FALSE;
        while(!listaVazia(copia) && !nomeValido){
            ch = acessarInicio(copia);
            removerInicio(&copia);
            
            if(ch == '=') nomeValido = TRUE;
            else inserirFim(&c.id, ch);
        }

        if(!listaVazia(copia) && nomeValido){
            pilha = criarLista();   repete = TRUE;

            while(!listaVazia(copia) && repete){
                ch = acessarInicio(copia);
                removerInicio(&copia);
                
                switch(ch){
                    case '(':
                        if(listaVazia(pilha) == TRUE) inserirInicio(&pilha, ch);
                        else repete = FALSE;
                        break;
                    case ',':
                        if((acessarInicio(pilha)) == '(') inserirInicio(&pilha, ch);
                        else repete = FALSE;
                        break;
                    case ')':
                        if((acessarInicio(pilha)) == ',') chaveValida = TRUE;
                        repete = FALSE;
                        break;
                    case '0'...'9':
                        if((acessarInicio(pilha)) == '(') c.n = c.n*10 + (ch - 48);
                        else if((acessarInicio(pilha)) == ',') c.x = c.x*10 + (ch - 48);
                        else repete = FALSE;
                        break;
                    default:
                        repete = FALSE;
                       break; 
                }
            }
            pilha = destruirLista(pilha);
            if(chaveValida) cRet = copiarChave(c, cRet);
        }  
    }
    copia = destruirLista(copia);
    return cRet;
}

Lista converterStringParaLista(unsigned char *str){
    Lista L;    int i = 0;

    L = criarLista();
    while(str[i] != '\0'){
        if(str[i] != ' ') inserirFim(&L, str[i]);
        i++;
    }
    return L;
}
