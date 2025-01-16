/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione che indentifica il massimo tra tre interi*/
int massimo(int a, int b, int c){
	int max; //valore massimo tra i tre interi
	if(a>=b&&a>=c)
		max=a;
	else if(b>=c&&b>=a)
		max=b;
	else if(c>=a&&c>=b)
		max=c;
	return max;
}

/* funzione ricorsiva che verifica se in una sequenza di interi in ogni tripla di valori il maggiore di essi è pari */
int massimoPari(int *seq, int lunghezza){
	//PRE CONDIZIONE: la sequenza è di MINIMO 3 interi.
	int r; //risposta all'istanza, 1 se è verificata, 0 se non lo è.
	//passo base
	if(lunghezza<3) r=1;

	//passo ricorsivo
	else{
		r=((massimo(seq[lunghezza-1],seq[lunghezza-2], seq[lunghezza-3])%2==0&&massimoPari(seq, lunghezza-1)));
	}
	return r;}

/* funzione che conta quanti valori sono salvati su file*/
int quantiNumeri() {
	int quanti=0; //variabile contatore
	int temp;
	FILE* fp=fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("file non trovato\n");
	else{
		while(fread(&temp, sizeof (int), 1, fp)>0)
			quanti++;
		fclose(fp);}
return quanti;}

/* funzione che legge i valori da un file e li memorizza all'interno dell'array */
void leggiNumeri(int* sequenza, int lunghezza) {
FILE *fp=fopen("interi.dat", "rb");
if (fp==NULL)
	printf("file non trovato\n");
else{
	fread(sequenza, sizeof(int), lunghezza, fp);
	fclose(fp);}
}

/* funzione che scrive i valori dell'array inserito dall'utente in un file */
void scriviNumeri(int* sequenza, int lunghezza) {
FILE *fp=fopen("interi.dat", "wb");

if(fp==NULL)
	printf("file non trovato\n");

else{
	fwrite(sequenza, sizeof(int), lunghezza, fp);
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
			printf("in ogni tripla di valori consecutivi il valore massimo dei tre e' pari!\n");
		else
			printf("esiste almeno una tripla di valori consecutivi per cui il valore massimo non e' pari.\n");

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
			printf("in ogni tripla di valori consecutivi il valore massimo dei tre e' pari!\n");
		else
			printf("esiste almeno una tripla di valori consecutivi per cui il valore massimo non e' pari.\n");


		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
