#include <bits/stdc++.h>
#include <stdlib.h>

#include "escribir.h"
#include "gen_aleatoria.h"
#include "solucion.h"

#define NUM_CASOS 1000

using namespace std;

int main(){
    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i < NUM_CASOS; i++){
        string nombre_archivo_entrada = to_string(i) + ".in";
        
        string entrada = entrada_aleatoria(nombre_archivo_entrada);
        escribir_archivo(entrada, nombre_archivo_entrada);  //Importante mandar a llamar a esta funcion (solo una vez)

        //modificamos entrada estandar y salida estandar
        string nombre_archivo_salida = to_string(i) + ".out";
        ifstream cin(nombre_archivo_entrada);
        ofstream cout(nombre_archivo_salida);

        // optional performance optimizations    
        ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        std::cin.rdbuf(cin.rdbuf());
        std::cout.rdbuf(cout.rdbuf());
        
        //llamamos a solucion
        solucion();        
    }

    
    return 0;
}
