/*
 =========== UNIVERSIDAD DE LAS AMÉRICAS =========
        FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
                INGENIERÍA DE SOFTWARE
                   PROGRAMACIÓN I

Autores:
    -David Cañizares
    -Sebastián Orbe
    -Jean Pierre Rosas
    -Derek Yépez

=============== OPTIMIZACIÓN DE FÁBRICA =============

*/

//Inclusión de librerías y archivos cabecera.
#include <stdio.h>
#include "funciones.h"

#include "funciones.c" /////////////////////////////////////////////////////////////////////
#include "procedimientos.c"

#include "procedimientos.h"


//==== PROTOTIPOS
//>>>>>>> PROCEDIMIENTOS
void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3]);
void registrarProductos(char nombresProductos[][50], float atributosProds[][3]);
void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto);

//>>>>>> FUNCIONES
int mostrarMenu(int *opcionMenu);
void mostrarDatos(char nombresProductos[][50], float atributosProds[][3] );
float calcularTiempoTotal(float atributosProds[][3]);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3] );
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3]);

//////////////////////////////////// F U N C I O N  P R I N C I P A L //////////////////////////////////////////////

int main(){
    int opcion=0;           
    int *opcionProducto;
    opcionProducto = &opcion; 

    int opcion2=0;
    int *opcionMenu;
    opcionMenu = &opcion2;

    char nombresProductos[5][50] = {"Resistencia", "Condensador", "Transistor", "Diodo", "Microprocesador"};
    //char nombresProductos[5][50];
    //solicitarProductos(nombresProductos);
    float atributosProds[5][3];
                                     
    registrarProductos(nombresProductos, atributosProds);
    mostrarMenu(opcionMenu);
    acciones(opcionMenu, nombresProductos, atributosProds);
    //escogerProducto(nombresProductos, opcionProducto, atributosProds);
    
    
    //mostrarDatos(nombresProductos, atributosProds);


    return 0;
}

