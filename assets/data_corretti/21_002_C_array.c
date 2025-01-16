/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA
 * Input : una sequenza s di interi e la sua lunghezza l
 * Pre-condizione : l è la lunghezza di s (l>=3)
 * Output : un intero esiste
 * Post-condizione : esiste vale 1 se esiste una tripla di elementi consecutuvi tale che
 * almeno due elementi hanno valore compreso tra -10 e 10 ed esattamente due sono
 * multipli di tre, altrimenti vale 0
 * TIPO DI PROBLEMA : VERIFICA ESISTENZIALE      */

#include <stdio.h>

/*Funzione che riceve come paramentro una sequenza di interi (e la sua lunghezza) e verifica se
 * esiste una tripla con almeno due elementi compresi tra -10 e 10 ed esattamente due multipli di 3 */
int compresiMultipli3 (int interi[], int lunghezza){
	// pre: lunghezza è la lunghezza di interi

	int esiste; //variabile di esistenza
	int i; //variabile contatore

	/*Inizialmente non hai ancora trovato una tripla che va bene*/
	esiste = 0;
	/*Scorri fino alla fine*/
	i = 0;
	while(i<=lunghezza-3 && !esiste){
		if(((interi[i]<=10 && interi[i]>=-10) && (interi[i+1]<=10 && interi[i+1]>=-10) ||
			(interi[i]<=10 && interi[i]>=-10) && (interi[i+2]<=10 && interi[i+2]>=-10) ||
			(interi[i+1]<=10 && interi[i+1]>=-10) && (interi[i+2]<=10 && interi[i+2]>=-10)) &&
			((interi[i]%3==0 && interi[i+1]%3==0 && interi[i+2]%3!=0) ||
			(interi[i]%3==0 && interi[i+1]%3!=0 && interi[i+2]%3==0) ||
			  (interi[i]%3!=0 && interi[i+1]%3==0 && interi[i+2]%3==0)))

				  esiste = 1; //hai trovato una tripla che soddisfa la richiesta
			else i++; //altrimenti vai alla successiva
	}
 return esiste;
}

/*Funzione principale*/

int main() {
	int lunghezza; //numero di elementi dell'array

	/*INPUT*/
	printf("Ciao utente, sono un programma che verifica se esiste una tripla di interi");
	printf("tale che due elementi siano compresi tra -10 e 10 e ce ne siano esattamente due multipli di 3");
	printf("\n Quanti interi vuoi introdurre?");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	printf("\n");
	printf("Introduci gli interi: ");
	for(int i=0; i<lunghezza; i++){
		scanf("%d", &sequenza[i]);
	}

	/*OUTPUT*/

	if(compresiMultipli3(sequenza, lunghezza))
		printf ("Esiste una tripla che corrisponde a quello che cerchi");
		else
			printf ("Non esiste nessuna tripla con queste caratteristiche");


}
