# TP 2 Listas (filtros) en C - Martin Cabrera, Ayrton Cuffaro - 5to Informática


## Compilación

gcc -std=c99 main.c archivos_listas.c filtros.c 


## Explicación de separación de archivos y uso de los mismos.

Planteamos un diagrama donde solo usaríamos 3 archivos que contengan código en C (teniendo en cuenta .c y .h), además del archivo CSV que menciona el enunciado, el makefile y el mismo readme.

### main
Se utiliza la función main y se llama a las funciones necesarias para la realización correcta del enunciado.

### archivos_listas
Librería donde se va a trabajar con archivos y listas, contiene las funciones principales abrir_archivo y csv_a_lista (entre otras).
 Este archivo está pensado para ser incluido en filtros.h

### filtros
Librería donde se van a ubicar todas las funciones puntero, y las funciones solicitadas de filter_listas y filter_fold_listas


## Explicación de decisiones durante del programa

- Decidimos que la estructura del programa sea "main < filtros < archivos_listas", debido a que en el archivo de filtros eran necesarias algunas funciones tanto de listas como de manejo de archivos. Esto hace que en main.h solo se incluya filtros.h (porque archivos_listas.h fue incluido en este anteriormente).

- Utilizamos algunas funciones de ejemplos dados en clase, dado que no era necesario crear nuestras propias, ya que entendíamos el funcionamiento de las mismas y fuimos capaces de adaptarlas a conveniencia del programa. Estas funciones son: abrir_archivo | slist_agregar_final | slist_destruir. 

- Utilizamos listas simplemente enlazadas porque no nos es relevante recorrer la lista de otra manera que no sea linealmente y en comparación al resto de tipos de listas, es la que necesita menos memoria.

- En las función sacar_string se nos presentó un problema, pediamos memoria para un string y luego lo retornabamos, haciendo imposible que luego podamos liberar la memoria. Para solucionar el problema decidimos pedir la memoria directamente en la funcion csv_a_archivo, e ingresar la direccion de memoria pedida como argumento en sacar_string, de esta manera no ibamos a perder esa dirección y luego podríamos utilizar la función free para liberar la memoria.

- Para facilitar la lectura de la función sacar_string, decidimos utilizar constantes, de esta manera, el código es mucho más entendible, pero en el pre-procesado queda exactamente igual que como estaría si no las utilizaramos, lo que nos asegura que no tiene ningún impacto negativo en el funcionamiento del programa.

- Dentro de archivos_listas.c en las función de slist_imprimir, más especificamente en esta parte: "|AYRTON COMPLETA|", tiene esta combinación de letras y números que a simple vista son extraños pero que en realidad cumplen la función de darle un formato uniforme a cada fila sin importar los valores que se le ingrese. 

## Resolución de consignas:

Consigna 6: La ventaja principal de reutilizar filter_listas para la funcion fold_filter_listas es la separación lógica de la función final en partes, en otras palabras, separa el trabajo de fold_filter_listas en otras funciones más pequeñas y simples, facilitando así su lectura.
 Hacer esto es sumamente óptimo ya que no tiene ninguna desventaja tan importante como para dejar de lado la separación lógica (más allá de poder ocupar más lineas en el archivo, una desventaja casi imperceptible).

Consigna 8: 
 Teniendo un archivo de n cantidad de lineas, por lo tanto, una lista de n-1 cantidad de nodos (se le resta los encabezados). Al ser simplemente enlazada el peor de los casos es que el elemento se encuentre en el ultimo nodo, por lo cual el peor caso se da cuando se recorre n-1 nodos (en el caso del archivo propuesto "viviendas_por_provincia.csv", que tiene 25 lineas, en el peor caso se recorreran 24 nodos).

 Poder asumir que la lista esta ordenada alfabeticamente no influye en nada, ya que los nodos trabajan con direcciones de memoria, y no son capaces de utilizar busquedas de tipo binario (exclusivas en estos casos de ordenamiento).

