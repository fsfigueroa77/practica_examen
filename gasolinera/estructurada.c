#include <stdio.h>

int main(){
    int elec = 0;
    while(elec = 0){
        primer_menu(&elec);
    }
    retun(0);
}

void primer_menu(int *elecc){
    int min = 1, max = 3;
    float cant_super = 0, cant_eco = 0, cant_diesel = 0, costo_super = 4.2, costo_eco = 1.85, costo_diesel = 2.4;
    printf("\n\t[1] Super (4.20 USD)\n\t[2] Eco (1.85 USD)\n\t[3] Diesel (2.40 USD)\nQue tipo de gasolina se esta comprando: ");
    verificacion(elecc, &min, &max);
    switch(*elecc){
        case 1:
            pedir_cantidad(&cant_super);
            break;
        case 2:
            pedir_cantidad(&cant_eco);
            break;
        case 3:
            pedir_cantidad(&cant_diesel);
            break;
    }
}

void verificacion(int *eleccc, int *mini, int *maxi){
    while(*eleccc < *mini || *eleccc > *maxi){
        scanf("%d", eleccc);
        if(*eleccc < *mini || *eleccc > *maxi){
            printf("\nOpcion incorrecta! Ingresa tu eleccion nuevamente: ");
        }
    }
}

void pedir_cantidad(float *cant_combustible){
    
}