/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.9
*/
// SPEICIFICA:
// Input: array di interi e n come la sua lunghezza
// Pre-condizioni: n e' la lunghezza del'array
// OUTPUT: un valore intero univers
//Post-condizioni: se univers vale 1 la ogni tipla di elementi dell'array ha esattamente due valori positivi //********** FALSO, ALTRIMENTI -0.1
// TIPO DI PROBLEMA: VERIFICA UNIVERSALE


//funzione che riceve un array input e la sua lunghezza e verifica se in oni tripla ci sono esattaemnte due valori positivi

#include <stdio.h>

int duePositivi(int array[], int n){
	int i=0;  //variabile iterativa
	int univers = 1; //variabile output
	while(i<n-2 && univers){
		if((array[i]>=0 && array[i+1]>=0 && array[i+2]<0) || (array[i]>=0 && array[i+1]<0 && array[i+2]>=0) || (array[i]<0 && array[i+1]>=0 && array[i+2]>=0)){ //condizione per cui nella tripla ci sono esattamente de numeri positivi
			i++;
		}
		else
			univers = 0;
	}
	return univers;
}

int main(){
	int i=0;
	int n;
	printf("Sono un programma che verifica se in array di valori interi dati iput tutte le triple hanno \n");
	printf("esattamente due numeri positivi, includo lo zero tra i positivi\n");
	printf("Inserisci la lunghezza dell'array in esame\n");
	scanf("%d", &n);

	int array[n]; //dichiarazione array con la sua lunghezza

	for(i=0;i<n;i++){ //ciclo per salvare i valori nell'array
		printf("Inserisci un valore intero\n");
		scanf("%d", &array[i]);
	}

	//output
	if(duePositivi(array, n)){
		printf("Ci sono esattamente due valori positivi per ogni tripla dell'array\n");
	}
	else{
		printf("NON ci sono esattamente due valori positivi per ogni tripla dell'array\n");
	}
}