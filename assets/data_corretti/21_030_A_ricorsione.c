/*
5pt massimo pari:..2.5
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..0
TOTALE ............2 //**** lascia i .... nell'output del main -0.5
*/
#include <stdio.h>

int massimoPari(int a[], int l){
    int esiste;
    if(l<3){
        esiste=0;//**** variabile di universalità inizializzata male -1
            }
    else{
        esiste=((a[0]>a[1] && a[1]>a[2] && a[0]>a[2] && a[0]%2==0)
																   //**** verifica della proprietà sbagliata -1.5
        ||(a[0]<a[1] && a[1]>a[2] && a[0]>a[2] && a[1]%2==0)       //**** (a[0]>a[1] && a[0]>a[2] && a[0]%2==0)
        //***** se avessi la terna [4,2,3] la proprietà non sarebbe verificata
        ||(a[0]>a[1] && a[2]>a[1] && a[0]<a[2] && a[2]%2==0) && massimoPari(a+1, l-1));
    }
    return esiste;
}
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
			printf(" ... \n");
		else
			printf(" ...\n");

		/* salva la sequenza su file */
    }
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];


		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */

	}
}