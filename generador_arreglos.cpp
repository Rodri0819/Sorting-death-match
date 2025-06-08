#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <ctime>
#include <cstdlib> 

using namespace std;

void guardarBinario(const string& nombre, const vector<int32_t>& datos) {
    ofstream archivo(nombre, ios::binary);
    for (int32_t num : datos)
        archivo.write(reinterpret_cast<const char*>(&num), sizeof(int32_t));
    archivo.close();
}

vector<int32_t> generarAscendente(int n) {
    vector<int32_t> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;
    return v;
}

vector<int32_t> generarDescendente(int n) {
    vector<int32_t> v(n);
    for (int i = 0; i < n; ++i) v[i] = n - i;
    return v;
}

std::vector<int32_t> generarAleatorio(int n) {
    std::srand(std::time(nullptr)); //Semilla con el tiempo actual
    std::vector<int32_t> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 1000000; //Entre 0 y 999999
    }
    return arr;
}

std::vector<int32_t> generarParcial(int n) {
    std::srand(std::time(nullptr));  // Semilla con la hora actual

    std::vector<int32_t> v = generarDescendente(n); //o generarAscendente(n);
    int desde = n * 0.66;

    // Mezclar elementos desde el 66% al final con rand()
    for (int i = desde; i < n; ++i) {
        int j = desde + std::rand() % (n - desde);  // índice aleatorio entre [desde, n)
        std::swap(v[i], v[j]);
    }

    return v;
}

int main() {
    int n = 1000000; //1 millón de elementos

    guardarBinario("dataset_ascendente.bin", generarAscendente(n));
    guardarBinario("dataset_descendente.bin", generarDescendente(n));
    guardarBinario("dataset_aleatorio.bin", generarAleatorio(n));
    guardarBinario("dataset_parcial.bin", generarParcial(n));

    cout << "¡Datasets binarios generados correctamente!" << endl;
    return 0;
}
