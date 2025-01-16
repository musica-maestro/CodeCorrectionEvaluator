/*
5pt massimo pari:..1
1pt scrivi numeri:.0.1
2pt quanti numeri:.0
2pt leggi numeri:..1.1
TOTALE ............2.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in un array di numeri interi, ogni tripla di interi consecutivi e' tale che il max fra i tre parametri e' pari*/
int massimoPari(int *seq, int l){
	int trovato;
	/*CASO BASE*/ //**** non si capisce se stai facendo una verifica esistenziale o universale.
	if(l<3)
		trovato =0;//**** variabile di universalità inizializzata male -1
		else{ // PASSO
			if(((seq[0]%2==0)> (seq[1]&&seq[2]) ) //**** questa espressione è sintatticamente corretta, ma verifica altro. -1.5
			|| ((seq[1]%2==0)>(seq[0]&&seq[2]))
			|| ((seq[2]%2==0)>(seq[0]&&seq[1])) && seq+1, l-1)
				trovato=1;                     //**** devi richiamare la funzione, invece scrivi solo i parametri -1.5
		}

}

/* funzione che conta quanti interi sono memorizzati su file */
int quantiNumeri() {
	int quanti=0;

}

/* funzione che legge una sequenza di interi da un file*/
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.dat", "rb");
	//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fread(&sequenza, lunghezza, *fp); //**** sintassi fread (sequenza,sizeof(int),lunghezza,fp)  -0.4
    //**** non chiudi il file -0.2

}

/* funzione che scrive i valori di un array su file*/
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("interi.dat","wb"); //**** come sopra -0.9
	fwrite(&sequenza,lunghezza,*fp);
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
			printf(" hai trovato un intero di una tripla, che oltre ad essere il massimo e' anche pari \n");
		else
			printf(" non hai trovato l'intero desiderato \n");

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
			printf(" hai trovato un intero di una tripla, che oltre ad essere il massimo e' anche pari \n");
		else
			printf(" non hai trovato l'intero desiderato  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
