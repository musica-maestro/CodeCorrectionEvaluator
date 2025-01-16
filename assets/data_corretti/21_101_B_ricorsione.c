/*
5pt minimo dispari:..5
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............5
*/
#include <stdio.h>
#include <stdlib.h>

int MinimoDispari (int seq[], int lun) {
	int verifica;
	if(lun<=2)
		verifica=1;
		else
			verifica=(((seq[0]<seq[1] && seq[0]<seq[2] && seq[0]%2!=0)
			        || (seq[1]<seq[2] && seq[1]<seq[0] && seq[1]%2!=0)
			        || (seq[2]<seq[1] && seq[2]<seq[0] && seq[2]%2!=0))&& (MinimoDispari(seq+1,lun-1)));
			return verifica;
}
int main() {
    int lunghezza; 		//	lunghezza dell'array
		//	scelta dell'utente

		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++) {
			printf(" Dammi un numero");
			scanf("%d",&array[i]);

		}

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(MinimoDispari(array,lunghezza))
			printf(" Si, la sequenza soddisfa la richiesta \n");
			else
				printf("No, non soddisfa la richiesta");
}
