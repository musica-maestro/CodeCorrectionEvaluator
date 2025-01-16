/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.2
*/
/*
INPUT: array e la sua lunghezza
PRE-CONDIZIONE: l'array deve contenere almeno 3 interi
OUTPUT:	il valore stamp
POSTCONDIZIONE: stamp == 1 //******** LA POST CONDIZIONE NON E' QUESTA -0.3
TIPO DI PROBLEMA: verifica universale

*/


#include <stdio.h>

int multipli(int sequenza[], int lunghezza){
	int i; //dichiaro il contatore 'i' per la lettura dell'array
	int stamp = 1; //inserisco un valore 'stamp' che restituirà se la successiva espressione è verificata o no

		for(i = 0; i < lunghezza-2 && stamp == 1; i++){ //leggo l'array
			if(sequenza[i] % sequenza[i+1] == 0 ||
			sequenza[i] % sequenza[i+2] == 0 ||
			sequenza[i+1] % sequenza[i+2] == 0 ||
			sequenza[i+1] % sequenza[i] == 0 ||
			sequenza[i+2] % sequenza[i+1] == 0 ||
			sequenza[i+2] % sequenza[i] == 0)
				stamp = 1;
			//******* METTERE LA VARIABILE A 1 NON SERVE (PERCHE' GIA' E' A 1), MA TI SALVI
			//******* PERCHE' HAI MESSO IL BOOLEANO NELLA CONDIZIONE DEL CICLO -0.5

			else
				stamp = 0;
	}




	return stamp;
}

int main(){
	int lunghezza;
	int i;

	printf("quanto e' lunga la sequenza di numeri che vuoi inserire? ");
	scanf("%d", &lunghezza); //richiedo la lunghezza dell'array

	int seq_numeri[lunghezza]; //dichiaro l'array

	for(i = 0; i < lunghezza; i++){ //ciclo for che richiede gli interi da inserire 'lunghezza' volte
		printf("inserisci un numero: ");
		scanf("%d", &seq_numeri[i]); //acquisisco il valore dell'intero
	}

	int result = multipli(seq_numeri, lunghezza); //richiamo la funzione 'multipli', assegnando il valore 'stamp' all'intero 'result'
	if(lunghezza >= 3){ //essendo la terna una precondizione, la funzione vale solo se sono presenti almeno 3 numeri
		if(result == 0) //se la condizione della funzione 'multipli' è falsa
			printf("non tutte le terne presentano multipli");
		else //se la condizione 'multipli' è vera
			printf("tutte le terne presentano almeno un numero multiplo di un altro");
	}
}