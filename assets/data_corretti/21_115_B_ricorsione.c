/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.1
2pt leggi numeri:....1.6
TOTALE ..............6.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int res;
	if(lunghezza<3)
		res = 1;
	else {                //**** seq[0]
		res = ((seq[0]<seq[1] && seq[1]<seq[2] && seq[0]%2!=0) ||
		                  //**** seq[1]
				(seq[1]<seq[0] && seq[0]<seq[2] && seq[1]%2!=0) ||
				          //**** seq[2]
	//**** COME CALCOLI LA CONDIZIONE! In questo modo dovresti provare tutte le possibili combinazioni!
	//**** se hai [1,7,4] non funziona! -1.5
				(seq[2]<seq[1] && seq[1]<seq[0] && seq[2]%2!=0) && minimoDispari(seq+1,lunghezza-1));
	}
	return res;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti;         //**** il contatore non è inizializzato -0.5
	FILE* fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("Impossibile aprire il file\n\n");
	else {
		int numero;
		while(fread(&numero, sizeof(INT), 1, fp)>0) //**** sizeof(int) -0.2
			quanti++;
	}      //**** non chiudi il file -0.2
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("Impossibile aprire il file\n\n");
	else {
		for(int i=0; i<lunghezza; i++) {
			fread(&sequenza[i], sizeof(INT), 1, fp);//**** sizeof(int) -0.2
		}
	}//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "wb");
	if(fp==NULL)
		printf("Salvataggio non riuscito");
	else {
		for(int i=0; i<lunghezza; i++)
			fwrite(&sequenza, sizeof(INT), 1, fp); //**** &sequenza[i] -0.3
	}
	fclose(fp);
	printf("Salvataggio eseguito\n\n");
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
			printf("Non ogni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");

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
			printf("Ogni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("Non ogni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}