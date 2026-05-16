#include "procedimientos.h"
#include "funciones.h"

void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods){
    do{
        printf("========= ESCOJA UN PRODUCTO ======\n");
        for(int i=0; i<*ptrprods; i++){
            printf("%d. %s.\n", i+1, nombresProductos[i]);
        }
        printf("6. Salir.\n");
        printf("Escoja: ");

        while(scanf("%d", opcionProducto) != 1 || *opcionProducto < 1 || *opcionProducto > 6){
            while(getchar() != '\n');
            printf("Opcion invalida. Ingrese un numero entre 1 y 6: ");
        }
        while(getchar() != '\n');

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
        while(scanf("%f", &atributosProds[i][0]) != 1 || atributosProds[i][0] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');

       // *ptrtiempoFabrica -= atributosProds[i][0];
                        
        printf("Recursos por Unidad: ");
        while(scanf("%f", &atributosProds[i][1]) != 1 || atributosProds[i][1] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');

       // *ptrrecursosFabrica -= atributosProds[i][1];

        printf("Cantidad Demandada: ");
        while(scanf("%f", &atributosProds[i][2]) != 1 || atributosProds[i][2] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');
    }
}

void modificarProductos(char nombresProductos[][50], float atributosProds[][3], int *opcionProducto){
    printf("====== REGISTRO DE PRODUCTOS =====\n");
    printf("\n>>>> %s: \n", nombresProductos[*opcionProducto-1]);
        
    printf("Tiempo de Fabricacion: ");
    while(scanf("%f", &atributosProds[*opcionProducto-1][0]) != 1 || atributosProds[*opcionProducto-1][0] <= 0){
        while(getchar() != '\n');
        printf("Valor invalido. Ingrese un numero mayor a 0: ");
    }
    while(getchar() != '\n');
                     
    printf("Recursos por Unidad: ");
    while(scanf("%f", &atributosProds[*opcionProducto-1][1]) != 1 || atributosProds[*opcionProducto-1][1] <= 0){
        while(getchar() != '\n');
        printf("Valor invalido. Ingrese un numero mayor a 0: ");
    }
    while(getchar() != '\n');

    printf("Cantidad Demandada: ");
    while(scanf("%f", &atributosProds[*opcionProducto-1][2]) != 1 || atributosProds[*opcionProducto-1][2] <= 0){
        while(getchar() != '\n');
        printf("Valor invalido. Ingrese un numero mayor a 0: ");
    }
    while(getchar() != '\n');
        
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
                while(scanf("%f", &atributosProds[indice][datoEditar-1]) != 1 || atributosProds[indice][datoEditar-1] <= 0){
                    while(getchar() != '\n');
                    printf("  [!] Valor invalido. Ingrese un numero mayor a 0: ");
                }
                while(getchar() != '\n');
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
