/*
5pt minimo dispari:..3.8
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............3.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se, in un array
 * di numeri interi, ogni tripla di interi consecutivi
 * nella sequenza Ã¨ tale che il minimo tra i tre interi
 * Ã¨ dispari */
int minimoDispari(int *seq, int lunghezza){
    int risultato;
    //**** Passo base: se lunghezza=1 o 2 restutuisci valori a caso, visto che risultato non è inizializzato -1
    //**** lunghezza==3 fa parte del passo ricorsivo.
    //**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 dispari". -0.2
    if ((seq[0]%2!=0 && seq[0]<seq[1] && seq[0]<seq[2]) ||
        (seq[1]%2!=0 && seq[1]<seq[0] && seq[1]<seq[2]) ||
        (seq[2]%2!=0 && seq[2]<seq[0] && seq[2]<seq[1]))
    risultato=1;
    else {
        if(lunghezza>3)
            risultato = (seq[0]%2!=0 && seq[0]<seq[1] && seq[0]<seq[2]) ||
                        (seq[1]%2!=0 && seq[1]<seq[0] && seq[1]<seq[2]) ||
                        (seq[2]%2!=0 && seq[2]<seq[0] && seq[2]<seq[1]) &&
                        (minimoDispari(seq+2, lunghezza-2));
    }
        return risultato;
}

/* funzione che conta quanti numeri interi sono memorizzati nel file */
int quantiNumeri() {
}

/* funzione che legge una sequenza di interi da file */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive i valori di un array di interi su file */
void scriviNumeri(int* sequenza, int lunghezza) {
}

//******* hai provato a modificare il main per escludere l'uso dei file, ma così il programma non compila piu'!

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza)) {
			printf("Ogni tripla di interi consecutivi nella sequenza ");
            printf("%c tale che il minimo tra i tre interi %c dispari\n", 138, 138);
		}
        else {
        }
			printf("NON Ogni tripla di interi consecutivi nella sequenza ");
            printf("%c tale che il minimo tra i tre interi %c dispari\n", 138, 138);
        }
		/* salva la sequenza su file */
		FILE* fp = fopen("interi.txt", "w");
        if(fp==NULL)
        printf("Niente da salvare!\n");
		else {
           for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
        }
        fprintf(scriviNumeri(array,lunghezza));
        printf("Salvataggio effettuato!\n");
	}
    fclose(FILE* fp)
}
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
        FILE* fp = fopen("interi.txt", "w");
        if fp==NULL
        printf("Niente da salvare!\n");
		else {
           for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
        }
        fprintf(scriviNumeri(array,lunghezza));
        printf("Salvataggio effettuato!\n");
	}
    fclose(FILE* fp)
}
