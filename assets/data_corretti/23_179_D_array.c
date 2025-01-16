/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
* INPUT: una sequenza di numeri e la sua lunghezza
* PRE-CONDIZIONE: almeno tre, interi
* OUTPUT: valore di verità (1 o 0)
* POST-CONDIZIONE: il valore risulta uguale a 1 se all'interno della sequenza
* esiste almeno una tripla in cui un elemento è uguale al resto della divisione
* tra interi tra gli altri due
* TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>

int resto (int, int, int);
int restoDivisione (int *, int);

/*funzione principale*/
int main () {

	/*presentazione programma*/
	printf ("sono un programma che analizza una sequenza e ti dico ");
	printf ("se esiste almeno una tripla\nin cui un elemento %c ",138);
	printf ("uguale al resto della divisione tra interi tra gli altri due,\n");

	int lunghezza;		//lunghezza array
	printf ("inserisci la lunghezza della sequenza:\n");

	/*inserimento lunghezza array (almeno tre elementi)*/
	do {
		scanf ("%d",&lunghezza);
		if (lunghezza<3)
			printf ("devi inserire almeno tre valori, riprova\n");
	} while (lunghezza<3);

	int sequenza [lunghezza];		//array di interi
	printf  ("inserisci i %d valori:\n",lunghezza);

	/*inserimento elementi array*/
	for (int i=0; i<lunghezza; i++)
		scanf ("%d",&sequenza[i]);

	/*verifica e stampa condizione*/
	if (restoDivisione(sequenza,lunghezza)) {
		printf ("si, esiste almeno una tripla in cui un elemento %c ",138);
		printf ("uguale al resto della\ndivisione tra interi tra gli altri due\n");
	}
	else {
		printf ("no, non esiste almeno una tripla in cui un elemento %c ",138);
		printf ("uguale al resto della\ndivisione tra interi tra gli altri due\n");
	}
}

/*funzione controllo condizione*/
int resto (int a, int b, int c) {
	return (a == (b%c));
}

/*funzione di controllo condizione finale*/
int restoDivisione (int s[], int l) {
	int i = 0;			//var contatore
	int esiste = 0;		//var di esistenza

	/*ciclo di controllo*/
	while (i<l-2 && !esiste) {
		if (resto(s[i],s[i+1],s[i+2]) || resto(s[i],s[i+2],s[i+1]) ||
			resto(s[i+1],s[i],s[i+2]) || resto(s[i+1],s[i+2],s[i]) ||
			resto(s[i+2],s[i],s[i+1]) || resto(s[i+2],s[i+1],s[i])) {

			esiste = 1;		//agg. var. esistenza
		}
		else
			i++;		//agg. var. contatore
	}
	return esiste;
}