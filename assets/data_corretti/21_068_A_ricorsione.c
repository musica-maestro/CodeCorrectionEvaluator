/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.5
2pt leggi numeri:..2
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int verifica;
	if(lunghezza<=2){
		verifica=1;
	}
	else{
		verifica=((seq[0]>seq[1]&&seq[0]>seq[2]&&seq[0]%2==0)
		||(seq[1]>seq[0]&&seq[1]>seq[2]&&seq[1]%2==0)
		||(seq[2]>seq[1]&&seq[2]>seq[0]&&seq[2]%2==0)) && massimoPari(seq+1,lunghezza-1);
	}
	return verifica;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE * fb= fopen("interi.dat","rb");
	int numeri=0;
	if(fb==NULL){
		printf("Impossibile aprire il file");
	}
	else{
		while(fread(&numeri,sizeof(int),1,fb)>0){
		numeri++;
		}//**** non puoi usare numero sia per contare, sia per la fread,
		//**** così ad ogni lettura perdi il contatore e in numero acquisisci
 		//**** il valore letto dal file (in teoria) -0.5
	}
	fclose(fb);
	return numeri;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE * fb=fopen("interi.dat","rb");
	if(fb==NULL){
		printf("Impossibile aprire il file!\n");
	}
	else{
		fread(sequenza,sizeof(int),lunghezza,fb);
		printf("Sequenza letta\n");
	}
	fclose(fb);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE * fb=fopen("interi.dat","wb");
	if(fb==NULL){
		printf("Impossibile aprire il file in scrittura!\n");
	}
	else{
		fwrite(sequenza,sizeof(int),lunghezza,fb);
		printf("Salvataggio riuscito\n");
	}
	fclose(fb);
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
			printf("IL numero massimo nella tripla  e' pari\n");
		else
			printf("il numero massimo nella tripla non e' pari\n");

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
			printf("IL numero massimo nella tripla  e' pari\n");
		else
			printf("il numero massimo nella tripla non e' pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}