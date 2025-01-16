/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
/*SPECIFICA
*Input: Una sequenza di interi positivi e la lunghezza
*Pre-condizione: Lunghezza>=3
*Output: Un intero dueUnaCifra
*Post-condizione: La funzione restituisce 1 se ogni tripla della sequenza contiene almeno due elementi con una sola cifra, altrimenti restituisce 0
*TIPO DI PROBLEMA: Verifica universale */

#include <stdio.h>

/*Funzione che riceve una sequenza di interi positivi e verifica che ogni tripla di elementi adiacenti
contenga almeno due numeri da una cifra*/
int dueUnaCifra(int array[], int dimensione) {	//Prototipo della funzione dueUnaCifra//

	int condizione=1;	//Inizializzazione della condizione a 1//
	for(int i=0; i<dimensione-3 && condizione; i++) //**** i<dimensione-2 -0.5
	{
		if ((array[i]<10&&array[i+1]<10)||(array[i]<10&&array[i+2]<10)||
			(array[i+1]<10&&array[i+2]<10)||(array[i]<10&&array[i+1]<10&&array[i+2]<10))	//Nella tripla ci sono almeno due interi da una cifra?//
			condizione;	//Variabile condizione resta 1// //******** BRUTTA!!!!!! -1
		else 																				//Nella tripla non ci sono almeno due interi da una cifra?//
			condizione=0;	//Variabile condizione diventa 0//
	}
	/* Restituzione del valore condizione*/
	return condizione;

}



/*	Funzione principale	*/
int main() {

	/*	Input	*/
	int lunghezza;
	printf("Questo programma riceve in input una sequenza di interi positivi e verifica che ogni\n");
	printf("tripla di elementi adiacenti contenga almeno due numeri composti da una cifra \n");
	printf("\nQuanti elementi ha la sequenza? ");
	scanf("%d", &lunghezza);	//Inserimento della lunghezza della sequenza//

	if (lunghezza>=3)			//Pre-condizione: la sequenza ha almeno tre interi//
	{
		int sequenza[lunghezza];	//Dichiarazione della sequenza di interi//


		/*	Inserimento degli interi nella sequenza	*/
		for(int i=0; i<lunghezza; i++)
		{
			printf("Inserisci l'elemento di indice %d:  ", i);
			scanf("%d", &sequenza[i]);	//Ho inserito tutta la sequenza//

		}


		/*Verifica che gli elementi sono tutti positivi*/
		int positivi=1;
		for(int j=0; j<lunghezza&&positivi; j++)
		{
			if(sequenza[j]>0)	//L'elemento di indice j è positivo?//
				positivi;
			else				//L'elemento non è positivo?//
				positivi=0;
		}

		if (positivi==1)	//Gli elementi sono tutti positivi?//
			{
				/*	Output	*/
			dueUnaCifra(sequenza, lunghezza);	//Invocazione della funzione dueUnaCifra//

			/* Stampa del risultato */
			if(dueUnaCifra(sequenza, lunghezza)==1)
				printf("Ogni tripla della sequenza ha almeno due numeri da una cifra! ");
			if(dueUnaCifra(sequenza, lunghezza)==0)
				printf("Non tutte le triple della sequenza hanno almeno due numeri da una cifra! ");
			}

		if (positivi==0)	//Gli elementi non sono tutti positivi?//
			printf("Tutti gli elementi della sequenza devono essere positivi! ");



	}
	else	//La sequenza ha meno di 3 elementi//
		printf("La sequenza non ha un numero di elementi sufficiente per verificare almeno una tripla. ");


}
