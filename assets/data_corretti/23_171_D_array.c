/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9
*/
#include <stdio.h>

/*SPECIFICA
*Input: una sequenza di interi e la sua lunghezza
*Pre-condizione: la sequenza inserita deve contenere almeno una tripla di elementi
*Output: un valore tripla
*Post-condizione: tripla vale 1 se all'interno della sequenza esiste una tripla di elementi adiacenti
in cui uno dei tre è il resto della divisione degli altri due, vale 0 se all'interno della sequenza non esiste
una tripla di elementi adiacenti in cui uno dei tre è resto della divisione degli altri due

*TIPO DI PROBLEMA: verifica esistenziale*/

/* funzione che restituisce 1 se esiste una terna di elementi adiacenti nell'array in cui è presente almeno
un intero multiplo degli altri due*/
int restoDivisione(int sequenza[], int lunghezza){    //fornisco come parametri un array di interi e un intero che ne rappresenta la lunghezza
	int i = 0;    //variabile contatore
	int terna = 0;

	while ((i < lunghezza -1) && terna == 0){ //****** i < lunghezza -2 -0.5
		/*uno degli elementi della terna è resto degli altri due?*/
		if ((sequenza[i]%sequenza[i+1] == sequenza[i+2]) || (sequenza[i+1]%sequenza[i+2] == sequenza[i]) || (sequenza[i+2]%sequenza[i] == sequenza[i+1]))
			terna = 1;
		else
			terna = 0;
		if ((sequenza[i+1]%sequenza[i] == sequenza[i+2]) || (sequenza[i+2]%sequenza[i+1] == sequenza[i]) || (sequenza[i]%sequenza[i+2] == sequenza[i+1]))
			terna = 1;
		else
			terna = 0;//******* METTERE LA VARIABILE A 0 E'  PERICOLOSO E NON SERVE (PERCHE' GIA' E' A 0), MA TI SALVI
					  //******* PERCHE' HAI MESSO IL BOOLEANO NELLA CONDIZIONE DEL CICLO -0.5
		i++;
	}
	return terna;
}

int main(){
	int lunghezza; //lunghezza della sequenza
	int terna;
	printf("Ciao! Sono un programma che, data una sequenza di interi, verifica che esista una tripla di elementi adiacenti in cui uno dei tre sia il resto della divisione degli altri due.\n");

	/*INPUT*/
	printf("Introduci la lunghezza della sequenza.\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for (int i = 0; i < lunghezza; i++){
		printf("Introduci l'intero i[%d]\n", i);
		scanf("%d", &sequenza[i]);
	}

	terna = restoDivisione(sequenza, lunghezza);

	/*OUTPUT*/
	if (terna == 1)
		printf("All'interno della sequenza esiste una terna di elementi adiacenti in cui uno dei tre %c resto della divisione degli altri due.\n", 138);
	if (terna == 0)
		printf("All'interno della sequenza non esiste una terna di elementi adiacenti in cui uno dei tre %c resto della divisione degli altri due.\n", 138);
}