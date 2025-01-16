/*
5pt minimo dispari:..0
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............0
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
    int n=0;//**** manca il passo base della ricorsione -1.5
     if(*seq+n<=*seq+n+1 && *seq<=*seq+n+2){ //**** verifica proprietà non corretta -1.5
         if(*seq%2==1)
             minimoDispari(seq,n+1);//**** verifichi un'altra proprietà -1.5riparti sempre con n=0,
                                    //**** la ricorsione va fatta sulla lunghezza -1.5

     }
   //**** manca il return! -0.5
}




/* funzione che conta ... */
int quantiNumeri() {

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {





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
			printf(" Ogni tripla e' dispari \n");
		else
			printf(" Almeno una tripla non e' dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		//lunghezza = quantiNumeri();

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