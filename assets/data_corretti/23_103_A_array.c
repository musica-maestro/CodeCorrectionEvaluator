/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA

    INPUT: UNA SEQUENZA DI INTERI E LA SUA LUNGHEZZA l
    PRE- CONDIZIONI: UNA LUNGHEZZA L >= 0
    OUTPUT: UNA VALORE BOOLEANO VERIFICATO
    POST - CONDIZIONE: VERIFICATO E' 1, SE PER CIASCUNA TERNA DI ELEMENTI ADIACENTI ALLA SEQUENZA, CI SIA ALMENO UN ELEMENTO DELLA TERNA MULTIPLO DI UNO DEGLI ALTRI DUE, 0 ALTRIMENTI
    TIPO DI PROBLEMA: VERIFICA UNIVERSALE */

#include <stdio.h>

int Multiplo (int array[], int lunghezza) {
	int verificato = 1; // visto che à un problema di verifica universale
	int i = 0;

	while ( i < lunghezza - 2 ) {//**** SE NON SCRIVE && verificato ESAMINI SEMPRE TUTTA LA SEQUENZA -0.2

		if ( !(array[i]%array[i+1] == 0) && !(array[i]%array[i+2] == 0) ) { // se il primo numero della tripla non è multiplo del secondo e del terzo, entra
			if ( !(array[i+1]%array[i] == 0) && !(array[i+1]%array[i+2] == 0) ) { // se il secondo della tripla non è multiplo del primo e del terzo, entra
				if ( !(array[i+2]%array[i+1] == 0) && !(array[i+2]%array[i] == 0) ) { // se il terzo numero della tripla non è multiplo del secondo e del terzo, allora
					verificato = 0; // il problema non è verificato
				}
			}
		}

		i++; // ciclo continua
	}

	return verificato;
}

int main () {
	int lunghezza;
	int verificato;

	printf("\nIn questo programma verifichiamo se per ciascuna terna di elementi adiacenti della sequenza, ci sia almeno un elemento della terna multiplo di uno degli altri due");
	printf("\nCiao utente, quanto deve essere lunga la sequenza?  ");
	scanf("%d", &lunghezza);

	int array[lunghezza]; //dichiaro la sequenza

	for ( int i = 0; i < lunghezza; i++ ) {
		printf("\nInserisci un numero:  ");
		scanf("%d", &array[i]);
	}

	/* Invoco la funzione */
	verificato = Multiplo ( array, lunghezza);

	if ( verificato == 0 ) {
		printf("\nIl mutiplo di uno degli altri due elementi della terna non %c stato trovato in tutte le terne della sequenza", 138);
	}
	else {
		printf("\nIn tutte le terne di elementi adiacenti della sequenza %c presente almeno un elemento multiplo di uno degli altri due", 138);
	}

}