/*
5pt massimo pari:..2.8
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............7.8
*/
#include <stdio.h>
#include <stdlib.h>


int massimo (int numero1,int numero2,int numero3){
	int massimo;// variabile da associare al massimo pari dei tre numeri
	if (numero1 >numero2 ){
		if(numero2>numero3)
			massimo = numero1;
		else{
			if(numero1>numero3)
				massimo=numero1;
			else
				massimo = numero3;
		}
	}
	else{
		if (numero2>numero3)
			massimo = numero2;
		else
			massimo = numero3;
	}
	return massimo; //**** molto complicata!! -0.1
}
/* funzione che restituisce 1 se numero pari , 0 altimenti*/
int ispari ( int n ){
	int pari;
	if ( n%2 == 0 )
		pari = 1;
	else
		pari = 0;
	return pari;//**** return (n%2==0); l'hai complicata parecchio -0.1
}
/* funzione ricorsiva che verifica la presenza di un massimo pari in ogni tripla, verifica universale */
int massimoPari(int *seq, int lunghezza){
	int mp; // valore booleano
	if (lunghezza==2){// caso base
		mp = 1 ;
	}//**** Passo base se lunghezza=1, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	else{ // passo ricorsivo
		mp = ispari(massimo(seq[lunghezza],seq[lunghezza-1],seq[lunghezza-2])) && massimoPari(seq,lunghezza-1); // verifico che il massimo sia anche pari per tutte le terne
	}    //**** seq[lunghezza] non è un elemento dell'array -1

	return mp;



}

/* funzione che conta quanti interi ci sono salvati nel file e restituisce questo numero di interi */
int quantiNumeri() {
	FILE * fp = fopen("interi.dat","rb");// chiudo il file
	int numeri;
	int letto=1;// verifica presenza di un elemento nel file
	int conto;// contatore
	conto = 0;
	while (letto){// finche ci sta qualcosa nel file
		letto=fread(&numeri,sizeof(int),1,fp);// lo leggo
		if (letto)
			conto++;// e lo conto
	}
	fclose(fp);// chiudo il file
	return conto;
}

/* funzione che legge gli interi da un file e li salva in un array */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen ("interi.dat","rb");
	for ( int i=0;i<lunghezza;i++){// aggiungo tutti gli elementi del file all'array
		fread(&sequenza[i],sizeof(int),1,fp);
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat","wb");// apro il file , se non esiste lo creo
	for ( int i=0;i<lunghezza;i++){// scrivo tutti gli elementi dell'array su di un file
		fwrite(&sequenza[i],sizeof(int),1,fp);
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
		if(massimoPari(array,lunghezza))
			printf("La sequenza di interi ha un massimo pari in ogni terna\n");
		else
			printf("Mi dispiace la sequenza NON ha un massimo pari in ogni terna \n");

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
			printf("La sequenza ha un massimo pari in ogni terna\n");
		else
			printf("La sequenza NON ha un massimo pari in ogni terna\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}