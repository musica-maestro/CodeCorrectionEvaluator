/*
5pt minimo dispari:..1
1pt scrivi numeri:...0
2pt quanti numeri:...1
2pt leggi numeri:....0
TOTALE ..............2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	/*caso base*/
	int min;
	int trovato=1;
	if(lunghezza==3){//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	min=seq[0];
	if(seq[1]<min)
		min=seq[1];
	else if(seq[2]<min)
		min=seq[2];
	if(min%2==0)
		trovato=0;
	}
	else{
		while(trovato==1){ //**** while nella funzione ricorsiva -2
			minimoDispari(seq+1,lunghezza-1);//**** non assegni il risultato della funzione a nessuna variabile -1
		}

	}

	return trovato;


}

/* funzione che conta ... */
int quantiNumeri() {
	FILE*fp=fopen("Interi.txt","r");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3


	int quanti=0;
	int tempo;
	while(tempo!=EOF){
		fscanf(fp,"%d",&tempo);
         //**** non incrementi il contatore nel while -0.5

	//**** non chiudi il file -0.2
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	;


}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.txt","w");
	//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	int i=0;
	while(i<=lunghezza){
	fprintf(fp,"%d",sequenza[i]);
	if(fp!=NULL)
		printf("Salvataggio riuscito\n");
    //**** loop infinito: non modifichi la i -0.5
    //**** non chiudi il file -.2

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
		if(minimoDispari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

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