/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.7
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.2
*/
#include <stdio.h>
/*SPECIFICA
 *input: sequenza di interi n (x1, x2,..., xn)  //**** MANCA LA LUNGHEZZA DELLA SEQUENZA -0.2
 *pre condizioni: n>=3
 *output: booleano esiste
 *post condizioni: esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione degli altri due
 //*** esiste E' VERO SE.... , FALSO ALTRIMENTI -0.2
 *tipo di PROBLEMA: esistenziale*/

/*Funzione restoDivisione*/
int restoDivisione ( int interi[], int dimensione) {
	int triple=1;
	int i;
	for (i=0; i<dimensione-2; i++) { //*** COSI' SCORRI TUTTA LA SEQUENZA ANCHE SE TROVI SUBITO LA TERNA CHE SODDISFA -0.3
		if(!((interi[i]%interi[i+1]==interi[i+2])||(interi[i+1]%interi[i+2]==interi[i])||
		     (interi[i]%interi[i+2]==interi[i+1])||(interi[i+1]%interi[i]==interi[i+2])||
		     (interi[i+2]%interi[i+1]==interi[i])||(interi[i+2]%interi[i]==interi[i+1])))
				triple=0;
	}
	return triple;
}

/*Funzione principale*/
int main () {
	int i;
	int lunghezza;
	printf("Ciao utente, quanti numeri vuoi inserire? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for (i=0; i<lunghezza; i++) {
		printf("Inserisci un numero: ");
		scanf("%d", &sequenza[i]);
	}
	if(restoDivisione(sequenza, lunghezza)==1)
		printf("Esiste una terna di elementi adiacenti in cui è presente almeno un elemento multiplo di uno degli altri due");
	else
		printf("Non esiste nessuna terna di elementi adiacenti in cui è presente almeno un multiplo di uno degli altri due");
                                                 //**** NO LETTERE ACCENTATE -0.1
}