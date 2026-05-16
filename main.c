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
>>>>>>>>>>>>>>>>>> ORBTIMIZER <<<<<<<<<<<<<<<<<<
*/

// Aquí incluimos las librerías y archivos de cabecera que necesita el programa
#include <stdio.h>
#include "funciones.h"
#include "procedimientos.h"


// ==== PROTOTIPOS
// Declaramos todas las funciones antes de usarlas para que el compilador las reconozca

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
    // La fábrica tiene un límite de 500 horas de trabajo y 300 unidades de recursos
    float tiempoFabrica = 500;
    float recursosFabrica = 300;

    // Punteros que apuntan a esos límites para poder pasarlos a las funciones
    //Puntero a limite de tiempo.
    float *ptrtiempoFabrica;
    ptrtiempoFabrica = &tiempoFabrica;

    //puntero a limite de recursos
    float *ptrrecursosFabrica;
    ptrrecursosFabrica = &recursosFabrica;

    // Variable para guardar la opción que elija el usuario en el menú
    int opcion2 = 0;
    int *opcionMenu;
    opcionMenu = &opcion2;

    // La fábrica maneja 5 productos fijos. Se usa puntero para modificarlos despues.
    int prods = 5;
    int *ptrprods;
    ptrprods = &prods;

    // Los 5 productos ya tienen nombre definido; sus atributos (tiempo, recursos, demanda) se llenan después
    char nombresProductos[5][50] = {"Resistencia", "Condensador", "Transistor", "Diodo", "Microprocesador"};
    float atributosProds[5][3];

    // Primero pedimos los datos de cada producto.
    registrarProductos(nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);
    //luego entramos al menú de acciones.
    acciones(opcionMenu, nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);

    return 0;
}