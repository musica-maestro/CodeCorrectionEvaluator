/* SPECIFICA (max 1):......0.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.2
*/
/*SPECIFICA
*Input: lunghezza array ed elementi dell'array //******** MANCA IL TIPO -0.2
*Pre-condizione: presa una terna di elementi, almeno uno tra quei tre elementi deve essere il resto della divisione degli altri due elementi
//****** NON E' QUESTA LA PRECONDIZIONE -0.2
*Output: Restituisce una frase che afferma la presenza di tale terna nella sequenza o ne restituisce una che smentisce la presenza di tale terna
//********* L'OUTPUT DEVE ESSERE UN BOOLEANO -0.2
*Post-condizione:  //**** MANCA -0.2
*Tipo di problema: Esistenziale*/

#include <stdio.h>
#include <stdlib.h>

int restoDivisione(int array[], int lunghezza){

	int siResto; //****** VARIABILE NON INIZIALIZZATA -1
	int i;
	for(i = 0; i < lunghezza-3; i++){ //****** i <=lunghezza-3 -0.5
		if(((array[i] % array[i+1] == array[i+2]) || (array[i+2] % array[i] == array[i+1]) ||
			(array[i+1] % array[i+2] == array[i]) || (array[i+2] % array[i+1] == array[i] ||
				(array[i] % array[i+2] == array[i+1]) || (array[i+1] % array[i] == array[i+2]))))
			siResto = 1;
	}
	if(siResto != 1)  //***** NON VUOL DIRE NIENTE -0.5
		siResto = 0;

	return siResto;

}

int main(){

	int n_intero;
	printf("Utente inserisci la lunghezza della tua sequenza: ");
	scanf("%d", &n_intero);
	int sequenzaU[n_intero];
	printf("\nAdesso inserisci gli elementi della tua sequenza:\n");
	for(int i = 0; i < n_intero; i++){
		scanf("%d", &sequenzaU[i]);
		printf("Hai inserito il valore: %d\n", sequenzaU[i]);
	}
	printf("I valori della tua sequenza sono: ");
	for(int i = 0; i < n_intero; i++){
		printf("%d ", sequenzaU[i]);
	}
	if(restoDivisione(sequenzaU, n_intero))
		printf("\nLa sequenza contiene una tripla di elementi in cui uno dei tre %c il resto della divisione tra gli altri due\n", 138);
	else
		printf("\nLa sequenza NON contiene una tripla di elementi in cui uno dei tre %c il resto della divisione tra gli altri due\n", 138);

	system("pause");
	return 0;
}