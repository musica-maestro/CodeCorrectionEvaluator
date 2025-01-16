/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/* SPECIFICA
* Input: una sequenza di interi seq e una lunghezza l
* Pre-condizioni: l è la lunghezza della sequenza seq ed è >= 3
* Output: un intero verificata
* Post-condizioni: verificata varrà 1 se per ogni terna di elementi nella sequenza
esiste almeno un elemento della terna multiplo di uno degli altri due,
* 0 in caso contrario
* TIPO DI PROBLEMA: Verifica universale
*/

#include <stdio.h>

//funzione che verifica se per ogni terna di elementi nella sequenza, esiste almeno un elemento della terna multiplo di uno degli altri duce
int multipli(int* seq, int lunghezza) {
	int i = 0;
	int verificata = 1; // verificata parte da 1 perché inizialmente si suppono che la proprietà valga per tutte le terne
	while(i<lunghezza-2 && verificata) {
	/* verifico che almeno 1 elemento della terna sia multiplo di uno degli altri due*/
	if((seq[i]%seq[i+1] == 0) || (seq[i]%seq[i+2] == 0) || (seq[i+1]%seq[i] == 0) || (seq[i+1]%seq[i+2] == 0) || (seq[i+2]%seq[i] == 0) || (seq[i+2]%seq[i+1] == 0))
			i++;
		else
			verificata = 0;
	}

	return verificata;
}

//funzione principale
int main() {

	int l; // lunghezza della sequenza
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d",&l);

	int seq[l]; // dichiarazione array
	for(int i = 0; i<l; i++) {
		printf("Inserisci valore con indirizzo %d: ",i);
		scanf("%d",&seq[i]);
	}

	if(multipli(seq,l))
		printf("Esiste almeno un valore multiplo degli altri due per tutte le triple");
	else
		printf("Non esiste almeno un valore multiplo degli altri due per tutte le triple");
}