/*
5pt massimo pari:..2.5
1pt scrivi numeri:.0.7
2pt quanti numeri:.1.7
2pt leggi numeri:..1.7
TOTALE ............6.6
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int maxP;
	/*caso base*/
	if(lunghezza==2)
		maxP=0;
	else{
	/*Passo Ricorsivo*/
		//1 se il primo elemento è il massimo ed è maggiore di 0
		if(seq[0]>seq[1] && seq[0]>seq[2] && seq[0]>0)  //**** deve  essere pari, non >0!
			maxP=1+massimoPari(seq+1,lunghezza-1);      //**** proprietà parzialmente sbagliata -1
		//1 se il secondo elemento è il massimo ed è maggiore di 0
		if(seq[1]>seq[0] && seq[1]>seq[2] && seq[1]>0)
			maxP=1+massimoPari(seq+1,lunghezza-1);
		//1 se il terzo elemento è il massimo ed è maggiore di 0
		if(seq[2]>seq[0] && seq[2]>seq[1] && seq[2]>0)
			maxP=1+massimoPari(seq+1,lunghezza-1);
		//se il massimo è minore di 0 restituisce 0
		if(seq[0]<0 && seq[1]<0 && seq[2]<0)       //**** questa non èuna verifica universale -1.5
			maxP=0+massimoPari(seq+1,lunghezza-1);
	}
	return maxP;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp=fopen("interi.dat","rb");   //apertura file in lettura
	int quanti=0;  //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	int numero;
	while(fread(&numero,sizeof(int),1,fp)){
		quanti++;  //aumenta quando conta un numero
	}
	fclose(fp); //chiusura del file
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","rb");			//apertura file in lettura
	fread(sequenza,sizeof(int),lunghezza,fp);  //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fclose(fp);  //chiusura del file
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","wb");				//apertura file in scrittura
	fwrite(sequenza,sizeof(int),lunghezza,fp);   //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fclose(fp);  //chiusura del file
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
			printf("Ogni tripla di interi il suo massimo e' positivo\n");
		else
			printf("Un massimo nella tripla di interi e' negativo\n");

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
			printf("Ogni tripla di interi il suo massimo e' positivo\n");
		else
			printf("Un massimo nella tripla di interi e' negativo\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}