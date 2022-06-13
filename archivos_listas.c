#include "archivos_listas.h"

FILE* abrir_archivo(const char *nombre_archivo, char *modo) {
  FILE *archivo = fopen(nombre_archivo, modo);
  assert(archivo != NULL);
  
  return archivo;
}

SList slist_agregar_final(SNodo* lista, char *provincia, int v_habitadas, int v_deshabitadas, int v_colectivas) {
  SList nuevo_nodo = malloc(sizeof(SNodo));

  int largo_nombre_provincia = strlen(provincia);
  nuevo_nodo->provincia = malloc(sizeof(char) * (largo_nombre_provincia + 1));
  nuevo_nodo->provincia = provincia;
  nuevo_nodo->v_habitadas = v_habitadas;
  nuevo_nodo->v_deshabitadas = v_deshabitadas;
  nuevo_nodo->v_colectivas = v_colectivas;
  nuevo_nodo->sig = NULL;

  if (lista == NULL)
    return nuevo_nodo;

  SList nodo_temp = lista;
  for (; nodo_temp->sig != NULL; nodo_temp = nodo_temp->sig);

  nodo_temp->sig = nuevo_nodo;
  return lista;
}

SList csv_a_lista(char const* viviendas_provincia){
  SList lista = NULL;
  FILE* provincia_info = abrir_archivo(viviendas_provincia,"r");
  
  char *provincia;
  int v_habitadas, v_deshabitadas, v_colectivas;

  for(; EOF != fscanf(provincia_info, "%s,%d,%d,%d\n", provincia, &v_habitadas, &v_deshabitadas, &v_colectivas);)
    lista = slist_agregar_final(lista, provincia, v_habitadas, v_deshabitadas, v_colectivas);

  fclose(provincia_info);

  return lista;
}
