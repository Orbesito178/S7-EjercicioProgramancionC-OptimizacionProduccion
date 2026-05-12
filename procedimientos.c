#include "procedimientos.h"

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3]){
    do{
        printf("========= ESCOJA UN PRODUCTO ======\n");
        for(int i=0; i<PRODS; i++){
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

void registrarProductos(char nombresProductos[][50], float atributosProds[][3]){
    printf("\n========== REGISTRO DE PRODUCTOS ==========");
    for(int i=0; i<PRODS; i++){
        printf("\n>>>> %s: \n", nombresProductos[i]);
            
        printf("Tiempo de Fabricacion: ");
        scanf("%f", &atributosProds[i][0]);
                        
        printf("Recursos por Unidad: ");
        scanf("%f", &atributosProds[i][1]);

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