#ifndef FILTROS_H
#define FILTROS_H
#include "archivos_listas.h"

/*
 * Declaramos la función de tipo Predicado, que obtiene un puntero a SNodo y retorna un int (que va a utilizarse como boole).
 */
typedef int (*Predicado) (SList nodo);

/*
 * Esta función obtiene como argumentos, un puntero a SNodo (que es el primer nodo de una lista) y una función de tipo predicado
 * 
 * Va a crear una nueva lista, donde solo estén presentes los nodos de la lista ingresada que cumplan con lo que
 * la funcion predicado pida, se retornará la lista nueva.
 */
SList filter_listas(SList lista, Predicado p);

/*
 * Función de tipo predicado, devuelve:
 * 0 si el dato v_deshabitadas del nodo ingresado es menor o igual a 1000
 * 1 0 si el dato v_deshabitadas del nodo ingresado es mayor a 1000
 */
int mayor_mil_v_deshabitadas(SList Nodo);

/*
 * Declaramos la función de tipo operador, que obtiene un puntero a SNodo y retorna un int (resultado de una operación).
 */
typedef int (*Operador) (SList Nodo);

/*
 * Esta función obtiene como argumentos, un puntero a SNodo (que es el primer nodo de una lista),
 * una función de tipo predicado y una función de tipo operador.
 * 
 * Va a utilizar la función filter_listas para filtrar una lista con la función predicado, y luego utilizará la función
 * operador en la lista resultante para retornar lo que retorne la misma.
 */
int filter_fold_listas(SList lista, Predicado p, Operador o);

/*
 * Función de tipo predicado, devuelve:
 * 0 si el dato v_colectivas del nodo ingresado es menor o igual a 1000
 * 1 0 si el dato v_colectivas del nodo ingresado es mayor a 1000
 */
int mayor_mil_v_colectivas(SList Nodo);

/*
 * Función de tipo operador, devuelve las viviendas totales que hay a lo largo de los nodos de una lista 
 * (v_habitadas + v_deshabitadas)
 */
int suma_viviendas_totales(SList lista);

#endif
