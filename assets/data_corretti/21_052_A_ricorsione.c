/*
5pt massimo pari:..2
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se ogni tripla di interi nella sequenza è tale che il massimo fra i 3 interi è pari */
int massimoPari(int *seq, int lunghezza){
	//pre: lunghezza>=3
	//pari se x%2==0
	int tutte=1;	//verifica universale

	if(lunghezza=3)
	{//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

		if( ((seq[0]>seq[1] && seq[0]>seq[2])&&seq[0]%2==0) ||
			((seq[1]>seq[0] && seq[1]>seq[2])&&seq[1]%2==0) ||
			((seq[2]>seq[0] && seq[2]>seq[1])&&seq[2]%2==0) )
				tutte=1;
	}
	else{
		tutte= massimoPari(seq+1, lunghezza-1); //**** in questo modo controlli solo l'ultima terna: qui non controlli nulla,
	}                                           //**** ma richiami solo la funzione ricorsiva -2
}

/* funzione che conta quanti numeri interi sono memorizzati sul file */
int quantiNumeri() {
	int conta;
	FILE* fp= fopen("interi.dat", "rb");

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive ... */
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
		if(massimoPari(array,lunghezza))
			printf(" ogni tripla di interi nella sequenza e'3 tale che il massimo fra i 3 interi e'3 pari \n");
		else
			printf("Non ogni tripla di interi nella sequenza e'3 tale che il massimo fra i 3 interi e'3 pari \n");

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