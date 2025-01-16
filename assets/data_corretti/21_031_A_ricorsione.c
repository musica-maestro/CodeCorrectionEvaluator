/*
5pt massimo pari:..3.5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............8.5
*/
#include <stdio.h>
#include <stdlib.h>

int massimo(int n1, int n2, int n3){ //funzione che calcola il massimo fra tre interi
	int max=n1;
	if(n2>n1)  		//**** sabgliato!
		max=n2;     //**** es. n1=4, n2=5, n3=6 => max=5  -1.5
	else
		if(n3>n1)
			max=n3;
	return max;
}

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int verificato; //variabile booleana da restituire per la verifica
	if(lunghezza<3) //CASO BASE
		verificato=1;
	else{ //PASSO RICORSIVO
		int nMax=massimo(seq[0], seq[1], seq[2]); //inizializziamo il nuovo massimo
		verificato=(nMax%2==0) && massimoPari(seq+1, lunghezza-1); //ricorriamo sulla sequenza di interi
	}
	return verificato; //restituiamo la variabile booleana
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0; //contatore da restituire
	int numero; //variabile per memorizzare il dato letto da file
	FILE *fp=fopen("interi.dat", "rb"); //apriamo il file in lettura
	if(fp==NULL) //inseriamo il controllo per l'apertura corretta del file
		printf("Apertura del file avvenuta con errore!\n");
	else{
		while(fread(&numero, sizeof(int), 1, fp)>0)
			quanti++; //incrementiamo la variabile finch èci sono dati da leggere
	}
	fclose(fp); //chiudiamo il file
	return quanti; //restituiamo la variabile, che sarà la lunghezza della sequenza
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat", "rb"); //apriamo il file in lettura
	if(fp==NULL) //inseriamo il controllo per l'apertura corretta del file
		printf("Apertura del file avvenuta con errore!\n");
	else
		fread(sequenza, sizeof(int), lunghezza, fp); //leggiamo la sequenza di interi dal file, memorizzandola nella sequenza
	fclose(fp); //chiudiamo il file
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat", "wb"); //apriamo il file il scrittura
	fwrite(sequenza, sizeof(int), lunghezza, fp); //scriviamo la sequenza di interi sul file
	fclose(fp); //chiudiamo il file3
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
			printf("Ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari!\n", 138, 138);
		else
			printf("NON ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari!\n", 138, 138);

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
			printf("Ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari!\n", 138, 138);
		else
			printf("NON ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari!\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}