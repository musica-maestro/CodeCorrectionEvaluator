/*
5pt massimo pari:..1.5
1pt scrivi numeri:.0.7
2pt quanti numeri:.1.7
2pt leggi numeri:..1.7
TOTALE ............5.6
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int massimo;
	//pre: lunghezzadeve essere >=3;
	if(lunghezza<3)
		massimo=0;     //**** errore nel tipo di verifica (scambia esistenziale con universale) -2
	else
		massimo=(((seq[0]%2==0)>seq[1] && (seq[0]%2==0)>seq[2])
		|| ((seq[1]%2==0)>seq[0] && (seq[1]%2==0)>seq[2])
		|| ((seq[2]%2==0)>seq[0] && (seq[2]%2==0)>seq[1])) || massimoPari(seq+1,lunghezza-1);
		//**** verifichi un'altra proprietà -1.5
		//**** (seq[1]%2==0)>seq[0] confronti un booleano che dice se un numero è pari o dispari, con il valore di seq[0]
	return massimo;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp=fopen64("massimoPari.dat","rb"); //**** non gestiamo file di grandi dimensioni....
	int quanti=0;
	if(fp!=NULL){ //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
		int massimo;
		while(fread(&massimo,sizeof(int),1,fp)){
			quanti++;
		}
		fclose(fp);
	}
		return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen64("massimoPari.dat","rb");  //
	if(fp!=NULL){
		fread(sequenza,sizeof(int),lunghezza,fp);
	}            //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
		fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen64("massimoPari.dat","wb");
	if(fp!=NULL){
	fwrite(sequenza,sizeof(int),lunghezza,fp);
	}          //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
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
			printf(" Esistono triple di interi consecutivi tale che il massimo fra i tre interi e' pari\n");
		else
			printf(" Non esistono triple di interi consecutivi tale che il massimo fra i tre interi e' pari\n");

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
			printf(" Esistono triple di interi consecutivi tale che il massimo fra i tre interi e' pari\n");
		else
			printf(" Non esistono triple di interi consecutivi tale che il massimo fra i tre interi e' pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}