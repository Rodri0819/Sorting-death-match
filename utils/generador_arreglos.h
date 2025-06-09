#ifndef GENERADOR_ARREGLOS_H
#define GENERADOR_ARREGLOS_H

#include <vector>
#include <string>
#include <cstdint>

std::vector<int32_t> generarAscendente(int n);
std::vector<int32_t> generarDescendente(int n);
std::vector<int32_t> generarAleatorio(int n);
std::vector<int32_t> generarParcial(int n);
void guardarBinario(const std::string& nombre, const std::vector<int32_t>& datos);

#endif
