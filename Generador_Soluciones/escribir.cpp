#include <string>
#include <fstream>

#include "escribir.h"

using namespace std;

void escribir_archivo(string contenido, string nombre_archivo){
    ofstream archivo;
    archivo.open (nombre_archivo);
    archivo << contenido << endl;
    archivo.close();
}
