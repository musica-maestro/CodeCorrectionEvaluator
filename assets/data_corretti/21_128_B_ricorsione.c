/*
5pt minimo dispari:..1.2
1pt scrivi numeri:...0.7
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............1.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in ogni tripla della sequenza il minimo è un numero dispari */
int minimoDispari(int *seq, int lunghezza){

	int disp=1;
	int min;
	int i;
	if(lunghezza<3)
		printf>("non possso eseguire las verifica\n"); //*** sintassi -0.1
		else {
	/*PRECONDIZIONE= lunghezza array maggiore o uguale a 3*/
	while(seq[i]<lunghezza-3){  //***** ciclo while nella chiamata ricorsiva -2
								//***** confronti un elemento dell'array con la sua lunghezza -1.5
		/*verifico che per la prima tripla la condizione sia vera*/
		/*chiamata ricorsiva*/
		                  //**** seq[1] -0.2
		if(((seq[0]<=array[1] && seq[i]<=seq[2] && seq[0]%2!=0)
		|| (seq[1]<=seq[0] && seq[1]<=seq[2] && seq[1]%2!=0)
		|| (seq[2]<=seq[0] && seq[2]<=seq[1] && seq[2]%2!=0)) && (minimoDispari(array+1, lunghezza-1)==1)){
			}                                                                                //**** non serve
			else {

				disp=0;

		}
	}

	}
	return disp;
	}

/* funzione che conta ... */
int quantiNumeri(FILE* fp) {


}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp= fopen("inetri.txt", "r");

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat", "w");

	for(int i=0; i<lunghezza; i++)
		fwrite(fp, "%d", sequenza[i]);
		if(fp==NULL)  //************ magari lo devi verificare prima di scrivere! -0.3
			printf("salvataggio non riuscito\n");
			else
				printf("salvataggio riuscito\n");


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
		if(minimoDispari(array,lunghezza)==0)
			printf("La sequenza che hai introdotto non ha tutti i mininimi delle triple consecutive dispari \n");
		else
			printf("La sequenza che hai introdotto ha tutti i mininimi delle triple consecutive dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}


