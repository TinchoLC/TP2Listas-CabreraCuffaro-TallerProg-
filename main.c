#include "main.h"

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    printf("Uso del ejecutable: %s <archivo_csv>\n", argv[0]);
    return 1;
  }

  SList viviendas_por_provincia = csv_a_lista(argv[1]); // Creamos la lista principal 
  
  SList provincias_mas_mil_deshabitadas = filter_listas(viviendas_por_provincia, mayor_mil_v_deshabitadas); // Consigna 4

  int cantitad_total_viviendas_mas_mil_colectivas = filter_fold_listas(viviendas_por_provincia, mayor_mil_v_colectivas, suma_viviendas_totales); // Consigna 7



  // faltan los free

  return 0;
}