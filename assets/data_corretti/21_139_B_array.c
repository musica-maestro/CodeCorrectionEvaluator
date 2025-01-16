/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10.2
*/
/* SPECIFICA
 * Tipo di problema: Verifica universale
 * Input: Array di numeri interi
 * Precondizione: Verificare se ogni tripla di numeri contiene esattamente due numeri maggiori o uguali a 5 e almeneo due numeri pari
  //********* QUESTA SAREBBE LA POST-CONDIZIONE  (che invece manca) -0.6
 * Output: Risultato controllo //******** OUTPUT: MANCA IL TIPO -0.2
 * */
#include <stdio.h>

int maggiori5Pari (int arr[], int lung) {
	int tutto = 1;
	for (int i = 0; i < lung-2 && tutto == 1; i++) { //******** == 1 BRUTTO!!
		// Reinizzializa i valori per la successiva tripla di numeri
		int pari = 0;
		int maggCin = 0;
		// Controlla nei successivi 3 numeri le condizioni del problema
		for (int j = i; j < i+3; j++) {
			if (arr[j] % 2 == 0) { //Controlla se è pari
				pari=pari+1;
			}
			if (arr[j] >= 5) { //Controlla se maggiore o uguale a 5
				maggCin=maggCin+1;
			}
		}
		// Controlla se la tripla di numeri non rispetta le condizioni
		if (!(pari >= 2 && maggCin == 2)) {
			tutto = 0;
		}
	}
	return tutto;
}

int main(int argc, char **argv)
{
	// Inizzializzazione variabili e input
	int lung;
	printf("Quanti interi ha la sequenza: ");
	scanf("%i", &lung);
	int arr[lung];

	// Inizializzazione array con i dati forniti dall' utente
	for (int i = 0; i < lung; i++) {
		printf("Inserisci il %i intero: ", i+1); //******* DI SOLITO SI USA %d, NON %i
		scanf("%i", &arr[i]);
	}
	// Stampa del risultato
	if (maggiori5Pari(arr, lung)) {
		printf("\n\nOgni tripla di numeri contiene esattamente due numeri maggiori o uguali a 5 e almeneo due numeri pari\n\n");
	} else {
		printf("\n\nOgni tripla di numeri NON contiene esattamente due numeri maggiori o uguali a 5 e almeneo due numeri pari\n\n");
	}

	return 0;
}
