#include <stdlib.h>
#include <string>

using namespace std;

int entero_aleatorio(int a, int b);  //entero aleatorio que pertenece al rango [a, b]

//char aleatorio
char char_aleatorio();

//cadena aleatoria
string cadena_aleatoria(int tamano);

int numero_aleatorio_alrededor_de(double media, double desv_estandar);
char char_aleatorio_alrededor_de(char c, double desv = 4);
string string_alrededor_de(int n, char c, double desv = 4);

int* arreglo_uni_aleatorio(int n, int a, int b);
int** arreglo_bi_aleatorio(int ren, int col, int a, int b);
int ***arreglo_tri_aleatorio(int n, int ren, int col, int a, int b);

void liberar_arreglo_uni(int *arr);
void liberar_arreglo_bi(int ren, int **arr);
void liberar_arreglo_tri(int n, int ren, int ***arr);

string cadena_arreglo_uni(int n, int* arr);
string cadena_arreglo_bi(int r, int c, int **arr);
string cadena_arreglo_tri(int n, int r, int c, int ***arr);
