#include "filtros.h"

SList filter_listas(SList lista, Predicado p){
	SList lista_nueva = NULL;
	for(; lista != NULL; lista = lista->sig){
		if(p(lista))
			slist_agregar_final(lista_nueva, lista->provincia, lista->v_habitadas, lista->v_deshabitadas, lista->v_colectivas);
	}
	return lista_nueva;
}

int mayor_mil_v_deshabitadas(SList lista){
	return lista->v_deshabitadas > 1000;
}


int filter_fold_listas(SList lista, Predicado p, Operador o){
	return o(filter_listas(lista, p));
}

int mayor_mil_v_colectivas(SList lista){
	return lista->v_colectivas > 1000;
}

int suma_viviendas_totales(SList lista){
	int suma;
	for(; lista != NULL;  lista = lista->sig){
		suma += lista->v_habitadas;
		suma += lista->v_deshabitadas;
	}
	return suma;
}
