/*
5pt massimo pari:..5
1pt scrivi numeri:.0
2pt quanti numeri:.2
2pt leggi numeri:..1.4
TOTALE ............7.9  //**** lascia i .... nell'output del main -0.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int ris;

	if(lunghezza<=3){
		//passo base
		ris=1;
	}
	else{
		//passo ricorsivo
		int massimoTripla;
		if(seq[0]>seq[1] && seq[0]>seq[2]){
			massimoTripla=seq[0];
		}else{
			if(seq[1]>seq[2]){
				massimoTripla=seq[1];
			}else{massimoTripla=seq[2];}
		}

		ris= ((massimoTripla%2==0) && (massimoPari(seq+1, lunghezza-1)));
	}
	return ris;

}

/* funzione che conta ... */
int quantiNumeri() {
	int lun;  //lunghezza da ritornare
	int garbage;
	FILE *fp= fopen("interi.dat", "rb"); //apro il file

	if(fp!=NULL){
		while(fread(&garbage, sizeof(int), 1,fp)>0){
			lun++;
		}
	}
	else{
		printf("File non trovato o vuoto! \n"); //File inesistente o vuoto
	}
	fclose(fp);
	return lun;

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE *fp=fopen("interi.dat", "rb");
	if(fp!=NULL){
		for(int i=0; i<lunghezza; i++){
			fread(&(sequenza[i]), sizeof(int), stdin);//**** sintassi fread (&(sequenza[i]),sizeof(int),1,fp)  -0.4
		}
	}
	else{
		printf("Non ci sono numeri nel file! \n") //**** manca il ; -0.2
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {


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
			printf("Si il massimo di ogni tripla %c pari!  \n",138);
		else
			printf("No il massimo di ogni tripla non %c pari!  \n",138);

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}