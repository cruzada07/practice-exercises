#include <iostream>
#include <fstream>
using namespace std;
/*
<<          write()
>>          read()
*/
struct Alumno{
    char nombre[50];  //en binario no se usa string porque string es dinamico
    int nota;
};
//funcion escribir en binario
void escribir(){
    ofstream archivoEscritura("notas.dat", ios::binary | ios::app);
    if(!archivoEscritura){
        cerr<<"Error\n";
        return;
    }

    Alumno a;
    cout<<"Nombre: ";cin>>a.nombre;
    cout<<"Nota: "; cin>>a.nota;

    archivoEscritura.write((char*)&a, sizeof(a));

    archivoEscritura.close();

}

//funcion leer en binario
void leer(){
    ifstream archivoLectura("notas.dat", ios::binary);

    if(!archivoLectura){
        cerr<<"Erro\n";
        return ;
    }
    Alumno a;
    while (archivoLectura.read((char*)&a, sizeof(a))){
        cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";
    }
    archivoLectura.close();
}
//funcion leer aprobados en binario
void leerAprobados(){
    ifstream archivoAprobados("notas.dat", ios::binary);
    if(!archivoAprobados){
        cerr<<"ERROR\n";
        return;
    }
    Alumno a;
    cout<<"Alumnos Aprobados: \n";
    while(archivoAprobados.read( (char*)&a, sizeof(a) )){
        if(a.nota>=10){
            cout<<"Nombre: "<<a.nombre<<" Nota: "<<a.nota<<"\n";
        }
    }
    archivoAprobados.close();
}
int main(){
    


    return 0;
}