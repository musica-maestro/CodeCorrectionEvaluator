/*
5pt minimo dispari:..1.5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............6.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int ris;
	int verifica;

	//***** prima calcoli il minimo e poi vedi se ci sono elementi a sufficienza? -2
	if(seq[0] <= seq[1] && seq[0] <= seq[2]){
		if(seq[0] % 2 == 1)
			verifica = 1;
	}

	if(seq[1] <= seq[0] && seq[1] <= seq[2]){
		if(seq[1] % 2 == 1)
		verifica = 1;
	}

	if(seq[2] <= seq[0] && seq[2] <= seq[1]){
		if(seq[2] % 2 == 1)
			verifica = 1;
	}

	if(lunghezza == 0) //****** e che succede se lunghezza =1 o 2? -1.5
		ris = 1;
	else{
		ris = verifica && minimoDispari(seq+1, lunghezza-1);
	}
	return ris;
}

/* funzione che conta ... */
int quantiNumeri() {
	int count = 0;
	FILE *fp = fopen("interi.dat", "rb");

	if(fp == NULL)
		printf("File non aperto o inesistente\n\n");
	else{
		int num;
		while(fread(&num, sizeof(int), 1, fp) > 0)
			count++;

		fclose(fp);
	}

	return count;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");

	if(fp == NULL)
		printf("File non aperto o inesistente\n\n");
	else{
		fread(sequenza, sizeof(int), lunghezza, fp);

		printf("Deti recuperati\n\n");
		fclose(fp);
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");

	if(fp == NULL)
		printf("File non aperto o inesistente\n\n");
	else{
		fwrite(sequenza, sizeof(int), lunghezza, fp);

		printf("Salvataggio riuscito\n\n");
		fclose(fp);
	}

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
			printf("Ogni valore minimo nelle triple di elementi adiacenti e' dispari \n");
		else
			printf("Almeno un valore minimo nelle triple di elementi adiacenti non e' dispari \n");;

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
			printf("Ogni valore minimo nelle triple di elementi adiacenti e' dispari \n");
		else
			printf("Almeno un valore minimo nelle triple di elementi adiacenti non e' dispari \n");;

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}