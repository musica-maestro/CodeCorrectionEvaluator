/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.7
*/
/* SPECIFICA
 * Input: valore per lunghezza, valori per l'array //******* MANCANO I TIPI DI DATO -0.2
 * Pre-condizione: lunghezza > 3
 * Output: valore booleano che verifica o no l'istanza;
 * Post-condizione: ogni terna dell'array deve avere almeno un numero multiplo di uno degli altri due;
 //******** FALSO, ALTRIMENTI -0.1
 * TIPO DI PROBLEMA: Verifica universale.
 */
#include <stdio.h>

/* Definiamo la funzione "multipli", che per ogni terna di elementi
   verifica se un elemento è multiplo di uno degli altri due.*/

int multipli(int sequenza[], int lunghezza){

	int i;             // contatore per scorrere la sequenza
	int numero = 1;    // variabile di verità, che verrà restituita alla fine della funzione

/*  per ogni valore di i, vengono considerati i valori subito successivo e il numero dopo al successivo,
	e ritorna un valore positivo se almeno una delle condizioni viene soddisfatta, ovvero se almeno uno dei numeri
	contenuti all'interno della terna è multiplo di uno degli altri due. */

	for(i=0;i<lunghezza-2;i++){

		if((sequenza[i]%sequenza[i+1]==0) || (sequenza[i]%sequenza[i+2]==0) ||
		   (sequenza[i+1]%sequenza[i]==0) || (sequenza[i+1]%sequenza[i+2]==0) ||
		   (sequenza[i+2]%sequenza[i]==0) || (sequenza[i+2]%sequenza[i+1]==0))
			//****** NON SERVE CAMBIARE DI VALORE SE E' VERIFICATO, BISOGNA CAMBIARE SE NON E' VERIFICATO -0.5
			numero = 1; // se è verificato, la variabile booleana non cambia di valore;
		else

			return 0; // se NON è verificato, la funzione ritorna subito 0, in quanto è un problema di verifica universale


	}//***** LA FUNZIONE DEVE ITORNARE UN VALORE, QUI IL RETURN E' NELL'ELSE -1.5
}




/* La funzione main chiede all'utente un input di interi e stampa un messaggio
   in base alla variabile ritornata dalla funzione "multipli". */

int main(){
	int lunghezza;  // variabile per definire la lunghezza dell'array

	printf("Caro utente, sono un programma che verifica, data una sequenza di interi, se esiste\n");
	printf("un elemento multiplo degli altri due per tutte le terne che vengono inserite.\n\n");
	printf("Prego utente, quanti interi vuoi inserire?\n");
	scanf("%d",&lunghezza);

	/*viene definita una condizione, ovvero che la lunghezza sia maggiore o uguale a 3, così da poter verificare tutte le terne adiacenti*/

	if(lunghezza<3)

		printf("Inserisci almeno tre interi!"); //se la lunghezza è minore di tre, il programma viene fermato

	else{         //il programma continua

		int sequenza[lunghezza]; //viene definito l'array "sequenza", contentente tanti interi quanta la lunghezza

	    /* viene chiesto all'utente di riempire l'array con dei valori interi*/

	    for(int i=0;i<lunghezza;i++){
		    printf("Inserisci i numeri: ");
		    scanf("%d",&sequenza[i]);
	    }

	        /* viene analizzato il valore booleano riportato dalla funzione "multipli", e viene stampato un messaggio */

	    if(multipli(sequenza, lunghezza))
		    printf("Per tutte le terne adiacenti della sequenza c'%c almeno un elemento multiplo degli altri due.",138);
	    else
		    printf("Il multiplo di uno degli altri due elementi di una terna non %c stato trovato in tutte le terne della sequenza.",138);
	    }








}