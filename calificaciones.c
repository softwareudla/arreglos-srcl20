#include <stdio.h>

#define nEstudiantes 5
#define NumAsignaturas 3
#define NumCalificaciones 5
#define NotaAprobacion 6.0

int main (int argc, char *argv[]) {
    char apellidos[nEstudiantes][30];
    float calificaciones_matematicas[nEstudiantes][NumCalificaciones];
    float calificaciones_lengua[nEstudiantes][NumCalificaciones];
    float calificaciones_ciencias[nEstudiantes][NumCalificaciones];
    int aprobados_matematicas = 0, aprobados_lengua = 0, aprobados_ciencias = 0;
    int reprobados_matematicas = 0, reprobados_lengua = 0, reprobados_ciencias = 0;

    // Ingreso de apellidos y calificaciones
    for (int a = 0; a < nEstudiantes; a++) { 
        printf("Ingrese el apellido del estudiante %d: ", a + 1);
        scanf("%s", apellidos[a]); 

        // Ingresar calificaciones de Matemáticas
        printf("Ingrese 5 calificaciones de Matemáticas para el estudiante %s:\n", apellidos[a]); 
        for (int b = 0; b < NumCalificaciones; b++) {
            float nota; 
            do {
                printf("Calificación %d: ", b + 1);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Ingrese una calificación entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            calificaciones_matematicas[a][b] = nota; 
        }

        // Ingresar calificaciones de Lengua
        printf("Ingrese 5 calificaciones de Lengua para el estudiante %s:\n", apellidos[a]); 
        for (int c = 0; c < NumCalificaciones; c++) {
            float nota; 
            do {
                printf("Calificación %d: ",  c + 1);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Ingrese una calificación entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            calificaciones_lengua[a][c] = nota; 
        }

        // Ingresar calificaciones de Ciencias
        printf("Ingrese 5 calificaciones de Ciencias para el estudiante %s:\n", apellidos[a]);
        for (int d = 0; d < NumCalificaciones; d++) {
            float nota;
            do {
                printf("Calificación %d: ", d + 1);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Ingrese una calificación entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            calificaciones_ciencias[a][d] = nota; 
        } 
    }

    // Cálculo de estadísticas y salida
    for (int a = 0; a < nEstudiantes; a++) {
        printf("\nEstudiante: %s\n", apellidos[a]); 

        float suma_general = 0;
        float suma_asignatura = 0, nota_max = 0, nota_min = 10, promedio;

        // Matemáticas
        suma_asignatura = 0, nota_max = 0, nota_min = 10;
        for (int b = 0; b < NumCalificaciones; b++) {
            float nota = calificaciones_matematicas[a][b];
            suma_asignatura += nota; 
            if (nota > nota_max) nota_max = nota;
            if (nota < nota_min) nota_min = nota;
        }
        promedio = suma_asignatura / NumCalificaciones;
        suma_general += promedio;
        printf(" - Matemáticas: Promedio: %.2f, Máxima: %.2f, Mínima: %.2f\n", promedio, nota_max, nota_min);
        if (promedio >= NotaAprobacion) {
            aprobados_matematicas++;
        } else {
            reprobados_matematicas++;
        }

        // Lengua
        suma_asignatura = 0, nota_max = 0, nota_min = 10;
        for (int c = 0; c < NumCalificaciones; c++) {
            float nota = calificaciones_lengua[a][c];
            suma_asignatura += nota; 
            if (nota > nota_max) nota_max = nota;
            if (nota < nota_min) nota_min = nota;
        }
        promedio = suma_asignatura / NumCalificaciones;
        suma_general += promedio;
        printf(" - Lengua: Promedio: %.2f, Máxima: %.2f, Mínima: %.2f\n", promedio, nota_max, nota_min);
        if (promedio >= NotaAprobacion) {
            aprobados_lengua++;
        } else {
            reprobados_lengua++;
        }

        // Ciencias
        suma_asignatura = 0, nota_max = 0, nota_min = 10;
        for (int d = 0; d < NumCalificaciones; d++) {
            float nota = calificaciones_ciencias[a][d];
            suma_asignatura += nota; 
            if (nota > nota_max) nota_max = nota;
            if (nota < nota_min) nota_min = nota;
        }
        promedio = suma_asignatura / NumCalificaciones;
        suma_general += promedio;
        printf(" - Ciencias: Promedio: %.2f, Máxima: %.2f, Mínima: %.2f\n", promedio, nota_max, nota_min);
        if (promedio >= NotaAprobacion) {
            aprobados_ciencias++;
        } else {
            reprobados_ciencias++;
        }

        // Promedio general del estudiante
        float promedio_general = suma_general / NumAsignaturas;
        printf("Promedio general del estudiante %s: %.2f\n", apellidos[a], promedio_general);
    }

    // Mostrar aprobados y reprobados por asignatura
    printf("\nResumen de aprobados y reprobados por asignatura:\n");
    printf("Matemáticas: %d aprobados, %d reprobados.\n", aprobados_matematicas, reprobados_matematicas);
    printf("Lengua: %d aprobados, %d reprobados.\n", aprobados_lengua, reprobados_lengua);
    printf("Ciencias: %d aprobados, %d reprobados.\n", aprobados_ciencias, reprobados_ciencias);

    return 0;
}
