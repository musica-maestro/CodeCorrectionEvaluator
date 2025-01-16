/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.7
*/
/*
 INPUT: sequenza di interi n //**** DI LUNGHEZZA n -0.1
 PRE-CONDIZIONE: n > 2
 OUTPUT: valore booleano
 POST-CONDIZIONE: vero se esiste una terna di elementi adiacenti in cui un elemento è pari al resto della divisione degli altri due //********** FALSO, ALTRIMENTI -0.1
 TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>
#include <stdlib.h>

int restoDivisione(int array[], int dimensione) {
	int restoDiv = 0;
	for (int i=1; i<dimensione-1; i++) {
		if (array[i]==array[i+1]%array[i-1]||array[i]==array[i-1]%array[i+1]||
		    array[i-1]==array[i]%array[i+1]||array[i-1]==array[i+1]%array[i]||
		    array[i+1]==array[i]%array[i-1]||array[i+1]==array[i-1]%array[i]) {
			restoDiv = 1;
		}
	}
	return restoDiv;
}

int main(int argv, char **argc) {
	int lunghezza;
	printf("Ciao utente, quanto %c lunga la tua sequenza?\n", 138);
	scanf("%d", &lunghezza);
	if (lunghezza < 3) {
		printf("La tua sequenza non %c idonea.\n", 138);
		exit(-1);
	}
	printf("Ok ora dammene i valori:\n");
	int sequenza[lunghezza];
	for (int i=0; i<lunghezza; i++) {
		scanf("%d", &sequenza[i]);
	}
	if (restoDivisione(sequenza, lunghezza)) {
		printf("Complimenti! Esiste una terna di elementi adiacenti in cui un elemento è pari al resto della divisione degli altri due.\n");
	} else {
		printf("Mi dispiace! Non esiste una terna di elementi adiacenti in cui un elemento è pari al resto della divisione degli altri due.\n");
	}                                                                      //***** NO LETTERE ACCENTATE -0.1
}