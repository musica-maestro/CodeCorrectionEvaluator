/*
5pt minimo dispari:..2.5
1pt scrivi numeri:...1
2pt quanti numeri:...0
2pt leggi numeri:....2
TOTALE ..............5.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica che in un dato array di interi, sapendo la sua lunghezza, in ogni tripla di numeri
 * consecutivi il numero minore Ã¨ dispari */
int minimoDispari(int *seq, int lunghezza) {
	int risultato;               //variabile risultato
/* caso base */
	if(lunghezza<=2) {
		risultato=1;
	}
/* passo ricorsivo */
	else {  //**** seq[lunghezza] non fa parte dell'array! -1
		if((seq[lunghezza-2]<seq[lunghezza-1]&&seq[lunghezza-2]<seq[lunghezza]&&(seq[lunghezza-2]%2!=0)) ||
		(seq[lunghezza-1]<seq[lunghezza-2]&&seq[lunghezza-1]<seq[lunghezza]&&(seq[lunghezza-1]%2!=0)) ||
		(seq[lunghezza]<seq[lunghezza-1]&&seq[lunghezza]<seq[lunghezza-2]&&(seq[lunghezza]%2!=0))
		&& minimoDispari(seq+1,lunghezza-1)) {
			//**** se parti dalla fine non puoi escludere la prima componente dell'array,
			//**** ma devi solo ridurre la sua lunghezza -1.5
			risultato=1;
		}
		else
			risultato = 0;
	}
	return risultato;
}

/* funzione che conta il numero di interi totale salvati nel file */
int quantiNumeri() {
	int numero;                            //variabile contatore
	//**** il contatore non è inizializzato -0.5

	int intero;                            //variabile salvataggio temporaneo degli interi
	FILE* fp = fopen("interi.dat","rb");
   //**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5

	numero = fread(&intero,sizeof(int),1,fp); //**** serve un ciclo per contare gli elemnti del file! -1
	//**** non chiudi il file -0.2
	return numero;
}

/* funzione che legge i numeri salvati su "interi.dat" e li salva in un array */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat","rb");
	if (fp==NULL)
		printf("Caricamento non riuscito!\n");
	else {
		if(fread(&sequenza,sizeof(int),1,fp)==0)
			printf("Nessun intero memorizzato!\n");
		else {
			for(int i=0;i<lunghezza;i++) {
				fread(&sequenza[i],sizeof(int),1,fp);
			}
			printf("Caricamento completato!\n");
		}
		fclose(fp);
	}
}

/* funzione che scrive la sequenza di interi introdotta dall'utente su un file .dat */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat","wb");
	if (fp==NULL)
		printf("Salvataggio non riuscito!\n");
	else {
		for(int i=0;i<lunghezza;i++) {
			fwrite(&sequenza[i],sizeof(int),1,fp);
		}
		printf("Salvataggio completato\n");
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
		if(minimoDispari(array,lunghezza))
			printf("La sequenza contiene solo triple di numeri interi tali che il minore dei tre sia dispari\n");
		else
			printf("La sequenza non contiene soltanto triple di numeri nelle quali il minore e' dispari\n");

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
			printf("La sequenza contiene solo triple di numeri interi tali che il minore dei tre sia dispari\n");
		else
			printf("La sequenza non contiene soltanto triple di numeri nelle quali il minore e' dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}