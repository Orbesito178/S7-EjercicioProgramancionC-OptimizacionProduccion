#include <stdio.h>
#include "funciones.h"

/*void solicitarProductos (char nombresProductos[5][50]){
    int i;
    for(i=0; i<PRODS; i++){
        printf("Ingrese el nombre del producto %d: ", i+1);
        fgets(nombresProductos[i], 50, stdin);
        nombresProductos[i][strcspn(nombresProductos[i], "\n")] = '\0';
    }
    for(i=0; i<PRODS; i++){
        printf("%s\t", nombresProductos[i]);
    }
}*/



                                                
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
    printf("\n========== REGISTRO DE PRODUCTOS ==========\n");
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

float calcularTiempoTotal(float atributosProds[][3]){
    float tiempoFabTotal[5]={0};
    for(int i=0; i<PRODS; i++){
        tiempoFabTotal[i] += atributosProds[i][0];
    }
}




//676y6y6



void mostrarResultados(char nombresProductos[][50], float atributosProds[][3] ){
    
    printf("\n==== RESULTADOS ====\n");

    printf("\nsix seven\n");
    

}


int mostrarMenu(int *opcionMenu){
    printf("\n========== ACCIONES ========\n");
    printf("1. Mostrar Resultados.\n");
    printf("2. Editar informacion.\n");
    printf("3. Borrar producto.\n");
    printf("4. Salir.\n");
    printf("Escoja: ");
    scanf("%d", opcionMenu);
    return *opcionMenu;
}

void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3]){
    switch(*opcionMenu){
        case 1:
            mostrarResultados(nombresProductos, atributosProds);
            break;

    }
}