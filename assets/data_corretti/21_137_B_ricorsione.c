/*
5pt minimo dispari:..0
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....1
TOTALE ..............1
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
		int lungezza=0;                   //**** la proprietà non era questa e comunque non c'è la ricorsione
		if((seq[0] + seq[1] + seq[2])!=0)
		lunghezza =1;
}

/* funzione che conta ... */
int quantiNumeri() {
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp= ("interi.txt","r");
	if(fp==NULL)
		printf("nulla da visualizzare");
		else {
			printf("ecco gli interi");
			//**** manca l'acquisizione! -1
		}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
		FILE *fp= ("interi.txt","w");
		if(fp==NULL)
			printf("nulla da visualizzare");
		else {
			printf("ecco gli interi");
			//**** manca l'acqa scrittura! -1
		}
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
		if(minimoDispari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

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
			printf(" il minimo fra i tre interi e' dispari \n");
		else
			printf("  il minimo fra i tre interi non e' dispari \n \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}