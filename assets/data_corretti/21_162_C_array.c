/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.2
*/
#include <stdio.h>

/* INPUT: un array e la sua lunghezza
 * PRE-CONDIZIONI: l'array contiene interi, lunghezza è un numero naturale //***** NADAVANO SOPRA, MA OK!
 * OUTPUT: messaggio //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * POST_CONDIZIONE: Il messaggio comunica all'utente se esiste una tripla di elementi consecutivi che contiene almeno due
 * elementi il cui valore è compreso fra -10 e 10 e che contiene esattamente due multipli di 3, oppure no */
 //******** POST-CONDIZIONE NON CORRETTA DEVI SPECIFICARE QUANDO L'OUTPPUT E' VERO O E' FALSO -0.3
 /* TIPO DI PROBLEMA = Verifica esistenziale */

 /* funzione per sapere se un intero è compreso tra -10 e 10 */
 int isComp (int n) {
	 return (n>=-10 && n<=10);
 }

 /* funzione per sapere se un intero è un multiplo di 3 */
 int isMult3 (int m) {
	 return (m%3 == 0);
 }

 int compresiMultipli3 (int array[], int lungh) {
	 int i;   //variabile per scorrere la stringa
	 int risultato = 0; //variabile booleana di ritorno

	 /* se esistono almeno una tripla con almeno due interi tra -10 e 10, e esattamente due multipli di 3, risultato=1 */
	 for (i=0; i<lungh-2; i++)
		if ( ( (isComp(array[i]) && isComp(array[i+1])) || (isComp(array[i]) && isComp(array[i+2]))
			|| (isComp(array[i+1]) && isComp(array[i+2])) )
			&& ( (isMult3(array[i]) && isMult3(array[i+1]) && !(isMult3(array[i+2])))
			|| (isMult3(array[i]) && !(isMult3(array[i+1])) && isMult3(array[i+2])) ||
			(!(isMult3(array[i])) && isMult3(array[i+1]) && isMult3(array[i+2])) ) )

			risultato = 1;

		return risultato;
 }


 int main () {
	 int lunghIN;      //lunghezza sequenza richiesta all'utente

	 /* chiedo all'utente quanti interi vuole inserire, e li acquisisco in lunghIN */
	 printf("\nCiao utente! Quanti interi contiene la tua sequenza? ");
	 scanf("%d", &lunghIN);

	 int seq[lunghIN];

	 /* chiedo all'utente di inserire gli elementi */
	 printf("\nBene! Adesso inserisci gli elementi:\n");
	 /* scorro la sequenza acquisendo ogni volta il numero inserito dall'utente */
	 for (int i=0; i<lunghIN; i++)
		 scanf("%d", &seq[i]);
	/* se la sequenza rispetta le condizioni, lo comunico all'utente */
	if (compresiMultipli3(seq, lunghIN)) {
		printf("\nBuone notizie! La sequenza da te introdotta possiede almeno una tripla di elementi");
		printf(" consecutivi che contiene almeno due elementi il cui valore %c compreso fra -10", 130);
		printf(" e 10 e che contiene esattamente due multipli di 3\n\n");
	}
	/* se la sequenza non rispetta le condizioni, lo comunico all'utente */
	else {
		printf("\nPessime notizie! La sequenza da te introdotta non possiede neanche una tripla di elementi");
		printf(" consecutivi che contiene almeno due elementi il cui valore %c compreso fra -10", 130);
		printf(" e 10 e che contiene esattamente due multipli di 3\n\n");
	}

 }
