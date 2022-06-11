#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdlib.h>
#include <stdio.h>

/* 
 * Usaremos la estructura SNodo
 * para trabajar con los datos
 */
typedef struct _SNodo {
	char *provincia;
	int v_habitadas;
	int v_deshabitadas;
	int v_colectivas;
	struct _SNodo *sig;
} SNodo; 

/* 
 * Como vamos a utilizar muchos punteros a Snodo, 
 * es efectivo crear una definición para estos.
 */
typedef SList *Snodo;


/*
 * Esta función va a tomar el primer nodo de una lista y todos los datos (excepto sig),del struct SNodo.
 * Va a agregar un nodo al final de la lista que contenga al nodo dado y ese nodo tendrá los datos ingresados.
 *
 * Retorna la lista que le fue ingresada, 
 * si ninguna lista fue ingresada retorna el nodo que debería estar en su última posición.
 */
SList slist_agregar_final(Slist lista, char const *provincia, int v_habitadas, int v_deshabitadas, int v_colectivas); 

/*
 * Esta función va a tomar un puntero a char que contenga el nombre del archivo ingresado al main (archivo CSV, 4 datos por linea),
 * lo va a abrir, y va crear una lista, haciendo uso de la funcion slist_agregar_final.
 * 
 * Retorna el primer nodo de la lista creada.
 */
SList csv_a_lista(char const* viviendas_provincia);

#endif