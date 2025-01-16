/*
5pt massimo pari:..5
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int res;
	if(lunghezza<3) {
		res=1;
	}
	else {
		int max=seq[0]; //*** non serviva inizializzare max in questo caso...

		if(seq[0]>seq[1] && seq[0]>seq[2])
			max=seq[0];
		else if(seq[1]>seq[0] && seq[1]>seq[2])
				max=seq[1];
			else if(seq[2]>seq[0] && seq[2]>seq[1])
					max=seq[2];

		if(max%2==0 && massimoPari(seq+1, lunghezza-1))
			res=1;
		else
			res=0;
	}
	return res;
}


/* funzione che conta ... */
int quantiNumeri() {
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
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
		if(massimoPari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}

