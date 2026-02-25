#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Estudiante{
    char nombre[30];
    int nota;
};
/*
convertir string a char:
            nombre.c_str()
*/
void escribirBinario(const string& nombreArchivo, const string & nombre, int nota){
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    //nombre
    strncpy(a.nombre, nombre.c_str(), sizeof(a.nombre));
    a.nombre[sizeof(a.nombre)-1]= '\0';
    //nota
    a.nota=nota;

    archivo.write( (char*)&a, sizeof(a)  );
    archivo.close();

}

void leerBinario(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"Error\n";
        return;
    }
    Estudiante a;
    while(archivo.read(  (char*)&a, sizeof(a)    )){
        cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";
    }

    archivo.close();
}



void leerAprobados(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cerr<<"ERROR\n";
        return;
    }
    Estudiante a;
    cout<<"Estudiantes aprobados: \n";
    while( archivo.read( (char*)&a, sizeof(a)  ) ){
        if(a.nota>=10){
            cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";
        }
    }
    archivo.close();
}

void modificarNota(const string& nombreArchivo,int posicion,int nuevaNota){
    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);

    archivo.seekg(posicion * sizeof(Estudiante), ios::beg);
    Estudiante e;
    archivo.read(  (char*)&e, sizeof(e) );
    e.nota=nuevaNota;

    archivo.seekp(posicion * sizeof(Estudiante), ios::beg);
    archivo.write((char*)&e, sizeof(e)  );

    archivo.close();
}













int main(){
    string nombreArchivo = "notas.dat";

    escribirBinario(nombreArchivo, "Victor", 19);
    escribirBinario(nombreArchivo, "Maria", 15);
    escribirBinario(nombreArchivo, "Kevin", 18);
    escribirBinario(nombreArchivo, "Teresa", 11);
    escribirBinario(nombreArchivo, "Leticia", 16);

    leerBinario(nombreArchivo);

    leerAprobados(nombreArchivo);
    
    return 0;

}