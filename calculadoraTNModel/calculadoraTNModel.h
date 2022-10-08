
//lógicas de validação
bool validarNumPrimo(int);
bool validarMdc(int, int);
bool validarFermat(int);
bool validarCongruencia(int, int, int);
bool validarInverso(int, int);

//verifica se um número é primo
bool verificaNumPrimo(int);

//calcula o mdc entre dois números
int mdc(int, int);

//fatora um número em dois fatores usando o algoritmo de fermat
void fatoracaoFermat(int, int*, int*);

//verifica se um número é congruo ao outro : a = b(mod n)
bool congruencia(int, int, int);

//obtem o inverso de um numero em certa classe mod n
int calcularInverso(int, int);