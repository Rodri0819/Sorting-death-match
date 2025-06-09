#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "insertion_sort/insertion_sort.h"
#include "sorting_estandar/sort_estandar.h"
#include "quick_sort/quick_sort.h"
#include "merge_sort/merge_sort.h"
#include "heap_sort/heap_sort_v2.h"
#include "radix_sort/radix_sort.h"
#include "merge_sort/merge_sort.h"
#include "quick_sort/quick_sort.h"


#include "../utils/generador_arreglos.h"
#include <functional>


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
        // cout << "Iteracion " << i + 1 << ": " << medirTiempo(f, datos) << " ms" << endl;
        total += medirTiempo(f, datos);
    }

    //Calculamos el promedio dividiendo el total por la cantidad de repeticiones.
    cout << "Tiempo total: " << total << " ms" << endl;
    return total / repeticiones;
}


int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Uso: " << argv[0] << " <archivo_dataset> <nombre_algoritmo> <repeticiones>" << endl;
        return 1;
    }

    string nombreArchivo = argv[1];
    string nombreAlgoritmo = argv[2];
    int repeticiones = stoi(argv[3]);

    vector<int32_t> datos = leerArregloDesdeArchivo(nombreArchivo);

    //Mapeo de algoritmos por nombre
    vector<pair<string, function<void(vector<int32_t>&)>>> algoritmos = {
        {"InsertionSort", insertionSort},
        {"MergeSort", mergeSort},
        {"QuickSort", quickSort},
        {"HeapSort", heapSort},
        {"SortEstandar", sortEstandar},
        {"RadixSort", radixSort},
    };

    bool encontrado = false;
    for (auto& [nombre, funcion] : algoritmos) {
        if (nombre == nombreAlgoritmo) {
            double tiempoPromedio = medirPromedio(funcion, datos, repeticiones);
            cout << tiempoPromedio << endl;  
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cerr << "Error: algoritmo '" << nombreAlgoritmo << "' no encontrado." << endl;
        return 1;
    }

    return 0;
}
