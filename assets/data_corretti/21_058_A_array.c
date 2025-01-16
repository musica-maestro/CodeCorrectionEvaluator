/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8.3
*/
/* Specifica
 * Input: Una sequenza di n numeri.
 * Pre-condizione: ALmeno 3 numeri, che devono essere interi.
 * Output: Vero/falso (1 o 0).
 * Post-condizione: Restituisce 1 se è rispettata la condizione del problema (almeno una tripla con somma tra 10 e 20 e due numeri uguali).
 * TIPO DI PROBLEMA: Verifica esistenziale. */      // //******** POST-CONDIZIONE NON COMPLETA (manca il caso del falso) -0.2

#include <stdio.h>

/* Funzione che determina se una sequenza rispetta la condizione espressa dal problema. */
int ugualiCompresi(int *array, int lunghezza) {
	/* Pre: lunghezza >= 3 */

	int i;             //Contatore
	int risultato = 0; //Valore da restituire
	int somma;         //Somma della tripla
	int uguaglianze;   //Numeri uguali in una tripla

	for (i = 2; i < lunghezza; i++) {
		/* Calcolo la somma della tripla. */
		somma = array[i-2] + array[i-1] + array[i];
		//******** CONDIZIONE ERRATA: CALCOLI LA SOMMA DI TUTTI E TRE GLI ELEMENTI DELLA TRIPLA
		//******** MENTRE E' RICHIESTO CHE ALMENO 2 ELEMENTI DELLA TRIPLA HANNO UNA SOMMA COMPRESA TRA 10 e 20
		//******** ES. se la tripla e' 3 4 4 non ci sono due elementi della tripla la cui somma sia comrea tra 10 e 20
		//******** -1.5

		/* Conta le uguaglianze tra i numeri della tripla.
		 * Una uguaglianza -> due numeri uguali tra loro. */
		uguaglianze = (array[i] == array[i-1]) + (array[i-1] == array[i-2]) + (array[i] == array[i-2]);


		/* Se la condizione è rispettata aggiorna il risultato. */
		if ((uguaglianze == 1) && (somma >= 10 && somma <= 20)) {
			risultato = 1;
			break;
			//******** BREAK NON PERVENUTO! -0.5
			//******** DOVEVI USARE LA VARIABILE BOOLEANA NELLA CONDIZIONE DEL CICLO
		}
	}

	return risultato;
}

/* Gestisce l'interazione con l'utente. */
int main(int argc, char **argv) {
	int i;         //Contatore per la richiesta dell'array
	int lunghezza; //Lunghezza dell'array

	/* Chiede la lunghezza dell'array. */
	printf("Di quanti numeri %c composta la sequenza?\n", 138);
	scanf("%d", &lunghezza);

	int array[lunghezza]; //Array inserito dall'utente

	/* Chiede i numeri dell'array. */
	for(i = 0; i < lunghezza; i++) {
		printf("Inserisci il numero #%d\n", i+1);
		scanf("%d", &array[i]);
	}

	/* Verifica la sequenza e informa l'utente. */
	if (ugualiCompresi(array, lunghezza))
		printf("La sequenza rispetta la condizione\n"); //******** I/O MOLTO POVERO -0.5
	else
		printf("La sequenza non rispetta la condizione\n");

	return 0;
}
