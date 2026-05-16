#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "procedimientos.h"


// Muestra las opciones del menú y valida que el usuario elija un número entre 1 y 5
int mostrarMenu(int *opcionMenu){
    printf("\n========== ACCIONES ========\n");
    printf("1. Mostrar Resultados.\n");
    printf("2. Editar informacion.\n");
    printf("3. Borrar producto.\n");
    printf("4. Mostrar datos actuales.\n");
    printf("5. Salir.\n");
    printf("Escoja: ");

    // Si el usuario escribe algo que no sea un número válido, se lo pedimos de nuevo
    while(scanf("%d", opcionMenu) != 1 || *opcionMenu < 1 || *opcionMenu > 5){
        while(getchar() != '\n');
        printf("Opcion invalida. Ingrese un numero entre 1 y 5: ");
    }
    return *opcionMenu;
}


// Suma el tiempo total que tomaría fabricar todos los productos
// (tiempo de fabricación de cada uno multiplicado por su cantidad demandada)
float calcularTiempoTotal(float atributosProds[][3], int *ptrprods){
    float tiempoFabTotal = 0;
    for(int i = 0; i < *ptrprods; i++){
        tiempoFabTotal += atributosProds[i][0] * atributosProds[i][2];
    }
    return tiempoFabTotal;
}

// Suma los recursos totales necesarios para fabricar todos los productos
// (recursos por unidad de cada producto multiplicado por su cantidad demandada)
float calcularRecursosTotal(float atributosProds[][3], int *ptrprods){
    float recursosFabTotal = 0;
    for(int i = 0; i < *ptrprods; i++){
        recursosFabTotal += atributosProds[i][1] * atributosProds[i][2];
    }
    return recursosFabTotal;
}


// Busca un producto por nombre y devuelve su posición en el arreglo
// Si no lo encuentra o el usuario cancela, devuelve -1
int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    char buscado[50] = {0};
    bool encontrado = false;
    int indice = -1;

    while(getchar() != '\n'); // Limpiamos el buffer antes de leer texto

    do{
        printf("\n======= BUSQUEDA POR NOMBRE ========\n");
        printf("Producto a buscar (0 para cancelar): ");

        fgets(buscado, 50, stdin);
        buscado[strcspn(buscado, "\n")] = '\0'; // Quitamos el salto de línea que deja fgets

        // Si escribe 0, cancelamos la búsqueda
        if(strcmp(buscado, "0") == 0){
            encontrado = true;
            return -1;
        } else {
            // Recorremos todos los productos buscando el que coincida con lo que escribió el usuario
            for(int i = 0; i < *ptrprods; i++){
                if(strcmp(nombresProductos[i], buscado) == 0){
                    encontrado = true;
                    indice = i;
                    break;
                } else {
                    encontrado = false;
                }
            }

            //si se encuentra, se retorna el índice del producto encontrado.
            if(encontrado == true){
                printf("----- PRODUCTO ENCONTRADO ----\n");
                return indice;
            } else {
                printf("------ PRODUCTO NO ENCONTRADO -----\n");
            }
        }

    } while(encontrado != true); // Seguimos preguntando hasta encontrarlo o cancelar

    return -1;
}


// Muestra los datos actuales de un producto y le pregunta al usuario cuál dato quiere editar
// Devuelve el número del dato elegido (1=Tiempo, 2=Recursos, 3=Demanda, 4=Salir)
int mostrarDatos(char nombresProductos[][50], float atributosProds[][3], int indice){
    int datoEditar = 0;
    printf(">>>> %s\n", nombresProductos[indice]);
    printf("\t-(1) Tiempo: %.2f\n", atributosProds[indice][0]);
    printf("\t-(2) Recursos: %.2f\n", atributosProds[indice][1]);
    printf("\t-(3) Cantidad Demandada: %.0f\n", atributosProds[indice][2]);
    printf("\t-(4) Salir.\n");
    printf("----------------------------\n");
    printf("Dato a Editar: ");

    // Validamos que elija una opción válida
    while(scanf("%d", &datoEditar) != 1 || datoEditar < 1 || datoEditar > 4){
        while(getchar() != '\n');
        printf("Opcion invalida. Ingrese un numero entre 1 y 4: ");
    }
    while(getchar() != '\n');
    return datoEditar;
}