#include <stdio.h>
void menu_gasolina(int *elecc, float *acum_s_usd, float *acum_e_usd, float *acum_d_usd, float *acum_s_cant, float *acum_e_cant, float *acum_d_cant);
void pedir_cantidad(int *eleccion, float *combustible_cant);
void operaciones(int *eleccion, float *combustible_usd, float *combustible_cant, float *combustible_desc, float *acum_combustible_usd);
void mostrar_resultados(float *super_usd, float *eco_usd, float *diesel_usd, float *super_cant, float *eco_cant, float *diesel_cant);

int main(){
    float super_usd_acum = 0, eco_usd_acum = 0, diesel_usd_acum = 0, super_cant_acum = 0, eco_cant_acum = 0, diesel_cant_acum = 0;
    int elec = 0;
    while(elec == 0){
        menu_gasolina(&elec, &super_usd_acum, &eco_usd_acum, &diesel_usd_acum, &super_cant_acum, &eco_cant_acum, &diesel_cant_acum);        
        printf("Desea seguir ingresando ventas. [1] Si [2] No: ");
        scanf("%d", &elec);
        if(elec == 1){
            elec = 0;
        }        
    }
    mostrar_resultados(&super_usd_acum, &eco_usd_acum, &diesel_usd_acum, &super_cant_acum, &eco_cant_acum, &diesel_cant_acum);
    return(0);
}

void menu_gasolina(int *elecc, float *acum_s_usd, float *acum_e_usd, float *acum_d_usd, float *acum_s_cant, float *acum_e_cant, float *acum_d_cant){
    float super_usd = 4.2, eco_usd = 1.85, diesel_usd = 2.4, super_cant = 0, eco_cant = 0, diesel_cant = 0, super_desc = .9, eco_desc = .95, diesel_desc = .93;
    printf("Tipo de gasolina [1] Super. [2] Eco. [3] Diesel: ");
    scanf("%d", elecc);
    switch(*elecc){
        case 1:
            pedir_cantidad(elecc, &super_cant);
            operaciones(elecc, &super_usd, &super_cant, &super_desc, acum_s_usd);
            *acum_s_cant = super_cant;
            break;
        case 2:
            pedir_cantidad(elecc, &eco_cant);
            operaciones(elecc, &eco_usd, &eco_cant, &eco_desc, acum_e_usd);
            *acum_e_cant = eco_cant;
            break;
        case 3:
            pedir_cantidad(elecc, &diesel_cant);
            operaciones(elecc, &diesel_usd, &diesel_cant, &diesel_desc, acum_d_usd);
            *acum_d_cant = diesel_cant;
            break;
    }
}

void pedir_cantidad(int *eleccion, float *combustible_cant){
    if(*eleccion == 1){
        printf("Cuantos galones de SUPER: ");
        scanf("%f", combustible_cant);
    }else if(*eleccion == 2){
        printf("Cuantos galones de ECO: ");
        scanf("%f", combustible_cant);
    }else if(*eleccion == 3){
        printf("Cuantos galones de DIESEL: ");
        scanf("%f", combustible_cant);
    }
}

void operaciones(int *eleccion, float *combustible_usd, float *combustible_cant, float *combustible_desc, float *acum_combustible_usd){
    if(*eleccion == 1){
        if(*combustible_cant > 50){
            *acum_combustible_usd = *combustible_usd * *combustible_cant * *combustible_desc;
        }else{
            *acum_combustible_usd = *combustible_usd * *combustible_cant;
        }
    }else if(*eleccion == 2){
        if(*combustible_cant > 25){
            *acum_combustible_usd = *combustible_usd * *combustible_cant * *combustible_desc;
        }else{
            *acum_combustible_usd = *combustible_usd * *combustible_cant;
        }
    }else if(*eleccion == 3){
        if(*combustible_cant > 35){
            *acum_combustible_usd = *combustible_usd * *combustible_cant * *combustible_desc;
        }else{
            *acum_combustible_usd = *combustible_usd * *combustible_cant;
        }
    }
}

void mostrar_resultados(float *super_usd, float *eco_usd, float *diesel_usd, float *super_cant, float *eco_cant, float *diesel_cant){
    printf("\nHay %.2f galones de SUPER.\nHay %.2f galones de ECO.\nHay %.2f galones de DIESEL.", *super_cant, *eco_cant, *diesel_cant);
    printf("\nHay %.2f USD de SUPER.\nHay %.2f USD de ECO.\nHay %.2f USD de DIESEL.", *super_usd, *eco_usd, *diesel_usd);
}

//tiempo: 42 min