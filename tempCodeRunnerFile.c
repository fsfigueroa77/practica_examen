#include <stdio.h>
void nota_primer_parcial(float *primera_nota);
void nota_segundo_parcial(float *segunda_nota);
void nota_academico(float *nota1);
void nota_practico(float *nota2);
void mensaje_error();
void calculo(float *primera_nota, float *segunda_nota, float *exam);
void mostrar_resultado(float *exam);

int main(){
    float primer_parcial = -1, segundo_parcial = 0, examen = 0;
    printf("\nPROGRAMA PARA CALCULAR LA NOTA DE EXAMEN NECESARIA PARA APROBAR PROGRAMASION xD\n");
    nota_primer_parcial(&primer_parcial);
    nota_segundo_parcial(&segundo_parcial);
    calculo(&primer_parcial, &segundo_parcial, &examen);
    if(examen > 10){
        printf("Reprobado papu xdxddd");
    }else if(examen < 10){
        printf("Aprobado sin dar examen... que GOD");
    }else{
        mostrar_resultado(&examen);
    }    

    return(0);
}

void nota_primer_parcial(float *primera_nota){
    while(*primera_nota < 0 || *primera_nota > 10){
        printf("Ingrese la nota del primer parcial: ");
        scanf("%f", primera_nota);
        if(*primera_nota < 0 || *primera_nota > 10){
            mensaje_error();
        }
    }    
}

void nota_segundo_parcial(float *segunda_nota){
    float academico = -1, practico = -1;
    nota_academico(&academico);
    nota_practico(&practico);
    *segunda_nota = academico + practico;
}

void nota_academico(float *nota1){
    while(*nota1 < 0 || *nota1 > 10){
        printf("Ingrese el promedio de la seccion ACADEMICO: ");
        scanf("%f", nota1);
        if(*nota1 < 0 || *nota1 > 10){
            mensaje_error();
        }
    }
}

void nota_practico(float *nota2){
    while(*nota2 < 0 || *nota2 > 10){
        printf("Ingrese el promedio de la seccion PRACTICO: ");
        scanf("%f", nota2);
        if(*nota2 < 0 || *nota2 > 10){
            mensaje_error();
        }
    }
}

void mensaje_error(){
    printf("Error! La nota debe ser un valor entre 0 y 10.\n");
}

void calculo(float *primera_nota, float *segunda_nota, float *exam){
    *exam = 3 * (14 - *primera_nota - (*segunda_nota / 3));
}

void mostrar_resultado(float *exam){
    printf("La nota requerida para aprobar PROGRAMASION xD es: %.2f", *exam);
}
