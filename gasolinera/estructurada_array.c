#include <stdio.h>

int main(){
  int n = 0, m = 5;
  float super_gal_acum = 0, eco_gal_acum = 0, diesel_gal_acum = 0, super_usd_acum = 0, eco_usd_acum = 0, diesel_usd_acum = 0;
  printf("Cuantas compras desea hacer?: ");
  scanf("%d", &n);
  llenar_matriz(&n, &m, &super_gal_acum, &eco_gal_acum, &diesel_gal_acum, &super_usd_acum, &eco_usd_acum, &diesel_usd_acum);

  return(0);
}

void llenar_matriz(int *nn, int *mm, float *super_gal_acumulador, float *eco_gal_acumulador, float *diesel_gal_acumulador, float *super_usd_acumulador, float *eco_usd_acumulador, float *diesel_usd_acumulador){
  int i;
  float matriz[*nn][*mm];
  for(i = 0; i < *nn; i++){
    matriz[i][0] = pedir_combustible();
    matriz[i][1] = escribir_precio(&matriz[i][0]);
    matriz[i][2] = pedir_cantidad(&matriz[i][0]);
    matriz[i][3] = subtotal(&matriz[i][1], &matriz[i][2]);
    matriz[i][3] = total(&matriz[i][0], &matriz[i][2], &matriz[i][3]);
  }
}

float pedir_combustible(){
  float elec = 0;
  printf("Elija el tipo de combustible. [1] SUPER [2] ECO [3] DIESEL: ");
  scanf("%d", &elec);
  return(elec);
}

float escribir_precio(float *tipo_combustible){
  float super = 4.2, eco = 1.85, diesel = 2.4;
  if(*tipo_combustible == 1){
    return(super);
  }else if(*tipo_combustible == 2){
    return(eco);
  }else{
    return(diesel);
  }
}

float pedir_cantidad(float *tipo_combustible){
  float cantidad = 0;
  if(*tipo_combustible == 1){
    printf("Cuantos galones de SUPER va a comprar: ");
  }else if(*tipo_combustible == 2){
    printf("Cuantos galones de ECO va a comprar: ");
  }else{
    printf("Cuantos galones de DIESEL va a comprar: ");
  }
  scanf("%f", &cantidad);
  return(cantidad);
}

float subtotal(float *precio, float *cantidad){
  float operacion = *precio * *cantidad;
  return(operacion);
}

float total(float *tipo_combustible, float *cantidad, float *subtotal){
  float total = 0, super_desc = .9, eco_desc = .95, diesel = .93;
  if(*tipo_combustible == 1){
    if(*cantidad > 50){
      
    }
  }else if(*tipo_combustible == 2){
    return(eco);
  }else{
    return(diesel);
  }
}
