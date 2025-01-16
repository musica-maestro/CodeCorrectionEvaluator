/*
5pt massimo pari:..3.5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............8.5
*/
#include <stdio.h>
#include <stdlib.h>

int massimo(int a,int b,int c){
	int max;
	if(a<b){
		if(c<b){
			max=b;
		}
		else{ //**** vai qui se a<b e c<=a
			if(a<c)
				max=c;

		}

	}
	else{ //**** vai qui se a>=b, confronti a con c, ma se a<=c cosa restituisci???
		if(a>c)
			max=a;          //***** errore nel calcolo del massimo! -1.5
                            //***** esempio: (2,1,3) max=???


	}
	return max;
}

/* funzione ricorsiva che verifica se il massimo in ogni tripla è pari*/
int massimoPari(int *seq, int lunghezza){
	int risultato; //valore da restituire
	/*CASO BASE*/
	if(lunghezza<3)
		risultato=1;
	/*VERIFICO SE IL MAX DI OGNI TRIPLA è pari*/
	else
		risultato=(massimo(seq[0],seq[1],seq[2])%2==0)&&massimoPari(seq+1,lunghezza-1);

	return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0; //valore da restituire
	int numero; //variabile d'appoggio
	FILE *fp=fopen("interi.dat","rb"); //apro il file
	/*FILE VUOTO?*/
	if(fp==NULL)
		printf("Il file non si può aprire oppure vuoto");
		/*Conto quanti numeri sono memorizzati sul file*/
	else{
		while(fread(&numero,sizeof(int),1,fp)>0)
			quanti++;

		fclose(fp); //chiudo il file

	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","rb"); //apro file
	/*FILE VUOTO?*/
	if(fp==NULL)
		printf("Il file non si può aprire oppure vuoto");
		/*leggo i valori di interi da un file binario*/
	else{
		fread(sequenza,sizeof(int),lunghezza,fp);
		fclose(fp); //chiudo file
	}


}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","wb");
	/*FILE VUOTO?*/
	if(fp==NULL)
		printf("Il file non si può aprire oppure vuoto");
	else{
		/*scrivo i valori di interi su un file binario*/
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
			printf("Il massimo di ogni tripla %c pari\n",138);
		else
			printf("NON %c vero che il massimo di ogni tripla %c pari\n",138,138);

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
			printf("Il massimo di ogni tripla %c pari\n",138);
		else
			printf("NON %c vero che il massimo di ogni tripla %c pari\n",138,138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}