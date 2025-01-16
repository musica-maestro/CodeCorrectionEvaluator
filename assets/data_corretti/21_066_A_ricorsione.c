/*
5pt massimo pari:..5
1pt scrivi numeri:.0.3
2pt quanti numeri:.1.3
2pt leggi numeri:..1.3
TOTALE ............7.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int verificato;
	int max;
	if(lunghezza<=2)
		verificato = 1;
	else{
		max = seq[0];
		if(seq[1]>max)
			max = seq[1];
		else if(seq[2]>max)
			max = seq[2];
		verificato = (max%2==0) && massimoPari(seq+1, lunghezza-1);
	}
	return verificato;
}

/* funzione che conta ... */
int quantiNumeri() {
	int numeri = 0;
	int valore;
	FILE *fp = fopen("numeri.txt", "r");
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	while(fscanf(&valore, "%d", 1, fp)==1)//**** sintassi! fscanf(fp,"%d",&sequenza[i]); -0.4
		numeri++;
	fclose(fp);
	return numeri;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("numeri.txt", "r");
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i=0; i<lunghezza; i++)
		fscanf(&sequenza[i], "%d", 1, fp); //**** sintassi! fscanf(fp,"%d",&sequenza[i]); -0.4
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("numeri.txt", "w");
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	for(int i=0; i<lunghezza; i++)
		fprintf(&sequenza[i], "%d", 1, fp);//**** sintassi! fprintf(fp,"%d",sequenza[i]); -0.4
	fclose(fp);
	printf("Salvataggio effettuato\n");
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
			printf("Nella sequenza ogni massimo tra tre interi e' pari\n");
		else
			printf("Non tutte le triple nella sequenza hanno massimo pari\n");

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
			printf(" Nella sequenza ogni massimo tra tre interi e' pari \n");
		else
			printf(" Non tutte le triple nella sequenza hanno massimo pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}