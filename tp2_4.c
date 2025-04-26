#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_PCS 5

// *** Declaración de estructuras ***
struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};


// *** Declaración de funciones ***
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);

// *** Función principal ***
int main() {
    // Variable que almacena las 5 PCs
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

    listarPCs(pcs, CANT_PCS);
    mostrarMasVieja(pcs, CANT_PCS);

    return 0;
}

// *** Definición de funciones ***
void listarPCs(struct compu pcs[], int cantidad) {
    printf("\nListado de PCs:\n\n");
    for (int i = 0; i < cantidad; i++) {
        printf("PC #%d\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Año: %d\n", pcs[i].anio);
        printf("  Núcleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int indice_mas_vieja = 0; // Suponemos que la primera es la más vieja

    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[indice_mas_vieja].anio) {
            indice_mas_vieja = i;
        }
    }

    printf("PC más vieja:\n");
    printf("  Velocidad: %d GHz\n", pcs[indice_mas_vieja].velocidad);
    printf("  Año: %d\n", pcs[indice_mas_vieja].anio);
    printf("  Núcleos: %d\n", pcs[indice_mas_vieja].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[indice_mas_vieja].tipo_cpu);
}