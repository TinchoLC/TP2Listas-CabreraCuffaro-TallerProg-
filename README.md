# TP 2 Listas (filtros) en C - Martin Cabrera, Ayrton Cuffaro - 5to Informática


## Compilación

gcc main.c archivos_listas.c filtros.c


## Explicación de separación de archivos y uso de los mismos.

Planteamos un diagrama donde solo usaríamos 3 archivos que contengan código en C (teniendo en cuenta .c y .h), además del archivo CSV que menciona el enunciad, el makefile y el mismo readme.

### main
Se utiliza la función main y se llama a las funciones necesarias para la realización correcta del enunciado.

### archivos_listas
Librería donde se va a trabajar con archivos y listas, contiene las funciones principales abrir_archivo y csv_a_lista (entre otras).
 Este archivo está pensado para ser incluido en filtros.h

### filtros
Librería donde se van a ubicar todas las funciones puntero, y las funciones solicitadas de filter_listas y filter_fold_listas


## Explicación de decisiones durante del programa



## Resolución de consignas:

