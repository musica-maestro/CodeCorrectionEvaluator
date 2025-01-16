/*
5pt massimo pari:..3
1pt scrivi numeri:.0
2pt quanti numeri:.0.2
2pt leggi numeri:..1.2
TOTALE ............4.4
*/
/*Dato un array di n interi, il programma determina a ogni tripla il numero massimo e
se esso è pari */
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in una tripla nell'array passato */
int massimoPari(int *seq, int lunghezza){  //*** deve essere verificata da TUTTE le triple -2
	int ris;
	if(lunghezza<3){   //caso base: se la lunghezza è inferiore a 3 viene restituito 0;
		ris=0;
	}
	else{
		int max=trovaMassimo(seq[lunghezza-1],seq[lunghezza-2],seq[lunghezza-3]);
		ris=(max%2==0) || massimoPari(seq,lunghezza-1); //si cerca il numero nella tripla che soddisfa la richiesta
	}
	return ris;
}

//**** se dichiari una funzione dopo averla richiamata, devi dichiarare la sua segnatura all'inizio -0.3
/*funzione che verifica quale è il numero maggiore dati 3 numeri passati come parametro*/
int trovaMassimo(int n1, int n2, int n3){
	if(n1>n2 && n1>n3){
		return n1;
	}
	else if(n2>n1 && n2>n3){
		return n2;
	}
	else if(n3>n1 && n3>n2){
		return n3;
	}
	else{
		return n1;
	}
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp=fopen("interi.txt","r");
	int n;
	int letto;
	if(fp!=NULL){
		letto=fp;
		if(letto!=NULL){ //*** letto è un intero, non un puntatore -0.5
			for(){

			}//**** manca la parte del conteggio! -1
		}
		else{
			printf("Non ci sono dati presenti nel file \n");
		}
	}//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fclose(fp);
}

/* funzione che legge i numeri salvati su di un file binario
 * interi.dat e li memorizza su un array che è ricevuto come parametro*/
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.txt","r");
	int n;
	int letto;
	if(fp!=NULL){
		letto=fp;
		if(letto!=NULL){ //*** letto è un intero, non un puntatore -0.5
			for(int i=0;i<lunghezza;i++){
				sequenza[i]=fread(fp,sizeof(int),1,n); //***** fread si usa per file binari, non per file di testo -0.2
			}
		}
		else{
			printf("Non ci sono dati presenti nel file \n"); //**** questo else si deve riferire all'if precedente: indentato male -0.1
		}
	}
	fclose(fp);
}

/* funzione che scrive i numeri della sequenza in un file binario*/
void scriviNumeri(int* sequenza, int lunghezza) {
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
		if(massimoPari(array,lunghezza)==1)
			printf(" Vi %c una tripla che soddisfa la condizione\n",138);
		else
			printf(" Non vi %c una tripla che soddisfa la condizione\n",138);

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}