#Makefile del programa

output: main.o archivos_listas.o filtros.o
	gcc -std=c99 main.o archivos_listas.o filtros.o -o Listas

main.o: main.c main.h
	gcc -std=c99 -c main.c main.h

archivos_listas.o: archivos_listas.c archivos_listas.h
	gcc -std=c99 -c archivos_listas.c archivos_listas.h

filtros.o: filtros.c filtros.h
	gcc -std=c99 -c filtros.c filtros.h

clear: *.o Listas
