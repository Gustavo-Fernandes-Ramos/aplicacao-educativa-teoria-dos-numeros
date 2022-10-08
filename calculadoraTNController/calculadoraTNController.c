#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../TAD/Booleano.h"
#include "../calculadoraTNModel/calculadoraTNModel.c"
#include "../calculadoraTNView/calculadoraTNView.c"

void executar();

void executar(){
    Exp p;

    bool repete;
    int a, b, r;
    char op;

    bar();
    do{
        menu(&op);
        switch(op){

        case '1':
            repete = TRUE;
            do{
                obterNumero(&a);
                if(validarNumPrimo(a)){
                    repete = FALSE;
                    if(verificaNumPrimo(a)) exibirPrimo(a);
                    else exibirComposto(a);
                    
                }else erroPrimo();
            }while(repete == TRUE);
            break;

        case '2':
            repete = TRUE;
            do{
                obterNumeros(&a, &b);
                if(validarMdc(a, b)){
                    repete = FALSE;
                    r = mdc(a, b);
                    exibirMdc(a, b, r);

                }else erroMdc();
            }while(repete == TRUE);
            break;

        case '3':
            repete = TRUE;
            do{
                obterNumero(&r);
                if(validarFermat(r)){
                    repete = FALSE;
                    fatoracaoFermat(r, &a, &b);
                    exibirFermat(r, a, b);

                }else erroFermat(); 
            }while(repete == TRUE); 
            break;

        case '4':
            repete = TRUE;
            do{
                obterNumerosEmodulo(&a, &b, &r);
                if(validarCongruencia(a, b, r)){
                    repete = FALSE;
                    if(congruencia(a, b, r)) exibirCongruo(a, b, r);
                    else exibirNaoCongruo(a, b, r);

                }else erroCongruencia(); 
            }while(repete == TRUE);
            break;

        case '5':
            repete = TRUE;
            do{
                obterNumeroEmodulo(&a, &b);
                if(validarInverso(a, b)){
                    repete = FALSE;
                    r = calcularInverso(a, b);
                    exibirInverso(a, b, r);

                }else erroInverso(a, b);
            }while(repete == TRUE);
            break;

        case '6':
            repete = TRUE;
            do{
                obterNumero(&a);
                if((p = criarExp(a)) != NULL){
                    repete = FALSE;
                    mostrarExp(p); bar();
                    destruirExp(p);

                }else erroFat(a);
            }while(repete == TRUE);
            break;

        case '7':
            repete = TRUE;
            do{
                obterNumero(&a);
                if((p = criarExp(a)) != NULL){
                    repete = FALSE;
                    b = obterFi(p);
                    exibirFi(a, b);
                    destruirExp(p);

                }else erroFat(a);
            }while(repete == TRUE);
            break;

        case '8':
            fim();
            break;

        default:
            opcaoInvalida();
            break;
        }
        flush_in();
    }while(op != '8');
}