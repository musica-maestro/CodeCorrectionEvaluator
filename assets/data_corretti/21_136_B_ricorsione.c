/*
5pt minimo dispari:..4
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....1.5
TOTALE ..............5.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int minimo;   //valore da restituire
	/*CASO BASE*/
	if(lunghezza<3)
		minimo=0;  //**** variabile di universalità inizializzata male -1
	/*passo ricorsivo*/
	else
		minimo = ((seq[lunghezza-3]<seq[lunghezza-2] && seq[lunghezza-3]<seq[lunghezza-1]  && seq[lunghezza-3]%2!=0) ||
				 (seq[lunghezza-2]<seq[lunghezza-3] && seq[lunghezza-2]<seq[lunghezza-1]  && seq[lunghezza-2]%2!=0) ||
				 (seq[lunghezza-1]<seq[lunghezza-3] && seq[lunghezza-1]<seq[lunghezza-2]  && seq[lunghezza-1]%2!=0) &&
				 minimoDispari(seq, lunghezza-1));

	return minimo;
}

/* funzione che conta quanti interi sono memorizzati sul file */
int quantiNumeri() {
	FILE*fP = fopen ("interi.dat", "wb"); //**** devi aprire il file in lettura -03
	//**** manca il contatore -0.5
	if(fp==NULL)
		printf("Qualcosa e' andato storto!");
	else
		for(int i=0; i<lunghezza; i++)
			fwrite(&sequenza[i], sizeof(int),1, fp);
	         //**** cos'e' sequenza? -0.5
//**** non chiudi il file -0.2
//**** manca il return -0.5
}

/* funzione che legge una sequenza di interi da un file */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fP = fopen ("interi.dat", "rb");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	if(fp==NULL)
		printf("Qualcosa e' andato storto!");
	else
		for(int i=0; i<lunghezza; i++)
			fread(&sequenza[i], sizeof(int),1, fp);
	//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp= fopen ("interi.txt", "w");  //**** usi un file testuale, mentre nell'altra funzione hai usato un binario! -1

	if(fp==NULL)
		printf("apertura non andata a buon fine! \n ");

	else
		for(int i=0; i<lunghezza; i++)
			fprintf(fp, "%d", sequenza[i]);

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
			printf(" Ogni tripla di interi consecutivi nella sequenza e' tale che il minimo tra i tre interi e' dispari!\n");
		else
			printf(" Non ogni tripla di interi consecutivi nella sequenza e' tale che il minimo tra i tre interi e' dispari! \n");

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
			printf(" Ogni tripla di interi consecutivi nella sequenza e' tale che il minimo tra i tre interi e' dispari! \n");
		else
			printf(" Non ogni tripla di interi consecutivi nella sequenza e' tale che il minimo tra i tre interi e' dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}