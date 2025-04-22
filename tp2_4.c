#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CANT_PCS 5

struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};

int main() {
    struct compu pcs[CANT_PCS];

    // Arreglo con los tipos posibles de CPU
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Generación de datos aleatorios
    for (int i = 0; i < CANT_PCS; i++) {
        pcs[i].velocidad = 1 + rand() % 3;           // 1 a 3 GHz
        pcs[i].anio = 2015 + rand() % 10;            // 2015 a 2024
        pcs[i].cantidad_nucleos = 1 + rand() % 8;    // 1 a 8 núcleos
        pcs[i].tipo_cpu = tipos[rand() % 6];         // Selección aleatoria de tipo CPU
    }

    // Mostrar datos generados
    for (int i = 0; i < CANT_PCS; i++) {
        printf("PC #%d\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Año: %d\n", pcs[i].anio);
        printf("  Núcleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
    }

    return 0;
}