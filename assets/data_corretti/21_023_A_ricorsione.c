/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..1.8
TOTALE ............9.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se tutte le triple della sequenza hanno come massimo
un intero che sia pari */
int massimoPari(int *seq, int lunghezza){
    int risultato; //valore da restituire: indica se le condizioni sono rispettate per tutte le triple
    /*caso base*/
    if(lunghezza<3) //dev'essere una tripla
        risultato=1;//condizione per problemi di verifica universale
    else //è presente almeno una tripla
        risultato=(((seq[0]>=seq[1] && seq[0]>=seq[2] && seq[0]%2==0) || (seq[1]>=seq[0] && seq[1]>=seq[2] && seq[1]%2==0)
            || (seq[2]>=seq[1] && seq[2]>=seq[0] && seq[2]%2==0)) && massimoPari(seq+1, lunghezza-1));
    return risultato;//restituisci il risultato

}

/* funzione che conta quanti interi sono salvati sul file */
int quantiNumeri() {
    int quanti=0; //quantità di numeri letti
    int n;  //variabile per gestire la lettura dal file
    /*apertura del file binario*/
    FILE *fp=fopen("interi.dat", "rb");
    if(fp!=NULL){
        while(fread(&n, sizeof(int), 1, fp)>0) //leggi un numero alla volta
            quanti++;                          //incrementa quanti
    }
    else
        printf("Impossibile aprire il file!\n");
    /*chiusura del file*/
    fclose(fp);

    return quanti;
}

/* funzione che legge gli interi dal file binario */
void leggiNumeri(int* sequenza, int lunghezza) {
    /*apertura del file*/
    FILE *fp=fopen("interi.dat", "rb");
    if(fp!=NULL){
        /*lettura dal file binario, la lumghezza già la conosciamo*/
        fread(sequenza, sizeof(int), lunghezza, fp);
        fclose(fp);           //chiusura del file
        printf("salvataggio riuscito!\n");  //**** casomai, acquisizione riuscita! -0.2
    }
    else
        printf("Impossibile aprire il file!\n");
}

/* funzione che scrive gli interi sul file binario */
void scriviNumeri(int* sequenza, int lunghezza) {
    /*apertura dal file*/
    FILE *fp=fopen("interi.dat", "wb");
    if(fp!=NULL){
        /*scrittura sul file binario, la lunghezza già la conosciamo*/
        fwrite(sequenza, sizeof(int), lunghezza, fp);
        fclose(fp);              //chiusura del file
        printf("salvataggio riuscito!\n");
    }
    else
        printf("Impossibile aprire il file!\n");
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
			printf("Ogni tripla della sequenza ha come massimo un intero pari!\n");
		else
			printf("Non tutte le triple della sequenza hanno come massimo un intero pari!\n");

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
			printf(" Ogni tripla della sequenza ha come massimo un intero pari! \n");
		else
			printf("Non tutte le triple della sequenza hanno come massimo un intero pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}