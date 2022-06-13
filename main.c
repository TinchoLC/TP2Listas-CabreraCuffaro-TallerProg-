#include "main.h"

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    printf("Uso del ejecutable: %s <archivo_csv>\n", argv[0]);
    return 1;
  }

  SList viviendas_por_provincia = csv_a_lista(argv[1]);
  

  return 0;
}