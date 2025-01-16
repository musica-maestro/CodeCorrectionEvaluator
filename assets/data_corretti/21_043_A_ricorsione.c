/*
5pt massimo pari:..5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.8
TOTALE ............9.4
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica che in un array di interi ogni tripla di interi consecutivi e' tale che il massimo tra i tre e' pari. La funzione restituisce 1 se tale condizione e' verificata, 0 altrimenti
 * questa funzione ricorsiva svolge una verifica universale*/
int massimoPari(int *seq, int lunghezza){
	int tutte; //variabile booleana di universalita'
	/*CASO BASE*/
	if (lunghezza<3){ //se non ci sono triple la condizione e' verificata
		tutte = 1;
	}
	/*PASSO RICORSIVO*/
	else{
		tutte = (((seq[0]>seq[1] && seq[0]>seq[2] && seq[0]%2==0)
		|| (seq[1]>seq[0] && seq[1]>seq[2] && seq[1]%2==0)
		|| (seq[2]>seq[0] && seq[2]>seq[1] && seq[2]%2==0)) && (massimoPari(seq+1, lunghezza-1)));
	}
	return tutte;
}

/* funzione che conta quanti interi ci sono in un file binario e ne restituisce il numero */
int quantiNumeri() {
	int quanti = 0;
	int n;

	FILE *fp = fopen("array.dat", "rb"); //apro il file binario in lettura

	if(fp==NULL){ //se non riesco ad aprire il file
		printf("IMPOSSIBILE APRIRE IL FILE\n\n");
	}
	else{ //se riesco ad aprire il file
		while(fread(&n, sizeof(int), 1, fp)>0){ //finche' riesco a leggere un intero dal file binario
			quanti++; //aumento quanti
		}
	}
	return quanti;  //**** non chiudi il file -0.2
}

/* funzione che riceve come parametro un puntatore ad una sequenza di interi e la sua lunghezza e legge il contenuto di un file binario e lo acquisisce all'interno di un array di interi */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("array.dat", "rb"); //apro il file binario in lettura

	if(fp==NULL){ //se non riesco ad aprire il file
		printf("IMPOSSIBILE APRIRE IL FILE\n\n");
	}
	else{ //se riesco ad aprire il file
		fread(sequenza, sizeof(int), lunghezza, fp); //leggo da file e memorizzo in 'sequenza'
	}
}//**** non chiudi il file -0.2

/* funzione che riceve come parametro un puntatore ad una sequenza di interi e la sua lunghezzas e scrive una sequenza acquisita da input in un file binario */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("array.dat", "wb"); //apro il file binario in scrittura

	if(fp==NULL){ //se non riesco ad aprire il file
		printf("IMPOSSIBILE APRIRE IL FILE\n\n");
	}
	else{ //se riesco ad aprire il file
		fwrite(sequenza, sizeof(int), lunghezza, fp);
	}
	printf("SALVATAGGIO EFFETTUATO!!\n\n");
}//**** non chiudi il file -0.2

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
			printf("Tutte le triple della sequenza sono tali che il massimo tra i tre %c pari\n", 138);
		else
			printf("Esiste almeno una tripla nella sequenza che non rispetta la condizione, ovvero il massimo tra i tre non %c pari\n", 138);

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
			printf("Tutte le triple della sequenza sono tali che il massimo tra i tre %c pari\n", 138);
		else
			printf("Esiste almeno una tripla nella sequenza che non rispetta la condizione, ovvero il massimo tra i tre non %c pari\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}