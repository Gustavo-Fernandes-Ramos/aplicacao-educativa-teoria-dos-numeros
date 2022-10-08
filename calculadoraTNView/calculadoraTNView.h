
//menus
void menuInicial();
void menu(char *);
void opcaoInvalida();
void fim();

//entradas
void obterNumero(int *);
void obterNumeros(int *, int *);
void obterNumeroEmodulo(int *, int *);
void obterNumerosEmodulo(int *, int *, int *);

//saidas
void exibirPrimo(int);
void exibirComposto(int);
void exibirMdc(int, int, int);
void exibirFermat(int, int, int);
void exibirCongruo(int, int, int);
void exibirNaoCongruo(int, int, int);
void exibirInverso(int, int, int);
void exibirFi(int, int);

//erro
void erroPrimo();
void erroMdc();
void erroFermat();
void erroCongruencia();
void erroInverso(int, int);
void erroFat(int);

//extras
void flush_in();