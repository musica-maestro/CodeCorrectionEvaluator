/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...1.7
2pt leggi numeri:....2
TOTALE ..............9.7
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* DELAY */
void delay(int sec){
    int millisec = 1*sec;
    clock_t start = clock();
    while(clock() < start + millisec);
}

/* funzione ricorsiva che verifica se all'interno di una sequenza ogni tripla di interi contiene il minimo che è dispari */
int minimoDispari(int *seq, int lunghezza){
    int tripla; // variabile universale

    /* caso base */
    if(lunghezza<3)
        tripla = 1;
    else    // passo ricorsivo
         tripla = (((seq[lunghezza-1]<seq[lunghezza-2] && seq[lunghezza-1]<seq[lunghezza-3]) && seq[lunghezza-1]%2!=0) ||
                ((seq[lunghezza-2]<seq[lunghezza-1] && seq[lunghezza-2]<seq[lunghezza-3]) && seq[lunghezza-2]%2!=0) ||
                ((seq[lunghezza-3]<seq[lunghezza-1] && seq[lunghezza-3]<seq[lunghezza-2]) && seq[lunghezza-3]%2!=0)) &&
                minimoDispari(seq, lunghezza-1);
    return tripla;
}

/* funzione che conta quanti interi sono stati memorizzati all'interno della sequenza */
int quantiNumeri() {
    int count = 0;  // contatore interi presenti sul file di testo
    /* apri il file.txt in modalità lettura */
    FILE* fp = fopen("interi.txt", "r");
    if(fp!=NULL){   // apertura riuscita //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
        // apertura riuscita
        int n;
        while(fscanf(fp, "%d", &n)!=EOF)
            count++;
        fclose(fp);
    }
    return count;
}

/* funzione che legge gli interi memorizzati nel file di testo */
void leggiNumeri(int* sequenza, int lunghezza) {
    /* apri il file.txt, in modalità lettura */
    FILE* fp = fopen("interi.txt", "r");
    if(fp==NULL)    // apertura non riuscita
        printf("\nFile non trovato.\n");
    else{   // apertura riuscita
        int lunghezza = quantiNumeri();
        for(int i=0; i<lunghezza; i++)
            fscanf(fp, "%d", &sequenza[i]);
        fclose(fp);
        delay(1000);
        printf("\n");
        printf("\nSto recuperando la sequenza");
        delay(1000); printf(".");
        delay(1000); printf(".");
        delay(1000); printf(".");
        delay(1000);
        printf("\n====================\n");
        printf("Sequenza recuperata.\n");
        printf("====================\n\n\n");
    }
}

/* funzione che scrive su file gli interi della sequenza introdotta dall'utente */
void scriviNumeri(int* sequenza, int lunghezza) {
    /* apri il file.txt in modalità scrittura */
    FILE* fp = fopen("interi.txt", "w");
    if(fp==NULL)    // apertura non riuscita
        printf("\nSalvataggio sequenza non riuscito.\n");
    else{   // apertura riuscita
        for(int i=0; i<lunghezza; i++)
            fprintf(fp, "%d ", sequenza[i]); // scrivi gli interi della sequenza su file.txt
        fclose(fp); // chiudi il file
        printf("\nSalvataggio effettuato.\n");
    }
}

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
		scanf("%d", &lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("\nOgni tripla di interi %c tale che il minimo fra tre interi %c dispari\n", 138, 138);
		else
			printf("\nNon tutte le triple di interi hanno il minimo che %c dispari.\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
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
			printf("\nOgni tripla di interi %c tale che il minimo fra tre interi %c dispari\n", 138, 138);
		else
			printf("\nNon tutte le triple di interi hanno il minimo che %c dispari.\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}