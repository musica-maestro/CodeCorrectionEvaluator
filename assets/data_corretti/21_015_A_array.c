/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................11
*/
/* SPECIFICA
 * Input: Una sequenza di interi ed un intero 'lunghezza'
 * Pre-condizione: 'lunghezza' e' un intero positivo ed e' la lunghezza della sequenza
 * Output: un intero 'verificata'
 * Post-condizione: 'verificata' e' uguale ad 1 se esiste almeno una terna di elementi consecutivi in cui la somma di due elementi e' compresa
 * 						tra 10 e 20 e che ha esattamente due elementi uguali tra loro, 0 altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale
 */

 #include <stdio.h>


 /* Funzione che riceve come parametri un array e la sua lunghezza e controlla se esiste almeno una tripla in cui la somma di due elementi e' compresa tra 10 e 20 ed ha esattamente due elementi uguali */
 int ugualiCompresi(int array[], int size){
	int i = 0;									// Variabile per scorrere l'array
	int verificata = 0;							// Variabile di esistenza inizializzata a 0

	/* Ciclo while per scorrere l'array fintanto che non arrivo all'elemento size -2 e fintanto che non ho trovato una terna che soddisfa le condizioni */
	while(i < size-2 && !verificata){
		/* Caso in cui la condizione di esistenza e' vera */
		 if((((array[i] + array[i+1]) >= 10 && (array[i] + array[i+1]) <= 20)
		 || ((array[i] + array[i+2]) >= 10 && (array[i] + array[i+2]) <= 20)
			|| ((array[i+1] + array[i+2]) >= 10 && (array[i+1] + array[i+2]) <= 20))
			&& ((array[i] == array[i+1] && array[i] != array[i+2])
			|| (array[i] == array[i+2] && array[i] != array[i+1])
			|| (array[i+1] == array[i+2] && array[i+1] != array[i])))
			verificata = 1;				// Ho trovato una terna. 'verificata' = 1 ed esco dal while
		/* Caso in cui la condizione non e' verificata */
		 else
			 i++;		// Incremento i
	 }
	return verificata;

 }

/* Funzione main */
int main(int argc, char **argv){
	int lunghezza; 						// Varaibile per la lunghezza dell'array
	int verificata; 					// Variabile in cui salvo il valore restituito dalla funzione  ugualiCompresi(int array[], int size)

	/* Input */
	printf("Quanti elementi vuoi inserire nella sequenza?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];			// Dichiaro un array di lunghezza 'lunghezza'

	/* Ciclo for per riempire l'array */
	for(int i = 0; i < lunghezza; i++){
		printf("Inserisci l'elemento %d della'array:   ", i);
		scanf("%d", &sequenza[i]);
	}



	/* Output */
	verificata = ugualiCompresi(sequenza, lunghezza); 			// Invoco la funzione  ugualiCompresi(int array[], int size) e salvo il valore nella variabile 'verificata'

	/* Se verificata == 1 ho trovato una terna che rispetta le condizioni */
	if(verificata == 1)
		printf("\nEsiste almeno una tripla in cui almeno due elementi hanno somma compresa tra 10 e venti ed esattamente due elementi sono uguali tra loro.\n");
	/* Se verificata == 0 non ho trovato una terna che rispetta le condizioni */
	else
		printf("\nNon esiste nessuna tripla in cui almeno due elementi hanno somma compresa tra 10 e venti ed esattamente due elementi sono uguali tra loro.\n");
}

