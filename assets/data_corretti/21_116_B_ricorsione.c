/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.7
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............9.7
*/
/*ricorsione*/

#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica la condizione */
int minimo(int a, int b, int c){
	int min;
	if(a<=b && a<=c)
		min= a;
	else{
		if(b<=a && b<=c)
			min= b;
		else
			min= c;
	}
	return min;
}

int minimoDispari(int *seq, int lunghezza){
	int verifica;
	if(lunghezza<3)
		verifica=1;
	else
		verifica= (minimo(seq[0], seq[1], seq[2])%2!=0) && minimoDispari(seq+1, lunghezza-1);
	return verifica;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;
	FILE*fp= fopen("interi.txt","r");
	if(fp==NULL)
		puts("lista vuota");
	else{
		int app;
		while(fscanf(fp, "%d", &app)!=EOF)
			quanti++;
		printf("ci sono %d interi\n", quanti);
		puts("quantiNumeri eseguita\n\n");
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fp= fopen("interi.txt","r");
	if(fp==NULL)
		puts("lista vuota");
	else{
		for(int i=0; i<lunghezza; i++)
			fscanf(fp, "%d", &sequenza[i]);
		puts("leggiNumeri eseguita\n\n");
		fclose(fp);
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp= fopen("interi.txt","w"); //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i=0; i<lunghezza; i++)
		fprintf(fp, "%d ", sequenza[i]);
	puts("scriviNumeri eseguita\n\n");
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
			printf(" la condizione e' verificata \n");
		else
			printf(" la condizione non e' verificata \n");

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
			printf(" la condizione e' verificata \n");
		else
			printf(" la condizione non e' verificata \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
