/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..0     //******** MANCANTE
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.7
*/
/* SPECIFICA
 input: int n , int array[]
 pre-condizioni: n intero che rappresenta il numero di valori di array, array è un intero
 output: risultato
 post condizione: risultato uguale a 1 se esiste in una terna un numero che è il multiplo di un altro, 0 se la condizione è falsa
 */ //**** POSTCOND. ERRATA, RISULTATO=1 SE IN OGNI TERNA ESISTE UN NUMERO MULTIPLO DI UNO DEGLI ALTRI DUE, FALSO ALTR. -0.3

#include<stdio.h>

int multipli(int array[], int size){
	int esistenza = 0;		//variabile di appoggio
	int risultato = 0;		//variabile di ritorno

	for (int i = 1; i < size-1; i++){					//ciclo per tutti i valori dell'array
		if((array[i-1]%array[i] == 0) ||
		   (array[i+1]%array[i] == 0) ||
		   (array[i]%array[i-1] == 0) ||
		   (array[i]%array[i+1] == 0) ||
		   (array[i-1]%array[i+1] == 0) ||
		   (array[i+1]%array[i-1] == 0)){ //controllo se esiste almeno un numero che è un multiplo di uno tra i due rimanenti
			esistenza++;		//aumento esistenza //**** LO TRATTI COME UN PRLEMA DI CONTEGGIO, OK.
		}
	}
	if(esistenza == size -2){		//controllo se il numero di terne è ugale ad esistenza
		risultato = 1;				//imposto a ritorno il valore 1
	}
	return risultato;
}

int main(){
	int dimensione;			//dimensione array
	do{
		printf("Inserisci il numero di valori da controllare: ");
		scanf("%d", &dimensione);
	}while(dimensione < 3);		//controllo se ci sono almeno 3 elementi

	int array[dimensione];		//array con lunghezza: dimensione

	for(int i = 0; i < dimensione; i++){
		printf("Inserisci valore con posizione %d: ", i);
		scanf("%d", &array[i]);
	}

	if(multipli(array, dimensione)){
		printf("La sequenza da te inserita rispetta la condizione per cui per ogni terna esiste almeno un numero tale che sia un multiplo di uno degli altri due \n");
	}else{
		printf("La sequenza da te inserita NON rispetta la condizione per cui per ogni terna esiste almeno un numero tale che sia un multiplo di uno degli altri due \n");
	}
}