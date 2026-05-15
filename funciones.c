#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
    printf("4. Mostrar datos actuales.\n");
    printf("5. Salir.\n");
    printf("Escoja: ");
    scanf("%d", opcionMenu);
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


void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods ){
    float tiempoFabTotal= calcularTiempoTotal(atributosProds, ptrprods);
    float recursosFabTotal=calcularRecursosTotal(atributosProds, ptrprods);
    printf("\n======= RESULTADOS ========\n");

    printf(">>>>> Tiempo Total de Fabricacion: %.2f\n", tiempoFabTotal);
    printf(">>>>> Recursos Totales de Fabricacion: %.2f\n", recursosFabTotal);
    if(tiempoFabTotal <= *ptrtiempoFabrica && recursosFabTotal<=*ptrrecursosFabrica){
        printf("\t----- SU PEDIDO SE PUEDE REALIZAR CORRECTAMENTE ------\n");
        printf("\t-Tiempo sobrante (de 500 h): %.2f\n", *ptrtiempoFabrica-tiempoFabTotal);
        printf("\t-Recursos Sobrantes (de 300 recursos): %.2f\n", *ptrrecursosFabrica-recursosFabTotal);
    }else{
        printf("\tSU PEDIDO NO SE PUEDE REALIZAR.\n");
        if(tiempoFabTotal>*ptrtiempoFabrica){
            printf("\t-Tiempo faltante (de 500 h): %.2f\n", tiempoFabTotal-*ptrtiempoFabrica);
        }else if(recursosFabTotal>*ptrrecursosFabrica){
            printf("\t-Recursos faltantes (de 300 recursos): %.2f\n", recursosFabTotal-*ptrrecursosFabrica);
        }
        
        
    }
    

}


int busquedaNombre(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    char buscado[50]={0};
    bool encontrado=false;
    int indice=0;
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
    scanf("%d", &datoEditar);
    return datoEditar;

}

void editarDatos(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    int indice=busquedaNombre(nombresProductos, atributosProds, ptrprods);
    int datoEditar=0;
    if(indice==-1){
        return;
    } else {
        do{
            datoEditar=mostrarDatos(nombresProductos, atributosProds, indice);
            if(datoEditar==4){
                return;
            }else{
                printf("Ingrese el nuevo dato: ");
                scanf("%f", &atributosProds[indice][datoEditar-1]);
            }
            
        }while(datoEditar!=4);
        
        
        
    }
    

}




void eliminarProducto(char nombresProductos[][50], float atributosProds[][3],int *ptrprods){
    int indice=busquedaNombre(nombresProductos, atributosProds, ptrprods);
    for(int i=indice; i<*ptrprods-1; i++){
        strcpy(nombresProductos[i], nombresProductos[i+1]);
        for(int j=0; j<ATRIB; j++){
            atributosProds[i][j]=atributosProds[i+1][j];
        }
        
    }
    (*ptrprods)--;
}






void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods){
    do{
        mostrarMenu(opcionMenu);
        switch(*opcionMenu){
            case 1:
                mostrarResultados(nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);
                break;
            case 2:
                editarDatos(nombresProductos, atributosProds, ptrprods);
                break;
            case 3:
                eliminarProducto(nombresProductos, atributosProds, ptrprods);
                break;
            case 4:
                mostrarDatosActuales(nombresProductos, atributosProds, ptrprods);
                break;
            case 5:
                printf("GRACIAS POR USAR ORB-INDUSTRIES\n");
                break;
        }
    }while(*opcionMenu!=5);
    
    
}