#ifndef LISTAEXPFAT_H
#define LISTAEXPFAT_H

#define fi 155
#define fantasmaFi -1

typedef struct Fat{
    int expo;
    int cof;
    struct Fat* prox;
} *Fat;

typedef struct Expressao{
    int num;
    Fat inicio;
} Express;

typedef Express *Exp;

Exp criarExp(int);     //retorna NULL caso paramatro > 2
void mostrarExp(Exp); 
int obterFi(Exp);       //retorna fantasmaFi caso parametro == NULL
void destruirExp(Exp);

Exp fatorarExp(Exp);
void insercaoOrdenada(Exp, int, int);

Exp criarExp(int num){
    Exp e;

    if(num >= 2 && num <= 2147483647){
        e = malloc(sizeof(Express));
        e->num = num;
        e->inicio = NULL;
        e = fatorarExp(e);
    }else e = NULL;
    return e;
}

//fatora pelo uso do algoritmo usual de fatoracao - pouco eficiente...melhorar
Exp fatorarExp(Exp e){
    int num, quoc, div = 2; //numero, quociente e divisor
    num = e->num;
    
    quoc = num;
    while((div <= num) && (quoc != 1)){

        if((quoc%div) == 0){
            quoc = quoc/div;
            insercaoOrdenada(e, div, 1);
            div = 2;

        }else div = div+1;
    }
    return e;
}

//insercao em ordem crescente sem duplicatas, incrementa-se ao expoente da celula duplicada para cada nova duplicata
void insercaoOrdenada(Exp e, int cof, int expo){
    Fat novo, p, ant;

    //cria nova celula
    novo = malloc(sizeof(struct Fat));
    novo->cof = cof;
    novo->expo = expo;

    p = e->inicio;
    if(p == NULL){  //caso 1 -> lista vazia
        novo->prox = p;
        e->inicio = novo;

    }else if(p->prox == NULL){  //caso 2 -> tamanho = 1
        if(cof > p->cof){
            novo->prox = p->prox;
            p->prox = novo;
        }else if(cof == p->cof){
            p->expo = p->expo+1;
            free(novo);
        }else{
            novo->prox = p;
            e->inicio = novo;
        }
    }else{      //caso 3 -> tamanho >= 2
        ant = p;
        p = p->prox;
        while((p != NULL) && (cof >= p->cof)){
            ant = p;
            p = p->prox;
        }
        if(cof == ant->cof){
            ant->expo = ant->expo+1;
            free(novo);
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }  
    }
}

void mostrarExp(Exp e){
    Fat p;
    if(e == NULL) printf("nao ha expressao\n");
    else{
        p = e->inicio;
        printf("expressao: %d = (%d)^%d", e->num, p->cof, p->expo);
        p = p->prox;
        while(p != NULL){
            printf(" + (%d)^%d", p->cof, p->expo); 
            p = p->prox;
        } printf("\n");
    }   
}

int obterFi(Exp e){
    Fat p;  int produto;
    double fat1, fat2;

    if(e != NULL){
        produto = 1;
        p = e->inicio;
        while(p != NULL){
            fat1 = pow(p->cof, p->expo);
            fat2 = pow(p->cof, p->expo-1);
            produto = produto * (fat1 - fat2);
            p = p->prox;
        }
    }else produto = fantasmaFi;

    return produto;
}

void destruirExp(Exp e){
    Fat prim, seg;

    if(e != NULL){  //caso "e" seja NULL, nao ha expresso
        prim = e->inicio;
        seg = e->inicio->prox;
        free(prim);
        while(seg != NULL){
            prim = seg;
            seg = seg->prox;
            free(prim);
        }
        free(e);
        e = NULL;
    } 
}

#endif