/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.2
2pt leggi numeri:....1.7
TOTALE ..............8.6
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int valida=1;
	if(lunghezza>=3){
		if((((seq[0]<seq[1] && seq[0]<seq[2]) && (seq[0]+1)%2==0)
		|| ((seq[1]<seq[0] && seq[1]<seq[2]) && (seq[1]+1)%2==0)
 		|| ((seq[2]<seq[1] && seq[2]<seq[0]) && (seq[2]+1)%2==0)) && valida){
			valida=minimoDispari(seq+1, lunghezza-1);
		}
		else
			valida=0;
	}
	return valida;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* f=fopen("interi.txt", "r");
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	int intero, quantiN;  //**** il contatore non è inizializzato -0.5
	if(fscanf(f, "%d", &intero)){
		quantiN=1;
		while(fscanf(f, "%d", &intero))
			quantiN++;
	}
	else
		quantiN=0;
	fclose(f);
	return quantiN;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* f=fopen("interi.txt", "r");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	int i=0;
	if(i<lunghezza){
		while(fscanf(f, "%d", &sequenza[i]) && i<lunghezza)
			i++;
	}
	else
		printf("La lunghezza della sequenza deve essere >0");
	fclose(f);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* f=fopen("interi.txt", "w");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i=0; i<lunghezza; i++){
		fprintf(f, "%d", sequenza[i]);
	}
	fclose(f);
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
			printf("Ogni tripla di interi consecutivi ha il minimo fra i tre interi dispari\n");
		else
			printf("NON tutte le triple di interi consecutivi hanno il minimo fra i tre interi dispari\n");

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
			printf("Ogni tripla di interi consecutivi ha il minimo fra i tre interi dispari\n");
		else
			printf("NON tutte le triple di interi consecutivi hanno il minimo fra i tre interi dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}