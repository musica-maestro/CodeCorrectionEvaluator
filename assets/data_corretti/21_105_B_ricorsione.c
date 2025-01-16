/*
5pt minimo dispari:..3
1pt scrivi numeri:...0.8
2pt quanti numeri:...1.8
2pt leggi numeri:....1.8
TOTALE ..............7.4
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se  nell array di interi ogni tripla presenta il minimo tra i tre dispari.
 * TIPOLOGIA: problema ricorsivo di verifica universale*/
int minimoDispari(int *seq, int lunghezza){
    int verifica = 1;
   /*caso base*/
    if(lunghezza<=2)
        verifica=0;  //**** variabile di universalità inizializzata male -1
   /*passo ricorsivo*/
    else{
        verifica= (((seq[0]<0) && (seq[0]<seq[1]) && (seq[0]<seq[2]))||
                    ((seq[1]<0) && (seq[1]<seq[0]) && (seq[1]<seq[2]))||
                     ((seq[2]<0) && (seq[2]<seq[0]) && (seq[2]<seq[1]))&& (minimoDispari(seq+1, lunghezza-1)));
    }               //**** proprietà incompleta -1 manca la verifica che il minimo sia dispari
    return verifica;
}

/* funzione che conta quanti interi sono presenti nella sequenza
 * scritta sul file per creare la lunghezza */
int quantiNumeri() {
   int conta= 0;
   FILE* fp=fopen("interi.txt", "r");                       //apriamo il file in lettura
   if(fp==NULL)
       printf("apertura file non riuscita\n\n");
    else{
        int numero;                                 //per poter contare gli interi, ma non per tenerne traccia
            while(fscanf(fp,"%d, ", &numero)!=EOF){
            conta++;
        }
    }//**** non chiudi il file -0.2
    return conta;
}

/* funzione che legge gli interi salvati sul file .txt e li restituisce a main */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("interi.txt","r");
    if(fp==NULL)
        printf("apertura file non riuscita\n\n");
    else{
        printf("ecco gli interi recuperati da file\n\n");
        for(int i= 0; i<lunghezza; i++){
            fscanf(fp, "%d, ", &sequenza[i]);
        }
    }//**** non chiudi il file -0.2
}

/* funzione che scrive gli interi inseriti dall'utente, su di un file .txt */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("interi.txt", "w");                              //apertura file in scrittura
    if(fp==NULL)
        printf("apertura file non riuscita\n\n");
    else{
        for(int i= 0; i<lunghezza; i++){
            fprintf(fp, "%d, ", sequenza[i]);
        }
        printf("salvataggio riuscito\n\n");
    }
}//**** non chiudi il file -0.2

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
			printf(" la sequenza introdotta contiene il minimo intero dispari in ogni tripla consecutiva\n");
		else
			printf(" la sequenza introdotta non contiene il minimo intero dispari in ogni tripla consecutiva \n");

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
			printf(" la sequenza introdotta contiene il minimo intero dispari in ogni tripla consecutiva \n");
		else
			printf(" la sequenza introdotta non contiene il minimo intero dispari in ogni tripla consecutiva \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}