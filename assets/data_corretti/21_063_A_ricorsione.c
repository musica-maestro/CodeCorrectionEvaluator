/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.5
2pt leggi numeri:..2
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int ris; // dichiaro variabile da restituire
	int massimo = 0; //dichiaro variabile massimo
	if(lunghezza == 3){ //se array contiene esattamente 3 elementi
		massimo = seq[0];                          //
		if(seq[1] > massimo) massimo = seq[1];    // -> si trova il massimo fra i 3 numeri
		if(seq[2] > massimo) massimo = seq[2];    //
		ris = (massimo % 2 == 0);
	} else {
		if(lunghezza > 3){ // se array continete piu di 3 elementi
			massimo = seq[0];                        //
			if(seq[1] > massimo) massimo = seq[1];  // -> si trova il massimo fra i 3 numeri
			if(seq[2] > massimo) massimo = seq[2];  //
			ris = (massimo % 2 == 0) && massimoPari(seq + 1,lunghezza - 1); // chiamata ricorsiva
		} else {
			ris = 0; //la sequenza contiene meno di 3 elementi e quindi non si puo dire niente
		}
	}
	return ris; // restituisco il valore di ris
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp = fopen("ricorsione.dat","rb"); // dichiaro puntatore a file
	int cont = 0;//dichiaro variabile di conteggio
	if(fp != NULL){ // controllo se
		while(fread(&cont,sizeof(int),1,fp)) // finche c'è un numero nel file continua a incrementare il valore di cont
			cont++;
			//**** non puoi usare numero sia per contare, sia per la fread,
			//**** così ad ogni lettura perdi il contatore e in numero acquisisci
			//**** il valore letto dal file (in teoria) -0.5

	} else printf("\nImpossibile Aprire Il File\n");
	fclose(fp);
	return cont; //restituisco il numero di numeri contati
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("ricorsione.dat","rb"); // dichiaro puntatore a file
	if(fp != NULL){
		fread(sequenza,sizeof(int),lunghezza,fp);
		printf("\nAcquisizione Effettuata\n");
	} else printf("\nImpossibile Aprire Il File\n");
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("ricorsione.dat","wb");
	if(fp != NULL){
		fwrite(sequenza,sizeof(int),lunghezza,fp);
		printf("\nSalvataggio Effettuato\n");
	} else printf("\nImpossibile Aprire Il File\n");
	fclose(fp);
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
			printf(" Ogni Tripla di Interi consecutivi e' tale che il massimo fra i 3 interi e' pari \n");
		else
			printf(" Uno o Ogni Tripla di Interi consecutivi è tale che il massimo fra i 3 interi non e' pari  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();
		printf("%d",lunghezza);
		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf(" Ogni Tripla di Interi consecutivi e' tale che il massimo fra i 3 interi e' pari \n");
		else
			printf(" Uno o Ogni Tripla di Interi consecutivi è tale che il massimo fra i 3 interi non e' pari  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
