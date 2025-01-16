/*
5pt massimo pari:..3.7
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............8.7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int seq[], int lunghezza){
	int max;
	int ris = 1;
	if(lunghezza==3){
		if(seq[0] > seq[1] && seq[0] > seq[2]){
			max = seq[0];
		}
		else if(seq[1] > seq[0] && seq[1] > seq[2]){
			max = seq[1];
		}
		else if(seq[2] > seq[0] && seq[2] > seq[1]){
			max = seq[2];
		}
		if(max%2 == 0){
			ris = 1;
		}
		else{
			ris = 0;
		}
	}
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

	//**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3

	else{
		ris = (((seq[0] > seq[1] && seq[0] > seq[2]) && seq[0] %2 == 0)
		|| ((seq[1] > seq[0] && seq[1] > seq[2]) && seq[1] %2 == 0)
		|| ((seq[2] > seq[0] && seq[2] > seq[1]) && seq[2] % 2 ==0)) && massimoPari(seq+1, lunghezza-1);
	}
	return ris;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp = fopen("interi.dat", "rb");
	int quanti = 0;
	int numero;
	if(fp==NULL){
		printf("impossibile aprire il file o file vuoto.\n");
	}
	else{
		while(fread(&numero, sizeof(int), 1, fp) > 0){
			quanti++;
		}
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int sequenza[], int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");
	if(fp==NULL){
		printf("impossibile aprire il file o file vuoto.\n");
	}
	else{
		fread(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);
	}
}


/* funzione che scrive ... */
void scriviNumeri(int sequenza[], int lunghezza){
	FILE *fp = fopen("interi.dat", "wb");
	if(fp == NULL){
		printf("impossibile aprire il file o file inesistente.\n");
	}
	else{
		fwrite(sequenza, sizeof(int), lunghezza, fp);
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
		if(massimoPari(array,lunghezza))
			printf(" ogni tripla di interi consecutivi e' tale che il massimo fra i tre interi e' pari. \n");
		else
			printf(" ogni tripla di interi consecutivi non e' tale che il massimo fra i tre interi e' pari. \n");

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
			printf(" ogni tripla di interi consecutivi e' tale che il massimo fra i tre interi e' pari \n");
		else
			printf(" ogni tripla di interi consecutivi non e' tale che il massimo fra i tre interi e' pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}