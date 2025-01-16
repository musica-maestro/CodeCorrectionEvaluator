/*
5pt massimo pari:..4.9
1pt scrivi numeri:.1
2pt quanti numeri:.1.7
2pt leggi numeri:..2
TOTALE ............9.6
*/
#include <stdio.h>
#include <stdlib.h>
//funzione che calcola il massimo in una tripla
int max(int a, int b, int c){
	int max=a;	//variabile per il calcolo del massimo inizializzata al primo elemento
	if(a>b && a>c)
			max=a;	//*** già ci stava! -0.1
		else{
			if(b>a && b>c)
				max=b;
			else
				max=c;
		}
	return max;
}
/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	//pre-cond:l>=0
	int risultato;		//booleana di verifica universale
	//caso base
	if(lunghezza<3)
		risultato=1;
	//passo ricorsivo
	else{
		//verifico che il massimo nella prima tripla sia pari e ricorro sulla sequenza scalata di un posto avanti(accorciando la lunghezza)
		risultato=(max(seq[0],seq[1],seq[2])%2==0) && massimoPari(seq+1,lunghezza-1);
	}
	return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	//apertura del file di testo
	FILE *fp=fopen("interi.txt","r");
	int numero;	//appoggio per la lettura
	int quanti;	//variabile di conteggio  //**** non inizializzi quanti=0; -0.3
	if(fp==NULL)
		printf("Impossibile aprire file o file vuoto\n");
	else{
		//fino a che ci sono interi da leggere
		while((fscanf(fp,"%d",&numero))>0)
			quanti++;

		fclose(fp);	//chiudo il file
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	//apertura del file di testo
	FILE *fp=fopen("interi.txt","r");
	if(fp==NULL)
		printf("Impossibile aprire file o file vuoto\n");
	else{
		printf("File aperto\n");
		//scorro all'interno del file
		for(int i=0; i<lunghezza; i++){
			fscanf(fp,"%d",&sequenza[i]);
		}
		fclose(fp);	//chiudo il file di testo
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	//apertura del file di testo
	FILE *fp=fopen("interi.txt","w");
	if(fp==NULL)
		printf("Impossibile aprire file o file vuoto\n");
	else{
		//scorro all'interno del file
		for(int i=0; i<lunghezza; i++){
			fprintf(fp,"%d ",sequenza[i]);
		}
		printf("Salvataggio effettuato\n");
		fclose(fp);	//chiudo il file di testo
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
		printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo nella tripla %c pari \n",138,138);
	else
		printf("NON ogni tripla di interi consecutivi nella sequenza %c tale che il massimo nella tripla %c pari \n",138,138);

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
			printf("Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo nella tripla %c pari \n",138,138);
		else
			printf("NON ogni tripla di interi consecutivi nella sequenza %c tale che il massimo nella tripla %c pari \n",138,138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}