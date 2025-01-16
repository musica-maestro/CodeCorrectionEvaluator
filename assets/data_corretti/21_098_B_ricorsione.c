/*
5pt minimo dispari:..2
1pt scrivi numeri:...1
2pt quanti numeri:...1
2pt leggi numeri:....1.7
TOTALE ..............5.7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *array, int l){
	int verifica;  // variabile universale
	if(l<3)
		verifica = 1;
	else{
		if(array[l-1] <0)
			array[l-1] = -array[l-1];  //**** perché trasformi i negativi in positivi?
	                                   //**** così alteri i dati del problema: se hai -3,2,4 (con min=-3)
	if(array[l-2] <0)                  //**** la terna diventa 3,2,4 con min=2 che non è dispari  -1.5
			array[l-2] = -array[l-2];

	if(array[l-3] <0)
			array[l-3] = -array[l-3];

		verifica = (((array[l-1]%3 == 0) && (array[l-1]< array[l-2]) && (array[l-1]< array[l-3])) ||
		            ((array[l-2]%3 == 0) && (array[l-2]< array[l-1]) && (array[l-2]< array[l-3]))  ||
					((array[l-3]%3 == 0) && (array[l-3]< array[l-2]) && (array[l-3]< array[l-1]))) && minimoDispari(array, l-1);
	}//***x%3==0 vuol dire che  è un multiplo di 3, non che è dispari! -1.5
return verifica;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("interi.dat", "rb");
	int quanti=0;
	if(fp == NULL)
		printf("Mi spiace ma o il file non esiste o la sua apertura non %c riuscita\n", 138);
		else{
	while(fp != NULL) //**** while(fp!=NULL): così hai un loop infinito! -1
	quanti ++;        //**** dovevi scrivere while(fread(&n,sizeof(int),1,fp)>0)
                      //**** dove n è un intero usato per leggere (ma non usare) il numero
		}             //**** è presente nel file
		fclose(fp);

	return quanti;

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "rb");
	if(fp== NULL)
		printf("Mi spiace ma il file non puo essere aperto o non esiste\n");
		else{
		fread(&sequenza,sizeof(int), lunghezza, fp); //**** nella fread primo parametro senza & -0.3
			printf("Lettura effettuata\n");
	}
fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp =fopen("interi.dat", "wb"); //**** W non è un'opzione per scrivere su file
	if(fp== NULL)
		printf("Salvataggio non riuscito\n");
	else{
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		printf("Salvataggio andato a buon fine\n");
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
			printf(" Nella tua sequenza ogni tripla di interi consecutivi %c tale che il minimo fra i tre %c dispari\n", 138, 138);
		else
			printf(" Nella tua sequenza NON ogni tripla di interi consecutivi %c tale che il minimo fra i tre %c dispari\n", 138, 138);

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
			printf(" Nella tua sequenza ogni tripla di interi consecutivi %c tale che il minimo fra i tre %c dispari\n", 138, 138);
		else
			printf(" Nella tua sequenza NON ogni tripla di interi consecutivi %c tale che il minimo fra i tre %c dispari\n", 138, 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}