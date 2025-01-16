/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione che trova il massimo di una tripla */
int Massimo(int seq1,int seq2,int seq3){
	int massimo; //variabile che prende il valore massimo
	/* la si inizializza al primo elemento*/
	massimo=seq1;
	if(seq2>massimo){
		massimo=seq2;

		if(seq3>massimo)
			massimo=seq3;
	}
	else if (seq3>massimo){
		massimo=seq3;
	}
	return massimo;
}

/* funzione ricorsiva che verifica se ogni tripla di interi consecutivi ha il valore massimo pari */
int massimoPari(int *seq, int lunghezza){
	int controllo; //variabile che controlla se la proprietà è verificata [1] o no [0]
	/* CASO BASE*/
	if(lunghezza<=2)
		controllo=1;
	/* PASSO RICORSIVO*/
	else{
		controllo=(Massimo(seq[0],seq[1],seq[2])%2==0)&&massimoPari(seq+1,lunghezza-1);
	}
	return controllo;
}

/* funzione che conta quanti interi sono stati scritti in un file di testo */
int quantiNumeri() {
	int quanti; //conta quanti numeri sono stati salvati sul file
	int intero; //variabile di supporto
	/* apri il file*/
	FILE* fp=fopen("interi.txt","r");
	/* se non riesce ad aprirlo*/
	if(fp==NULL)
		printf("apertura file non riuscita\n");
	/* se si apre*/
	else{
		/* vai avanti fino alla fine del file e conta ogni intero letto*/
		while(fscanf(fp,"%d",&intero)!=EOF){
			quanti++;
		}
		/* poi chiudi il file*/
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge gli interi dal file di testo */
void leggiNumeri(int* sequenza, int lunghezza) {
	/* apertura file*/
	FILE* fp=fopen("interi.txt","r");
	/* se non riesce ad aprire il file*/
	if(fp==NULL)
		printf("apertura non riuscita\n");
	/* se lo apre*/
	else{
		/* leggi gli interi al suo interno*/
		for(int i=0;i<lunghezza;i++){
			fscanf(fp,"%d",&sequenza[i]);
		}
		/* poi chiudi il file*/
		fclose(fp);
	}
}

/* funzione che scrive gli interi di una sequenza su un file di testo */
void scriviNumeri(int* sequenza, int lunghezza) {
	/* apertura o creazione file*/
	FILE* fp=fopen("interi.txt","w");
	/* se non riesce ad aprire il file*/
	if(fp==NULL)
		printf("apertura non riuscita\n");
	/* se lo apre*/
	else{
		/* scrivi gli interi al suo interno*/
		for(int i=0;i<lunghezza;i++){
			fprintf(fp,"%d ",sequenza[i]);
		}
		/* poi chiudi il file*/
		fclose(fp);
		printf("salvataggio riuscito\n");
	}
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
			printf("ogni tripla di interi consecutivi ha il valore massimo pari \n");
		else
			printf("non e' vero che ogni tripla di interi consecutivi ha il valore massimo pari \n");

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
			printf(" ogni tripla di interi consecutivi ha il valore massimo pari \n");
		else
			printf(" non e' vero che ogni tripla di interi consecutivi ha il valore massimo pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}