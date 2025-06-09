#!/bin/bash

# Ruta del ejecutable de ordenamiento
EXECUTABLE=./ordenar

# Ruta del dataset ascendente
DATASET="datasets/generados/dataset_ascendente.bin"

# Tamaño del dataset en elementos (dividido por 4 bytes por entero)
TAMANO=$(stat -c %s "$DATASET")
TAMANO=$((TAMANO / 4))

# Algoritmo a probar
ALGORITMO="InsertionSort"

# Número de repeticiones
REPS=10

# Ejecutar y capturar el tiempo promedio
TIEMPO=$($EXECUTABLE "$DATASET" "$ALGORITMO" "$REPS")

# Ruta de destino en OneDrive (WSL usa /mnt/c/)
OUTPUT="/mnt/c/Users/rodri/OneDrive/Escritorio/estructura_de_datos/2/Sorting-death-match/resultados/resultados.csv"

# Escribir encabezado y resultado en archivo CSV
{
  echo "algoritmo,tamano,tiempo_ms"
  echo "$ALGORITMO,$TAMANO,$TIEMPO"
} > "$OUTPUT"
