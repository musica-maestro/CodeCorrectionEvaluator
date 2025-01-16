/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
#include <stdio.h>
/*Specifica:
 * INPUT: una sequenza di interi x1,...,xn ed un intero l
 * PREC: nessuna
 * OUTPUT: un intero tripla
 * POSTC: tripla vale 1 se esiste almeno una tripla che contiene alemeno due elementi il cui valore è compreso
 * tra -10 e 10 e che contiene esattamente due elementi multipli di tre, altrimenti 0
 * Problema di verifica esistenziale*/

int compresiMultipli3(int* seq, int dim) {
	int i = 0;				//contatore per far scorrere l'array
	int tripla = 0;			//variabile booleana

	while(i < dim-2 && !tripla) {
		if( ( ((seq[i] >= -10 && seq[i] <= 10)&&(seq[i+1] >= -10 && seq[i+1] <= 10)) ||
			((seq[i] >= -10 && seq[i] <= 10)&&(seq[i+2] >= -10 && seq[i+2] <= 10)) ||
			((seq[i+1] >= -10 && seq[i+1] <= 10)&&(seq[i+2] >= -10 && seq[i+2] <= 10)))&&
			((seq[i]%3 == 0 && seq[i+1]%3 == 0 && seq[i+2]%3 == 1) || (seq[i+1]%3 == 0 && seq[i+2]%3 == 0 && seq[i]%3 == 1) ||
			(seq[i+2]%3 == 0 && seq[i]%3 == 0 && seq[i+1]%3 == 1)))
			tripla = 1;
		else
			i++;
	}
	return tripla;
}


int main() {
	int lungh;
	printf("Quanto vuoi sia lunga la tua sequenza? ");
	scanf("%d", &lungh);

	/*creazione dell'array*/
	int sequenza[lungh];

	/*Inserisco i valori nel vettore*/
	for(int i = 0; i < lungh; i++) {
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	if(compresiMultipli3(sequenza, lungh)) {
		printf("\nEsiste almeno una tripla di elementi che contiene almeno due elementi il cui valore ");
		printf("%c compreso fra -10 e 10 ed esattamente due multipli di 3.\n", 138);
	}
	else {
		printf("\nEsiste almeno una tripla di elementi consecutivi che non contiene almeno due elementi il cui valore ");
		printf("%c compreso fra -10 e 10 ed esattamente due multipli di 3.\n", 138);
	}
}
