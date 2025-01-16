/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
#include <stdio.h>
/*Specifica
 * INPUT: Una sequenza di interi e la sua lunghezza
 * Pre-condizioni: La sequenza inserita deve essere disoli interi
 * OUTPUT: Un valore booleano
 * Post-condizioni:Se il valore booleano è 1, stampa un messaggio che informa l'utente che nella sequenza inserita ogni tripla contiene esattamente 2 numeri maggiori o uguali a 5 e almeno 2 numeri pari, 0 altrimenti
 *Tipo di problema: Verifica Universale
 */

int maggiori5Pari(int sequenza[], int lunghezza) {
	int i;
	int verificato;
	verificato = 1;
	for(i=0; i<lunghezza-2 && verificato; i++)
		if(!(((sequenza[i]>=5 && sequenza[i+1]>=5 && sequenza[i+2]<5)
		||(sequenza[i+1]>=5 && sequenza[i+2]>=5 && sequenza[i]<5)|
		|(sequenza[i]>=5 && sequenza[i+2]>=5 && sequenza[i+1]<5)) &&
		((sequenza[i]%2==0 && sequenza[i+1]%2==0)
		||(sequenza[i+1]%2==0 && sequenza[i+2]%2==0)
		||(sequenza[i]%2==0 && sequenza[i+2]%2==0)
		||(sequenza[i]%2==0 && sequenza[i+1]%2==0 && sequenza[i+2]%2==0))))
		//******* L'ULTIMA CONDIZIONE NON SERVE
			verificato=0;
	return verificato;
}

int main() {
	int i;
	int lunghezza;
	printf("Inserisci la lunghezza della tua sequenza: ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("\nInserisci il %d%c elemento: ", i+1, 167);
		scanf("%d", &sequenza[i]);
	}
	if(maggiori5Pari(sequenza, lunghezza)==1)
		printf("La sequenza inserita contiene esattamente due valori maggiori o uguali a 5 e almeno due elementi pari\n");
	else
		printf("La sequenza inserita NON contiene esattamente due valori maggiori o uguali a 5 e almeno due elementi pari\n");
}
