#include <bits/stdc++.h>

#include "solucion.h"
#include "gen_aleatoria.h"

using namespace std;

//num1 num2
string entrada_aleatoria(string nombre_archivo_entrada){
    //definimos la entrada(s) aleatoria(s)
    int num1 = entero_aleatorio(-50, 50);
    int num2 = entero_aleatorio(-50, 50);
    string entrada = to_string(num1) + " " + to_string(num2);
    return entrada;
}

void solucion(){
    int num1, num2;
    cin >> num1 >> num2;
    cout << (num1 + num2);
}
