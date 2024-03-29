#include "filtros.h"

SList filter_listas(SList lista, Predicado p){
  SList lista_nueva = NULL;

  for (; lista != NULL; lista = lista->sig) {
    if (p(lista))
      lista_nueva = slist_agregar_final(lista_nueva, lista->datos->provincia, lista->datos->v_habitadas, lista->datos->v_deshabitadas, lista->datos->v_colectivas);
  }
  return lista_nueva;
}

int mayor_mil_v_deshabitadas(SList lista){
  return lista->datos->v_deshabitadas > 1000;
}


int filter_fold_listas(SList lista, Predicado p, Operador o){
  SList lista_auxiliar = filter_listas(lista, p);
  int operacion = o(lista_auxiliar);
  slist_destruir(lista_auxiliar);
  return operacion;
}

int mayor_mil_v_colectivas(SList lista){
  return lista->datos->v_colectivas > 1000;
}

int suma_viviendas_totales(SList lista){
  int suma = 0;
  for (SList nodo = lista; nodo != NULL; nodo = nodo->sig) {
    suma += nodo->datos->v_habitadas;
    suma += nodo->datos->v_deshabitadas;
  }
  return suma;
}
