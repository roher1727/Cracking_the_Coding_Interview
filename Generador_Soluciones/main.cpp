// #include <bits/stdc++.h>
#include <stdlib.h>
#include "sesion2.h"
#include "escribir.h"
#include "gen_aleatoria.h"
#include "solucion_2_4.h"
#include <iostream>

#define NUM_CASOS 1000

using namespace std;

int main(){
    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i < NUM_CASOS; i++){
        string nombre_archivo_entrada = to_string(i) + ".in";
        
        list<int> rapido = entrada_aleatoria(nombre_archivo_entrada);

        string entrada = lista_int_cadena(rapido);

        int particion = entero_aleatorio(1,100);
        
        entrada = entrada + '\n' + to_string(particion);
        cout<<entrada;

        escribir_archivo(entrada, nombre_archivo_entrada);  //Importante mandar a llamar a esta funcion (solo una vez)

        //modificamos entrada estandar y salida estandar
        string nombre_archivo_salida = to_string(i) + ".out";
        // ifstream cin(nombre_archivo_entrada);
        // ofstream cout(nombre_archivo_salida);

        // optional performance optimizations    
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);

        // cin.rdbuf(cin.rdbuf());
        // cout.rdbuf(cout.rdbuf());
        
        //llamamos a solucion
        list <int> salida_l = partition(rapido, particion);
        string salida = lista_int_cadena(salida_l);
        escribir_archivo(salida, nombre_archivo_salida);        
    }

    
    return 0;
}
