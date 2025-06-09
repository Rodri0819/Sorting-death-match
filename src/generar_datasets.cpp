#include "../utils/generador_arreglos.h"
#include <iostream>

int main() {
    int n = 100000;

    guardarBinario("datasets/generados/dataset_ascendente.bin", generarAscendente(n));
    guardarBinario("datasets/generados/dataset_descendente.bin", generarDescendente(n));
    guardarBinario("datasets/generados/dataset_aleatorio.bin", generarAleatorio(n));
    guardarBinario("datasets/generados/dataset_parcial.bin", generarParcial(n));

    std::cout << "¡Datasets binarios generados correctamente!" << std::endl;
    return 0;
}
