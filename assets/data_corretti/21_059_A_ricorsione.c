/*
5pt massimo pari:..3
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............3
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int ver;
	if(lunghezza<=2)
		ver=0;   //**** variabile di universalità inizializzata male -1
	else{
		ver=((massimoPariRic(seq[lunghezza-1],seq[lunghezza-2],sequenza[lunghezza-3])%2==0)
		&&massimoPari(seq,lunghezza-1));
		}
	}
int massimoPariRic(int num1,int num2,int num3){  //**** calcolo del massimo  mancante -1
	int massimo;

	}

/* funzione che conta ... */
int quantiNumeri(File*fp) {
	int num=0;
//	num=(fp[num])+quantiNumeri(fp);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {



}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	int i=0;
	while(sequenza[i])



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
			printf("caso verificato \n");
			printf("ogni tripla di interi consecutivi nella sequenza e' tale che il massimo fra i tre interi e' pari \n");
		else{
			printf("caso non verificato \n");
			printf("non ogni tripla di interi consecutivi nella sequenza e' tale che il massimo fra i tre interi e' pari \n");
			}

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		FILE*fp=fopen("fileInteri.txt","wb");
		lunghezza = quantiNumeri(fp);

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf("caso verificato \n");
			printf("ogni tripla di interi consecutivi nella sequenza e' tale che il massimo fra i tre interi e' pari \n");
		else
			printf("caso non verificato \n");
			printf("non ogni tripla di interi consecutivi nella sequenza e' tale che il massimo fra i tre interi e' pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
