#ifndef PROCEDIMIENTOS_H
#define PROCEDIMIENTOS_H

#define PRODS 5
#define ATRIB 3

#include <stdio.h>

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods);
void registrarProductos(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto);
void eliminarProducto(char nombresProductos[][50], float atributosProds[][3],int *ptrprods);
void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
void editarDatos(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);

#endif