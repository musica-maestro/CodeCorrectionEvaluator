/*
5pt minimo dispari:..2.8
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............7.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione per trovare il minimo tra tre interi */
int minimo (int primo, int secondo, int terzo) {
	int minimo;

	if (primo<=secondo && primo<=terzo)
		minimo = primo;
	else
		if (secondo<=terzo)
			minimo = secondo;
		else
			minimo = terzo;

	return minimo;
}


/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int risposta = 1;         //valore booleano. vale 1 se la richiesta della funzione Ã¨ verificata, 0 altrimenti


	/* caso base */
	if (lunghezza==3)//**** se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
		risposta = (minimo(seq[0], seq[1], seq[2]))%2;
		//**** lunghezza==3 fa parte del passo ricorsivo.
		//**** Così devi ripetere 2 volte la verifica della condizione "minimo tra 3". -0.2
	if else (lunghezza > 3) {  //**** SINTASSI! -1
		/* caso ricorsivo */
		risposta = ((minimo(seq[lunghezza-1], seq[lunghezza-2], seq[lunghezza-3]))%2) && minimoDispari(seq, lumghezza-1);
		}
	}
	return risposta;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("interi.dat", "rb");

	if (fp == NULL)
		printf("\nApertura del file non riuscita :(\n");
	else {
		int contatore = 0;    //per contare quanti interi ci sono

		int intero;

		while (fread(&intero, sizeof(int), 1, fp)) {
			contatore++;
		}
		fclose(fp);
		return contatore;
	}
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "rb");

	if (fp == NULL)
		printf("\nApertura del file non riuscita\n")
	else {
		for (int i=0; i<quantiNumeri(); i++) {
			fread(&sequenza[i], sizeof(int), 1, fp);
		}
		fclose(fp);
		printf("\nElementi acquisiti!\n");
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "wb");

	for (int i=0; i<lunghezza; i++) {
		fwrite(&sequenza[i], sizeof(int), 1, fp);
	}
	fclose(fp);
	printf("\nElementi salvati!\n");
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
		if(minimoDispari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}