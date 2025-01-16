/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10
*/
/*SPECIFICA
 *Input: la sequenza deve avere una lunghezza e degli interi /
 * Output: restituisco 0 nel caso in cui la tripla cercata non esistesse e 1 nel caso in cui esistesse
 * TIPO DI PROBLEMA: verifica esistenziale
*/  //***** MACANO PRE E POST-CONDIZIONI -0.8

#include <stdio.h>

int compresiMultipli3 (int intero[], int lunghezza){

	int i;			//variabile contatore
	int esiste;		//variabile di esistenza

	esiste=0;
	i=2;

	while(i<lunghezza && !esiste){

		/* se ho almeno due elementi il cui valore e' compreso fra -10 e 10 */
		if ((((intero[i]>= -10) && (intero[i]<= 10)) && ((intero[i-1]>= -10) && (intero[i-1]<=10))) ||
			(((intero[i] >= -10) && (intero[i] <= 10)) && ((intero[i-2]>= -10) && (intero[i-2] <= 10))) ||
			(((intero[i-1] >= -10) && (intero[i-1] <= 10)) && ((intero[i-2] >= -10) && (intero[i-2] <= 10)))) {

				/*se ho almeno due elementi multipli di 3*/  //**** COMMENTO ERRATO: ESATTAMENTE, NON ALMENO -0.2
				if (((intero[i]%3== 0) && (intero[i-1]%3==0) && (intero[i-2]%3!=0)) ||
				    ((intero[i]%3==0) && (intero[i-2]%3==0) && (intero[i-1]%3!=0)) ||
				    ((intero[i-1]%3==0) && (intero[i-2]%3==0) && (intero[i]%3!=0))) {
						esiste = 1;
					}
				else
					i++;
			}
		else
			i++;
	}
	return esiste;
}

/*funzione principale*/

int main () {

	int lunghezza;		//numero di interi presenti nella sequenza

	printf("Caro utente questo e' un programma che data una sequenza di interi\n");
	printf("verifica se esiste una tripla di elementi consecutivi che contiene almeno\n");
	printf("due elementi il cui valore e' compreso fra -10 e 10 (estremi inclusi) e che\n");
	printf("contiene esattamente due elementi multipli di 3.\n\n");

	printf("\n\n");

	printf("Quanti interi vuoi inserire?");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci i tuoi interi: ");
		scanf("%d", &sequenza[i]);
	}
	if(compresiMultipli3(sequenza, lunghezza)) {
		printf("La tua sequenza contiene una tripla di elementi con almeno due\n");
		printf("elementi multipli di 3 e due elementi il cui valore e'compreso\n");
		printf("fra -10 e 10.\n\n");
	}
	else {
		printf("La tua sequenza non contiene una tripla di elementi con almeno\n");
		printf("due elementi multipli di 3 e due elementi il cui valore e' compreso\n");
		printf("fra -10 e 10.\n\n");
	}
}