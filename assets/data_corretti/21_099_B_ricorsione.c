/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.5
2pt leggi numeri:....0
TOTALE ..............7.2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*FUNZIONE MINIMO DISPARI*/
int minimoDispari(int array[], int l) { // l rappresenta la lunghezza della sequenza
    int perfetto;
    if(l<=2)
        perfetto = 1;
    else {
        perfetto = ((array[l-1]%2!=0 &&(array[l-1]<array[l-2]) && (array[l-1]<array[l-3])) ||
        (array[l-2]%2!=0 &&(array[l-2]<array[l-1]) && (array[l-2]<array[l-3])) ||
        (array[l-3]%2!=0 &&(array[l-3]<array[l-2]) && (array[l-3]<array[l-1]))) &&
        minimoDispari(array,l-1);
    }
    return perfetto;
}

/*FUNZIONA SCRIVI NUMERI*/
void scriviNumeri(int array[], int lunghezza) {
    FILE *fp = fopen("scrivi.dat","wb");
    int i=0;
    if(fp!=NULL) {
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
        while(i<lunghezza) {
            fwrite(&array[i],sizeof(int),1,fp);
            i++;
        }
    }
    fclose(fp);
}

/******************/
/*QUANTI NUMERI*/
/*****************/
int quantiNumeri() {
    FILE*fp = fopen("scrivi.dat","rb");
    int i=0;
    int array[i]; //**** bastava una qualunque variabile intera, tanto serve solo per andare avanti con la lettura da file.
    if(fp!=NULL) {
//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
        while(fread(&array[i],sizeof(int),1,fp))
            i++;
    }
//**** non chiudi il file -0.2
    return i;
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
			printf("Tutti il numero piu picolo di ogni 3 sequenze conzecutivi sono dispari!\n\n");
		else
			printf("NON Tutti il numero piu picolo di ogni 3 sequenze conzecutivi sono dispari!\n\n");

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
