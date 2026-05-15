#ifndef FUNCIONES_H
#define FUNCIONES_H

#define PRODS 5
#define ATRIB 3


#include<stdio.h>
#include <string.h>

//void solicitarProductos(char nombresProductos[5][50]);


int mostrarMenu(int *opcionMenu);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
int mostrarDatos(char nombresProductos[][50], float atributosProds[][3], int indice);
float calcularTiempoTotal(float atributosProds[][3], int *ptrprods);
float calcularRecursosTotal(float atributosProds[][3], int *ptrprods);
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);

#endif
