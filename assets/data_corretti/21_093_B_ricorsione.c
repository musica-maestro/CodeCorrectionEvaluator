/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.8
2pt quanti numeri:...1.3
2pt leggi numeri:....1.8
TOTALE ..............8.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int dim){
	int trovato;
	printf("\n%d %d\n", seq[0], dim);

	if(dim<=2)
		trovato=1;
		else
			trovato=((((seq[0]<seq[1]&&seq[0]<seq[2])&&(seq[0]%2!=0))
			        ||((seq[1]<seq[0]&&seq[1]<seq[2])&&(seq[1]%2!=0))
			        ||((seq[2]<seq[0]&&seq[2]<seq[1])&&(seq[2]%2!=0)))&&(minimoDispari(seq+1, dim-1)));

	return trovato;
}

/* funzione che conta quanti numeri interi ci sono sul file */
int quantiNumeri() {
	FILE*fp=fopen("Interi.txt", "r");
	int conta;                           //variabile contatore
	//**** il contatore non è inizializzato -0.5
	if(fp==NULL)
		printf("\nApertura file non andata a buon fine.\n\n");
		else{
			int numero;                 //variabile utilizzata per leggere il numero
			while((fscanf(fp, "%d ", &numero))!=EOF){
				conta++;
			}
		}
	//**** non chiudi il file -0.2
	return conta;
}

/* funzione che legge una sequenza di numeri da file */
void leggiNumeri(int* seq, int lunghezza) {
	FILE*fp=fopen("Interi.txt", "r");

	if(fp==NULL)
		printf("\nLettura da file non riuscita.\n\n");
		else{
			for(int i=0; i<lunghezza; i++){
				fscanf(fp, "%d", &seq[i]);
			}
			printf("\nLettura riuscita.\n\n");
		}
	//**** non chiudi il file -0.2
}

/* funzione che scrive scrive i numeri sul file */
void scriviNumeri(int* seq, int lunghezza) {
	FILE*fp=fopen("Interi.txt", "w");

	if(fp==NULL)
		printf("\nScrittura su file non andata a buon fine.\n\n");
		else{
			for(int i=0; i<lunghezza; i++){
				fprintf(fp, "%d ", seq[i]);
			}
			printf("\nScrittura su file riuscita.\n\n");
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
		if(minimoDispari(array,lunghezza))
			printf("\nIn ogni tripla di interi consecutivi della tua lista, %c tale che il minimo fra i tre %c dispari\n\n", 138, 138);
		else
			printf("\nNon in tutte le triple di interi consecutivi della tua sequenza, %c tale che il minimo fra i tre %c dispari\n\n", 138, 138);

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
			printf("\nIn ogni tripla di interi consecutivi della tua lista, %c tale che il minimo fra i tre %c dispari\n\n", 138, 138);
		else
			printf("\nNon in tutte le triple di interi consecutivi della tua sequenza, %c tale che il minimo fra i tre %c dispari\n\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}