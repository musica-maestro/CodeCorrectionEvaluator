/*
5pt minimo dispari:..4.5
1pt scrivi numeri:...0.7
2pt quanti numeri:...0.7
2pt leggi numeri:....0.6
TOTALE ..............6.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int risultato; //**** devi inizializzare risultato=0 -0.5
	/* caso base */
	if(lunghezza<3)
		risultato= 1;
	/* passo ricorsivo */
	else if(((((seq[0]< seq[1]) && (seq[0]< seq[2]))) && (seq[0]%2 !=0))
	     || ((((seq[1]< seq[0]) && (seq[1]< seq[2]))) && (seq[1]%2!=0))
	     || ((((seq[2]< seq[1]) && (seq[2]< seq[0]))) && (seq[2]%2!=0)))
		risultato = minimoDispari(seq+1, lunghezza-1);

		return risultato;
}


/* funzione che conta ... */
int quantiNumeri() {

	FILE *fp = fopen("interi.txt", "r");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3

	int cont = 0;

	while(fscanf(fp, "", )) //**** mancano gli argomenti -0.8
		cont++;
//**** non chiudi il file -0.2
	return cont;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE*fp = fopen("interi.txt"); //**** manca l'opzione r/w -0.5
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i = 0; sequenza<quantiNumeri(); i++){
		fscanf(fp, "%d", sequenza[i]) //**** manca il ; -0.1 //**** &sequenza[i] -0.3
	}
//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.txt", "w");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i = 0 ; i<lunghezza; i++){
		fprintf(fp, sequenza[i], lunghezza);

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
			printf(" La sequenza rispetta la condizione\n");
		else
			printf(" La sequenza NON rispetta la condizione \n");

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
			printf(" La sequenza rispetta la condizione \n");
		else
			printf(" La sequenza NON  rispetta la condizione\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}