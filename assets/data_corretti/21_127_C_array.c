/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9
*/
/* SPECIFICA
 * Input: sequenza s di lunghezza l //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * Pre-Condizione: l>=3 /l è la lunghezza di s / s contiene tutti numeri interi
 * Output: true/false
 * Post-Condizione: true se esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è
 *                  compreso tra -10 e 10 e che contiene esattamente due multipli di 3
              //******** POST-CONDIZIONE NON COMPLETA (0, ALTRIMENTI) -0.2
 * TIPO DI PROBLEMA: verifica esistenziale
 */

#include <stdio.h>

//Questa funzione controlla che un numero dato sia compreso tra -10 e 10
int compreso10(int arr[], int index){  //******** BASTAVA PASSAR UN INTERO, MA VA UGUALMENTE BENE
	if(arr[index]>=-10 && arr[index]>=-10)
		return 1;
	return 0;      //******* DUE return PER UNA FUNZIONE DI 4 RIGHE!!!! 0.5
}

//Questa funzione controlla che un numero dato sia multiplo di 3
int multiplo3(int arr[], int index){ //******** BASTAVA PASSAR UN INTERO, MA VA UGUALMENTE BENE
	if(arr[index]%3==0)
		return 1;
	return 0;     //******* DUE return PER UNA FUNZIONE DI 4 RIGHE!!!! 0.5
}

// Vedi specifica
int compresiMultipli3(int arr[], int len)
{
	for(int i=2; i<len; i++){
		if((compreso10(arr, i-2) && compreso10(arr, i-1))
		|| (compreso10(arr, i-2) && compreso10(arr, i))
		|| (compreso10(arr, i) && compreso10(arr, i-1))){
			if((multiplo3(arr, i-2) && multiplo3(arr, i-1) && !(multiplo3(arr, i)))
			|| (multiplo3(arr, i-2) && multiplo3(arr, i) && !(multiplo3(arr, i-1)))
			|| (multiplo3(arr, i) && multiplo3(arr, i-1) && !(multiplo3(arr, i-2)))){
				return 1; //********* ANCORA!!!!!!! -0.5
			}
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	int lunghezza;

	printf("Questo programma verifica che in una sequenza esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	printf("Da quanti interi %c formata la sequenza?\n", 138);
	scanf("%d", &lunghezza);

	int array[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Inserisci l'intero di indice %d: ", i);
		scanf("%d", &array[i]);
	}

	if(compresiMultipli3(array, lunghezza)){
		printf("In questa sequenza ESISTE una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	} else {
		printf("In questa sequenza NON ESISTE una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	}

	return 0;
}
