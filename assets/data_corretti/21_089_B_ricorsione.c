/*
5pt minimo dispari:..4.6
1pt scrivi numeri:...0.5
2pt quanti numeri:...1.5
2pt leggi numeri:....1.5
TOTALE ..............8.1
*/
#include <stdio.h>
#include <stdlib.h>


/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
    int r;
    if(lunghezza<3)
        r=1;
    else
        r= (!(minimo(seq[0],seq[1],seq[2])%2==0) && minimoDispari(seq+1, lunghezza-1));
        //**** se scrivi una funzione dopo averla richiamata, devi dichiarare la sua segnatura all'inizio -0.3
    return r;
}

int minimo(int a, int b, int c){
    if(a<b && a<c) return a;   //***** tre return!!! -0.1
    if(b<a && b<c) return b;
    if(c<a && c<b) return c;
}

/* funzione che conta ... */

//**** non segnali se l'apertura del file è fallita if(file==NULL) -0.3

//**** non chiudi il file -0.2

int quantiNumeri() {
    int v[100], i=0;
    FILE* file=fopen("interi.txt","r");
    while(fscanf(file,"%d",&v[i])>0)
        i++;
    return  i;
}

/* funzione che legge ... */

//**** non segnali se l'apertura del file è fallita if(file==NULL) -0.3

//**** non chiudi il file -0.2

void leggiNumeri(int* sequenza, int lunghezza) {
    FILE* file=fopen("interi.txt","r");
    for(int i=0; i<lunghezza; i++)
    fscanf(file,"%d",&sequenza[i]);
}

/* funzione che scrive ... */

//**** non segnali se l'apertura del file è fallita if(file==NULL) -0.3

//**** non chiudi il file -0.2

void scriviNumeri(int* sequenza, int lunghezza) {
    FILE* file= fopen("interi.txt","w");
    for(int i=0;i<lunghezza;i++)
    fprintf(file,"%d ",sequenza[i]);
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
			printf("la sequenza e' tale che per ogni tripla di interi il loro minimo e' dispari \n");
		else
			printf("la sequenza NON e' tale che per ogni tripla di interi il loro minimo e' dispari \n");

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
			printf("la sequenza e' tale che per ogni tripla di interi il loro minimo e' dispari \n");
		else
			printf("la sequenza NON e' tale che per ogni tripla di interi il loro minimo e' dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}