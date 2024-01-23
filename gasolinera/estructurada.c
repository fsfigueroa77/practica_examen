#include <stdio.h>
void pedir_tipo_gasolina(int *tipo);
void pedir_cant_gasolina(int *tipo, float *super_cant, float *eco_cant, float *diesel_cant, float *super_usd, float *eco_usd, float *diesel_usd);
void operaciones(float *combustible, float *cantidad, float *descuento, float *acumulador_usd);
void verificacion(int *elecc, int *mini, int *maxi);
void repetir_programa(int *opc);
void mostrar_galones(float *super, float *eco, float *diesel);
void mostrar_usd(float *super, float *eco, float *diesel);

int main(){
    int opcion = 0, min = 1, max = 2;
    float acum_cant_super = 0, acum_cant_eco = 0, acum_cant_diesel = 0;
    float acum_usd_super = 0, acum_usd_eco = 0, acum_usd_diesel = 0;
    while (opcion == 0){
        int tipo_gasolina = 0;
        pedir_tipo_gasolina(&tipo_gasolina);
        pedir_cant_gasolina(&tipo_gasolina, &acum_cant_super, &acum_cant_eco, &acum_cant_diesel, &acum_usd_super, &acum_usd_eco, &acum_usd_diesel);
        printf("Desea ingresar mas ventas? [1] Si [2] No: ");
        verificacion(&opcion, &min, &max);
        repetir_programa(&opcion);
    }
    mostrar_galones(&acum_cant_super, &acum_cant_eco, &acum_cant_diesel);
    mostrar_usd(&acum_usd_super, &acum_usd_eco, &acum_usd_diesel);
    return(0);
}

void mostrar_galones(float *super, float *eco, float *diesel){
    printf("\nHay %.2f galones de SUPER.\nHay %.2f galones de ECO.\nHay %.2f galones de DIESEL.", *super, *eco, *diesel);
}

void mostrar_usd(float *super, float *eco, float *diesel){
    printf("\nHay %.2f USD de SUPER.\nHay %.2f USD de ECO.\nHay %.2f USD de DIESEL.", *super, *eco, *diesel);
}

void pedir_tipo_gasolina(int *tipo){
    int min = 1, max = 3;
    printf("Elija el tipo de gasolina. [1] Super, [2] Eco, [3] Diesel: ");
    verificacion(tipo, &min, &max);
}

void pedir_cant_gasolina(int *tipo, float *super_cant, float *eco_cant, float *diesel_cant, float *super_usd, float *eco_usd, float *diesel_usd){
    float super_precio = 4.2, eco_precio = 1.85, diesel_precio = 2.4, super_gal = 0, eco_gal = 0, diesel_gal = 0, super_desc = .9, eco_desc = .95, diesel_desc = .93, no_descuento = 1.0;
    if(*tipo == 1){
        printf("Cuantos galones de SUPER se compro: ");
        scanf("%f", &super_gal);
        if(super_gal > 50){
            operaciones(&super_precio, &super_gal, &super_desc, super_usd);
        }else{
            operaciones(&super_precio, &super_gal, &no_descuento, super_usd);
        }
        *super_cant = super_gal;
    }else if(*tipo == 2){
        printf("Cuantos galones de ECO se compro: ");
        scanf("%f", &eco_gal);
        if(eco_gal > 25){
            operaciones(&eco_precio, &eco_gal, &eco_desc, eco_usd);
        }else{
            operaciones(&eco_precio, &eco_gal, &no_descuento, eco_usd);
        }
        *eco_cant = eco_gal;
    }else{
        printf("Cuantos galones de DIESEL se compro: ");
        scanf("%f", &diesel_gal);
        if(diesel_gal > 35){
            operaciones(&diesel_precio, &diesel_gal, &diesel_desc, diesel_usd);
        }else{
            operaciones(&diesel_precio, &diesel_gal, &no_descuento, diesel_usd);
        }
        *diesel_cant = diesel_gal;
    }
}

void operaciones(float *combustible, float *cantidad, float *descuento, float *acumulador_usd){
    *acumulador_usd = *combustible * *cantidad * *descuento;
}

void verificacion(int *elecc, int *mini, int *maxi){
    while(*elecc < *mini || *elecc > *maxi){
        scanf("%d", elecc);
        if(*elecc < *mini || *elecc > *maxi){
            printf("Opcion no valida. Vuelva a elegir: ");
        }
    }
}

void repetir_programa(int *opc){
    if(*opc == 1){
        *opc = 0;
    }
}
