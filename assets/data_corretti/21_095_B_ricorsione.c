/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se, in un array di interi, ogni tripla
	di interi consecutivi è tale che il minimo fra i tre interi è dispari REALIZZAZIONE 3 */
int minimoDispari(int *seq, int dim){
	//pre: dim è la lunghezza della sequenza
	int tutti;		//per il risultato
	/* CASO BASE */
	if (dim<3)
		tutti = 1;
	/* PASSO RICORSIVO */
	else	{
		if(seq[0]<seq[1] && seq[0]<seq[2])			//se il primo della tripla è il minimo
			tutti = (seq[0]%2!=0) && minimoDispari(seq+1,dim-1);
		else if (seq[1]<seq[0] && seq[1]<seq[2])	//se il secondo della tripla è il minimo
			tutti = (seq[1]%2!=0) && minimoDispari(seq+1,dim-1);
		else if (seq[2]<seq[1] && seq[2]<seq[0])	//se il terzo della tripla è il minimo
			tutti = (seq[2]%2!=0) && minimoDispari(seq+1,dim-1);
	}
	return tutti;
}

/* funzione che conta il numero di interi memorizzati su un file */
int quantiNumeri() {
	int letti=0;
	FILE* fp = fopen("numeri.txt","r");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n\n");
	/* apertura riuscita */
	else {
		int numero;				// variabile di appoggio
		while(fscanf(fp, "%d", &numero)!=EOF)
			letti++;
		fclose(fp);
	}
	return letti;
}



/* funzione che legge una sequenza di interi da file e li memorizza
	su un array ricevuto come parametro */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("numeri.txt","r");
	if(fp==NULL)
		printf("Importazione interi da file non riuscita!\n\n");
	else {
		for(int i=0; i<lunghezza; i++)
			fscanf(fp, "%d", &sequenza[i]);
		printf("Importazione riuscita!\n\n");
		fclose(fp);
	}
}

/* funzione che scrive i numeri contenuti in una sequenza su un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("numeri.txt","w");
	if (fp==NULL)
		printf("Salvataggio non riuscito!\n\n");
	else {
		for(int i=0; i<lunghezza; i++)
			fprintf(fp, "%d ", sequenza[i]);
		printf("Salvataggio effettuato!\n\n");
		fclose(fp);
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
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla %c tale che il minimo fra i tre interi della tripla %c dispari!\n\n", 138, 138);
		else
			printf("Non tutte le triple sono tali che il minimo fra i tre interi della tripla %c dispari!\n\n", 138);

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
			printf("Ogni tripla %c tale che il minimo fra i tre interi della tripla %c dispari!\n\n", 138, 138);
		else
			printf("Non tutte le triple sono tali che il minimo fra i tre interi della tripla %c dispari!\n\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}