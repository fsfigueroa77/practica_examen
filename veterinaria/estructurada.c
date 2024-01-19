#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void primer_menu(int *elecc);
void valores_adicionales(int *elecc);
void verificacion(int *eleccc, int *mm, int *nn);
void repetir_programa(int *elecc);

int main(){
    int elec = 0;
    while(elec == 0){
        primer_menu(&elec);
        valores_adicionales(&elec);
        elec = 0;
        repetir_programa(&elec);
        if(elec == 100){
            break;
        }
    }
    printf("\nGracias por usar el programa <3");
    return(0);
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
    printf("\n\t[1] Emergencia:\t\t40 USD\n\t[2] Control:\t\t25 USD\n\t[3] Vacunas:\t\t30 USD\nElija el tipo de consulta: ");
    verificacion(elecc, &m, &n);
}

void valores_adicionales(int *elecc){
    int elec2 = 0, m = 1, n = 2;
    float emer = 40, cont = 25, vacu = 30, adicional = 0;
    if(*elecc == 1){ //adicional para EMERGENCIA
        printf("\n\t[1] Si.\n\t[2] No.\nHay costos adicionales?: ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            srand(time(NULL));
            adicional = rand() % 81 + 20;  //Genero un numero aleatorio entre 20 y 100 para anhadir un valor adicional al azar dentro del menu de emergencia.
            printf("\nEl Valor a pagar por EMERGENCIA es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", emer, adicional, emer + adicional);
        }else{
            printf("\nEl Valor a pagar por EMERGENCIA es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", emer, adicional, emer + adicional);
        }
    }else if(*elecc == 2){ //adicional para CONTROL
        printf("\n\t[1] Si.\n\t[2] No.\nDesea agregar el corte y banho? (20 USD): ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            adicional = 20;
            printf("\nEl Valor a pagar por CONTROL es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", cont, adicional, cont + adicional);
        }else{
            printf("\nEl Valor a pagar por CONTROL es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", cont, adicional, cont + adicional);
        }
    }else{ //adicional para VACUNAS
        printf("\n\t[1] Si.\n\t[2] No.\nDesea obtener el certificado? (5 USD): ");
        verificacion(&elec2, &m, &n);
        if(elec2 == 1){
            adicional = 5;
            printf("\nEl Valor a pagar por VACUNAS es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", vacu, adicional, vacu + adicional);
        }else{
            printf("\nEl Valor a pagar por CONTROL es de %.2f USD. Con costo adicional de %.2f USD. Valor total: %.2f USD", vacu, adicional, vacu + adicional);
        }
    }
}

void verificacion(int *eleccc, int *mm, int *nn){
    while(*eleccc < *mm || *eleccc > *nn){
        scanf("%d", eleccc);
        if(*eleccc < *mm || *eleccc > *nn){
            printf("Eleccion incorrecta! Elije nuevamente: ");
        }
    }
}
