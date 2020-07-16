#include <stdlib.h>
#include <string>

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