/*
5pt minimo dispari:..4
1pt scrivi numeri:...0.4
2pt quanti numeri:...0.8
2pt leggi numeri:....1.8
TOTALE ..............7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica che ogni tripla di interi consecutivi della sequenza presenta un minimo disprari */
int minimoDispari(int *seq, int lunghezza){
	int triplaDispari=1;
	/*cado base*/
	if(lunghezza<=2)
		triplaDispari=0; //**** variabile di universalità asseganta male -1
		else{            //**** comunque arriva al passo base e assegna 0, quindi il risultato è sempre 0.
			if((((seq[0]<seq[1])&&(seq[0]<seq[2])&&(seq[0]%2!=0))||
			((seq[1]<seq[0])&&(seq[1]<seq[2])&&(seq[1]%2!=0))||
			((seq[2]<seq[1])&&(seq[2]<seq[0])&&(seq[2]%2!=0)))&&minimoDispari(seq+1,lunghezza-1));//***** istruzione if vuota!!

			triplaDispari=1;


		}

		return triplaDispari;

}

/* funzione che conta quanti numeri sono memorizzati su file */
int quantiNumeri() {
	int quanti;
	FILE*fp=fopen("interi.txt","r");
	if(fp==NULL)
		printf("Il file Ã¨ vuoto!\n");
		else{
			int numero;
			while(  //**** manca la parte del conteggio! -1
		}//**** non chiudi il file -0.2
}

/* funzione che legge la sequenza scritta sul file  */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.txt","r");
	if(fp==NULL)
		printf("Nel file non c'e' nessuna sequenza!\n\n");
		else{
			for(int i=0;i<lunghezza;i++)
				fscanf(fp,"%d",&sequenza[i]);
		}
}//**** non chiudi il file -0.2

/* funzione che scrive la sequenza su file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.txt",'w'); //**** "w" errore di sintassi -0.4
	if(fp==NULL)
		printf("Niente da scrivere!\n\n");
		else{
			for(int i=0;i<lunghezza;i++)
				fprintf(fp,"%d ",sequenza[i]);

		}
		printf("Scrittura effettuata!");

//**** non chiudi il file -0.2
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
			printf(" Ogni tripla di interi consecutivi presenta un minimo dispari! \n");
		else
			printf("Non tutte le tripre soddisfano le proprieta'! \n");

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