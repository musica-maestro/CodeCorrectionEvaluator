/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA DEL PROBLEMA
*  INPUT: una sequenza di n interi
*  PRE CONDIZIONI: n>=3
*  OUTPUT: un valore booleano
*  POST CONDIZIONI: il valore è 1 se in ogni tripla ci sono esattamente 2 numeri positivi
*                   il valore è 0 se almeno in una tripla non ci sono esattamente 2 numeri positivi

*  tipo di problema: PROBLEMA DI VERIFICA UNIVERSALE */

#include <stdio.h>

int duePositivi(int* array, int lunghezza){
	int i=0;
	int triple=1;

	while(i<lunghezza-2 && triple){
		if(!((array[i]>0 && array[i+1]>0 && array[i+2]<0) || (array[i]>0 && array[i+1]<0 && array[i+2]>0) || (array[i]<0 && array[i+1]>0 && array[i+2]>0)))
			triple=0;
		else             //******* DEVI CONSIDERARE ANCHE LA POSSIBILITA' CHE SIA 0 -0.2
			i++;
	}
return triple;
}

int main(){
	int lunghezza;
	int i;

	printf("caro utente quanti interi vuoi introdurre? (minimo 3)\n");
	scanf("%d", &lunghezza);

	int array[lunghezza];

	for(i=0; i<lunghezza; i++){
		printf("caro utente introduci un intero:\n");
		scanf("%d", &array[i]);
	}

	if(duePositivi(array, lunghezza))
		printf("in tutte le triple adiacenti della sequenza ci sono esattamente due numeri positivi\n");
	else
		printf("almeno in una delle triple adiacenti della sequenza NON ci sono esattamente due numeri positivi\n");
}