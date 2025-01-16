/*
5pt massimo pari:..1.5
1pt scrivi numeri:.0
2pt quanti numeri:.0.1
2pt leggi numeri:..0
TOTALE ............1.6
*/
#include <stdio.h>
#include <stdlib.h>




/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int vero = 0;
	int max;
	max=seq[lunghezza]; //**** non è un elemento dell'array -1

	 if (seq[lunghezza+1]>max) //**** a maggior ragione questo -1
		 max=seq[lunghezza+1];

	if (lunghezza<3)
		printf("non ci sono abbastanza elementi \n"); //**** questo non è il PB -1.5
	else {
		if ((max%2 == 0)&&massimoPari(seq+2,lunghezza-2))
			vero = 1;
	}
	return vero;
}

/* funzione che conta ... */
int quantiNumeri() {
	int i;
	int numero;
	int quanti; //**** il contatore non è inizializzato -0.5
	FILE *fp=fopen("numeri.dat", "rb");
	if (i==NULL)  //**** non puoi confrontare un puntatore con un intero -0.5
		printf("niente da leggere\n");
	fread(&i,numero,1,fp); //**** sintassi fread (&i,sizeof(int),1,fp)  -0.4
	while(i!=NULL,i>0,i++)/**** non puoi confrontare un puntatore con un intero -0.5
		quanti++;

		return quanti;
	fclose (fp);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	int numero;
	FILE *fp=fopen("numeri.dat", "rb");
	if (lunghezza==NULL)
		printf("niente da leggere\n");
    //**** manca l'else -0.5
	do{
		fread(&lunghezza,numero,1,fp);
		for (lunghezza=0;lunghezza++;)
		lunghezza=sequenza[lunghezza];
	}
	while(lunghezza!=NULL); //**** confronti un int con un puntatore -0.5

	return(sequenza,lunghezza); //**** non ritornano due valori! -3
		fclose(fp); //**** dopo il return la funzione termina -2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	int i;

	FILE *fp=fopen("numeri.dat", "rb");
	if (lunghezza==NULL)
		fwrite(&i,lunghezza,1,fp);  //*** come sopra
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
		if(massimoPari(array,lunghezza))
			printf("in ogni tripla di interi il massimo e' pari \n");
		else
			printf("non tutti i massimi di ogni tripla di interi sono pari \n");

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
			printf("in ogni tripla di interi il massimo e' pari \n");
		else
			printf("non tutti i massimi di ogni tripla di interi sono pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}