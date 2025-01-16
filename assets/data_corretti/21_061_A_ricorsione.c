/*
5pt massimo pari:..5
1pt scrivi numeri:.0.5
2pt quanti numeri:.1.8
2pt leggi numeri:..1.5
TOTALE ............8.8
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica che in ogni tripla di interi consecutivi consecutivi nella sequenza è tale che
 * il massimo fra i tre interi è pari*/
int massimoPari(int *seq, int lunghezza){
    int verificato; //variabile booleana per il risultato
    int max;   //variabile per il massimo elemento della tripla

    /*CASO BASE*/
    if(lunghezza<=2){
        verificato=1;
    }

    /*PASSO RICORSIVO*/
    else{
        /*troviamo il massimo tra gli elementi della tripla*/
        if(seq[0]>seq[1] && seq[0]>seq[2]){
            max=seq[0];
        }
         else if(seq[1]>seq[0] && seq[1]>seq[2]){
            max=seq[1];
        }
        else if(seq[2]>seq[0] && seq[2]>seq[1]){
            max=seq[2];
        }
        verificato=(max%2==0) && massimoPari(seq+1,lunghezza-1);

    }
    return verificato;
}

/* funzione che conta ... */
int quantiNumeri() {
    int quanti=0;  //variabile per il numero degli elementi
    int numero;
    FILE* fp=fopen("interi.dat","rb");
    if(fp==NULL) {
        printf("File non esiste o non puo' essere aperto\n");
    }
    else{
        while(fread(&(numero),sizeof(int),1,fp)>0);
        quanti ++;
    }
    return quanti;
//**** non chiudi il file -0.2
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

    FILE* fp=fopen("interi.dat","rb");
     if(fp==NULL) {
        printf("File non esiste o non puo' essere aperto\n");
    }
    else{
        fread(&(sequenza),sizeof(int),lunghezza,fp); //**** nella fread primo parametro senza & -0.3


    }
//**** non chiudi il file -0.2

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE* fp=fopen("interi.dat","wb");
     if(fp==NULL) {
        printf("Salvataggio non riuscito\n");
    }
    else{
        fwrite(&(sequenza),sizeof(int),lunghezza,fp); //**** nella fread primo parametro senza & -0.3
    }//**** non chiudi il file -0.2
}


/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Caro utente sono un programma che inserita una sequenza verifica che ");
    printf("in ogni tripla di interi consecutivi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari\n",138,138);
    printf("Altrimenti leggo la sequenza memorizzat in un file\n");
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
			printf(" La sequenza e' tale che in ogni tripla il massimo tra i tre interi e' pari \n");
		else
			printf(" La sequenza e' tale che in ogni tripla il massimo tra i tre interi NON e' pari  \n");

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
			printf("  La sequenza e' tale che in ogni tripla il massimo tra i tre interi e' pari  \n");
		else
			printf("  La sequenza e' tale che in ogni tripla il massimo tra i tre interi NON e' pari  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}