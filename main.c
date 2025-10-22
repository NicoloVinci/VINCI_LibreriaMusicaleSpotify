#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *titolo;
    char *artista;
    int minuti;
    short secondi;
} Canzone;

Canzone *libreria;
int main(void) {
    libreria = malloc(sizeof(Canzone) * 10);
    do {
        system("clear");
        printf("Benvenuto nella libreria musicale.\n");
        printf("Scegli un'operazione:\n");
        printf("1. Aggiungi una canzone\n");
        printf("2. Visualizza libreria\n");
        printf("3. Esci\n");
        int scelta;
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                system("clear");
                aggiungiCanzone();
                break;
            case 2:
                system("clear");
                visualizzaLibreria();
                break;
            case 3:
                system("clear");
                printf("Arrivederci!\n");
                return 0;
            default:
                system("clear");
                printf("Scelta non valida. Premi un tasto per tornare al menù principale...\n");
                getchar();
        }
    } while (1);
    printf("Hello, World!\n");
    return 0;
}