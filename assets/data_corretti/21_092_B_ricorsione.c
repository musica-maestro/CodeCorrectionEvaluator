/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>

/* In questa funzione non è necessario passare la lunghezza della sequenza perché
 * è invocata solo se esistono almeno tre elementi da confrontare */
int condizione(int* seq){
	int minimo=seq[0];
	for(int i=1;i<3;i++){
		if(seq[i]<minimo)
			minimo=seq[i];
	}
	return minimo%2;
}

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int ris = 1;
	if(lunghezza>=3){
		ris = condizione(seq) && minimoDispari(seq+1, lunghezza-1);
	}
	return ris;
}

/* funzione che conta ... */
int quantiNumeri() {
	int letti=0;
	FILE* fp = fopen("interi.dat","rb");
	if(fp==NULL){
		printf("Errore di lettura!\n\n");
	} else {
		int numero;
		while(fread(&numero, sizeof(int), 1, fp)>0)
			letti++;
		fclose(fp);
		printf("Numeri contati!\n\n");
	}
	return letti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat","rb");
	if(fp==NULL){
		printf("Errore di lettura!\n\n");
	} else {
		int i=0;
		while(fread(sequenza+i, sizeof(int), 1, fp)>0)
			i++;
		fclose(fp);
		printf("Numeri letti!\n\n");
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat","wb");
	if(fp==NULL){
		printf("Errore di scrittura!\n");
	} else {
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);
		printf("Scrittura completata!\n");
	}
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);
	printf("\n");

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		do {
			printf("Introduci la lunghezza della sequenza: ");
			scanf("%d",&lunghezza);
			if(lunghezza<3)
				printf("La lunghezza deve essere di almeno tre elementi!\n");
		} while(lunghezza<3);
		printf("\n");
		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);
		printf("\n");
		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Tutte le triple hanno come minimo un numero dispari!!\n\n");
		else
			printf("NON Tutte le triple hanno come minimo un numero dispari!\n\n");

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
		printf("\n\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Tutte le triple hanno come minimo un numero dispari!!\n\n");
		else
			printf("NON Tutte le triple hanno come minimo un numero dispari!\n\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
