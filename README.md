# TP 2 Listas (filtros) en C - Martin Cabrera, Ayrton Cuffaro - 5to Informática

## Tabla de contenidos
1. [Compilación](#compilación)
2. [Separación y uso de archivos](#Separación-y-uso-de-archivos)
3. [Decisiones tomadas](#decisiones-tomadas)
4. [Resolución de consignas](#Resolución-de-consignas)

## Compilación

gcc main.c archivos_listas.c filtros.c


## Separación y uso de archivos

Planteamos un diagrama donde solo usaríamos 3 archivos que contengan código en C (teniendo en cuenta .c y .h), además del archivo CSV que menciona el enunciado, el makefile y el mismo readme.

### main
Se utiliza la función main y se llama a las funciones necesarias para la realización correcta del enunciado.

### archivos_listas
Librería donde se va a trabajar con archivos y listas, contiene las funciones principales abrir_archivo y csv_a_lista (entre otras).
 Este archivo está pensado para ser incluido en filtros.h

### filtros
Librería donde se van a ubicar todas las funciones puntero, y las funciones solicitadas de filter_listas y filter_fold_listas


## Decisiones tomadas

- Decidimos que la estructura del programa sea "main < filtros < archivos_listas", debido a que en el archivo de filtros eran necesarias algunas funciones tanto de listas como de manejo de archivos. Esto hace que en main.h solo se incluya filtros.h (porque archivos_listas.h fue incluido en este anteriormente).

- Utilizamos algunas funciones de ejemplos dados en clase, dado que no era necesario crear nuestras propias, ya que entendíamos el funcionamiento de las mismas y fuimos capaces de adaptarlas a conveniencia del programa. Estas funciones son: abrir_archivo | slist_agregar_final | slist_destruir. 

- Utilizamos listas simplemente enlazadas porque no nos es relevante recorrer la lista de otra manera que no sea linealmente y en comparación al resto de tipos de listas, es la que necesita menos memoria.

- En las función sacar_string se nos presentó un problema, pediamos memoria para un string y luego lo retornabamos, haciendo imposible que luego podamos liberar la memoria. Para solucionar el problema decidimos pedir la memoria directamente en la funcion csv_a_archivo, e ingresar la direccion de memoria pedida como argumento en sacar_string, de esta manera no ibamos a perder esa dirección y luego podríamos utilizar la función free para liberar la memoria.

- Para facilitar la lectura de la función sacar_string, decidimos utilizar constantes, de esta manera, el código es mucho más entendible, pero en el pre-procesado queda exactamente igual que como estaría si no las utilizaramos, lo que nos asegura que no tiene ningún impacto negativo en el funcionamiento del programa.

- Dentro de archivos_listas.c en las función de slist_imprimir, más especificamente en esta parte: "| %-52s | %-11d | %-14d | %-12d |\n", tiene esta combinación de letras y números que a simple vista son extraños pero que en realidad cumplen la función de darle un formato uniforme a cada fila sin importar los valores que se le ingrese. La primera columna tiene esto ya que la provincia con el nombre más largo (Tierra del Fuego y demás) posee un largo de 52 carácteres y de esta manera reservamos los 52 carácteres que van a tener los nombres como máximo. En cuanto al resto de columnas, fue producto de primero el tipo de carácter (el cuál es int en todos los casos) y luego el número es debido al largo del encabezado de la columna (claramente una provincia no va a tener más de 10^11 viviendas).

- Utilizamos la herramienta de valgrind, y con esta misma pudimos certificar que nuestro programa funcionaba sin fugas de memoria:
```
$ ==3119== HEAP SUMMARY:
$ ==3119==     in use at exit: 0 bytes in 0 blocks
$ ==3119==   total heap usage: 110 allocs, 110 frees, 2,282 bytes allocated
```

## Resolución de consignas:

### Consigna 6
 La ventaja principal de reutilizar filter_listas para la funcion fold_filter_listas es la separación lógica de la función final en partes, en otras palabras, separa el trabajo de fold_filter_listas en otras funciones más pequeñas y simples, facilitando así su lectura.
 Hacer esto es sumamente óptimo ya que no tiene ninguna desventaja tan importante como para dejar de lado la separación lógica (más allá de poder ocupar más lineas en el archivo, una desventaja casi imperceptible).

### Consigna 8
 Teniendo un archivo de n cantidad de lineas, podemos crear una lista de n-1 cantidad de nodos (le restamos la linea de los encabezados). Al ser simplemente enlazada el peor de los casos es que el elemento se encuentre en el último nodo, es decir, el peor caso se da cuando se recorre n-1 nodos (en el caso del archivo propuesto "viviendas_por_provincia.csv", que tiene 25 lineas, en el peor caso se recorrerán 24 nodos).

 Poder asumir que la lista esta ordenada alfabeticamente no influye en nada, ya que los nodos trabajan con direcciones de memoria, y no son capaces de utilizar busquedas de tipo binario (exclusivas en estos casos de ordenamiento). Si en caso de querer realizar una busqueda de este tipo, previamente habrá que adaptar cada nodo para que posea la dirección del nodo en el centro de cada subdivisión (lo cuál si se piensa detenidamente es prácticamente inviable y se le agregaría una mayor complejidad de la necesaria).
