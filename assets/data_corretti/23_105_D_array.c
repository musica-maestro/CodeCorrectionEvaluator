/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
/*programma che verifica se all'interno di una sequenza di interi, esiste una tripla di elementi adiacenti
*in cui uno dei tre è il resto della divisione degli altri due*/
/*SPECIFICA:
*INPUT: una sequenza di interi x1, x2..., xn
*PRE-CONDIZIONE: lunghezza equivale alla dimensione della sequenza
*OUTPUT: un valore booleano trovata
*POST-CONDIZIONE: la funzione restituisce true se esiste una terna di elementi adiacenti all'array
in cui è uno dei tre è il resto della divisione degli altri due, restituisce false altrimenti*/

/*TIPO DI PROBLEMA: VERIFICA ESISTENZIALE*/

/*programma che verifica se all'interno di una sequenza di interi, esiste una tripla di elementi adiacenti
*in cui uno dei tre è il resto della divisione degli altri due*/

#include <stdio.h>

/*funzione invocata che restituisce true se esiste una terna di elementi adiacenti all'array
in cui è presente almeno un elemento multiplo di uno degli altri due, restituisce false altrimenti*/

int restoDivisione(int interi[], int lunghezza) {
	int i = 0;    //variabile contatore
	int trovata;  //variabile che verifica se sin dall'inizio si verifica la condizione
	trovata = 0;  //inizialemnete no

	while(i<=lunghezza-2 && !trovata) { //***** i<lunghezza-2 -0.5
		if((interi[i] % interi[i+1]==interi[i+2]) ||//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1
			(interi[i+1] % interi[i+2]==interi[i]) ||
			(interi[i] % interi[i+2]==interi[i+1]))
			trovata = 1;
		else
			i++;
	}
	return trovata;
}

/*funzione principale*/
int main() {
	/*input*/
	int lunghezza;    //per la dimensione della sequenza

	printf("Ciao Utente, sono un programma che verifica se, nella sequenza da te introdotta,\n");
	printf("esiste una tripla di elementi adiacenti in cui uno dei tre risulta essere\n");
	printf("il resto della divisione degli altri due.\n");
	printf("Ora tocca a te, quanti interi desisderi inserire?\n");
	scanf("%d", &lunghezza);


	int sequenza[lunghezza];
	for (int i = 0; i < lunghezza; ++i)
	 {
	 	/*inserisce un numero fino a che non arriva a quello desiderato dall'utente*/
	 	printf("Inserisci un intero!\n");
	 	scanf("%d", &sequenza[i]);
	 }

/*output*/
if(restoDivisione(sequenza, lunghezza))
	printf("\nGrandioso! Esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione degli altri due.");
else
	printf("\nSpiacente! Non esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione degli altri due.");




}




