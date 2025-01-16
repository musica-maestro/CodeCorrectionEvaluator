/*
5pt minimo dispari:..2.5
1pt scrivi numeri:...0.7
2pt quanti numeri:...0
2pt leggi numeri:....2
TOTALE ..............5.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int minimod;

	if(lunghezza<3)
		minimod=0;//**** variabile di universalità inizializzata male -1
	else
		minimod=(((seq[0]<seq[1]<seq[2])&&(seq[0]%2!=0)) || ((seq[1]<seq[0]<seq[2])&&(seq[1]%2!=0)) ||
		((seq[2]<seq[0]<seq[1])&&(seq[2]%2!=0)) || ((seq[0]<seq[2]<seq[1])&&(seq[0]%2!=0))||
		((seq[1]<seq[2]<seq[0])&&(seq[1]%2!=0))||((seq[2]<seq[1]<seq[0])&&(seq[2]%2!=0)) && minimoDispari(seq+1, lunghezza-1));
		//**** non è la sintassi corretta per valutare le espressioni booleane.
		//**** es: se hai seq[0]=2, seq[1]=3, seq[2]=4, la seconda espressione (seq[1]<seq[0]<seq[2])&&(seq[1]%2!=0)
		//**** calcola 3<2<4 && 3%2!=0 dove (3<2)<4 restituisce 0<4 (0 perché 3<2 è falso) e 0<4 è vero, quindi 1
		//**** -1.5
		return minimod;
}

/* funzione che conta ... */
int quantiNumeri() {
	int conta=0;

	FILE* fp=fopen("interi.txt", "r");



	fclose(fp);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.txt", "r");
	if(fp==NULL)
		printf("Apertura file non riuscita.\n");
	else{
		for(int i=0; i<lunghezza; i++)
			fscanf(fp, "%d", &sequenza[i]);
	}
	fclose(fp);
	printf("File recuperato\n");
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.txt", "w");
	if(fp==NULL)
		printf("Apertura file non riuscita.\n");
	else{
		for(int i=0; i<lunghezza;i++)
			fprintf(fp, "%d", &sequenza[i]);  //**** sequenza[i] -0.3
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
			printf("Tutte le triple hanno il loro minimo dispari\n");
		else
			printf("Non tutte le triple hanno il noro minimo dispari\n");

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}