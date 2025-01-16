/*
5pt minimo dispari:..4.4
1pt scrivi numeri:...1
2pt quanti numeri:...0.8
2pt leggi numeri:....2
TOTALE ..............8.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se per ogni tripla di interi adiacenti il minimo fra i 3 è dispari */
int minimoDispari(int *seq, int lunghezza){
    int tutti;
    if(lunghezza<2) //**** lunghezza <=2 -0.5
        tutti=1;
        else{
            tutti=((((seq[0]<seq[1]&&seq[0]<seq[2])&&(seq[0]%2!=0))||
                (seq[1]<seq[0]&&seq[1]<seq[2]&&(seq[1]%2!=0))||
                (seq[2]<seq[0]&&seq[2]<seq[1]&&(seq[2]%2!=0)))&&minimoDispari(seq+1,lunghezza-1));

                } //**** l'indentazione! -0.1
 return tutti;

}

/* funzione che conta quanti numeri ci sono nell'array in un file */
int quantiNumeri() {
  int quanti=0;
  FILE* fp=fopen("file.txt","r");
  if(fp==NULL)
      printf("Niente da contare!\n\n");
      else{
           int numero;
            fscanf(fp,"%d", &numero);
               quanti++;
//**** leggi solo un numero, perché manca il ciclo per l'acquisizione! -1.2

      fclose(fp);
      }

    return quanti;
}

/* funzione che legge un array di interi da un file */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("file.txt", "r");
    if(fp==NULL)
        printf("Niente da leggere!\n\n");
        else{
            for(int i=0; i<lunghezza; i++)
                fscanf(fp, "%d", &sequenza[i]);
        }
      fclose(fp);
}

/* funzione che scrive un array di interi su file */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("file.txt","w");
    if(fp==NULL)
        printf("File inesistente\n\n");
        else{
            for(int i=0; i<lunghezza; i++){
                fprintf(fp," %d ", sequenza[i]);

            }
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
			printf(" Ogni tripla di interi nella tua sequenza ha un minimo disparo \n"); //**** DISPARI!
		else
			printf(" Non è stato possibile trovare un minimo disparo in ogni tripla di elemnti adiacenti \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */

		lunghezza=quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		 int array[lunghezza];
		leggiNumeri(array, lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("  Ogni tripla di interi nella tua sequenza ha un minimo disparo \n");
		else
			printf("  Non è stato possibile trovare un minimo disparo in ogni tripla di elemnti adiacenti \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}