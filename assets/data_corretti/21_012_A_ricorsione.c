/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int pari=1;               //verifica universale
	if(lunghezza<3)       //passo base
		pari=1;
	else{                        //passo ricorsivo
		pari=((((seq[0]>seq[1])&&(seq[0]>seq[2])&&(seq[0]%2==0))
		|| ((seq[1]>seq[0])&&(seq[1]>seq[2])&&(seq[1]%2==0))
		|| ((seq[2]>seq[0])&&(seq[2]>seq[1])&&(seq[2]%2==0)))
&& massimoPari(seq+1, lunghezza-1));
	}
	return pari;
}
/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;                                  //inizializzo il contatore a 0
	FILE*fp=fopen("interi.dat", "rb");    //apro il file
	if(fp==NULL)
		printf("file non esiste o non puo' essere aperto\n");
	else{
		int numero;
		while(fread(&numero, sizeof(int), 1, fp))           //verifico se ci sono elementi
			quanti++;
	}
		fclose(fp);
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("file non esiste o non puo' essere aperto\n");
	else
		fread(sequenza, sizeof(int), lunghezza, fp);   //leggo gli elementi tutti insieme: so gia la lunghezza
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.dat", "wb");
	if(fp==NULL)
		printf("salvataggio non riuscito\n");
	else
		fwrite(sequenza, sizeof(int), lunghezza, fp);        //scrivo gli elementi tutti insieme: so gia la lunghezza
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
			printf(" in tutte le terne il valore massimo %c pari\n", 138 );
		else
			printf("NON in tutte le terne il valore massimo %c pari\n", 138 );

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
			printf(" in tutte le terne il valore massimo %c pari\n", 138);
		else
			printf(" NON in tutte le terne il valore massimo %c pari\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}