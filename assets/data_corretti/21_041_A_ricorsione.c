/*
5pt massimo pari:..5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.8
TOTALE ............9.4
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che calcola il massimo tra 3 elementi consecutivi di una sequenza*/
int CalcoloMax(int *seq){
	int max;

	max=seq[0]; //inizializzazione variabile max

	/*si determina il valore max tra i 3 elementi*/
		if(seq[1] > max && seq[1] > seq[2])
			max=seq[1];
		else{
			if(seq[2] > max && seq[2] > seq[1])
				max=seq[2];
		}

	/*la funzione restituisce il valore max trovato*/
	return max;
}

/* funzione ricorsiva che verifica se, in un array di numeri interi, ogni tripla di interi consecutivi nella sequenza è tale che il
massimo tra tre interi è pari  precondizione:lunghezza>=3*/
int massimoPari(int *seq, int lunghezza){
	int verificato; //variabile esistenza

	/*CASO BASE*/
	if(lunghezza<3)
		verificato = 1;

	/*PASSO RICORSIVO*/
	else verificato = CalcoloMax(seq) % 2 == 0 && massimoPari(seq+1,lunghezza-1);


	/*OUTPUT FUNZIONE*/
	return verificato;
}

/* funzione che conta quanti numeri sono contenuti nel file */
int quantiNumeri() {
	int conteggio = 0; //variabile conteggio numeri
	int intero; //variabile di appoggio

	/*Apertura File*/
	FILE *fp = fopen("interi.dat","rb");

	/*se l'apertura del file dà errore*/
	if(fp==NULL)
		printf("Errore di apertura del file \n");

	else{
		/*altrimenti aumenta il conteggio fino a che non ci sono più numeri*/
		while(fread(&intero,sizeof(int),1,fp) > 0)
			conteggio++;
	}

	/*la funzione restituisce il numero di interi dentro al file*/
	return conteggio;//**** non chiudi il file -0.2
}

/* funzione che legge i numeri contenuti dentro un file e li salva nella sequenza */
void leggiNumeri(int* sequenza, int lunghezza) {

	/*apertura file*/
	FILE *fp = fopen("interi.dat","rb");

	/*errore nell'apertura?*/
	if(fp==NULL)
		printf("Errore di apertura file \n");

	else{
		/*sappiamo il numeri di elementi dentro al file e la lunghezza della sequenza, quindi si salvano tutti insieme*/
		fread(sequenza,sizeof(int),lunghezza,fp);
	}
}//**** non chiudi il file -0.2

/* funzione che scrive dentro al file i numeri contenuti dentro una sequenza */
void scriviNumeri(int* sequenza, int lunghezza) {

	/*Apertura File*/
	FILE *fp = fopen("interi.dat","wb");

	/*Errore di apertura?*/
	if(fp==NULL)
		printf("Errore apertura file \n");

	else{
		/*prende tutti i numeri dell'array e li salva nel file*/
		fwrite(sequenza,sizeof(int),lunghezza,fp);
	}
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
			printf("Ogni elemento massimo in ogni tripla della sequenza e' pari \n");
		else
			printf("non tutti gli elementi massimi di ogni tripla contenuta nella sequenza sono pari \n");

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
			printf("Ogni elemento massimo in ogni tripla della sequenza e' pari \n");
		else
			printf("non tutti gli elementi massimi di ogni tripla contenuta nella sequenza sono pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
