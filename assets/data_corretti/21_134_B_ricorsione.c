/*
5pt minimo dispari:..0
1pt scrivi numeri:...0
2pt quanti numeri:...0.2
2pt leggi numeri:....0
TOTALE ..............0.2
*/
//esercizio sulla ricorsione
#include <stdio.h>
#include <stdlib.h>
 //minimo
 int minimoDispariRic(int* seq , int l){ //*** il minimo lo devi calcolare su 3 interi! -1.5
	 int minimo;
	 for(int i=0;i<l-2;i++){
		 if(seq[i]<minimo){ //**** confronti seq[i] con minimo a cui non è assgnato nessun valore -0.5
			 minimo=seq[i];
		 }
		 else
			 minimoDispariRic(i+1,l-1); //**** un ciclo for in una chiamata ricorsiva! -2
	 }
	 return minimo;
 }
/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int verifica=0;
	for(int i=0;i<lunghezza-2;i++){  //**** un ciclo for in una chiamata ricorsiva! -2
	if( minimoDispariRic(seq,lunghezza)%2!=0) //***** non esamini la terna, ma tutto l'array
		verifica=1;
		else
			minimoDispari (seq+1,lunghezza-1);
			return verifica;
}

/* funzione che conta ... */
int quantiNumeri() {
	 int conta;  //**** il contatore non è inizializzato -0.5
	  FILE *fp=fopen("interi.dat","r");
	  //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	  while(fp!=NULL){//**** while(fp!=NULL): così hai un loop infinito! -1
		  conta++;
	  }
	  fclose(fp);
	  return conta;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
          FILE *fp=fopen("interi.dat","r");
		  if(fp!=NULL){//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
			  for(int i=0;i<lunghezza;i++){
				  fscanf(fp,"%d%*c",&sequenza[i]);
			  }
      fclose(fp);
    }
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp=fopen("interi.dat","wb");
	fp=(int*)malloc(sizeof(int sequenza));//**** assegnazione incompatibile: fp è un puntatore a un file, non a un int -0.5
	fprintf(fp,"inserire i valori dell'array: "); //**** non devi richiedere i valori da input, li devi prendere dall'array -1
	for(int i=;i<lunghezza ;i++)
	fscanf(fp,"%d",&sequenza[i]); //**** per scrivere su un file ci vuole la fprintf -0.5
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
		if(minimoDispari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

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
			printf(" esiste un minimo in una tripla di valori tale che sia dispari\n");
		else
			printf(" non esiste un minimo in una tripla di valori tale che sia dispar \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}