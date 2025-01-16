/*
5pt massimo pari:..5
1pt scrivi numeri:.0
2pt quanti numeri:.2
2pt leggi numeri:..1.4
TOTALE ............8.4
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
    int verificata=0;
    if(lunghezza<3) //passo base
        verificata=1;
        /*passo induttivo,con la sequente condizione*/
    else {
        verificata=((seq[lunghezza-1]>seq[lunghezza-2] && seq[lunghezza-1]>seq[lunghezza-3] && seq[lunghezza-1]%2==0)
        || (seq[lunghezza-2]>seq[lunghezza-1] && seq[lunghezza-2]>seq[lunghezza-3] && seq[lunghezza-2]%2==0)
        || (seq[lunghezza-3]>seq[lunghezza-1] && seq[lunghezza-3]>seq[lunghezza-2] && seq[lunghezza-3]%2==0))
        &&  massimoPari(seq,lunghezza-1);
    }
    return verificata;
}

/* funzione che conta ... */
int quantiNumeri() {
    int quanti=0;
    int numero;
    int seq;
    FILE *fp=fopen("Numeri.dat","rb");
    if(fp==NULL) //controllo che il file esiste e sia possibile aprirlo
        printf("File inesistente o impossibile da aprire\n");
    else
        while(!seq) {
            seq=fread(&numero,sizeof(int),1,fp);
            quanti++;
    }
       fclose(fp);
    return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("Numeri.dat","rb");
    if(fp==NULL)
        printf("Impossibile leggere il file\n");
    else {
        sequenza=fread(&sequenza,sizeof(int),lunghezza,fp); //**** sequenza, non &sequenza! -0.3
    }                                                       //**** fread ritorna un int, sequenza è un indirizzo -0.3
    fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("Numeri.dat","wb");//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
    while(lunghezza!=0)
        sequenza=fwrite(&sequenza,sizeof(int),lunghezza,fp);//**** sequenza, non &sequenza! -0.3
}//**** non chiudi il file -0.2                             //**** fread ritorna un int, sequenza è un indirizzo -0.3

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
			printf("In ogni tripla il numoro maggiore e' pari! \n");
		else
			printf("Non in ogni tripla il numero maggiore e' pari \n");

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
			printf("In ogni tripla il numoro maggiore e' pari! \n");
		else
			printf("Non in ogni tripla il numero maggiore e' pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}

