#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>

#include "gen_aleatoria.h"

using namespace std;

//entero aleatorio
int entero_aleatorio(int a, int b){  //entero aleatorio que pertenece al rango [a, b]
    return rand() % (b - a + 1) + a;
}

//char aleatorio
char char_aleatorio(){  //
    return (char)entero_aleatorio(33, 125); // Caracteres ascii imprimibles (sin contar el espacio)
}

//cadena aleatoria
string cadena_aleatoria(int tamano){  //debe ser mayor a cero   
    string ret = "";
    for(int i = 0; i < tamano; i++)
        ret = ret + char_aleatorio();
    return ret;
}

/*
  Retorna un entero cuya valor ronda la media y tiene una desviacion estandar desv_estandar
*/
int numero_aleatorio_alrededor_de(double media, double desv_estandar){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    normal_distribution<double> distribution(media, desv_estandar);
    return  (int) round(distribution(generator));
}

char char_aleatorio_alrededor_de(char c, double desv){
    int i = (int)c;
    i = numero_aleatorio_alrededor_de(i, desv);
    i = max(i, 33);
    i = min(i, 125);
    return (char) i;
}

string string_alrededor_de(int n, char c, double desv){
    string s = "";
    for(int i = 0; i < n; ++i){
        s = s + char_aleatorio_alrededor_de(c, desv);
    }
    return s;
}

int* arreglo_uni_aleatorio(int n, int a, int b){
    int *v = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        v[i] = entero_aleatorio(a, b);
    return v;
}

int** arreglo_bi_aleatorio(int ren, int col, int a, int b){
    int **v = (int**) malloc(ren * sizeof(int*));
    for(int i = 0; i < ren; ++i)
        v[i] = arreglo_uni_aleatorio(col, a, b);
    return v;
}

int ***arreglo_tri_aleatorio(int n, int ren, int col, int a, int b){
    int ***v = (int***) malloc(n * sizeof(int**));
    for(int i = 0; i < ren; i++)
        v[i] = arreglo_bi_aleatorio(ren, col, a, b);
    return v;
}


void liberar_arreglo_uni(int *arr){
    free(arr);
}

void liberar_arreglo_bi(int ren, int **arr){
    for(int i = 0; i < ren; ++i)
        liberar_arreglo_uni(arr[i]);
    free(arr);
}

void liberar_arreglo_tri(int n, int ren, int ***arr){
    for(int i = 0; i < n; i++)
        liberar_arreglo_bi(ren, arr[i]);
    free(arr);
}


string cadena_arreglo_uni(int n, int* arr){
  if(n <= 0) return "";
  int i;
  string s = "";
  for(i = 0; i < n - 1; i++)
    s = s + to_string(arr[i]) + " ";
  return s + to_string(arr[i]) + "\n";
}

string cadena_arreglo_bi(int r, int c, int **arr){
  if(r <= 0) return "";
  int i;
  string s;
  for(i = 0; i < r; i++)
    s = s + cadena_arreglo_uni(c, arr[i]);
  return s;
}

string cadena_arreglo_tri(int n, int r, int c, int ***arr){
    if(n <= 0) return "";
    int i;
    string s;
    for(i = 0; i < n; i++)
        s = s + cadena_arreglo_bi(r, c, arr[i]);
    return s;
}
