/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA

*Input: X1,X2,...,Xn e n

*Pre-condizione: X1,X2,...,Xn sono numeri interi e n>=3

*Output: Un valore booleano

*Post-condizione: Vale TRUE se In tutte le terne degli elementi adiacenti è presente un multiplo di uno degli altri due.
                  Altrimenti vale FALSE.

*TIPO DI PROBLEMA: Verifica Universale */


#include <stdio.h>

int Multipli(int sequenza[], int lunghezza) {
	int risultato=1;

	for(int z=0; z<lunghezza-2 && risultato==1; z++) {
		/*controllo se almeno un valore della tripla è un multiplo di uno degli altri due*/

		if(sequenza[z]%sequenza[z+1]!=0  &&
		sequenza[z]%sequenza[z+1]!=0 && //**** z+2 -0.2
		sequenza[z+1]%sequenza[z]!=0  &&
		sequenza[z+1]%sequenza[z+2]!=0 &&
		sequenza[z+2]%sequenza[z]!=0  &&
		sequenza[z+2]%sequenza[z+1]!=0)
			risultato=0;
	}
	return risultato;
}




int main() {
	int lunghezza=0;
	int a=0; //variabile per invocare la funzione

	printf("Ciao utente, quanto vuoi che sia lunga la sequenza?\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for(int x=0; x<lunghezza; x++) { //inserisco i valori all'interno dell'array
		printf("Inserisci un intero, in posizione %d\n", x);
		scanf("%d", &sequenza[x]);
	}

	a=Multipli(sequenza, lunghezza);

	if(a==1)
		printf("In tutte le terne degli elementi adiacenti %c presente un multiplo di uno degli altri due\n", 138);
	if(a==0)
		printf("Non in tutte le terne degli elementi adiacenti %c presente un multiplo di uno degli altri due\n", 138);
}
