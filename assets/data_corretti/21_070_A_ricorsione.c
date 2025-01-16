/*
5pt massimo pari:..1.5
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............1.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int verificata = 0;
	int massimo;
	/* Caso Base */
	if(lunghezza==0) //**** lunghezza <3 -1
		verificata = 0;
//**** variabile di universalità inizializzata male -1
	else{
		for(int i=0; i<3; i++){ //**** non serve il for!!! -1.5
			massimo =seq[i];
			if(seq[i+1]>massimo)
				massimo=seq[i+1];
			if(seq[i+2]>massimo)
				massimo = seq[i+2];
		}
		verificata = massimo%2==0 && massimoPari(seq+1, lunghezza-1);
		}
	return verificata;
	}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp = fopen("interi.txt", "r");
	int quanti = 0;
	quanti = ()
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.txt", "a"); //***** "w", non "a" -0.5
	for(int i=0; i<lunghezza; i++){
		fprintf("%d",sequenza[i]); //**** sintassi sbagliata, manca il nome del file -0.4
	} //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3

//**** non chiudi il file -0.2
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
			printf(" Tutti i massimi delle triple sono pari! \n");
		else
			printf(" Non tutti i massimi delle triple sono pari \n");

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
			printf(" Tutte i massimi delle triple sono pari! \n");
		else
			printf(" Non tutti i massimi delle triple sono pari! \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}