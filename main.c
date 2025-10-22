#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *titolo;
    char *artista;
    int minuti;
    short secondi;
} Canzone;

Canzone *libreria;
int grandezza = 5;
int indice = 0;

void aggiungiCanzone() {
    Canzone *nuovaCanzone = malloc(sizeof(Canzone));
    printf("Inserisci il titolo della canzone: ");
    getchar();
    scanf("%s", nuovaCanzone->titolo);
    printf("Inserisci l'artista della canzone: ");
    scanf("%s", nuovaCanzone->artista);
    printf("Inserisci il tempo in minuti della canzone: ");
    scanf("%d", &nuovaCanzone->minuti);
    printf("Inserisci i secondi della canzone: ");
    scanf("%hd", &nuovaCanzone->secondi);
    if (libreria[grandezza - 1].titolo!= NULL) {
        libreria[indice] = *nuovaCanzone;
        printf("Canzone aggiunta con successo!\n");
        indice++;
        printf("Premere un tasto per tornare al menù principale...\n");
        getchar();
        return;
    }
    libreria = realloc(libreria, sizeof(Canzone) * (grandezza * 2));
    grandezza *= 2;
    libreria[indice] = *nuovaCanzone;
    printf("Canzone aggiunta con successo!\n");
    printf("Premere un tasto per tornare al menù principale...\n");
    getchar();
    return;
}

void visualizzaLibreria() {
    printf("Titolo\tArtista\tTempo\n");
    for (int i = 0; i < indice; i++) {
        printf("%s\t%s\t%d:%02d\n", libreria[i].titolo, libreria[i].artista, libreria[i].minuti, libreria[i].secondi);
    }
    printf("Premere un tasto per tornare al menù principale...\n");
    getchar();
}
int main(void) {
    libreria = (Canzone *) malloc(sizeof(Canzone) * 10);
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
    free(libreria);
    return 0;
}