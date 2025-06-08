#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "insertion_sort/insertion_sort.h"

using namespace std;

vector<int32_t> leerArregloDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error: no se pudo abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    vector<int32_t> datos;
    int32_t numero;

    while (archivo.read(reinterpret_cast<char*>(&numero), sizeof(int32_t))) {
        datos.push_back(numero);
    }

    return datos;
}

template <typename Funcion> //Para que funcione con cualquier tipo de dato
//Función para medir el tiempo de una iteración
double medirTiempo(Funcion f, vector<int32_t>& datos) {
    //Creamos una copia del vector original para no modificarlo directamente.
    auto copia = datos;

    //Guardamos el tiempo actual (inicio) usando alta resolución.
    auto inicio = chrono::high_resolution_clock::now();

    //Ejecutamos la funcion de ordenamiento sobre la copia.
    f(copia);

    //Guardamos el tiempo actual (fin) una vez termina de ejecutar.
    auto fin = chrono::high_resolution_clock::now();

    //Calculamos la duración en milisegundos entre inicio y fin.
    chrono::duration<double, milli> duracion = fin - inicio;

    //Retornamos el tiempo de ejecución en milisegundos.
    return duracion.count();
}



template <typename Funcion> //Para que funcione con cualquier tipo de dato
//Función para calcular el tiiempo promedio con cierta cantidad de repeticiones
double medirPromedio(Funcion f, vector<int32_t>& datos, int repeticiones) {
    //Variable para acumular el tiempo total de todas las repeticiones.
    double total = 0;

    //Ejecutamos la función de ordenamiento 'repeticiones' veces.
    for (int i = 0; i < repeticiones; ++i) {
        // En cada repetición sumamos el tiempo que tomó ordenar.
        total += medirTiempo(f, datos);
    }

    //Calculamos el promedio dividiendo el total por la cantidad de repeticiones.
    return total / repeticiones;
}


int main() {
    string nombreArchivo = "datasets/dblp.100MB.4B.lcp"; //Poner nombre del archivo aqui
    vector<int32_t> datos = leerArregloDesdeArchivo(nombreArchivo);

    cout << "Elementos cargados: " << datos.size() << endl;

    double tiempoPromedio = medirPromedio(insertionSort, datos, 10);
    cout << "Insertion sort (promedio de 10 ejecuciones): " << tiempoPromedio << " ms" << endl;

    return 0;
}
