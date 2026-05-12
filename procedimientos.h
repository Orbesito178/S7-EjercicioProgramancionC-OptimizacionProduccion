#ifndef PROCEDIMIENTOS_H
#define PROCEDIMIENTOS_H

#define PRODS 5
#define ATRIB 3

#include <stdio.h>

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3]);
void registrarProductos(char nombresProductos[][50], float atributosProds[][3]);
void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto);

#endif