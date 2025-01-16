/*
5pt massimo pari:..5
1pt scrivi numeri:.0.7
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............9.7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione che verifica il massimo fra tre numeri*/
int trovaMassimo(int * array,int n){
	int max = array[n-1];  // variabile max che rappresenta il massimo della tripla che inizialmente è pari al primo elemento della tripla
	if(n>=3){ // verifico se ci sono minimo 3 elementi nell'array
	/* confronto max con il secondo e il terzo elemento dell'array per vedere chi è il massimo*/
		if(max < array[n-2]){
			max = array[n-2];
		}else if(max < array[n-3]){
			max = array[n-3];
		}
	}else{
		printf("Array troppo piccolo, deve avere minimo 3 elementi\n");
	}
	return max;
}

/* funzione ricorsiva che verifica se per ogni tripla in un array il numero massimo è pari*/
int massimoPari(int *seq, int lunghezza){
	int verificato = 0; // variabile verificato che e' pari a 1 se la propietà è verificata
	if(lunghezza >= 3){// verifico se ci sono minimo 3 elementi nell'array
		if(lunghezza == 3){ // CASO BASE  verifica se la propietà vale per il primo,secondo e terzo elemento dell'array
			verificato = (trovaMassimo(seq,3)) % 2 ==0;
		}else{ // PASSSO RICORSIVO
			verificato = ((trovaMassimo(seq,lunghezza)) % 2 == 0) && massimoPari(seq,lunghezza-1); // verifica se la proprietà vale per la tripla corrente e se vale anche per le successive
		}
	}else{
		printf("Array troppo piccolo, deve avere minimo 3 elementi\n");
	}
	return verificato;
}

/* funzione che conta quanti interi ci sono in un file */
int quantiNumeri() {
	FILE *fp = fopen("interi.txt","r"); // inzializzo il puntatore allo stream del file di testo
	int cont=0,temp=0;// inzializzao una variabile contatore e una di appoggio
	if( fp != NULL){ // verifico se il file esiste , dunque se il puntatore al suo stream è diverso da NULL
		while(fscanf(fp,"%d",&temp)>0) // legge da file fino a che non arriva a l'EOF
			cont ++;
	}else{
		printf(" file non esiste\n");
	}
	fclose(fp); // salvo le modifiche fatt odeallocando puntatore
	return cont;
}

/* funzione che legge un array da un file */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.txt","r");// inzializzo il puntatore allo stream del file di testo
	int intero = 0, i=0; // variabile i è il contatore che scorre l'array, variabile intero memoriza l'intero da mettere nell'array
	if( fp != NULL){ // verifico se il file esiste , dunque se il puntatore al suo stream è diverso da NULL
		while(fscanf(fp,"%d",&intero)>0 && i<lunghezza){ // legge dal file fino a che fscanf non ritorna 0, ovvero non trova più elementi nel txt; o fino a che i non >= lunghezza
			sequenza[i] = intero; // inserisco l'intero letto nell'array
			i++; // incremento i
		}
	}else{
		printf("File non esiste\n");
	}
	fclose(fp); // salvo le modifiche fatt odeallocando puntatore
}

/* funzione che scrive un array su un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.txt","w"); // inizializzo puntatore allo stream del file
	/* scrivo gli interi nel file .txt*/
	for (int i = 0; i<lunghezza;i++){
		fprintf(fp,"%d\n",sequenza[i]); // scrivo l'iesimo elemento sul file
	}
	fclose(fp); // salvo le modifiche fatt odeallocando puntatore    //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
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
			printf(" per ogni tripla nell'array il massimo e' pari\n");
		else
			printf(" non per tutte le triple nell'array il massimo e' pari\n");

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
			printf(" per ogni tripla nell'array il massimo e' pari\n");
		else
			printf(" non per tutte le triple nell'array il massimo e' pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
