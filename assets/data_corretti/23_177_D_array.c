/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.4
*/
#include <stdio.h>

/*
Input: una sequenza di interi di lunghezza 'lunghezza'
Pre-condizione: lunghezza>=0
Output: un valore booleano 'esiste'
Post-condzione: 'esiste' vale true se esiste una tripla in cui uno dei tre è il resto della divisione degli altri due
//***FALSO ALTRIMENTI -0.1
TIPO DI PROBLEMA: verifica Esistenziale
*/

 /*funzione che vede se esiste una tripla che contiene almeno un elemento che è il resto degli altri due*/
int restoDivisione(int seq[], int lung){
    int i=0;
	int esiste=0;


	while(i<=lung-3 && !esiste){
	if((seq[i]%seq[i+1]==seq[i+2]) || (seq[i]%seq[i+2]==seq[i+1]) || (seq[i+1]%seq[i+2]==seq[i])||
		(seq[i+1]%seq[i]==seq[i+2]) || (seq[i+2]%seq[i]==seq[i+1]) || (seq[i+2]%seq[i+1]==seq[i]) )

		esiste=1;
	else
		i++;
    }
}


/*funzione principale*/
int main(){

	int lunghezza;
	int sequenza[lunghezza];

	printf("Ciao utente quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);

	for(int i=0; i<lunghezza; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	if(restoDivisione(sequenza, lunghezza))
		printf("Esiste una tripla che ha un elemento che %c uguale al resto della divione degli altri due! ", 138);
	else
		printf("NON esiste!"); //**** NON E' SIGNIFICATIVO, L'UTENTE VEDE SOLO QUESTA COMUNICAZIONE -0.5
}

