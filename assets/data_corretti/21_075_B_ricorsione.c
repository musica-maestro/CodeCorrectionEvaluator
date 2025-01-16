/*
5pt minimo dispari:..1.3
1pt scrivi numeri:...0.5
2pt quanti numeri:...0.3
2pt leggi numeri:....1.5
TOTALE ..............3.6
*/
#include <stdio.h>
#include <stdlib.h>

int minimo(int *seq, int length){ //**** i commenti! questa funzione ritorna vero se il minimo è dispari -0.2
	int mini;
	int mini1, mini2, mini3;
	if(length < 1)  //**** il minimo deve essere tra tre numeri, quindi length<3 -0.5
		mini = 0;
    else{
		if(seq[0] < seq[1] && seq[0] < seq[2]){
			mini1 = seq[0];
		}
		else if(seq[1] < seq[0] && seq[1] < seq[2]){
			mini2 = seq[1];
		}
		else if(seq[2] < seq[0] && seq[2] < seq[1]){
			mini3 = seq[2];
		}
		mini = ((mini1 % 2 == 1 || mini2 % 2 == 1 || mini3 % 2 == 1) || minimo(seq+1,length-1));
	}
	return mini;   //**** è complicatissima!
}

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int ex;
	int min = minimo(seq,lunghezza); //**** a ogni attivazione della funzione minimoDispari chiami minimo
                                     //**** che verifica se SU TUTTO il resto dell'array esiste una terna
	if(lunghezza < 3){               //**** che ha il minimo dispari -1.5
		ex = 1;
	}
	else{
		ex = ((min % 2 == 0) && minimoDispari(seq+1,lunghezza-1));
	}         //**** minimo è un valore booleano ed è 1 se esiste il minimo dispari, ma se è 1, min%2==0 è falsa! -1.5
	return ex;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("ric.dat", "rb");
	int *seq;
	int i;
	int quanti = 0;
	if(fp = NULL)  //**** == -0.2
		printf("Apertura file non riuscita\n\n");
	else{
		for(int i = 0; i < length; i++){ //**** ma length non la conosci, la funzione serve proprio a calcolarla! -1
			fread(&seq[i], "%d", 1, fp); // **** sizeof(int) -0.3
			quanti++;
		}
		printf("Lettura riuscita\n\n");
	}
//**** non chiudi il file -0.2
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("ric.dat", "rb");
	if(fp = NULL)  //**** == -0.2
		printf("Apertura file non riuscita\n\n");
	else{
		for(int i = 0; i < length; i++){
			fread(&seq[i], "%d", 1, fp); // **** sizeof(int) -0.3
		}
		printf("Lettura riuscita\n\n");
	}
}
//**** non chiudi il file -0.2

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("ric.dat", "wb");
	if(fp = NULL)  //**** == -0.2
		printf("Apertura file non riuscita\n\n");
	else{
		for(int i = 0; i < length; i++){
			fwrite(&seq[i], "%d", 1, fp); // **** sizeof(int) -0.3
		}
	}  //**** non chiudi il file -0.2
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
			printf("NON tutte le triple soddisfano tale condizione\n\n");
		else
			printf("Tutte le triple soddisfano tale condizione\n\n");

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
			printf("NON tutte le triple soddisfano tale condizione\n\n\n");
		else
			printf("Tutte le triple soddisfano tale condizione\n\n\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
