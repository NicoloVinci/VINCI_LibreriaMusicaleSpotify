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
    nuovaCanzone->titolo = malloc(sizeof(char) * 100);
    nuovaCanzone->artista = malloc(sizeof(char) * 100);
    printf("Inserisci il titolo della canzone: ");
    fgets(nuovaCanzone->titolo, 100, stdin);
    int i = 0;
    while (nuovaCanzone->titolo[i] != '\0') {
        i++;
    }
    if (i > 0 && nuovaCanzone->titolo[i-1] == '\n') {
        nuovaCanzone->titolo[i-1] = '\0';
    }
    printf("Inserisci l'artista della canzone: ");
    fgets(nuovaCanzone->artista, 100, stdin);
    i = 0;
    while (nuovaCanzone->artista[i] != '\0') {
        i++;
    }
    if (i > 0 && nuovaCanzone->artista[i-1] == '\n') {
        nuovaCanzone->artista[i-1] = '\0';
    }
    printf("Inserisci il tempo in minuti della canzone: ");
    char buffer[100];
    char *endptr;
    fgets(buffer, 100, stdin);
    nuovaCanzone->minuti = strtol(buffer, &endptr, 10);
    while (endptr == buffer) {
        printf("Formato non valido. Inserisci il tempo in minuti della canzone: ");
        fgets(buffer, 100, stdin);
        nuovaCanzone->minuti = strtol(buffer, &endptr, 10);
    }
    printf("Inserisci i secondi della canzone: ");
    fgets(buffer, 100, stdin);
    nuovaCanzone->secondi = strtol(buffer, &endptr, 10);
    while (endptr == buffer) {
        printf("Formato non valido. Inserisci i secondi della canzone: ");
        fgets(buffer, 100, stdin);
        nuovaCanzone->secondi = strtol(buffer, &endptr, 10);
    }
    if (indice < grandezza) {
        libreria[indice] = *nuovaCanzone;
    } else {
        libreria = realloc(libreria, sizeof(Canzone) * (grandezza * 2));
        grandezza *= 2;
        libreria[indice] = *nuovaCanzone;
    }
    printf("Canzone aggiunta con successo!\n");
    indice++;
    printf("Premere un tasto per tornare al menù principale...\n");
    getchar();
    return;
}

void visualizzaLibreria() {
    for (int i = 0; i < indice; i++) {
        printf("Titolo: %s\nArtista: %s\nDurata: %d:%02d\n\n", libreria[i].titolo, libreria[i].artista, libreria[i].minuti, libreria[i].secondi);
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
        getchar();
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