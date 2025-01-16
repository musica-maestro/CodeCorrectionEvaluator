/*
5pt minimo dispari:..4
1pt scrivi numeri:...0.8
2pt quanti numeri:...1.8
2pt leggi numeri:....1.8
TOTALE ..............8.4
*/
#include <stdio.h>
#include <stdlib.h>

int minimo(int x, int y, int z) {
	int min = x;
	if(y<x) {
		min = y;
	}
	else if (z<x) {
		min = z;
	}

	return min;
}

/* funzione ricorsiva che verifica se ogni tripla nella sequenza ha come minimo un intero dispari */
int minimoDispari(int *seq, int lunghezza){
	int tutte = 0;
	if(lunghezza==3) {
		if(minimo(seq[0],seq[1],seq[2])%2!=0)
			tutte = 1;
	}//**** passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	else {
		tutte = minimoDispari(seq+1, lunghezza-1) && (minimo(seq[0],seq[1],seq[2])%2!=0);
	}          //**** meglio se scambi gli operandi

	return tutte;
}

/* funzione che conta ... */
int quantiNumeri() {
	int i=0;
	FILE* fp = fopen("interi.txt","r");
	if(fp==NULL)
		printf("\nApertura non riuscita!\n\n");
	else {
		int intero;
		while(fscanf(fp, "%d", &intero)>0) {
			i++;
		}
	}
//**** non chiudi il file -0.2
	return i;
}


/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt","r");
	if(fp==NULL)
		printf("\nApertura non riuscita!\n\n");
	else {
		for(int i=0; i<lunghezza; i++) {
			fscanf(fp, "%d", &sequenza[i]);
		}
	}
}
//**** non chiudi il file -0.2

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt","w");
	if(fp==NULL)
		printf("\nSalvataggio non riuscito!\n\n");
	else {
		int i=0;
		while(i<lunghezza) {
			if(i==lunghezza-1)
				fprintf(fp, "%d", sequenza[i]);
			else
				fprintf(fp, "%d ", sequenza[i]);
			i++;
		}
	}
}
//**** non chiudi il file -0.2


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
			printf("\nNella sequenza ogni tripla ha come minimo un intero dispari!\n\n");
		else
			printf("Nella sequenza ogni tripla NON ha come minimo un intero dispari!\n\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		if(lunghezza!=0){
			leggiNumeri(array,lunghezza);
			printf("Ecco la sequenza recuperata\n");
			for(int i=0;i<lunghezza;i++)
				printf("%d ", array[i]);
			printf("\n");

			/* invoca la funzione ricorsiva e stampa il risultato */
			if(minimoDispari(array,lunghezza))
				printf("\nNella sequenza ogni tripla ha come minimo un intero dispari!\n\n");
			else
				printf("\nNella sequenza ogni tripla NON ha come minimo un intero dispari!\n\n");
			/* salva la sequenza su file */
			scriviNumeri(array,lunghezza);
		}
		else {
			printf("\nNon c'e' nessuna sequenza salvata su file\n\n");
		}
	}
}
