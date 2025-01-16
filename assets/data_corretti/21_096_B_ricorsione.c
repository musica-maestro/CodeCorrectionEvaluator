/*
5pt minimo dispari:..4.1
1pt scrivi numeri:...1
2pt quanti numeri:...1.8
2pt leggi numeri:....2       output molto povero -0.2
TOTALE ..............8.9-0.2=8.7
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se, in un array di numeri interi, ogni tripla di interi consecutivi
nella sequenza è tale che il minimo tra i tre interi è dispari */

int minimoDispari(int *seq, int lunghezza){

	//pre: lunghezza è la lunghezza della sequenza

	int risultato; // variabile di stato

	/*CASO BASE*/

	if(lunghezza<=2)
		risultato = 1;

	/*PASSO RICORSIVO*/

	else
		risultato = (((seq[0]<seq[1] && seq[0]<seq[2]) && (seq[0]%2!=0) )
		          || ((seq[1]<seq[0] && seq[1]<seq[2]) && (seq[1]%2!=0))
		          || ((seq[2]<seq[1] && seq[2]<seq[0]) && (seq[0]%2!=0)) && (minimoDispari(*seq, lunghezza-1))) ;
	                                                  //**** seq[2] -0.2            //**** seq+1 -0.7


	return risultato;

	}

/* funzione che conta quanti numeri interi sono memorizzati su un file*/
int quantiNumeri() {
int quanti = 0; // variabile di conteggio
 FILE* fp = fopen("interi.dat", "rb");
 if(fp==NULL)
	printf("File non esiste o non puo' essere aperto!\n");
	else {
         int numero;
		 while(fread(&numero, sizeof(int), 1, fp))
             quanti++;
			 fclose(fp); //**** l'indetazione! -0.2
			 }
    return quanti;
}

/* funzione che legge una sequenza di interi da un file e li memorizza su un array che è ricevuto come parametro */
void leggiNumeri(int* sequenza, int lunghezza) {
	 FILE* fp = fopen("interi.dat", "rb");
	  if(fp==NULL)
		   printf("File non esiste o non puo' essere aperto!\n");
		   else {
			   fread(sequenza, sizeof(int), lunghezza, fp);
		       fclose(fp);
		   }
}

/* funzione che scrive i valori di un array di interi su un file */
void scriviNumeri(int* sequenza, int lunghezza) {
FILE* fp = fopen("interi.dat", "wb");
if(fp==NULL)
	printf("Salvataggio non riuscito\n");
	else {
		fwrite(sequenza, sizeof(int), lunghezza, fp);
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
			printf(" OK \n",138);
		else
			printf(" Riprova \n");

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
			printf(" OK! \n");
		else
			printf(" Riprova \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}





