#!/bin/bash

EXEC=./ordenar
REPS=20
RESULTS_DIR="resultados"

# Crear carpeta de resultados si no existe
mkdir -p "$RESULTS_DIR"

# Tipos de datasets
TIPOS=("ascendente" "descendente" "aleatorio" "parcial")

# Algoritmos definidos
ALGORITMOS=("MergeSort" "HeapSort" "QuickSort" "SortEstandar" "RadixSort")

# Encabezado CSV
for tipo in "${TIPOS[@]}"; do
    echo "algoritmo,tamano,tiempo_ms" > "$RESULTS_DIR/resultados_${tipo}.csv"
done

# Ejecutar combinaciones
for tipo in "${TIPOS[@]}"; do
    archivo="dataset_${tipo}.bin"
    if [[ ! -f "$archivo" ]]; then
        echo "No existe $archivo"
        continue
    fi

    # TamaÃ±o en elementos
    TAMANO=$(($(stat -c%s "$archivo") / 4))

    for alg in "${ALGORITMOS[@]}"; do
        TIEMPO=$($EXEC "$archivo" "$alg" "$REPS")
        echo "$alg,$TAMANO;$TIEMPO;ms" >> "$RESULTS_DIR/resultados_${tipo}.csv"
        echo "[$tipo] $alg -> $TIEMPO ms"
    done
done