/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se, in un array di numeri interi,
 * ogni tripla di interi consecutivi nella sequenza è tale che il minimo fra i tre interi è dispari. */
int minimoDispari(int *seq, int lunghezza) {

	int tutti;			//variabile booleana di universalità
	tutti = 1;			//inizializzata a true
	int minimo;			//contiene il minimo fra 3 interi consecutivi

	/* Caso base implicito: lunghezza <= 2 */
	if (lunghezza >= 3) {		//passo ricorsivo

		/* Cerca e trova il minimo fra i primi tre interi consecutivi nella sequenza */
		if (seq[0] <= seq[1] && seq [0] <= seq[2])
			minimo = seq[0];
		else if (seq[1] <= seq[2] && seq [1] <= seq[0])
			minimo = seq[1];
		else
			minimo = seq[2];

		/* Ricorri sulla sequenza */
		tutti = minimo % 2 != 0 && minimoDispari(seq + 1, lunghezza - 1);
	}

	return tutti;
}

/* funzione che conta gli interi memorizzati all'interno del file cosi da recuperare la lunghezza della sequenza */
int quantiNumeri() {
	int quanti;			//variabile di conteggio per contare il numero di interi nel file
	quanti = 0;			//inizializzata al valore nullo (non significativo)

	FILE* fp = fopen("interi.dat", "rb");		//apertura file

	/* Apertura riuscita? */
	if (fp == NULL)
		printf("Apertura non riuscita!\n\n\n");
	else {		//apertura riuscita
		int temp;		//variabile di appoggio per memorizzare un intero da file

		/* Finche leggi un intero da file vai avanti e incrementa quanti */
		while(fread(& temp, sizeof(int), 1, fp) > 0)
			quanti += 1;

		fclose(fp);		//chiusura file
	}

	return quanti;

}

/* funzione che legge interi dal file e li memorizza all'interno di una sequenza */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE* fp = fopen ("interi.dat", "rb");		//apertura file

	/* Apertura riuscita? */
	if (fp == NULL)
		printf("Acquisizione non riuscita!\n\n\n");
	else {		//apertura riuscita

		/* Vai avanti fino alla fine della sequenza e leggi da file l'intero e inseriscilo nella sequenza */
		for(int i = 0; i < lunghezza; i++)
			fread(& sequenza[i], sizeof(int), 1, fp);

		fclose(fp);
		printf("Acquisizione riuscita!\n\n\n");
	}
}

/* funzione che scrive i valori della sequenza passata come parametro su di un file binario. */
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE* fp = fopen("interi.dat", "wb");		//apertura file

	/* Apertura riuscita? */
	if(fp == NULL)
		printf("Salvataggio non riuscito!\n\n\n");
	else {		//apertura riuscita

		/* Salva la sequenza su file e chiudilo */
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		printf("Salvataggio effettuato!\n\n\n");
		fclose(fp);								//chiusura file
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
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla di interi nella sequenza e' tale che il minimo fra i tre interi e' dispari!\n\n");
		else
			printf("Non tutte le triple nella sequenza sono tali che il minimo fra i tre interi e' dispari!\n");

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
			printf("Ogni tripla di interi nella sequenza e' tale che il minimo fra i tre interi e' dispari!\n\n");
		else
			printf("Non tutte le triple nella sequenza sono tali che il minimo fra i tre interi e' dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
