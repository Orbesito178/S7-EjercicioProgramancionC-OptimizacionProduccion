#ifndef FUNCIONES_H
#define FUNCIONES_H

#define PRODS 5
#define ATRIB 3


#include<stdio.h>

//void solicitarProductos(char nombresProductos[5][50]);


int mostrarMenu(int *opcionMenu);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3] );
void mostrarDatos(char nombresProductos[][50], float atributosProds[][3] );
float calcularTiempoTotal(float atributosProds[][3]);
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3]);

#endif
