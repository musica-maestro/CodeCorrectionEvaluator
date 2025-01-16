/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*

	SPECIFICA DEL PROBLEMA:

	INPUT: una sequenza di interi e la sua dimensione;

	PRE-CONDIZIONI: interi positivi e dimensione >= 0;

	OUTPUT: un'espressione booleana 'tutte'(VERO O FALSO);

	POST-CONDIZIONI: se in OGNI tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra
					 'TUTTE' vale 1, altrimenti 'tutte' vale 0



	TIPO DI PROBLEMA: verifica universale



*/



#include <stdio.h>

int dueUnaCifra(int array[], int quanti){

	int i = 0;
	int tutte = 1;

	while(i < quanti - 2 && tutte)

		if( !((array[i] >= 0 && array[i] <= 9) && (array[i+1] >= 0 && array[i+1] <= 9) ||
		      (array[i] >= 0 && array[i] <= 9) && (array[i+2] >= 0 && array[i+2] <= 9) ||
		   	  (array[i+1] >= 0 && array[i+1] <= 9) && (array[i+2] >= 0 && array[i+2] <= 9)) )

			tutte = 0;

		else

			i++;

return tutte;

}


int main(){

	int lunghezza;

	printf("Quanti interi mi vuoi dare? ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	printf("\nDammi %d interi:\n", lunghezza);

	for (int i = 0; i < lunghezza; i++)

		scanf("%d", &sequenza[i]);

	if(dueUnaCifra(sequenza, lunghezza))

		printf("\nIn ogni tripla adiacente della tua sequenza sono presenti almeno 2 numeri composti da una sola cifra.");

	else

		printf("\nNon in tutte le triple adiacenti della tua sequenza sono presenti 2 numeri composti da una sola cifra.");

}