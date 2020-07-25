#include "sesion2.h"
#include <iostream>
#include <unordered_map>

using namespace std;

// string entrada_aleatoria(){

// }

// void solucion_24(){
// 	string cadena;
// 	cin >> cadenas;
// }

list<int> partition(list<int> lista, int partition){
	list<int> predecesores;
	list<int> sucesores;

	// list<int>::iterator it;
	for (int it : lista){
		if(it >= partition){
			predecesores.push_back(it);
		}else{
			sucesores.push_back(it);
		}
	}
	sucesores.splice(sucesores.end(), predecesores);
	return sucesores;
}


list<int> sum_lists(list<int> lista1, list<int> lista2){
	int a, b, suma;
	int acumulador = 0;
	list<int> ::iterator principio1 = lista1.begin();
	list<int> ::iterator principio2 = lista2.begin();
	list<int> sum;

	advance(principio1, 0);
	advance(principio2, 0);
	a = (*principio1);
	b = (*principio2);

	for(int i = 0 ; i < lista1.size(); i++){

		
		cout<<a<<"+"<<b<<"+"<<acumulador<<endl;

		suma = a + b + acumulador;
		cout<<i<<endl;

		if (suma > 9){
			acumulador = 1;
			suma = suma % 10;
		}else{
			acumulador = 0;
		}
		sum.push_back(suma);

		advance(principio1, 1);
		advance(principio2, 1);
		a = (*principio1);
		b = (*principio2);
	}

	if (acumulador == 1)
		sum.push_back(1);
	return sum;
}

bool palindrome(list<char> lista){
	list<char> ::iterator principio = lista.begin();
	list<char> ::reverse_iterator fin = lista.rbegin();
	char a,b;
	advance(principio, 0);
	advance(fin, 0);
	a = (*principio);
	b = (*fin);

	for(int i = 0 ; i < (lista.size()/2); i++){

		if (a != b){
			return false;
		}

		advance(principio, 1);
		advance(fin, 1);
		a = (*principio);
		b = (*fin);
	}

	return true;

}

int intersection(list<int> lista1, list<int> lista2){
	int a,b,index;
	bool check = false;
	list<int> ::iterator principio1 = lista1.begin();
	list<int> ::iterator principio2 = lista2.begin();

	for (int i = 0 ; i < lista1.size(); i++){
		principio2 = lista2.begin();
		principio1 = lista1.begin();
		advance(principio1, i);
		advance(principio2, i);

		a = (*principio1);
		b = (*principio2);
		index = a;
		for (int j = i; j < lista2.size(); j++){
			if (a == b){
				check = true;
			}else{
				check = false;
			}
			advance(principio1, 1);
			advance(principio2, 1);
			a = (*principio1);
			b = (*principio2);
		}
		if(check){
			return index;
		}
	}
	return 0;

}

char loop_detection(list<char> lista){
	unordered_map<int, int> hash;
	for (int e : lista){
		hash[e] = 0;
	}
	for (int e : lista){

		hash[e]++;
		if (hash[e] > 1){
			return e;
		}
	}
	return 'F';
}

int main(){
	// list<char> lista1({'b','o','b','o','b'});
	list<int> lista1({2,3,9,7,9});
	list<int> lista2({2,3,9,7,9});
	// list<int> iron = sum_lists(lista1, lista2);
	// for (int i : iron){
	// 	cout<<i<<" ";
	// }

	cout<<intersection(lista1, lista2)<<endl;
}
