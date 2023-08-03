#include <stdio.h>
#include <stdlib.h>

void sumale(int posicion, int suma, int *arreglo, int tamano) {
    // Verificar que la posición sea válida
    if (posicion < 0 || posicion >= tamano) {
        printf(" No se puede realizar la suma.\n");
        return;
    }

    // Realizar la suma en la posición dada
    arreglo[posicion] += suma;

    // Ajustar el arreglo para mantener dígitos entre 0 y 9
    for (int i = posicion; i >= 0; i--) {
        if (arreglo[i] > 9) {
            arreglo[i] -= 10;
            if (i - 1 >= 0) {
                arreglo[i - 1]++;
            } else {
                // Si llegamos al primer elemento y aún hay que llevar, debemos expandir el arreglo
                tamano++;
                int *nuevo_arreglo = (int *)malloc(tamano * sizeof(int));
                nuevo_arreglo[0] = 1;
                for (int j = 1; j < tamano; j++) {
                    nuevo_arreglo[j] = arreglo[j - 1];
                }
                free(arreglo);
                arreglo = nuevo_arreglo;
            }
        }
    }
    // Imprimir el resultado
    printf("Resultado: [");
    for (int i = 0; i < tamano - 1; i++) {
        printf("%d,", arreglo[i]);
    }
    printf("%d]\n", arreglo[tamano - 1]);
}

int main() {
    int tamano;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tamano);

    int *arreglo = (int *)malloc(tamano * sizeof(int));

    printf("Ingrese los %d elementos del arreglo: ", tamano);
    for (int i = 0; i < tamano; i++) {
        scanf("%d", &arreglo[i]);
    }

    printf("Arreglo original: [");
    for (int i = 0; i < tamano - 1; i++) {
        printf("%d,", arreglo[i]);
    }
    printf("%d]\n", arreglo[tamano - 1]);

    int posicion, suma;
    while (1) {
        printf("Ingrese la posicion y el valor de suma: ");
        if (scanf("%d %d", &posicion, &suma) != 2) {
            printf("Entrada inválida. Saliendo del programa.\n");
            break;
        }
        sumale(posicion, suma, arreglo, tamano);
    }

    free(arreglo);

    return 0;
}
