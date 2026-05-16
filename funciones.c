#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "procedimientos.h"

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
    printf("4. Mostrar datos actuales.\n");
    printf("5. Salir.\n");
    printf("Escoja: ");
    while(scanf("%d", opcionMenu) != 1 || *opcionMenu < 1 || *opcionMenu > 5){
        while(getchar() != '\n');
        printf("Opcion invalida. Ingrese un numero entre 1 y 5: ");
    }
    while(getchar() != '\n');
    return *opcionMenu;
}


float calcularTiempoTotal(float atributosProds[][3], int *ptrprods){
    float tiempoFabTotal=0;
    for(int i=0; i<*ptrprods; i++){
        tiempoFabTotal += atributosProds[i][0]*atributosProds[i][2];
        
    }
    return tiempoFabTotal;
}

float calcularRecursosTotal(float atributosProds[][3], int *ptrprods){
    float recursosFabTotal=0;
    for(int i=0; i<*ptrprods; i++){
        recursosFabTotal += atributosProds[i][1]*atributosProds[i][2];
    }
    return recursosFabTotal;
}


int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    char buscado[50]={0};
    bool encontrado=false;
    int indice=-1;
    while(getchar()!='\n');
    do{
        printf("\n======= BUSQUEDA POR NOMBRE ========\n");
        printf("Producto a buscar (0 para cancelar): ");
        
        fgets(buscado, 50, stdin);
        buscado[strcspn(buscado, "\n")]='\0';
        
        if(strcmp(buscado, "0")==0){
            encontrado=true;
            return -1;
        }else{
            for(int i=0; i<*ptrprods; i++){
                if(strcmp(nombresProductos[i], buscado)==0){
                    encontrado=true;
                    indice=i;
                    break;
                }else{
                    encontrado=false;
                }
            }
            if(encontrado==true){
                printf("----- PRODUCTO ENCONTRADO ----\n");
                return indice;
            }else{
                printf("------ PRODUCTO NO ENCONTRADO -----\n");
                
            }
        }
        
    }while(encontrado!=true);

    return -1;
}




int mostrarDatos(char nombresProductos[][50], float atributosProds[][3], int indice){
    int datoEditar=0;
    printf(">>>> %s\n", nombresProductos[indice]);
    printf("\t-(1) Tiempo: %.2f\n", atributosProds[indice][0]);
    printf("\t-(2) Recursos: %.2f\n", atributosProds[indice][1]);
    printf("\t-(3) Cantidad Demandada: %.0f\n", atributosProds[indice][2]);
    printf("\t-(4) Salir.\n");
    printf("----------------------------\n");
    printf("Dato a Editar: ");
    while(scanf("%d", &datoEditar) != 1 || datoEditar < 1 || datoEditar > 4){
        while(getchar() != '\n');
        printf("Opcion invalida. Ingrese un numero entre 1 y 4: ");
    }
    while(getchar() != '\n');
    return datoEditar;

}
