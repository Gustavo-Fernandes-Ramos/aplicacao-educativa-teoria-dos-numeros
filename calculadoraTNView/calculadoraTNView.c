#include "calculadoraTNView.h"

void bar(){
    printf("===================================================================================\n");
}
void menu(char *op){
    printf("(1) - verificar se um numero e primo\t"); printf("(6) - obter expressao fatorada\n");
    printf("(2) - obter o mdc entre dois numeros\t"); printf("(7) - obter %c do numero n\n", 155);
    printf("(3) - fatorar pelo algoritmo de fermat\t"); printf("(8) - sair\n");
    printf("(4) - congruencia entre dois numeros\n"); //printf("(9) - \n");
    printf("(5) - obter o inverso modulo n\n"); //printf("(0) - \n");
    bar();   
    printf("selecione uma opcao: ");
    scanf("%c",op);
    bar();
}


void obterNumero(int *a){
    printf("digite o numero: ");
    scanf("%d",a);
    bar();
}
void obterNumeros(int *a, int *b){
    printf("digite o primeiro numero: ");
    scanf("%d",a);
    bar();
    printf("digite o segundo numero: ");
    scanf("%d",b);
    bar();
}
void obterNumeroEmodulo(int *a, int *mod){
    printf("digite o numero: ");
    scanf("%d",a);
    bar();
    printf("digite o modulo: ");
    scanf("%d",mod);
    bar();
}
void obterNumerosEmodulo(int *a, int *b, int *mod){
    printf("digite o primeiro numero: ");
    scanf("%d",a);
    bar();
    printf("digite o segundo numero: ");
    scanf("%d",b);
    bar();
    printf("digite o modulo: ");
    scanf("%d",mod);
    bar();
}

void exibirPrimo(int a){
    printf("o numero %d e primo\n",a);
    bar();
}
void exibirComposto(int a){
    printf("o numero %d e composto\n",a);
    bar();
}
void erroPrimo(){
    printf("o valor deve ser diferente de 0, 1 e -1\n");
    bar();
}


void exibirMdc(int a, int b, int r){
    printf("resultado: mdc(%d, %d) = %d\n", a, b, r);
    bar();
}

void erroMdc(){
    printf("os valores tem de ser maiores que zero!\n");
    bar();
}


void exibirFermat(int r, int a, int b){
    printf("%d x %d = %d\n",a, b, r);
    bar();
}
void erroFermat(){
    printf("o valor tem de ser impar e maior que 2!\n");
    bar();
}


void exibirFi(int a, int b){
    printf("%c(%d) = %d\n", 155, a, b);
    bar();
}
void erroFat(int a){
    printf("o valor de %d tem de ser entre 2 e 2.147.483.647\n", a);
    bar();
}


void exibirCongruo(int a, int b, int mod){
    printf("os numeros sao congruos, %d = %d(mod %d)\n", a, b, mod);
    bar();
}
void exibirNaoCongruo(int a, int b, int mod){
    printf("os numeros %d e %d nao sao congruos em Z%d!\n", a, b, mod);
    bar();
}
void erroCongruencia(){
    printf("os numeros devem ser maiores ou iguais a\n");
    printf("zero, o modulo deve ser maior que zero!\n");
    bar();
}


void exibirInverso(int a, int mod, int r){
    printf("o inverso de %d em Z%d = %d\n", a, mod, r);
    bar();
}
void erroInverso(int a, int mod){
    printf("%d nao possui inverso em Z%d\n", a, mod);
    bar();
}


void opcaoInvalida(){
    printf("opcao invalida, digite novamente...\n");
    bar();
}
void fim(){
    printf("FIM\n");
}
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

    