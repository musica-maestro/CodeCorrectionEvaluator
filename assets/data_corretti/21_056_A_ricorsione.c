/*
5pt massimo pari:..2
1pt scrivi numeri:.0
2pt quanti numeri:.1.3
2pt leggi numeri:..1.8
TOTALE ............5.1
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int risultato;
	/*PASSO BASE*/
	if(lunghezza<3)
		risultato=0; //**** errore nel tipo di verifica (scambia esistenziale con universale) -2
	else
		risultato=((seq[1]>seq[0])&&(seq[1]>seq[2])&&(seq[1]%2==0))||(massimoPari(seq+1,lunghezza-1));
	    //**** proprietà incompleta -1 il massimo potrebbe anche essere seq[0] o seq[2]
return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;
	FILE *fp=fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("file vuoto o non aperto correttamente");
	else
		while(fread(&quanti,sizeof(int),1,fp)>0)
		quanti++;
		//**** non puoi usare quanti sia per contare, sia per la fread,
		//**** così ad ogni lettura perdi il contatore e in quanti acquisisci
		//**** il valore letto dal file (in teoria) -0.5
return quanti;
}//**** non chiudi il file -0.2


/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","rb");
	if(fp==NULL)
		printf("file vuoto o non apeto correttamente");
	else
		fread(sequenza,sizeof(int),lunghezza,fp);
}//**** non chiudi il file -0.2


/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.txt","w");  //**** Usi un file di testo per scrivere e un file binario per leggere! -1
	if(fp==NULL)
		printf("file vuoto o non aperto correttamente");
	else{
		for(int i=0; i<lunghezza; i++){
			fprintf(fp," %d", sequenza[i]);}

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
			printf("\n verificato! il massimo fra tre interi della sequenza e' pari!\n");
		else
			printf(" \n non verificato \n");

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
			printf("\n verificato! il massimo fra tre interi della sequenza e' pari!\n");
		else
			printf(" \n non verificato \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}