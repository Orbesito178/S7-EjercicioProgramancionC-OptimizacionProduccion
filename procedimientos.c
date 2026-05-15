#include "procedimientos.h"

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods){
    do{
        printf("========= ESCOJA UN PRODUCTO ======\n");
        for(int i=0; i<*ptrprods; i++){
            printf("%d. %s.\n", i+1, nombresProductos[i]);
        }
        printf("6. Salir.\n");
        printf("Escoja: ");
        scanf("%d", opcionProducto);
        if(*opcionProducto!=6){
            modificarProductos(nombresProductos, atributosProds, opcionProducto);
        }else{
            break;
        }
        
    }while(*opcionProducto!=6);
    
    
}

void registrarProductos(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods){
    printf("\n========== REGISTRO DE PRODUCTOS ==========\n");
    printf("Tiempo Disponible de Fabrica: 500 horas.\n");
    printf("Recursos Disponibles de Fabrica: 300 recursos.\n");
    printf("----------------------------------------------\n");

    for(int i=0; i<*ptrprods; i++){
        printf("\n>>>> %s: \n", nombresProductos[i]);
            
        printf("Tiempo de Fabricacion: ");
        scanf("%f", &atributosProds[i][0]);
       // *ptrtiempoFabrica -= atributosProds[i][0];
                        
        printf("Recursos por Unidad: ");
        scanf("%f", &atributosProds[i][1]);
       // *ptrrecursosFabrica -= atributosProds[i][1];

        printf("Cantidad Demandada: ");
        scanf("%f", &atributosProds[i][2]);
    }
}

void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto){
    printf("====== REGISTRO DE PRODUCTOS =====\n");
    printf("\n>>>> %s: \n", nombresProductos[*opcionProducto-1]);
        
    printf("Tiempo de Fabricacion: ");
    scanf("%f", &atributosProds[*opcionProducto-1][0]);
                     
    printf("Recursos por Unidad: ");
    scanf("%f", &atributosProds[*opcionProducto-1][1]);

    printf("Cantidad Demandada: ");
    scanf("%f", &atributosProds[*opcionProducto-1][1]);
        
}

void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    printf("\n========== DATOS ACTUALES ==========\n");
    for(int i=0; i<*ptrprods; i++){
        printf(">>>>> %s:\n", nombresProductos[i]);
        printf("\t-Tiempo: %.2f\n", atributosProds[i][0]);
        printf("\t-Recursos: %.2f\n", atributosProds[i][1]);
        printf("\t-Cantidad Demandada: %.0f\n", atributosProds[i][2]);
        printf("--------------------------------------\n");
    }
}