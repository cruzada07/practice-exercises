#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Estudiante{
    char nombre[50];
    int nota;
};


void escribirBinario(const string & nombreArchivo, const string & nombre, int nota){
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    strncpy(a.nombre  ,  nombre.c_str()  ,  sizeof(a));
    a.nombre[ sizeof(a.nombre)-1 ]='\0';
    a.nota=nota;

    archivo.write( (char*)&a, sizeof(a)  );
    archivo.close();
}


void leerBinario(const string & nombreArchivo){
    
}   

void leerAprobados(const string & nombreArchivo){
    
}

void modificarNota(const string & nombreArchivo, int posicion, int nuevaNota){

}

int main(){



    return 0;
}