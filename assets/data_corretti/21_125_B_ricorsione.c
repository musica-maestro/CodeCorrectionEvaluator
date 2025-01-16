/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.5
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............5.5
*/
#include <stdio.h>
#include <stdlib.h>


/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int res;

	if(lunghezza<3)
		res=0;
		else{
			if(lunghezza==3)
				res= (((seq[0]<seq[1] && seq[0]<seq[2]) && seq[0]%2!=0) ||
				((seq[1]<seq[0] && seq[1]<seq[2]) && seq[1]%2!=0) ||
				((seq[2]<seq[1] && seq[2]<seq[0]) && seq[2]%2!=0));
				else{
					res= (((seq[0]<seq[1] && seq[0]<seq[2]) && seq[0]%2!=0) ||
				((seq[1]<seq[0] && seq[1]<seq[2]) && seq[1]%2!=0) ||
				((seq[2]<seq[1] && seq[2]<seq[0]) && seq[2]%2!=0)) + minimoDispari(seq+1, lunghezza-1);
				}

		}
		return res;
}

/* funzione che conta ... */
int quantiNumeri() {
	printf("Non ancora!\n");
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	printf("Non ancora!\n");
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "wb");
	if(fp==NULL)
		printf("Slavataggio non riuscito.\n");
		else{
			while(fp!=NULL){//**** devi iterare sulla lunghezza dell'array -0.5
				fwrite(&sequenza[0], sizeof(lunghezza), 1, fp);
				sequenza++;
			}
			printf("Salvataggio riuscito!\n");
		}
		fclose(fp);
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
			printf("La sequenza contiente tutte triple dove il minimo della tripla è anche disparo. \n");
		else
			printf("La sequenza non contiente tutte triple dove il minimo della tripla è anche disparo. \n");

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}