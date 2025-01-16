/*
5pt massimo pari:..5
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............5
*/
#include <stdio.h>
#include <stdlib.h>
//funzione che calcola il massimo
int massimo(int i,int j,int z){
    int max=i;
    if(j>i && j>z)
        max=j;
    else if(z>max)
        max=z;
return max;
}

/* funzione ricorsiva che verifica ... */
int massimoPari(int seq[], int lunghezza){
    int risultato;
    if(lunghezza<3)
        risultato=1;
    else
        risultato=(massimo(seq[0],seq[1],seq[2])%2==0 && massimoPari(seq+1,lunghezza-1));
    return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* funzione che scrive ... */
/*//sbagliato
void scriviNumeri(int sequenza[], int lunghezza) {
    FOPEN *fp(fp,"interi.txt" "w");
    if(fp==NULL)
        printf("Apertura non riuscita.\n");
    else{
        for(int i=0;i<lunghezza;i++){
        fprintf(""); //**** devi scrivere su file!
        printf("Salvataggio farro.\n");
    }
}
}
*/

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
			printf(" Verificato! \n");
		else
			printf(" Non verificato!\n");

		/* salva la sequenza su file */
	//	scriviNumeri(array,lunghezza);
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
	//	scriviNumeri(array,lunghezza);
	}
}