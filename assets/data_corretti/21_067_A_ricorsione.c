/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.2
2pt leggi numeri:..2
TOTALE ............9.2
*/
#include <stdio.h>
#include <stdlib.h>

int trovamassimo(int a, int b, int c) {
	int massimo;
	if(a>b) {
		if(a>c)
			massimo=a; //se a è maggiore di b e c è il massimo
		else
			massimo=c; //se c è maggiore di a, sapendo che a è maggiore di b, c è il massimo
	}
	else {
		if(b>c)
			massimo=b; //se b è maggiore di a e c è il massimo
		else
			massimo=c; //se c è maggiore di b, sapendo che b è maggiore di a, c è il massimo
	}
	return massimo;
}

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int verita;
	if(lunghezza<=2)
		verita=1; //sono stati esaminati tutti gli elementi della sequenza, e la proprietà è sempre verificata
	else {
		int massimo=trovamassimo(seq[0], seq[1], seq[2]); //variabile che esprime il massimo tra i tre valori dell'array
		if(massimo%2==0)
			verita=1&&massimoPari(seq+1, lunghezza-1); //se la proprietà è verificata, si passa ad analizzare gli altri elementi della sequenza
		else
			verita=0; //non c'è bisogno di andare avanti, perchè la proprietà non è verificata per una tripla della sequenza
	}
	return verita; //si restituisce il valore di verità
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp=fopen("interi.dat", "rb"); //apertura del file
	int numero; //
	int lunghezza; //**** il contatore non è inizializzato -0.5
	if(fp!=NULL) {
		while(fread(&numero, sizeof(int), 1, fp)) //finchè ci sono numeri all'interno del file, si va avanti
			lunghezza++; //per ogni numero all'interno del file si incrementa la lunghezza di 1;
	}
	else //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
		lunghezza=0; //se non ci sono valori all'interno del file, la lunghezza è 0
	fclose(fp); //chiusura del file
	return lunghezza; //si restituisce la lunghezza
}

/* funzione che legge un array da un file */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat", "rb"); //apertura del file
	if(fp!=NULL) {
		fread(sequenza, sizeof(int), lunghezza, fp); //visto che si conosce la lunghezza del file, si leggono tutti i valori al suo interno in una volta
		fclose(fp); //chiusura del file
	}
	else
		printf("Impossibile aprire il file\n");
}

/* funzione che scrive i valori dell'array all'interno di un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat", "wb");
	if(fp!=NULL) {
		fwrite(sequenza, sizeof(int), lunghezza, fp); //visto che si conosce la lunghezza del file, si scrivono tutti i valori al suo interno in una volta
		fclose(fp); //chiusura del file
	}
	else
		printf("Impossibile aprire il file\n");
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
			printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo tra i tre interi %c pari\n", 138, 138);
		else
			printf("NON in tutte le triple di interi consecutive nella sequenza il massimo tra i tre interi %c pari\n", 138);

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
			printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo tra i tre interi %c pari\n", 138, 138);
		else
			printf("NON in tutte le triple di interi consecutive nella sequenza il massimo tra i tre interi %c pari\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
