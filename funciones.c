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

                                            


float calcularTiempoTotal(float atributosProds[][3]){
    float tiempoFabTotal[5]={0};
    for(int i=0; i<PRODS; i++){
        tiempoFabTotal[i] += atributosProds[i][0];
    }
}


void mostrarResultados(char nombresProductos[][50], float atributosProds[][3] ){
    
    printf("\n==== RESULTADOS ====\n");

    printf("\nsix seven\n");
    

}


void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3]){
    switch(*opcionMenu){
        case 1:
            mostrarResultados(nombresProductos, atributosProds);
            break;

    }
}