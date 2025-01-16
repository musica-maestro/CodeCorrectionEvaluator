/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/* SPECIFICA
 * Input: una sequenza di interi e la sua lunghezza n
 * Pre-condizione: n>=3
 * Output: un valore booleano esisteTripla
 * Post-condizione: esisteTripla vale 1 se nella sequenza esiste una tripla di elementi adiacenti
 	tali che uno dei tre è il resto della divisione tra gli altri due. Vale 0 altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>

/* funzione che, dato un array di interi e la sua lunghezza, restituisce 1 se
	nella sequenza esiste una tripla di elementi adiacenti tali che uno dei tre
	è il resto della divisione tra gli altri due. Vale 0 altrimenti. */
int restoDivisione(int array[], int l) {
	int bVal=0;			// valore booleano da restituire

	for (int i=0; i<l-2 && bVal==0; i++) {
		/* array[i]==array[i+1]%array[i+2] || array[i]==array[i+2]%array[i+1] ||
		 	array[i+1]==array[i]%array[i+2] || array[i+1]==array[i+2]%array[i] ||
		 	array[i+2]==array[i]%array[i+1] || array[i+2]==array[i+1]%array[i] */

		/* considerata la terna di elementi i, i+1 e i+2, se uno di essi è il resto della divisione tra gli altri due */
		// printf("NEL FOR ALLin i%d val%d\n", i, bVal);
		if (array[i]==0) {
			if (array[i]==array[i+1]%array[i+2] || array[i]==array[i+2]%array[i+1] ||
		 		array[i+1]==array[i]%array[i+2] || array[i+2]==array[i]%array[i+1]) {
				/* la funzione restituirà 1 */
				bVal=1;

			}//***OK,PER EVITARE CHE IL DIVISORE FOSSE 0
		}
		else {
			if (array[i+1]==0) {
				if (array[i]==array[i+1]%array[i+2] || array[i+1]==array[i]%array[i+2] ||
					array[i+1]==array[i+2]%array[i] || array[i+2]==array[i+1]%array[i]) {
					/* la funzione restituirà 1 */
					bVal=1;

				}
			}
			else {
				if (array[i+2]==0) {
					if (array[i]==array[i+2]%array[i+1] || array[i+1]==array[i+2]%array[i] ||
		 				array[i+2]==array[i]%array[i+1] || array[i+2]==array[i+1]%array[i]) {
						/* la funzione restituirà 1 */
						bVal=1;

					}
				}
				else {
					if (array[i]==array[i+1]%array[i+2] || array[i]==array[i+2]%array[i+1] ||
		 				array[i+1]==array[i]%array[i+2] || array[i+1]==array[i+2]%array[i] ||
		 				array[i+2]==array[i]%array[i+1] || array[i+2]==array[i+1]%array[i]) {
						/* la funzione restituirà 1 */
						bVal=1;
					}
					// printf("ELSE i%d val%d\n", i, bVal);
				}
			}
		}

		// printf("NEL FOR ALLA FINE i%d val%d\n", i, bVal);
	}

	return bVal;
}

/* funzione principale */
int main(int argc, char const *argv[]) {

	/* messaggio */
	printf("Ciao! Questo programma verifica se in una sequenza di n interi esiste almeno una tripla ");
	printf("di elementi adiacenti tali che uno dei tre %c il resto della divisione tra gli altri due\n\n", 138);

	/* input1, lunghezza della sequenza */
	int n=0;								// lunghezza dell'array
	printf("Inserisci la lunghezza n=");
	scanf("%d", &n);
	printf("\n");

	/* input2, inserimento degli interi nella sequenza */
	int sequenza[n];						// array di lunghezza n dove verrà memorizzata la sequenza
	printf("Ora digita %d interi\n", n);
	for (int i=0; i<n; i++) {
		scanf("%d", &sequenza[i]);
	}
	printf("\n");

	/* verifica della condizione tramite funzione restoDivisione */
	int esisteTripla = restoDivisione(sequenza, n);

	/* output */
	if (esisteTripla==1)
		printf("SI, esiste una tripla di elementi dove uno dei tre %c il resto della divisione tra gli altri due\n", 138);
	else
		printf("NO, non esiste una tripla di elementi dove uno dei tre %c il resto della divisione tra gli altri due\n", 138);


	return 0;
}