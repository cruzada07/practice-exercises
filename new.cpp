/*
IMplemente un programa para gestionar notas de un curso utilizando asignacion dinamica
EL programa debe
1.1 Solicitar al usuario el numero de estudiantes (n)
1.2 reservar memoria dinamica para almacenar las notas (float notas[n])
1.3 Leer las notas desde el teclado
1.4 Calcular el promedio del curso, Nota Maxima, Nota minima
1.5 Redimensionar dinamicamente el arreglo para agregar otro numero de estudiantes (k)
1.6 Leer las nuevas notas
1.7 Reecalcular los valores(promedio del curso, Nota Maxima, Nota minima)
1.8 Liberar Correctamente la memoria
*/
#include <iostream>
using namespace std;

float* reservarMemoria(int n) {
    return new float[n];
}

void leerEstudiantes(float* v, int n, int inicio) {
    for (int i = inicio; i < n; i++) {
        cout << "Ingrese nota del estudiante " << i + 1 << ": ";
        cin >> v[i];
    }
}

float calcularPromedio(float* v, int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    return (n > 0) ? (suma / n) : 0;
}

void calcularMinMax(float* v, int n, float &maxima, float &minima) {
    maxima = v[0];
    minima = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maxima) maxima = v[i];
        if (v[i] < minima) minima = v[i];
    }
}

void redimensionar(float *&notas, int &n, int k) {
    float *nuevo = new float[n + k];

    // Copiar los valores antiguos
    for (int i = 0; i < n; ++i) {
        nuevo[i] = notas[i];
    }

    delete[] notas;   
    notas = nuevo;    
    n += k;            
}

int main() {
    int n, k;
    float max, min;

    cout << "Numero inicial de estudiantes (n): ";
    cin >> n;
    float* notas = reservarMemoria(n);

    leerEstudiantes(notas, n, 0);

    cout << "\n--- Resultados iniciales ---" << endl;
    cout << "Promedio: " << calcularPromedio(notas, n) << endl;
    calcularMinMax(notas, n, max, min);
    cout << "Max: " << max << " | Min: " << min << endl;

    cout << "\nCuantos estudiantes mas desea agregar (k)?: ";
    cin >> k;
    int n_antiguo = n; 
    redimensionar(notas, n, k);

    leerEstudiantes(notas, n, n_antiguo);

    cout << "\n--- Resultados finales ---" << endl;
    cout << "Nuevo Promedio: " << calcularPromedio(notas, n) << endl;
    calcularMinMax(notas, n, max, min);
    cout << "Nuevo Max: " << max << " | Nuevo Min: " << min << endl;

    delete[] notas;

    return 0;
}