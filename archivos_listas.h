#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // para utilizar strlen
#include <assert.h> // para utilizar assert

#define ESPACIO_MAX_STRING 60  // Se utiliza en mallocs de guardar palabras
#define ESPACIO_MAX_LINEA_CSV 100  // Se utiliza en mallocs de guardar linea 
#define STRING_MOVI *(string+i)  // Se utiliza para representar la letra de una palabra (dentro de un for, con su movimiento)
#define CSV_LINE_MOV *(csv_line + *mover_linea)  // Se utiliza para representar el caracter de una linea (teniendo en cuenta su movimiento)
#define MOV (*mover_linea)  // Se utiliza como contador de movimiento

/* 
 * Usaremos la estructura DProvincia
 * como campo de la estructura Nodo donde se ingresan los datos
 */
typedef struct _DProvincia {
    char *provincia;
    int v_habitadas;
    int v_deshabitadas;
    int v_colectivas;
} DProvincia;

/* 
 * Usaremos la estructura SNodo
 * para crear las listas
 */
typedef struct _SNodo {
    struct DProvincia *datos;
    struct _SNodo *sig;
} SNodo;

/* 
 * Como vamos a utilizar muchos punteros a Snodo, 
 * es efectivo crear una definición para estos.
 */
typedef struct _SNodo* SList;

/*
 * Esta función toma la ruta de un archivo y el modo en el que
 * se quiere abrir y devuelve el archivo objeto resultado de
 * abrirlo en dicho modo
 */
FILE* abrir_archivo(const char *nombre_archivo, char *modo);

/*
 * Esta funcion recibe un puntero a char que apunta al primer caracter de una linea
 * de un archivo CSV y además recibe un puntero a int que apunta al numero que 
 * indica en que caracter de la linea estamos en ese momento. Obtiene adicionalmente un
 * string que es el que luego retornará.
 *
 * Retorna un string con todo lo que haya antes de la siguiente coma del archivo CSV
 * a partir de el corrimiento de la linea (mover linea). Además modifica el int al que apunta mover_linea
 * dejándolo en la posición siguiente a la coma.
 */
char* sacar_string(char* csv_line, int* mover_linea, char* string);

/*
 * Esta funcion recibe un puntero a char que apunta al primer caracter de una linea
 * de un archivo CSV y además recibe un puntero a int que apunta al numero que 
 * indica en que caracter de la linea estamos en ese momento. Obtiene adicionalmente un
 * string que es el que luego retornará.
 *
 * Utiliza la función sacar_string y le aplica la función atoi (de stdlib.h) para retornar
 * un entero con los numeros dentro del string obtenido.
 */
int sacar_int(char* csv_line, int* mover_linea, char* string);

/*
 * Esta función va a tomar el primer nodo de una lista y todos los datos (excepto sig),del struct SNodo.
 * Va a agregar un nodo al final de la lista que contenga al nodo dado y ese nodo tendrá los datos ingresados.
 *
 * Retorna la lista que le fue ingresada, 
 * si ninguna lista fue ingresada retorna el nodo que debería estar en su última posición.
 */
SList slist_agregar_final(SList lista, char* provincia, int v_habitadas, int v_deshabitadas, int v_colectivas); 

/*
 * Esta funcion libera la memoria solicitada para los nodos de una lista ingresada
 * y el dato "provincia" en cada uno de ellos.
 */
void slist_destruir(SList lista);

/*
 * Obtiene el primer nodo de una lista y muestra todos los campos de
 * todos los nodos de la misma (utiliza solamente printf).
 */
void slist_imprimir(SList lista);

/*
 * Esta función va a tomar un puntero a char que contenga el nombre del archivo ingresado al main (archivo CSV, 4 datos por linea),
 * lo va a abrir, y va crear una lista, haciendo uso de la funcion slist_agregar_final.
 * 
 * Retorna el primer nodo de la lista creada.
 */
SList csv_a_lista(char const* viviendas_provincia);

#endif
