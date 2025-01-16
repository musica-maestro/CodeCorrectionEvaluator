/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...1.5
2pt leggi numeri:....2
TOTALE ..............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in una sequenza introdotta ogni tripla di interi consecutivi
 * è tale che il minimo fra i tre interi è dispari */
int minimoDispari(int *seq, int lunghezza){
	int tripla;     //variabile universale
	/*CASO BASE*/
	if(lunghezza<3)
		tripla = 1;
	/*PASSO RICORSIVO*/
	else
		tripla = ((seq[0]<seq[1] && seq[0]<seq[2] && seq[0]%2==1) ||
		         (seq[1]<seq[0] && seq[1]<seq[2] && seq[1]%2==1) ||
				 (seq[2]<seq[1] && seq[2]<seq[0] && seq[2]%2==1)) &&
				 minimoDispari(seq+1, lunghezza-1);

	/*resituisci la variabile*/
	return tripla;
}

/* funzione che conta quanti numeri interi sono memorizzati su un file binario */
int quantiNumeri() {
	/*apertura di un file binario*/
	FILE* fp = fopen("interi.dat", "rb");
	int quanti;     //variabile contatore   //**** il contatore non � inizializzato -0.5
	/*apertura file riuscita?*/
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	/*apertura file riuscita*/
	else {
		int numero;     //variabile per memorizzare indirizzo numero letto
		while(fread(&numero, sizeof(int), 1, fp)>0) {
			quanti++;
		}
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge una sequenza di interi da un file interi.dat e li memorizza su un arrar ricevuto come parametro */
void leggiNumeri(int* sequenza, int lunghezza) {
	/*apertura del file binario*/
	FILE* fp = fopen("Interi.dat", "rb");
	/*apertura file riuscita?*/
	if(fp==NULL)
		printf("File inesistente o apertura non riuscita!\n");
	else {
		for(int i=0; i<lunghezza;i++)
			fread(&sequenza[i], sizeof(int), 1, fp);
	}
		fclose(fp);
		printf("Ho letto la sequenza di interi e li ho memorizzari sulla sequenza ricevuta!\n");
}

/* funzione che scrive i valori di un array di interi su di un file binario */
void scriviNumeri(int* sequenza, int lunghezza) {
	/*apertura del file*/
	FILE* fp = fopen("interi.dat", "wb");
	/*apertua fle riuscita?*/
	if(fp==NULL)
		printf("File inesistente o apertura file non riuscita!\n");
	else {
		/*hai aperto il file, scrivi i numeri*/
		for(int i=0; i<lunghezza; i++)
			fwrite(&sequenza[i], sizeof(int), 1, fp);
	}
		/*sei alla fine chiudi il file*/
		fclose(fp);
		printf("Numeri scirtti su file!\n");
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
			printf("Nella sequenza introdotta ogni tripla %c tale che il minimo fra i tre interi %c dispari!!\n\n", 138, 138);
		else
			printf("Nella sequenza introdotta non ogni tripla %c tale che il minimo fra i tre interi %c dispari!!\n\n", 138, 138);

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
			printf("Nella sequenza introdotta ogni tripla %c tale che il minimo fra i tre interi %c dispari!!\n\n", 138, 138);
		else
			printf("Nella sequenza introdotta non ogni tripla %c tale che il minimo fra i tre interi %c dispari!!\n\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
