#include <stdio.h>
#include <string.h>

void pedir_placa(char *placa_vehiculo);
void pedir_tipo(char *tipo);
void pedir_galones(float *cantidad);
float venta(float *galones, char *tipogas, char *placa);

int main(){
    char placa[10];
    char tipo_gas[20];
    float galones = 0;
    pedir_placa(placa);
    pedir_tipo(tipo_gas);
    pedir_galones(&galones);
    venta(&galones, tipo_gas, placa);
    return(0);
}

void pedir_placa(char *placa_vehiculo){
    printf("Cual es la placa del vehiculo: ");
    scanf("%s", placa_vehiculo);
}

void pedir_tipo(char *tipo){
    printf("Escriba el tipo de combustible de estas opciones.- super, eco, diesel: ");
    scanf("%s", tipo);
}

void pedir_galones(float *cantidad){
    printf("Cuantos galones va a comprar: ");
    scanf("%f", cantidad);
}

float venta(float *galones, char *tipogas, char *placa){
    char super[20] = "super", eco[20] = "eco", diesel[20] = "diesel";
    if(strcmp(tipogas, super) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total: %.2f USD.", placa, *galones, tipogas, *galones * 4.2);
    }else if(strcmp(tipogas, eco) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total: %.2f USD.", placa, *galones, tipogas, *galones * 2.5);
    }else if(strcmp(tipogas, diesel) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total: %.2f USD.", placa, *galones, tipogas, *galones * 1.8);
    }
    return(0);   
}

//tiempo = 42 mins