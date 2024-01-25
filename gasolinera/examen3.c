#include <stdio.h>
#include <string.h>
void pedir_texto(char *texto);
void comparar_texto(char *texto);

int main(){
    char texto1[20];
    pedir_texto(texto1);
    comparar_texto(texto1);    
    return(0);
}

void pedir_texto(char *texto){
    printf("Escribe uno de tus nombres: ");
    scanf("%s", texto);
}

void comparar_texto(char *texto){
    char cadena1[] = "felipe", cadena2[] = "santiago";
    if(strcmp(texto, cadena1) == 0){
        printf("El nombre %s que ingresaste, coincide con el que tenemos en la base de datos: %s.", texto, cadena1);
    }else if(strcmp(texto, cadena2) == 0){
        printf("El nombre %s que ingresaste, coincide con el que tenemos en la base de datos: %s.", texto, cadena2);
    }else{
        printf("El nombre %s que ingresaste, no coincide con lo que tenemos en la base de datos.", texto);
    }
}
