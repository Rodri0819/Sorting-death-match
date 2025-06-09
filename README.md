<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8"></head>
<body style="font-family: sans-serif; background-color: #1e1e1e; color: #000000; padding: 2rem;">

  <h1 align="center">Sorting death-match</h1>
  <h3 align="center">Estructura de Datos</h3>

  <hr>

  <h2>Integrantes</h2>
  <ul>
    <li>Rodrigo Bascuñán León</li>
    <li>Sebastian Emir Garcia</li>
  </ul>

  <hr>

  <h2>Instrucciones de uso</h2>
  <p>Estando en la carpeta Sorting-death-match/ compila el proyecto con:</p>
  <pre><code>g++ -std=c++17 -I. src/main.cpp insertion_sort/insertion_sort.cpp merge_sort/merge_sort.cpp quick_sort/quick_sort.cpp heap_sort/heap_sort_v2.cpp radix_sort/radix_sort.cpp sorting_estandar/sort_estandar.cpp -o ordenar.exe</code></pre>

  <p>Una vez compilado, ejecuta el programa con:</p>
  <pre><code>./ordenar &lt;archivo_dataset&gt; &lt;nombre_algoritmo&gt; &lt;repeticiones&gt;</code></pre>

  <p>Ejemplo:</p>
  <pre><code>./ordenar dataset_aleatorio.bin QuickSort 20</code></pre>

  <hr>

<h2>Generar archivos datasets</h2>

<p>Para generar los datasets utilizados en los experimentos, sigue estos pasos:</p>

<ol>
  <li>
    Estando en la carpeta Sorting-death-match/
    compila el generador de datasets:
    <pre><code>g++ src/generar_datasets.cpp utils/generador_arreglos.cpp -o generar_datasets.exe cpp</code></pre>
  </li>

  <li>
    Ejecuta el generador:
    <pre><code>./generar_datasets</code></pre>
  </li>
</ol>

<p>Esto generará los siguientes archivos binarios:</p>
<ul>
  <li><code>dataset_ascendente.bin</code> : datos ordenados ascendentemente</li>
  <li><code>dataset_descendente.bin</code> : datos ordenados en reversa</li>
  <li><code>dataset_aleatorio.bin</code> : datos completamente aleatorios</li>
  <li><code>dataset_parcial.bin</code> : 66% descendente, 34% aleatorio</li>
</ul>


  <hr>

  <h2>Algoritmos comparados</h2>
  <ul>
    <li>InsertionSort</li>
    <li>MergeSort</li>
    <li>QuickSort</li>
    <li>HeapSort</li>
    <li>RadixSort</li>
    <li>SortEstandar (<code>std::sort</code>)</li>
  </ul>

  

</body>
</html>
