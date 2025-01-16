/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....1.8
TOTALE ..............9.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int verifica;
	if(lunghezza<3){
		verifica = 1;
	}else{
		if(seq[0] < seq[1] && seq[0]<seq[2]){		//Controllo caso primo numero piu piccolo tripla
			verifica = ((abs(seq[0])%2==1)  && minimoDispari(seq+1,lunghezza-1));
		}else if(seq[1] < seq[0] && seq[1]<seq[2]){		//Controllo caso secondo numero piu piccolo tripla
			verifica = ((abs(seq[1])%2==1)  && minimoDispari(seq+1,lunghezza-1));
		}else if(seq[2] < seq[0] && seq[2]<seq[1]){		//Controllo caso terzo numero piu piccolo tripla
			verifica = ((abs(seq[2])%2==1)  && minimoDispari(seq+1,lunghezza-1));

		}

	}
	return verifica;
}

/* funzione che conta ... */
int quantiNumeri() {
	int cont=0;
	FILE* fp=fopen("interi.txt","r");
	if(fp == NULL){
		printf("Errore conteggio numeri");
	}else{
		int app;
		while(fscanf(fp,"%d",&app)!=EOF){
			cont++;
		}
	}
	fclose(fp);
	return cont;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.txt","r");
	if(fp == NULL){
		printf("Errore lettura numeri");
	}else{
		int i =0;
		while(fscanf(fp,"%d",&sequenza[i])!=EOF){
			i++;
		}
	}//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt","w");
	if(fp == NULL){
		printf("Errore scrittura file");
	}else{
		for(int i = 0 ; i < lunghezza ; i++){
			fprintf(fp,"%d\n",sequenza[i]);
		}
	}
	fclose(fp);
}

/* funzione principale */
int main(int argc, char **argv) {
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
			printf("\nOgni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("\nOgni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi NON e' dispari\n");

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
			printf("\nOgni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("\nOgni tripla di interi consecutivi nella sequenza e' tale che il minimo fra i tre interi NON e' dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}