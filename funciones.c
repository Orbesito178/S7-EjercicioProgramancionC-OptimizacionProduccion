#include "funciones.h"

void solicitarProductos (char nombresProductos[5][50]){
    int i;
    for(i=0; i<PRODS; i++){
        printf("Ingrese el nombre del producto %d: ", i+1);
        fgets(nombresProductos[i], 50, stdin);
        nombresProductos[i][strcspn(nombresProductos[i], "\n")] = '\0';
    }
    for(i=0; i<PRODS; i++){
        printf("%s\t", nombresProductos[i]);
    }
}