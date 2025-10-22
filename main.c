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
    printf("Hello, World!\n");
    return 0;
}