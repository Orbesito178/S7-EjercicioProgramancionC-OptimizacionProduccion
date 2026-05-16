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
#include "procedimientos.h"


//==== PROTOTIPOS
//>>>>>>> PROCEDIMIENTOS
void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods);
void registrarProductos(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);
void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto);
void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
void eliminarProducto(char nombresProductos[][50], float atributosProds[][3],int *ptrprods);
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods );
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods);

//>>>>>> FUNCIONES
int mostrarMenu(int *opcionMenu);
int mostrarDatos(char nombresProductos[][50], float atributosProds[][3], int indice );
int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods);
float calcularTiempoTotal(float atributosProds[][3], int *ptrprods);
float calcularRecursosTotal(float atributosProds[][3], int *ptrprods);

//////////////////////////////////// F U N C I O N  P R I N C I P A L //////////////////////////////////////////////

int main(){
    float tiempoFabrica=500; //Limitación preestablecida de el tiempo de fábrica.
    float recursosFabrica=300; //Limitación preestablecida de los recursos de fábrica.
    


    float *ptrtiempoFabrica;
    ptrtiempoFabrica = &tiempoFabrica;

    float *ptrrecursosFabrica;
    ptrrecursosFabrica = &recursosFabrica;

    // variables de menus inicializadas en 0


    int opcion2=0;
    int *opcionMenu;
    opcionMenu = &opcion2;

    //Numero de productos

    int prods=5;
    int *ptrprods;
    ptrprods = &prods;

    //Datos de los productos

    char nombresProductos[5][50] = {"Resistencia", "Condensador", "Transistor", "Diodo", "Microprocesador"};
    float atributosProds[5][3];

    //char nombresProductos[5][50];
    //solicitarProductos(nombresProductos);
    

    //Flujo principal del programa
                                     
    registrarProductos(nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);
    
    acciones(opcionMenu, nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);


    //escogerProducto(nombresProductos, opcionProducto, atributosProds);
    //mostrarDatos(nombresProductos, atributosProds);


    return 0;
}

