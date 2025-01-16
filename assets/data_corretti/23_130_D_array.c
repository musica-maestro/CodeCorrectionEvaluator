/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.8
*/
/* Specifica
INPUT: Una sequenza //**** MANCA LA LUNGHEZZA -0.2
PRECONDIZIONI: i valori della sequenza sono tutti interi
OUTPUT: un valore booleano tripla
POSTCONDIZIONI: tripla è true se nella sequenza esiste almeno una tripla in cui un elemento è il resto della divisione tra gli altri due.

TIPO DI PROBLEMA: Verifica Esistenziale */



#include <stdio.h>

/* funzione che restituisce 1(true) se esiste una terna di elementi tale che un elemento è multiplo di uno degli altri due, altrimenti restituisce 0(false)*/
int restoDivisione(int array[], int l){
	int i=0;		//var. contatore
	int risultato;	//var. per risultato

	for(int i=1; i<=l-2; i++){ //**** i<l-2 -0.5
		if(((array[i+1]%array[i+2])==array[i]) || ((array[i+2]%array[i+1])==array[i]) ||
			((array[i]%array[i+2])==array[i+1]) || ((array[i+2]%array[i])==array[i+1]) ||
			((array[i+1]%array[i])==array[i+2]) || ((array[i]%array[i+1])==array[i+2])){

			risultato = 1;
		}//******** COSI' RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
		else
			risultato = 0;
	}

	return risultato;

}


/*funzione principale*/
int main(){
	int lunghezza;		//var. lunghezza array
	int i;				//var. contatore
	int esiste;			//var. risultato

	/*inizializzazione di lunghezza*/
	printf("\nDi quanti elementi si compone la sequenza?\n");
	scanf("%d", &lunghezza);

	/*dichiarazione array e assegnazione*/
	int sequenza[lunghezza];

	for(i=1; i<=lunghezza; i++){
		printf ("Inserire l'intero: ");
		scanf("%d", &sequenza[i]);
	}

	esiste=restoDivisione(sequenza, lunghezza);

	if(esiste==1)
		printf("Esiste almeno una terna tale che un numero e' il resto degli altri due.");
	else
		printf("Non esiste nessuna terna tale che un numero e' il resto degli altri due.");

}