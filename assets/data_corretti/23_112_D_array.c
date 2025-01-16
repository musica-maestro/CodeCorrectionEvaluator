/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.5
*/
/*

Specifica: Data una sequenza di interi, verificare se al suo interno esiste una tripla che contiene al suo interno il resto della divisione (tra interi) tra il primo e il terzo

Input: Sequenza di interi //**** MANCA LA LUNGHEZZA -0.2

Pre-condizione: Gli input devono essere interi

Output: un valore booleano

Post-condizione: nessuna //*** NO! MANCA -0.3

Tipo di problema: Verifica esistenziale

*/

#include <stdio.h>

// Dichiarazione funzione verifica resto

int restoDivisione (int seq[], int lunghezza){

	int risposta = 0;			//Dichiarazione variabile risposta: 0 se non c'e' una terna che soddisfa il problema e 1 viceversa

	/* Ciclo per il controllo delle terne ricercate

		Ciclo fiche la condizione non individua la terna necessaria o finche non finisce di leggere tutto l'array

		Nell'if verifico se la divisione tra il primo e il terzo elemento o tra il terzo e il primo a come resto il secondo

	*/

	for (int i = 0; i < lunghezza-1 && risposta == 0; i++){		//*** i<lunghezza-2 -0.5

		if(((seq[i] % seq[i+2]) == seq[i+1]) || ((seq[i+2] % seq[i]) == seq[i+1])){
        //**** MANCANO ALTRE QUATTRO COMBINAZIONI DA VERIFICARE -1.5
			risposta = 1;

		}

	}

	return risposta;

}

//Dichiarazione funzione main

int main(){

	// Inserimento grandezza array

	int n;

	printf("Inserire grandezza array:");
	scanf("%d", &n);

	// Dichiarazione array e riempimento

	int sequenza[n];

	for (int i = 0; i < n; i++){

		printf("Inserire valore %d dell'array:", i+1);
		scanf("%d", &sequenza[i]);

	}

	//Invocazione funzione restoArray e stampa della stringa conseguente

	int risposta = restoDivisione(sequenza, n);

	if (risposta == 0) {

		printf("Non e' presente una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione tra gli altri due\n");

	}else{

		printf("Esiste una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione tra gli altri due\n");

	}

}


