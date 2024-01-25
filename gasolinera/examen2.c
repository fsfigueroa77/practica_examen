#include <stdio.h>
#include <string.h>
void pedir_placa(char *placa);
void tipo_combustible(char *tipogas);
void pedir_galones(float *galones);
float venta(float *galones, char *tipogas, char *placa);

int main(){
    char placa_vehiculo[20], tipo[20];
    float cantidad = 0;
    pedir_placa(placa_vehiculo);
    tipo_combustible(tipo);
    pedir_galones(&cantidad);
    venta(&cantidad, tipo, placa_vehiculo);

}

void pedir_placa(char *placa){
    printf("Ingrese la placa del vehiculo: ");
    scanf("%s", placa);
}

void tipo_combustible(char *tipogas){
    printf("Ingrese el tipo de combustible: ");
    scanf("%s", tipogas);
}

void pedir_galones(float *galones){
    printf("Cuantos galones va a comprar: ");
    scanf("%f", galones);
}

float venta(float *galones, char *tipogas, char *placa){
    char super[] = "super", eco[] = "eco", diesel[] = "diesel";
    if(strcmp(tipogas, super) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total = %.2f", placa, *galones, tipogas, *galones * 4.2);
    }else if(strcmp(tipogas, eco) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total = %.2f", placa, *galones, tipogas, *galones * 1.85);
    }else if(strcmp(tipogas, diesel) == 0){
        printf("El vehiculo de placa %s ha comprado %.2f galones de %s. Precio total = %.2f", placa, *galones, tipogas, *galones * 2.4);
    }
    return(0);
}
