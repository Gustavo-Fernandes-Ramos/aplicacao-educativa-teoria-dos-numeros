#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#include "ListaDuplamLigadaCh.h"

#define EXP1 0
#define EXP2 1

typedef Lista ExpMod;   //expresso do formato: 2x + 5 * 9

//expresso do formato: 2x + 5 = 18(mod 19)
typedef struct EqMod{
    ExpMod parcelaExp[2];
    int modulo;
} EqMod;

EqMod criarEqMod();
ExpMod criarExpressaoInfixaMod(unsigned char *);
EqMod criarExpressaoPosfixaMod(EqMod, ExpMod);

int main(){
    EqMod posfixa;  ExpMod infixa, Pilha;
    unsigned char expressao[100];   int tam;

    posfixa = criarEqMod();

    printf("digite: ");
    gets(expressao);
    
    infixa = criarExpressaoInfixaMod(expressao);
    posfixa = criarExpressaoPosfixaMod(posfixa, infixa);

    mostrarListaInicio(posfixa.parcelaExp[0]);
    mostrarListaInicio(posfixa.parcelaExp[1]);
    
    return 0;
}

//cria expressao modular vazia
EqMod criarEqMod(){
    EqMod Exp;

    Exp.modulo = 0;
    Exp.parcelaExp[0] = criarLista();
    Exp.parcelaExp[1] = criarLista();
    return Exp;
}

//transforma o array em uma lista de caracteres
ExpMod criarExpressaoInfixaMod(unsigned char *str){
    ExpMod L;    int i = 0;

    L = criarLista();
    while(str[i] != '\0'){
        inserirFim(&L, str[i]);
        i++;
    }
    return L;
}

EqMod criarExpressaoPosfixaMod(EqMod posfixa, ExpMod infixa){
    ExpMod copia;    unsigned char ch;   int j = EXP1;

    copia = criarLista();
    copia = copiarLista(infixa, copia);

    while(!listaVazia(copia)){
        ch = acessarInicio(copia);
        removerInicio(&copia);

        switch(ch){
            case '+':
            case '-':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case '*':
            case '/':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case '^':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case '(':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case ')':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case '=':
                j = EXP2;
                break;
            
            case 'x': case 'X': case 'y':
            case 'Y': case 'z': case 'Z':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case 'm':
            case 'M':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case 'o':
            case 'O':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case 'd':
            case 'D':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;

            case '0' ... '9':
                inserirFim(&posfixa.parcelaExp[j], ch);
                break;
            
            default:
                break;
        }
    }
    return posfixa;
}






