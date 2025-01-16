/*
5pt minimo dispari:..3
1pt scrivi numeri:...0.2
2pt quanti numeri:...0
2pt leggi numeri:....1.5
TOTALE ..............4.7
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che controlla qual Ã¨ il minimo della tripla*/
int min(int *seq){
	int min;

		if(seq[0]<seq[1] && seq[0]<seq[2]){
			seq[0]=min;
		}else if(seq[1]<seq[0] && seq[1]<seq[2]){
					seq[1]=min;
		}else if(seq[2]<seq[0] && seq[2]<seq[3]){
					seq[2]=min;   //**** seq[1] -0.2
		}return min;
}

/* funzione ricorsiva che verifica il minimo*/
int minimoDispari(int *seq, int lunghezza){
	int ris;
	if(lunghezza<=1){
	//**** PB non corretto: <=2 (perché devi considerare una terna di elementi) -0.5
		ris=1;
	}else{
		ris=((min(seq)%2!=0) && minimoDispari(seq, lunghezza-1));
	}   //**** se per il calcolo del minimo passi seq e prendi i primi 3 elementi di seq,
		//**** richiamando la funzione ricorsiva senza l'ultimo valore, ti ritrovi a calcolare
		//**** il minimo sempre sui primi tre elementi dell'array! -1.5
	return ris;
}

/* funzione che conta quanti sono i numeri presenti nel file*/
int quantiNumeri() {
	FILE* fp=fopen("interi.dat","rb");


	fclose(fp);
}

/* funzione che legge i numeri presenti nel file */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","rb");
	//**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5
	fread(sequenza, sizeof(int), lunghezza, fp);
	fclose(fp);
}

/* funzione che scrive i numeri nel file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","wb");
	//**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5
	fwrite(sequenza, sizeof(int), 1, fp); //**** non 1, ma lunghezza -0.3
	fclose(fp);
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
	printf("questo e' un programma che verifica se\n in un array di numeri interi ogni tripla di interi consecutivi nella sequenza\n e' tale che il minimo fra i tre interi e' dispari.");
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
			printf("la sequenza verifica la condizione\n");
		else
			printf("la sequenza non verifica la condizione\n");

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
			printf("la sequenza verifica la condizione\n");
		else
			printf("la sequenza non verifica la condizione\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}