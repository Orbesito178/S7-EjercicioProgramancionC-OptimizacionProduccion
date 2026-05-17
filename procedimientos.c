#include "procedimientos.h"
#include "funciones.h"

// Le muestra al usuario la lista de productos y le deja escoger uno para modificarlo
// Si elige la opción 6, sale del menú
void escogerProducto(char nombresProductos[][50], int *opcionProducto, float atributosProds[][3], int *ptrprods){
    do{
        printf("========= ESCOJA UN PRODUCTO ======\n");
        for(int i = 0; i < *ptrprods; i++){
            printf("%d. %s.\n", i+1, nombresProductos[i]);
        }
        printf("6. Salir.\n");
        printf("Escoja: ");

        // Si el usuario no ingresa un número válido, se lo pedimos de nuevo
        while(scanf("%d", opcionProducto) != 1 || *opcionProducto < 1 || *opcionProducto > 6){
            while(getchar() != '\n');
            printf("Opcion invalida. Ingrese un numero entre 1 y 6: ");
        }
        while(getchar() != '\n');

        // Si no eligió salir, pasamos a modificar el producto seleccionado
        if(*opcionProducto != 6){
            modificarProductos(nombresProductos, atributosProds, opcionProducto);
        } else {
            break;
        }

    } while(*opcionProducto != 6);
}

