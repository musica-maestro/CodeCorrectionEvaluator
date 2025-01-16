/*
5pt massimo pari:..4.8
1pt scrivi numeri:.0.7
2pt quanti numeri:.2
2pt leggi numeri:..1.7
TOTALE ............9.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ricorsivamnete se in un array lÃ¹il numero massimo di ogni tripla Ã¨ un numero pari */
int massimoPari(int a[], int n){
    int v = 1; //varaibile booleana per la specifica del problema
    //caso base n==2
    //**** non è solo n==2, ma anche 1 o 0.
    if (n>2) {
        //passo ricorsivo
        v = ((a[n-1]>a[n-2] && a[n-1]>a[n-3] && a[n-1]%2==0)
        || (a[n-2]>a[n-1] && a[n-2]>a[n-3] && a[n-2]%2==0)
        || (a[n-3]>a[n-1] && a[n-3]>a[n-2] && a[n-2]%3==0)) && massimoPari(a, n-1);
    }                                    //**** a[n-3]%2==0 -0.2
    return v;
}

/* funzione che conta il numero di interi persenti su un file */
int quantiNumeri() {
     FILE *fp = fopen("interi.dat", "rb"); //apro il file binario
     int letto; //conferma lettura
     int i = 0; //contatore
     int a; //per la lettura del file

    if (fp) {
        letto = fread(&a, sizeof(int), 1, fp);
        if (letto) ++i;
        while (letto) {
            letto = fread(&a, sizeof(int), 1, fp);
            if (letto) ++i; //i aumenta per ogni intero presente sul file
        }
    } else printf("File non aperto correttamente"); //se il file non si apre mando un messaggio di errore
    fclose(fp);
    return i;
}

/* funzione che legge i dati da un file e li trascrive in un array */
void leggiNumeri(int a[], int n) {
    FILE *fp = fopen("interi.dat", "rb"); //apro il file binario
    if (fp) { //**** meglio (fp!=NULL)
        for(int i=0; i<n; ++i) {
            //trascrivo tutti gli elementi
             fread(&a[i], sizeof(int), 1, fp);
        }
    }//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
    fclose(fp);
}

/* funzione che scrive i numeri presenti nell'array all'interno di un file binario */
void scriviNumeri(int a[], int n) {
    FILE *fp = fopen("interi.dat", "wb");
    //salvo ogni valore dell'array sul file incrementando i nel ciclo for
    for (int i =0; i<n; ++i) {
        fwrite(&a[i], sizeof(int), 1, fp);
    }//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
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
		if(massimoPari(array,lunghezza))
			printf("In ogni tripla dell'array l'elemento massimo e' pari \n");
		else
			printf("La condizione che in ogni tripla dell'array l'elemento massimo e' pari  non e' verificata\n");

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
			printf("In ogni tripla dell'array l'elemento massimo e' pari \n");
		else
			printf("La condizione che in ogni tripla dell'array l'elemento massimo e' pari  non e' verificata \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}