/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>


/* funzione ausiliaria per calcolare il minimo */

int minimo(int *s){
	int minimo;
	if(s[0]<=s[1] && s[0]<=s[2]){
		minimo = s[0];
	}
	else if(s[1]<=s[0] && s[1]<=s[2])
		minimo = s[1];
	else
		minimo = s[2];

	return minimo;
}

/* funzione ricorsiva che verifica se ogni tripla di interi consecutivi è tale che il minimo tra i tre è dispari */
int minimoDispari(int *seq, int lunghezza){
	//pre: lunghhezza>3
	//verifica universale
	int result;							//variabile da restituire
	/* caso base */
	if(lunghezza<3)
		result = 1;
	/* passo ricorsivo */
	else
		//se il minimo dela tripla è dispari restituisco 1 e vado a fare una chiamata ricorsiva per il resto della sequenza
		result = (minimo(seq)%2!=0) && minimoDispari(seq+1, lunghezza-1);
	return result;
}

/* funzione che conta quanti interi ci sono nel file */
int quantiNumeri() {
	//inizializzazione puntatore a file
	FILE *fp = fopen("minimoDispari.txt", "r");

	int conteggio=0;						//variabile contatore

	//controllo se il file è stato aperto correttamente
	if(fp==NULL)
		printf("Apertura file non riuscita!\n\n");
	else{
		//variabile temporanea dove inserisco il valore letto
		int temp;
		//scorro il file fino a che non finisce
		while(fscanf(fp, "%d ", &temp)!=EOF)
			conteggio++;
	}
	//chiudo il file
	fclose(fp);
	return conteggio;
}

/* funzione che legge la sequenza dal file */
void leggiNumeri(int* sequenza, int lunghezza) {
	//inizializzazione puntatore a file
	FILE *fp = fopen("minimoDispari.txt", "r");

	//controllo se il file è stato aperto correttamente
	if(fp==NULL)
		printf("Apertura file non riuscita!\n\n");
	else{
		//scorro il file fino a che non finisco di acquisire valori
		for(int i=0; i<lunghezza; i++)
			//salvo il contenuto nella mia sequenza
			fscanf(fp, "%d", &sequenza[i]);
	}
	//chiudo il file
	fclose(fp);

	//stampa trionfale
	printf("Acquisizione effettuata!\n\n");
}

/* funzione che scrive la sequenza inserita su un file */
void scriviNumeri(int* sequenza, int lunghezza) {

	//inizializzazione puntatore a file
	FILE *fp = fopen("minimoDispari.txt", "w");

	//controllo se il file è stato aperto correttamente
	if(fp==NULL)
		printf("Apertura file non riuscita!\n\n");
	else{
		//scorro la sequenza fino al penultimo elemento
		for(int i=0; i<lunghezza-1; i++)
			fprintf(fp, "%d ", sequenza[i]);
		//acquisisco lìultimo elemento e poi stampo uno \n per andare a capo
		fprintf(fp, "%d\n", sequenza[lunghezza-1]);
	}
	//fclose per assicurarmi il salvataggio
	fclose(fp);
	printf("Salvataggio su file effettuato!\n\n");
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
			printf("La sequenza soddisfa la condizione!\n");
		else
			printf("La sequenza NON soddisfa la condizione!\n");

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
			printf("La sequenza soddisfa la condizione!\n");
		else
			printf("La NON sequenza soddisfa la condizione!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	return 0;
}