/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se, in un array di numeri interi, ogni tripla di interi consecutivi nella sequenza
è tale che il minimo fra i tre interi è dispari */



int minimo(int n1, int n2, int n3)
{
	int minimo;

	if(n1 < n2 && n1 < n3) {
		minimo = n1;
	} else {
		if(n2 < n1 && n2 < n3) {
			minimo = n2;
		} else {
			minimo = n3;
		}
	}
	return minimo;
}



int minimoDispari(int *seq, int lunghezza)
{
	int universale  = 1;

	/* caso base implicito*/
	if(lunghezza>=3) {
		universale = ((minimo(seq[0], seq[1], seq[2]))%2 != 0) && minimoDispari(seq+1, lunghezza-1);
	}
	return universale;
}

/* funzione che conta quanti numeri interi sono memorizzati su un file dal nome interi.dat */
int quantiNumeri()
{
	int conteggio = 0;

	FILE* fp = fopen("interi.dat", "rb");

	if(fp == NULL) {
		printf("Lettura non riuscita!\n\n");
	} else {
		int numero;
		while(fread(& numero, sizeof(int), 1, fp) > 0) {
			conteggio++;
		}
		fclose(fp);
	}
	return conteggio;
}

/* funzione che legge una sequenza di interi da un file dal nome interi.dat */
void leggiNumeri(int* sequenza, int lunghezza)
{
	FILE* fp = fopen("interi.dat", "rb");

	if(fp == NULL) {
		printf("Lettura non riuscita!\n\n");
	} else {
		for(int i = 0; i<lunghezza; i++) {
			fread(& sequenza[i], sizeof(int), 1, fp);
		}
		fclose(fp);
		printf("Lettura riuscita!\n\n");
	}
}

/* funzione che scrive i valori di un array su di un file*/
void scriviNumeri(int* sequenza, int lunghezza)
{
	FILE* fp = fopen("interi.dat", "wb");

	if(fp == NULL) {
		printf("Salvataggio non riuscito!\n\n");
	} else {
		fwrite(sequenza, sizeof(int), lunghezza, fp);

		fclose(fp);
		printf("Salvataggio effettuato!\n\n");
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
			printf("Ogni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("Non ogni tripla di interi consecutivi, o nessuna, nella sequenza E' tale che il minimo fra i tre interi e' dispari \n");

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
			printf("Ogni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari \n");
		else
			printf("Non ogni tripla di interi consecutivi, o nessuna, nella sequenza E' tale che il minimo fra i tre interi e' dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}