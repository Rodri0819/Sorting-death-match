#include "../utils/generador_arreglos.h"
#include <iostream>

int main() {
    int n = 1000000;

    guardarBinario("dataset_ascendente.bin", generarAscendente(n));
    guardarBinario("dataset_descendente.bin", generarDescendente(n));
    guardarBinario("dataset_aleatorio.bin", generarAleatorio(n));
    guardarBinario("dataset_parcial.bin", generarParcial(n));

    std::cout << "¡Datasets binarios generados correctamente!" << std::endl;
    return 0;
}
