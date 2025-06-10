#include <vector>
#include <cstdint>
#include "merge_sort.h"


void merge(std::vector<int32_t>& A, int left, int mid, int right) {
    //Tamaño de las sublistas izquierda y derecha
    int n1 = mid - left + 1; //Mitad - izquierda + 1, osea la parte derecha + la mitad
    int n2 = right - mid; //Derecha - mitad, osea la parte izquierda
    //Subarreglos temporales
    std::vector<int32_t> L(n1), R(n2);

    //Copiar datos a los subarreglos temporales    
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i]; //Copiamos la parte izquierda
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j]; //Copiamos la parte derecha

    //Indices para recorrer los subarreglos y el arreglo original
    int i = 0, j = 0, k = left; 

    //Mezclar los subarreglos de vuelta en el arreglo original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { //Si el elemento en L es menor o igual 
            A[k++] = L[i++]; //Lo copiamos
        } else {             //Si no
            A[k++] = R[j++]; //Copiamos la parte izquierda
        }
    }

    //Copiar los elementos restantes de la sublista izquierda
    while (i < n1) {
        A[k++] = L[i++];
    }

    //Copiar los elementos restantes de la sublista derecha
    while (j < n2) {
        A[k++] = R[j++];
    }
}

//Función auxiliar recursiva que divide el arreglo en mitades y luego las mezcla ordenadas
void mergeSortAux(std::vector<int32_t>& A, int left, int right) {
    if (left >= right) return; //Caso base

    int mid = left + (right - left) / 2; //Calculamos el punto medio
    //Dividir recursivamente el arreglo en mitades
    mergeSortAux(A, left, mid); //Parte izquierda
    mergeSortAux(A, mid + 1, right); //Parte derecha
    //Combinar las mitades ordenadas
    merge(A, left, mid, right);
}

void mergeSort(std::vector<int32_t>& A) {
    if (!A.empty())
        mergeSortAux(A, 0, A.size() - 1);
}