// Pide al usuario los datos de todos los productos al inicio del programa
// (tiempo de fabricación, recursos por unidad y cantidad demandada)
void registrarProductos(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods){
    printf("\n========== REGISTRO DE PRODUCTOS ==========\n");
    printf("Tiempo Disponible de Fabrica: 500 horas.\n");
    printf("Recursos Disponibles de Fabrica: 300 recursos.\n");
    printf("----------------------------------------------\n");

    for(int i = 0; i < *ptrprods; i++){
        printf("\n>>>> %s: \n", nombresProductos[i]);

        printf("Tiempo de Fabricacion: ");
        while(scanf("%f", &atributosProds[i][0]) != 1 || atributosProds[i][0] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');

        printf("Recursos por Unidad: ");
        while(scanf("%f", &atributosProds[i][1]) != 1 || atributosProds[i][1] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');

        printf("Cantidad Demandada: ");
        while(scanf("%f", &atributosProds[i][2]) != 1 || atributosProds[i][2] <= 0){
            while(getchar() != '\n');
            printf("Valor invalido. Ingrese un numero mayor a 0: ");
        }
        while(getchar() != '\n');
    }
}

// Permite cambiar los datos de un producto específico que ya fue registrado
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

// Imprime en pantalla todos los productos con sus datos actuales
void mostrarDatosActuales(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    printf("\n========== DATOS ACTUALES ==========\n");
    for(int i = 0; i < *ptrprods; i++){
        printf(">>>>> %s:\n", nombresProductos[i]);
        printf("\t-Tiempo: %.2f\n", atributosProds[i][0]);
        printf("\t-Recursos: %.2f\n", atributosProds[i][1]);
        printf("\t-Cantidad Demandada: %.0f\n", atributosProds[i][2]);
        printf("--------------------------------------\n");
    }
}

// Calcula el tiempo y recursos totales necesarios y los compara con los límites de la fábrica
// Muestra si el pedido se puede cumplir o no, y cuánto sobra o falta
void mostrarResultados(char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods){
    float tiempoFabTotal = calcularTiempoTotal(atributosProds, ptrprods); //se arigna el tiempo a una variable
    float recursosFabTotal = calcularRecursosTotal(atributosProds, ptrprods); //se asigna los recursos a una variable


    printf("\n========== RESULTADOS ===========\n");
    printf(">>> Tiempo Total de Fabricacion: %.2f horas\n", tiempoFabTotal);
    printf(">>> Recursos Totales de Fabricacion: %.2f unidades\n", recursosFabTotal);

    if(tiempoFabTotal <= *ptrtiempoFabrica && recursosFabTotal <= *ptrrecursosFabrica){
        // El pedido entra dentro de los límites, todo bien
        printf("----- SU PEDIDO SE PUEDE REALIZAR CORRECTAMENTE ------\n");
        printf("\t> Tiempo sobrante: %.2f/500 <\n", *ptrtiempoFabrica - tiempoFabTotal);
        printf("\t> Recursos Sobrantes: %.2f/300 <\n", *ptrrecursosFabrica - recursosFabTotal);
    } else {
        // El pedido supera alguno o ambos límites, indicamos qué falta
        printf("----------- SU PEDIDO NO SE PUEDE REALIZAR.-----------\n");
        if(tiempoFabTotal > *ptrtiempoFabrica && recursosFabTotal > *ptrrecursosFabrica){
            // Se pasan tanto en tiempo como en recursos
            printf("\t> Tiempo faltante: %.2f horas <\n", tiempoFabTotal - *ptrtiempoFabrica);
            printf("\t> Recursos faltantes: %.2f unidades <\n", recursosFabTotal - *ptrrecursosFabrica);
        } else if(recursosFabTotal > *ptrrecursosFabrica){
            // Solo los recursos se pasan del límite
            printf("\t> Recursos faltantes: %.2f unidades <\n", recursosFabTotal - *ptrrecursosFabrica);
        } else if(tiempoFabTotal > *ptrtiempoFabrica){
            // Solo el tiempo se pasa del límite
            printf("\t> Tiempo faltante: %.2f horas <\n", tiempoFabTotal - *ptrtiempoFabrica);
        }
    }
}

// Busca un producto por nombre y permite editar uno de sus datos
// Si no se encuentra o se cancela, simplemente regresa sin hacer nada
void editarDatos(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    int indice = busquedaNombre(nombresProductos, atributosProds, ptrprods);
    int datoEditar = 0;

    if(indice == -1){
        return; // No se encontró el producto o el usuario canceló
    } else {
        do{
            datoEditar = mostrarDatos(nombresProductos, atributosProds, indice);

            if(datoEditar == 5){
                return; // El usuario decidió salir sin editar más
            } else {
                if(datoEditar==1){
                    printf("Ingrese el nuevo nombre: ");
                    fgets(nombresProductos[indice], 20, stdin);
                    nombresProductos[indice][strcspn(nombresProductos[indice], "\n")] = '\0';
                } else{
                    // Pedimos el nuevo valor y lo guardamos en la posición correspondiente
                    printf("Ingrese el nuevo dato: ");
                    while(scanf("%f", &atributosProds[indice][datoEditar-2]) != 1 || atributosProds[indice][datoEditar-2] <= 0){
                        while(getchar() != '\n');
                        printf("  [!] Valor invalido. Ingrese un numero mayor a 0: ");
                    }
                    while(getchar() != '\n');
                }
                
            }

        } while(datoEditar != 5);
    }
}

// Busca un producto por nombre y lo elimina de la lista
// Para borrarlo, corre todos los productos que están después una posición hacia atrás
void eliminarProducto(char nombresProductos[][50], float atributosProds[][3], int *ptrprods){
    int indice = busquedaNombre(nombresProductos, atributosProds, ptrprods);

    // Desplazamos los productos siguientes para llenar el hueco que deja el eliminado
    for(int i = indice; i < *ptrprods - 1; i++){
        strcpy(nombresProductos[i], nombresProductos[i+1]);
        for(int j = 0; j < ATRIB; j++){
            atributosProds[i][j] = atributosProds[i+1][j];
        }
    }

    (*ptrprods)--; // Reducimos el contador de productos
}

// Controla el flujo principal del programa mostrando el menú y ejecutando la acción elegida
// Se repite hasta que el usuario elija salir (opción 5)
void acciones(int *opcionMenu, char nombresProductos[][50], float atributosProds[][3], float *ptrtiempoFabrica, float *ptrrecursosFabrica, int *ptrprods){
    do{
        mostrarMenu(opcionMenu);
        switch(*opcionMenu){
            case 1: //Muestra los resultados (tiempo, recursos y la disponibilidad de la fábrica a poder cumplir el pedido)
                mostrarResultados(nombresProductos, atributosProds, ptrtiempoFabrica, ptrrecursosFabrica, ptrprods);
                break;
            case 2: //Editar los datos por búsqueda de nombre y elección de atributo.
                editarDatos(nombresProductos, atributosProds, ptrprods);
                break;
            case 3: //Eliminar un producto de la "base de datos"
                eliminarProducto(nombresProductos, atributosProds, ptrprods);
                break;
            case 4: //Muestra los datos actualizados de todos los productos hasta el momento (sin los borrados)
                mostrarDatosActuales(nombresProductos, atributosProds, ptrprods);
                break;
            case 5: //Despedida
                printf("\n--- GRACIAS POR USAR ORB-INDUSTRIES ----\n");
                break;
        }
    } while(*opcionMenu != 5);
}