/*
5pt massimo pari:..5
1pt scrivi numeri:.0.3
2pt quanti numeri:.1.3
2pt leggi numeri:..1.3
TOTALE ............7.9
*/
#include <stdio.h>
#include <stdlib.h>

int massimoPari(int *sequenza, int lunghezza) {
	int risultato;
	if (lunghezza<=2)
		risultato=1;
	else
		risultato = ((((sequenza[0]>sequenza[1])&&(sequenza[0]>sequenza[2]))&&(sequenza[0]%2==0))||
		(((sequenza[1]>sequenza[0])&&(sequenza[1]>sequenza[2]))&&sequenza[1]%2==0)||
		(((sequenza[2]>sequenza[0])&&(sequenza[2]>sequenza[1]))&&sequenza[2]%2==0)) && massimoPari(sequenza+1, lunghezza-1);
	return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;
	FILE *fp = fopen("interi.dat", "rb"); //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	while (fp!=NULL){
		fread(&fp, sizeof(int massimoPari));//**** sintassi fread (&intero,sizeof(int),1,fp)  -0.4
		quanti++;
	}
	return quanti;
	fclose(fp);

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb"); //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fread (&fp, sizeof(int massimoPari)); //**** sintassi fread (sequenza,sizeof(int),lunghezza,fp)  -0.4
	fclose(fp);
}


/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb"); //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fwrite(&fp, sizeof(int massimoPari));//**** sintassi fwrite (sequenza,sizeof(int),lunghezza,fp)  -0.4
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
			printf(" L'elemento massimo di ogni tripla dell'array e' pari \n");
		else
			printf(" L'elemento massimo di ogni tripla dell'array non e' pari  \n");

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
			printf(" L'elemento massimo di ogni tripla dell'array e' pari  \n");
		else
			printf(" L'elemento massimo di ogni tripla dell'array non e' pari  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
