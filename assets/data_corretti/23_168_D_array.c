/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............5.5
*/
#include <stdio.h>

/*specifica del problema
input: un array di interi, e la sua lunghezza
precondizione: un intero rappresenta la lunghezza dell'array
output:un intero 1 oppure 0
postcondizione: il programma restituisce 1 se se esiste una terna di elementi
				adiacenti nella quale uno degli elementi è il resto
				della divisione degli altri due, 0 altrimenti
tipo di problema: verifica esistenziale
*/

int restoDivisione(int a[], int lung){
	int ris;
	for (int i=0; i<lung; i++){ //**** i=1; i<lung-1; -1
		if((a[i]%a[i+1] == a[i-1]) || (a[i-1]%a[i+1] == a[i]) ||
			(a[i]%a[i-1] == a[i+1]))//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1
			ris = 1;
		else
			ris = 0; //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	}
	return ris;
}

int main()
{
	int lunghezza;
	printf("salve utente, sono un programma che verifica l'esistenza di un \n");
	printf("elemento multiplo di altri elementi nell'array introdotto\n");
	printf("introduci la lunghezza dell'array\n");
	scanf("%d", &lunghezza);
	//printf("introduci l'array\n");
	int array[lunghezza];
	for(int i=0; i<lunghezza;i++){
		printf("introduci l'intero: ");
		scanf("%d", &array[i]);
	}
	printf("esito della verifica: %d", restoDivisione(array,lunghezza));
}//************ OUTPUT PRATICAMENTE MANCANTE -1
