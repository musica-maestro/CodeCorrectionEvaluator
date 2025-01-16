/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.3
*/
/* SPECIFICA

* INPUT: interi x1, x2, ...., xn; //******** MANCA LA LUNGHEZZA -0.2

*PRE-CONDIZIONE: numeri interi xn;

*OUTPUT: un intero 'tripla';

*POST-CONDIZIONE: 'tripla' risulta positivo quando all'interno della sequenza c'è una terna di elementi adiacenti in cui uno dei tre è il resto della divisione degli altri due,
				   altrimenti 'triple' risulta negativo.

*TIPO DI PROBLEMA: Problema di Verifica Esistenziale. */

#include <stdio.h>


int restoDivisione(int sequenza[], int lunghezza) {

	int i = 0;			//Variabile Contatore
	int tripla = 0;		//Variabile Esistenziale

	/* Inizio ciclo */
	while (i<lunghezza-3 && !(tripla)) { //**** i<=lunghezza-3 -0.5

		/* C'è un numero che è il resto della divisione tra gli altri due? */
		if(((sequenza[i+1]%sequenza[i+2] == sequenza[i]) || (sequenza[i] % sequenza[i+2] == sequenza[i+1]) || (sequenza[i] % sequenza[i+1] == sequenza[i+2]) ||
			 (sequenza[i+2]%sequenza[i+1] == sequenza[i]) || (sequenza[i+2] % sequenza[i] == sequenza[i+1]) || (sequenza[i+1] % sequenza[i] == sequenza[i+2])))		//verifico anche i numeri scambiati di posizione

			tripla = 1;		//variabile esistenziale inizializzata a 0 in modo da uscire dal ciclo

		/* Non c'è un numero che è il resto della divisione tra gli altri due? */
		else
			i++;		//passo al prossimo numero

	return tripla;

	}

}




/* Funzione Principale */
int main() {

	int lunghezza;		//lunghezza array

	/* Input */
	printf("Ciao utente, quanti numeri vuoi inserire?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];		//array con lunghezza data dall'utente

	for (int i=0; i<lunghezza; i++){
	printf("Dammi un elemento: ");
	scanf("%d", &sequenza[i]);
	}


	/* Output */
	if (restoDivisione(sequenza, lunghezza))
		printf("La sequenza contiene almeno una tripla di numeri adiacenti dove uno %c il resto della divisione degli altri due", 138);
	else
		printf("La sequenza NON contiene almeno una tripla di numeri adiacenti dove uno %c il resto della divisione degli altri due", 138);
}