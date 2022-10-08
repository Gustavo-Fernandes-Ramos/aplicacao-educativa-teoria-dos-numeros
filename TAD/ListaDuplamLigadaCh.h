#ifndef LISTADUPLAMLIGADACH_H
#define LISTADUPLAMLIGADACH_H

//utilizada como fila, pilha, lista simples ou duplamente ligada;

#define fantasma 158

typedef struct Celula{
    unsigned char item;
    struct Celula *ant;
    struct Celula *prox;
} Celula;

typedef struct Lista{
    int tam;
    Celula *inicio;
    Celula *fim;
} Lista;

Lista criarLista();
int obterTamanho(Lista);
bool listaVazia(Lista);

void inserirInicio(Lista*, unsigned char);
void removerInicio(Lista*);
unsigned char acessarInicio(Lista);
void mostrarListaInicio(Lista);

void inserirFim(Lista*, unsigned char);
void removerFim(Lista*);
unsigned char acessarFim(Lista);
void mostrarListaFim(Lista);

Lista destruirLista(Lista);
Lista copiarLista(Lista, Lista);

Lista criarLista(){
    Lista L;
    L.tam = 0;
    L.inicio = NULL;
    L.fim = NULL;
    return L;
}

int obterTamanho(Lista L){
    int tam;
    tam = L.tam;
    return tam;
}

bool listaVazia(Lista L){
    bool vazia;
    vazia = FALSE;
    if(L.inicio == NULL) vazia = TRUE;
    return vazia;
}

void inserirInicio(Lista *L, unsigned char ch){
    Celula *novo;
    
    novo = malloc(sizeof(Celula));
    novo->item = ch;

    novo->prox = L->inicio;
    novo->ant = NULL;

    if(L->inicio == NULL) L->fim = novo;    //caso 1 - lista vazia
    else L->inicio->ant = novo;     //caso 2 - lista com 1 item ou mais

    L->inicio = novo;
    L->tam = L->tam+1;
}

void removerInicio(Lista *L){
    Celula *prim, *seg;

    if(L->inicio != NULL){  //se a lista nao e vazia
        prim = L->inicio;
        seg = L->inicio->prox;

        L->inicio = seg;

        if(seg == NULL) L->fim = NULL;  //caso 1 - lista tem 1 item
        else seg->ant = NULL;  //caso 2 - lista com 2 ou mais itens

        free(prim);
        L->tam = L->tam-1;
    } 
}

unsigned char acessarInicio(Lista L){
    Celula *p;  unsigned char ch;

    p = L.inicio;
    if(p != NULL) ch = p->item;
    else ch = fantasma;
    return ch;
}

void mostrarListaInicio(Lista L){
    Celula *c;

    c = L.inicio;
    if(c == NULL) printf("lista vazia");
    else{
        while(c != NULL){
            printf("%c", c->item);
            c = c->prox;
        }
    }
}

void inserirFim(Lista *L, unsigned char ch){
    Celula *novo;
    
    novo = malloc(sizeof(Celula));
    novo->item = ch;

    novo->ant = L->fim;
    novo->prox = NULL;

    if(L->fim == NULL) L->inicio = novo;
    else L->fim->prox = novo;

    L->fim = novo;
    L->tam = L->tam+1;
}

void removerFim(Lista *L){
    Celula *prim, *seg;

    if(L->fim != NULL){  //se a lista nao e vazia
        prim = L->fim;
        seg = L->fim->ant;

        L->fim = seg;

        if(seg == NULL) L->inicio = NULL;  //caso 1 - lista tem 1 item
        else seg->prox = NULL;  //caso 2 - lista com 2 ou mais itens

        free(prim);
        L->tam = L->tam-1;
    } 
}

unsigned char acessarFim(Lista L){
    Celula *p;  unsigned char ch;

    p = L.fim;
    if(p != NULL) ch = p->item;
    else ch = fantasma;
    return ch;
}

void mostrarListaFim(Lista L){
    Celula *c;

    c = L.fim;
    if(c == NULL) printf("\nlista vazia\n");
    else{
        while(c != NULL){
            printf("%c ", c->item);
            c = c->ant;
        }printf("\n");
    }
}

Lista copiarLista(Lista original, Lista copia){
    Celula *p;
    p = original.inicio;
    while(p != NULL){
        inserirFim(&copia, p->item);
        p = p->prox;
    }
    return copia;
}

Lista destruirLista(Lista L){
    Celula *prim, *seg;
    prim = L.inicio;
    if(prim != NULL){
        seg = prim->prox;
        free(prim);
        while(seg != NULL){
            prim = seg;
            seg = seg->prox;
            free(prim);
        }
        L.inicio = NULL;
        L.fim = NULL;
        L.tam = 0;
    }
    return L;
}

#endif