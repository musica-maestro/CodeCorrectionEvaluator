/*
5pt massimo pari:..5
1pt scrivi numeri:.0.6
2pt quanti numeri:.0.5
2pt leggi numeri:..1.6
TOTALE ............7.7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se ogni tripla di interi consecutivi
 * nella sequenza è tale che il massimo fra i tre interi è pari */
int massimoPari(int *seq, int lunghezza){
	int pari;

	if(lunghezza < 3)
		pari = 1;
	else {
		pari = ((seq[0]>seq[1] && seq[0]>seq[2] && seq[0]%2 == 0) || (seq[1]>seq[0] && seq[1]>seq[2] && seq[1]%2 == 0) ||
				(seq[2]>seq[1] && seq[2]>seq[0] && seq[2]%2 == 0)) && massimoPari(seq+1, lunghezza-1);
	}

	return pari;
}

/* funzione che conta quanti numeri interi sono memorizzati su un file */
int quantiNumeri() {
	FILE* fp = fopen("interi.txt", "r");
	int quanti = 0;

	if(fp == NULL)
		printf("Non sono stati memorizzati interi sul file o non si riesce ad accedere al file!\n\n");
	else
		//**** manca la parte di conteggio! -1
	fclose(fp);
	//**** manca il return! -0.5
}

/* funzione che legge una sequenza di interi da un file e li memorizza su un array che è ricevuto come parametro */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "r");

	if(fp == NULL)
		printf("Non %c possibile accedere al file o non sono stati memorizzati numeri nel file!\n\n", 138);
	else
		fread(sequenza, sizeof(int), lunghezza, fp);
//***** fread si usa per file binari, non per file di testo -0.3
		printf("Interi memorizzati correttamente!\n\n");//**** questa deve far parte dell'else -0.2

	fclose(fp);
}

/* funzione che scrive i valori di un array di interi su di un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "r");

	if(fp == NULL)
		printf("Non %c possibile aprire il file!\n\n", 138);
	else
		fwrite(sequenza, sizeof(int), lunghezza, fp);
//***** fwrite si usa per file binari, non per file di testo -0.3
		printf("Valori scritti sul file!\n\n"); //**** questa deve far parte dell'else -0.2

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
			printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari\n", 138, 138);
		else
			printf("Non ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari\n", 138, 138);

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
			printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari\n", 138, 138);
		else
			printf("Non ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}