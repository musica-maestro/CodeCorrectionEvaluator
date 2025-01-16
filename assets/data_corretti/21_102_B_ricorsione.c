/*
5pt minimo dispari:..3.8
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............8.8
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che restituisce 1 se il minimo tra i tre numeri che gli sono stati passati è dispari, restituisce 0
 * altrimenti*/
int isMinDisp(int n1, int n2, int n3)
{
    return ((n1 < n2 && n1 < n3 && n1 % 2 != 0) || (n2 < n3 && n2 < n1 && n2 % 2 != 0) ||
        (n3 < n2 && n3 < n1 && n3 % 2 != 0));
}

/* funzione ricorsiva che restituisce 1 se ogni tripla di interi consecutivi in una sequenza è tale che il minimo fra i
 * tre interi è dispari, restituisce 0 altrimenti*/
int minimoDispari(int* seq, int lunghezza)
{
    int verificato = 1; // variabile universale

    /*caso base*/
    if(lunghezza == 3) {
//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
//**** lunghezza==3 fa parte del passo ricorsivo.
//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.2
        verificato = isMinDisp(seq[0], seq[1], seq[2]);
    } else {
        /*passo induttivo*/
        verificato = isMinDisp(seq[0], seq[1], seq[2]) && minimoDispari(seq + 1, lunghezza - 1);
    }
    return verificato;
}

/* funzione che conta quanti interi sono salvati sul file in modo tale da trovare la lunghezza dell'array*/
int quantiNumeri()
{
    int dim = 0; // variabile che conterra' la lunghezza di seq
    /*apri il file*/
    FILE* fp = fopen("interi.txt", "r");
    /*file non trovato o problemi?*/
    if(fp == NULL) {
        printf("Conteggio interi nel file non riuscito.\n\n");
    } else {
        int numero;  // variabile d'appoggio
        /*scorri il file fino a che non finisce*/
        while(fscanf(fp, "%d", &numero) != EOF) {
            dim++; // incrementa lunghezza
        }
        printf("\nHo trovato %d interi nel file.\n\n", dim);
    }
    fclose(fp); // chiudi il file
    return dim;
}

/* funzione che legge una sequenza di interi in un file e li memorizza su una sequenza */
void leggiNumeri(int* sequenza, int lunghezza)
{
    FILE* fp = fopen("interi.txt", "r");
    /*problemi?*/
    if(fp == NULL) {
        printf("\nApertura del file non riuscita.\n\n");
    } else {
        /*inserisci nell'array il numero di elementi che hai contato in precedenza*/
        for(int i = 0; i < lunghezza; i++) {
            fscanf(fp, "%d", &sequenza[i]);
        }
        printf("\nHo trovato tutti gli interi e li ho inseriti nella sequenza.\n\n");
    }
    fclose(fp);
}

/* funzione che scrive tutti gli interi della sequena su di un file testuale */
void scriviNumeri(int* sequenza, int lunghezza)
{
    /*Apri il file*/
    FILE* fp = fopen("interi.txt", "w");
    /*problemi con il file?*/
    if(fp == NULL) {
        printf("\nSalvataggio della sequenza su file non riuscito.\n\n");
    } else {
        /*inserisci tutti gli interi che trovi dento al file*/
        for(int i = 0; i < lunghezza; i++) {
            fprintf(fp, "%d ", sequenza[i]); // scrivi l'intero nel file
        }
        printf("\nSalvataggio effettuato correttamente.\n\n");
    }
    fclose(fp); // chiudi il file
}

/* funzione principale */
int main()
{
    int lunghezza; //	lunghezza dell'array
    int scelta;    //	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d", &scelta);

    /* introduzione sequenza da input */
    if(scelta == 1) {
        /* determina la lunghezza della sequenza */
        printf("Introduci la lunghezza della sequenza: ");
        scanf("%d", &lunghezza);

        /* crea l'array e leggine i valori degli elementi */
        int array[lunghezza];
        printf("Scrivi %d elementi \n", lunghezza);
        for(int i = 0; i < lunghezza; i++)
            scanf("%d", &array[i]);

        /* invoca la funzione ricorsiva e stampa il risultato */
        if(minimoDispari(array, lunghezza))
            printf("Congratulazioni, nella sequenza che hai inserito tutte le triple sono tali che il minimo tra i tre "
                   "elementi e' dispari.\n");
        else
            printf("Spiacente, nella sequenza che hai inserito NON tutte le triple sono tali che il minimo tra i tre "
                   "elementi e' dispari.\n");

        /* salva la sequenza su file */
        scriviNumeri(array, lunghezza);
    }
    /* recupero sequenza da file */
    else {
        /* determina la lunghezza della sequenza */
        lunghezza = quantiNumeri();

        /* crea l'array e leggine i valori degli elementi da file */
        int array[lunghezza];
        leggiNumeri(array, lunghezza);
        printf("Ecco la sequenza recuperata\n");
        for(int i = 0; i < lunghezza; i++)
            printf("%d ", array[i]);
        printf("\n");

        /* invoca la funzione ricorsiva e stampa il risultato */
        if(minimoDispari(array, lunghezza))
            printf("Congratulazioni, nella sequenza che hai inserito tutte le triple sono tali che il minimo tra i tre "
                   "elementi e' dispari.\n");
        else
            printf("Spiacente, nella sequenza che hai inserito NON tutte le triple sono tali che il minimo tra i tre "
                   "elementi e' dispari.\n");

        /* salva la sequenza su file */
        scriviNumeri(array, lunghezza);
    }
}