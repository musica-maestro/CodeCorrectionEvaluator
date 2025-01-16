/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>


// Funzone cha calcola il massimo tra tre interi
int maxTripla(int n1, int n2, int n3){
	int max = n1;
	if(n2 > n1 && n2 > n3)
		max = n2;
	else{
		if(n3 > n2 && n3 > n1)
			max = n3;
	}
	return max;
}

/* funzione ricorsiva che verifica se per ogni tripla dell'array il massiome è un numero pari */
int massimoPari(int *seq, int lunghezza){
	int vero; 					// variabile per la verifica universale

	// CASO BASE
	if(lunghezza < 3)
		vero = 1;
	// PASSO RICORSIVO
	else
		vero = (maxTripla(seq[0], seq[1], seq[2])%2 == 0) && massimoPari(seq + 1, lunghezza - 1);			// verifico la condizione e richiamo corsivamente la funzione massimoPari

	return vero;
}

/* funzione che conta quanti numeri sono scritti nel file */
int quantiNumeri() {
	FILE *fp = fopen("interi.dat", "rb");		// apro il file
	int quanti = 0;				// variabile per contare i numeri all'interno del file
	if(fp == NULL)
		printf("Read: impossibile aprire il file.\n");		// stampa di controllo nel caso in cui l'apertura vada male
	else{
		int elemento;
		while(fread(&elemento, sizeof(int), 1, fp) > 0)			// fino a quando sono presenti elementi incremento 'quanti'
			quanti++;

		fclose(fp);		// chiudo il file
	}
	return quanti;
}


/* funzione che legge i numeri dauù un file binario */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");		// apro il file in lettura
	if(fp == NULL)
		printf("Read: impossibile aprire il file.\n");			// stampa di controllo nel caso in cui l'apertura vada male
	else{
		fread(sequenza, sizeof(int), lunghezza, fp);			// leggo gli interi dal file e li salvo in un'array
		fclose(fp);      // chiudo il file
	}

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");
	if(fp == NULL)
		printf("Write: impossibile aprire il file.\n");				// stampa di controllo nel caso in cui l'apertura vada male
	else{
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);

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
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf("Ogni tripla dell'array e' tale che il massimo e' un numero pari.\n");
		else
			printf("Non tutte le triple dell'array sono tali che il massimo e' un numero pari\n");

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
		if(massimoPari(array,lunghezza))
			printf("Ogni tripla dell'array e' tale che il massimo e' un numero pari.\n");
		else
			printf("Non tutte le triple dell'array sono tali che il massimo e' un numero pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
