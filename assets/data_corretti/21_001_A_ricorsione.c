/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/


#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza) {
	//pre: l>=3
	int ogniTripla;			//variabile di universalit√
	int max;				//per memorizzare il massimo in ogni tripla

	/* CASO BASE */
	if(lunghezza<=2)
		ogniTripla=1;
	/* PASSO RICORSIVO */
	else {
		/* cerca il massimo nella tripla */
		max = seq[0];
		if(seq[1]>max && seq[1]>seq[2])
			max=seq[1];
		else {
			if(seq[2]>seq[1] && seq[2]>max)
				max=seq[2];
		}

		ogniTripla = (max%2==0) && massimoPari(seq+1, lunghezza-1);
	}
	return ogniTripla;
}

/* funzione che conta ... */
int quantiNumeri() {
	int intero;			//per appoggio
	int quanti = 0;		//conta il numero di interi memorizzati sul file

	FILE *fp = fopen("interi.dat", "rb");		//per lettura di un file binario
	if(fp==NULL)
		printf("impossibile aprire file o file non esistente!\n\n");
		else {
			/* leggi quanti interi sono memorizzati sul file */
			while(fread(&intero, sizeof(int), 1, fp)>0)
				quanti++;			//incrementa la variabile di conteggio
			fclose(fp);			//chiudi file
		}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");			//per lettura di un file binario

	if(fp==NULL)
		printf("impossibile aprire file o file non esistente!\n\n");
	else {
		/* leggi una sequenza di interi da un file e memorizzali sull'array ricevuto come parametro */
		fread(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);			//chiudi file
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");		//per scrittura su file
	if(fp==NULL)
		printf("salvataggio non riuscito!\n\n");
	else {
		/* scrivi i valori dell'array passato per riferimento su un file */
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);		//chiudi file
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
			printf("Ogni tripla di interi consecutivi nella sequenza inserita %c tale che il massimo fra i tre interi %c pari\n\n", 138, 138);
		else
			printf("NON ogni tripla di interi consecutivi nella sequenza inserita %c tale che il massimo fra i tre interi %c pari\n\n", 138, 138);

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
			printf("Ogni tripla di interi consecutivi nella sequenza recuperata dal file %c tale che il massimo fra i tre interi %c pari\n\n", 138, 138);
		else
			printf("NON ogni tripla di interi consecutivi nella sequenza recuperata dal file %c tale che il massimo fra i tre interi %c pari\n\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
