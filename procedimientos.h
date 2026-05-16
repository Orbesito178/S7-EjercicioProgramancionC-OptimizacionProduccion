// Guardamos aquí las definiciones de todas las funciones de procedimientos.h
// para que otros archivos puedan usarlas sin redefinirlas
#ifndef PROCEDIMIENTOS_H
#define PROCEDIMIENTOS_H

#define ATRIB 3 // Cada producto tiene 3 atributos: tiempo, recursos y demanda

#include <stdio.h>
#include <string.h>

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods);
void registrarProductos(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto);
void eliminarProducto(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
void editarDatos(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);

#endif