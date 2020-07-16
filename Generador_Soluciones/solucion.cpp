#include <bits/stdc++.h>

#include "solucion.h"
#include "gen_aleatoria.h"

using namespace std;

string entrada_aleatoria(string nombre_archivo_entrada){
    //definimos la entrada(s) aleatoria(s)
    string entrada_aleatoria = cadena_aleatoria(entero_aleatorio(20, 100));  //pueden obtener datos aleatorios (checar gen_aleatoria.h para ver mas funciones)

    return entrada_aleatoria;
}

void solucion(){
    string cadena;
    cin >> cadena;
    set<char> cadenas;
    for(int i = 0; i < cadena.size(); i++)
        cadenas.insert(cadena[i]);
    bool d = cadenas.size() == cadena.size();
    cout << d << endl;
}