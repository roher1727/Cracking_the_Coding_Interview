#include "sesion2.h"
#include "gen_aleatoria.h"
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;


list<int> entrada_aleatoria(string nombre_archivo_entrada){
    //definimos la entrada(s) aleatoria(s)
    list<int> entrada_aleatoria = lista_enteros_aleatoria(entero_aleatorio(20, 100));  //pueden obtener datos aleatorios (checar gen_aleatoria.h para ver mas funciones)

    return entrada_aleatoria;
}

// list<int> solucion(){
 
//     return partition(solucion, 4) << endl;
// }