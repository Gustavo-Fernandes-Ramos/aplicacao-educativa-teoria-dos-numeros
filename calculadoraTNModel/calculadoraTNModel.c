#include "calculadoraTNModel.h"
#include "../TAD/ListaExpfat.h"

//numero primo
bool validarNumPrimo(int a){
    bool r = FALSE;
    if(a < -1 || a > 1) r = TRUE;
    return r;
}
bool verificaNumPrimo(int a){
	int i = 2;	int n = a/2;
	bool result = TRUE;

	if(a <= 1) result = FALSE;
    else{
        while(i <= n && result != FALSE){

            if(a%i == 0) result = FALSE;
            i++;
	    }
    }
    return result;
}

//MDC
bool validarMdc(int a, int b){
    bool r = FALSE;
    if(a > 0 && b > 0) r = TRUE;
    return r;
}
int mdc(int a, int b){
    int r, aux = b;

    while(aux > 0){
        r = aux;
        aux = a%b;
        a = b;
        b = aux;
    }
    return r;
}

//algoritmo de fermat
bool validarFermat(int N){
    bool r = FALSE;
    if(N > 2 && N%2 != 0) r = TRUE;
    return r;
}
// entrada : N = numero a ser fatorado
// saida : a, b = fatores de N
void fatoracaoFermat(int N, int *a, int *b){
    int max, x, Y;
    double n, y, raiz;

    max = (1+N)/2;  //maximo de vezes que sera executada a tabela do algoritmo de fermat

    n = (double)N;
    raiz = sqrt(n); //raiz quadrada do valor de N

    x = (int)raiz;  //parte inteira da raiz quadrada do valor de N

    do{     //lógica da tabela do algoritmo (x, sqrt(x*x-n))
        x = x+1;
        y = sqrt(x*x-n);
        Y = (int)y;
    }while(Y != y && x != max); //termina quando y for um número inteiro ou após rodar max vezes
    
    *a = x + Y;     //fatores de N, já que : N = (x + y)*(x - y)
    *b = x - Y; 
}

//congruência entre dois numeros modulo n
bool validarCongruencia(int a, int b, int mod){
    bool r = FALSE;
    if(a >= 0 && b >= 0 && mod > 0) r = TRUE;
    return r;
}
bool congruencia(int a, int b, int mod){
    bool r = FALSE;
    int restoA = a%mod;   int restoB = b%mod;
    
    if(restoA == restoB) r = TRUE;

    return r;
}

bool validarInverso(int D, int mod){
    bool r = FALSE;
    if(D > 0 && mod > 1){
        if(mdc(D, mod) == 1) r = TRUE;
    }
    return r;
}
//mdc(a, b) = mdc(b, r(1)) = mdc(r(1), r(2)) ... mdc(r(n-1), r(n)) = r(n)
int calcularInverso(int D, int mod){
    int a, b, q, resto, inv;
    int xAnt, x, xProx;    //itens da coluna de x

    a = mod;    //primeiro elemento do mdc
    b = D%mod;  //segundo elemento do mdc
    
    resto = b;  //menor elemento entre os 2 parametros que inicializa o resto

    xAnt = 0;   //elementos imaginarios da coluna x
    x = 1;

    do{
        inv = x;

        q = a/b;    
        resto = a%b;
        xProx = xAnt - q * x;  //calcula o prox valor da coluna x

        a = b;      //avança em 1 casa a coluna dos restos
        b = resto;

        xAnt = x;   //avança em 1 casa a coluna x
        x = xProx;

    } while(resto > 0); //roda até que o resto posterior seja igual á 0

    if(inv < 0) inv = inv + mod; //caso negativo, inverso é somado ao módulo

    return inv;
}