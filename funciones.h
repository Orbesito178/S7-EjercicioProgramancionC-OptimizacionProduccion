// Guardamos aquí las definiciones de todas las funciones de funciones.h
// para que otros archivos puedan usarlas sin redefinirlas
#ifndef FUNCIONES_H
#define FUNCIONES_H


#define ATRIB 3  // Cada producto tiene 3 atributos: tiempo, recursos y demanda

#include <stdio.h>
#include <string.h>

int mostrarMenu(int *opcionMenu);
int mostrarDatos(char nombresProductos[][50], float atributosProds[][3], int indice);
float calcularTiempoTotal(float atributosProds[][3], int *ptrprods);
float calcularRecursosTotal(float atributosProds[][3], int *ptrprods);
int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);

#endif