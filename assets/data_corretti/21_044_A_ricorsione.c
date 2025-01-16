/*
5pt massimo pari:..4.8
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............9.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se il massimo in una tripla è pari*/
int massimo(int n1, int n2, int n3){
	int max = n1;
	if (max < n2){					//verifiche per trovare il massimo
		max = n2;
		if (max < n3)
			max = n3;  //**** poteva essere scritta meglio: per due volte scrivi max=n3 -0.2
	}
	else{
		if (max < n3)
			max = n3;
	}
	return max;						//ritorno il massimo
}

int massimoPari(int *seq, int lunghezza){
	int tutte;
	if (lunghezza < 3)		//CASO BASE
		tutte = 1;
	else{					//PASSO RICORSIVO
		int max = massimo (seq[0], seq[1], seq[2]);					//trovo il massimo nella tripla tramite una funzione massimo
		tutte = (max % 2 == 0) && massimoPari(seq+1, lunghezza-1);	//condizione se massimo è pari e ricorsione
	}
	return tutte;													//ritorno il risultato
}

/* funzione che conta quanti sono i numeri salvati su file */
int quantiNumeri() {
	int conta = 0;												//variabile contatore
	FILE *fp = fopen("interi.dat", "rb");						//apro file binario in lettura
	if (fp == NULL)
		printf("Apertura file non riuscita.\n");				//problemi in apertura
	else{
		int n;													//variabile ausiliare per la funzione fread
		while (fread(&n, sizeof(int), 1, fp)>0)					//fino a che posso leggere un intero, incremento conta
			conta++;
		fclose(fp);												///chiudo file
	}
	return conta;												//ritorno il numero di interi contati su file
}


/* funzione che legge in numeri dell'array su file*/
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");					//apro file binario in lettura
	if (fp == NULL)
		printf("Apertura file non riuscita.\n");			//problemi in apertura
	else{
		fread(sequenza, sizeof(int), lunghezza, fp);		//leggo su file gli interi della sequenza
		fclose(fp);											//chiudo file
	}
}

/* funzione che scrive i numeri dell'array su file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");					//apro file binario in scrittura
	if (fp == NULL)
		printf("Apertura file non riuscita.\n");			//problemi in apertura
	else{
		fwrite(sequenza, sizeof(int), lunghezza, fp);		//scrivo su file gli interi della sequenza
		fclose(fp);											//chiudo file
	}
}

/* funzione principale */
int main() {
    int lunghezza; 			//	lunghezza dell'array
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
			printf("In tutte le triple il massimo numero %c pari.\n", 138);
		else
			printf("Non in tutte le triple il massimo numero %c pari.\n", 138);

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
			printf("In tutte le triple il massimo numero %c pari.\n", 138);
		else
			printf("Non in tutte le triple il massimo numero %c pari.\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}