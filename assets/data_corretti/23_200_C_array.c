
/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............8
*/
/*SPECIFICA:
 *input: una sequenza di interi x1,..., xn e la sua lunghezza
 *pre-condizioni: x1,...,xn sono numeri interi positivi. n rappresenta quanti elementi contiene la sequenza ed è un numero intero positivo strettamente maggiore di 2
 * output: 	variabile intera tutte
 *postcondiz<ioni: tutte vale 1 se in ogni tripla di elementi adiacenti sono presenti almeno due numeri acomposti da una sola cifra, 0 altrimenti
 *TIPO: verifica universale
 */



#include <stdio.h>

int dueUnaCifra(int*array, int l);


int main(){

	int lunghezza;			//lunghezza array
	int triple;				//risultato


	/*input*/
	printf("Ciao utente!! Dimmi quanti numeri vuoi inserire: ");
	scanf("%d", &lunghezza);

	if(lunghezza<3){
		printf("\nLa tua sequenza e' tropppo piccola, deve contenere almeno 3 elementi");
		scanf("%d", &lunghezza);
	}

	int sequenza [lunghezza];

	for(int i=0; i<lunghezza; i++){
		printf("\nInserisci intero: ");
		scanf("%d", &sequenza); //******* seuqenza[i]  -0.5
	}

	/*output*/
	triple= dueUnaCifra(sequenza, lunghezza);
	if(triple)
		printf("\nIn tutte le triple di elementi adiacenti della tua sequenza sono presentia almeno due numeri composti da una sola cifra");
	else

		printf("\nNON in tutte le triple di elementi adiacenti della tua sequenza sono presentia almeno due numeri composti da una sola cifra");

}


/*funzione che controlla se in tutte le triple sono presenti 2 coppie di numeri a una cifra oppure no*/

int dueUnaCifra(int*array, int l){

	int i=0;				//scandisce gli indici degli elementi dell'array
	int triple=1;				//variabile di universalità


	/*triple viene inizializzata a 1 perché non sono ancora state trovate triple che non rispettano la proprietà*/


	while(i<l-2 && triple){

		if((array[i]<=9 && array[i+1]<=9 && array[i+2]>9 ) ||
		   (array[i]<=9  && array[i+2]<=9 && array[i+1]>9 ) ||
		   (array[i+1]<=9 && array[i+2]<=9 && array[i]>9 )){   //****** COSI' VERIFICHI SE CI SONO ESATTAMENTE DUE DI UNA CIFRA, NON ALMENO DUE -1.5

			i++; //va avanti

		}

		else
			triple=0;			//è stata trovata una tripla che non rispecchia le proprietà






	}

	return triple;





}



/*
 interi positivi
 ogni tripla di elementi adiacenti
 almenio due numeri composti da una sola cifra*/