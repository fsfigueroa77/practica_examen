#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void verificacion(int *eleccc, int *mm, int *nn);
void repetir_programa(int *elecc);
void primer_menu(int *elecc);
void segundo_menu(int *eleccc, float *costo);
void mostrar_resultados1(float *cost, float *adi);
void mostrar_resultados2(float *cost, float *adi);
void mostrar_resultados3(float *cost, float *adi);

int main(){
    int elec = 0;
    while(elec == 0){
        primer_menu(&elec);        
        elec = 0;
        repetir_programa(&elec);
        if(elec == 100){
            break;
        }
    }
    printf("\nGracias por usar el programa <3");
    return(0);
}

void verificacion(int *eleccc, int *mm, int *nn){
    while(*eleccc < *mm || *eleccc > *nn){
        scanf("%d", eleccc);
        if(*eleccc < *mm || *eleccc > *nn){
            printf("Eleccion incorrecta! Elije nuevamente: ");
        }
    }
}

void repetir_programa(int *elecc){
    int m = 1, n = 2;
    printf("\n\t[1] Si.\n\t[2] No.\nDesea seguir con otra consulta?: ");
    verificacion(elecc, &m, &n);
    if(*elecc == 1){
        *elecc = 0;
    }else{
        *elecc = 100;
    }
}

void primer_menu(int *elecc){
    int m = 1, n = 3;
    float emer = 40, cont = 25, vacu = 30, adicional = 0;
    printf("\n\t[1] Emergencia:\t\t40 USD\n\t[2] Control:\t\t25 USD\n\t[3] Vacunas:\t\t30 USD\nElija el tipo de consulta: ");
    verificacion(elecc, &m, &n);
    switch(*elecc){
        case 1:
            segundo_menu(elecc, &emer);
            break;
        case 2:
            segundo_menu(elecc, &cont);
            break;
        case 3:
            segundo_menu(elecc, &vacu);
            break;
    }
}

void segundo_menu(int *eleccc, float *costo){
    int elec2 = 0, m = 1, n = 2;
    srand(time(NULL));
    float emer_adi = rand() % 81 + 20, cont_adi = 20, vacu_adi = 5, sin_adional = 0;
    if(*eleccc == 1){
        printf("\n\t[1] Si.\n\t[2] No.\nHay costos adicionales?: ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            mostrar_resultados1(costo, &emer_adi);
        }else{
            mostrar_resultados1(costo, &sin_adional);
        }
    }else if(*eleccc == 2){
        printf("\n\t[1] Si.\n\t[2] No.\nDesea agregar el corte y banho? (20 USD): ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            mostrar_resultados2(costo, &cont_adi);
        }else{
            mostrar_resultados2(costo, &sin_adional);
        }
    }else{
        printf("\n\t[1] Si.\n\t[2] No.\nDesea obtener el certificado? (5 USD): ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            mostrar_resultados3(costo, &vacu_adi);
        }else{
            mostrar_resultados3(costo, &sin_adional);
        }
    }
}

void mostrar_resultados1(float *cost, float *adi){
    printf("\nEl Valor a pagar por EMERGENCIA es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", *cost, *adi, *cost + *adi);
}

void mostrar_resultados2(float *cost, float *adi){
    printf("\nEl Valor a pagar por CONTROL es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", *cost, *adi, *cost + *adi);
}

void mostrar_resultados3(float *cost, float *adi){
    printf("\nEl Valor a pagar por VACUNAS es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", *cost, *adi, *cost + *adi);
}
