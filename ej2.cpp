#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno{
    char nombre[30];
    int nota;
};

// 🔹 Escribir un alumno en el archivo
void escribir(const string & nombreArchivo, const Alumno & a){
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if(!archivo){
        cout << "Error al abrir archivo\n";
        return;
    }

    archivo.write((char*)&a, sizeof(a));
    archivo.close();
}

// 🔹 Leer todos los alumnos
void leer(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cout << "Error al abrir archivo\n";
        return;
    }

    Alumno a;

    while(archivo.read((char*)&a, sizeof(a))){
        cout << "Nombre: " << a.nombre 
             << " Nota: " << a.nota << endl;
    }

    archivo.close();
}

// 🔹 Leer solo aprobados
void leerAprobados(const string & nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
        cout << "Error al abrir archivo\n";
        return;
    }

    Alumno a;
    cout << "\nAprobados:\n";

    while(archivo.read((char*)&a, sizeof(a))){
        if(a.nota >= 10){
            cout << a.nombre << " - " << a.nota << endl;
        }
    }

    archivo.close();
}

int main(){
    string nombreArchivo = "notas.dat";

    Alumno a1 = {"Kevin", 18};
    Alumno a2 = {"Miguel", 9};
    Alumno a3 = {"Andrea", 7};
    Alumno a4 = {"Lesly", 10};
    Alumno a5 = {"Yessenia", 11};

    escribir(nombreArchivo, a1);
    escribir(nombreArchivo, a2);
    escribir(nombreArchivo, a3);
    escribir(nombreArchivo, a4);
    escribir(nombreArchivo, a5);

    cout << "Todos los alumnos:\n";
    leer(nombreArchivo);

    leerAprobados(nombreArchivo);

    return 0;
}