/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>

//Input: lunghezza variabile intera che definisce la lunghezza dell'array. seq è un array di interi
//Precondizione: lunghezza>=3
//output massimoPari restituisce un intero
//postcondizione: massimoPari restituisce 1 se ogni massimo, individuato all'interno di una tripletta dell'array, è divisibile per 2

/* funzione ricorsiva che verifica che in ogni tripla di numeri, il massimo della tripla è anche pari.  */
int massimoPari(int *seq, int lunghezza){
	int res;
	if(lunghezza<3){
		res=1;
	}else{
		res=((seq[0]>=seq[1]&&seq[0]>=seq[2]&&seq[0]%2==0)
		||(seq[1]>=seq[0]&&seq[1]>=seq[2]&&seq[1]%2==0)
		||(seq[2]>=seq[1]&&seq[2]>=seq[0]&&seq[2]%2==0))&&massimoPari(seq+1,lunghezza-1);
	}
	return res;
}

/* funzione che conta ... */
int quantiNumeri(){
	int l=0;
	int buff;
	FILE *fp=fopen("interi.dat","rb");
	if(fp!=NULL){
		while(fread(&buff,sizeof(int),1,fp)>0){
			l++;
		}
		fclose(fp);
	}else{
		printf("Nessuno file da aprire.\n");
	}
	return l;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","rb");
	if(fp!=NULL){
		fread(sequenza,sizeof(int),lunghezza,fp);
		fclose(fp);
	}else{
		printf("Nessun file da aprire.\n");
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","wb");
	if(fp!=NULL){
		printf("Salvataggio in corso.\n");
		fwrite(sequenza,sizeof(int),lunghezza,fp);
		fclose(fp);
	}
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
			printf("Ogni tripla di interi ha come numero pari il suo massimo.\n");
		else
			printf("Non ogni tripla di interi ha come numero pari il massimo della tripla.\n");

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
			printf("Ogni tripla di interi ha come numero pari il suo massimo.\n");
		else
			printf("Non ogni tripla di interi ha come numero pari il massimo della tripla.\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}