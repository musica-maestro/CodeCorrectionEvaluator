/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.2
*/
/*Data una sequenza di intei, verificare se per ciascuna terna di elementi adiacenti dela sequenza,
ci sia almeno un elemento della terna multiplo di uno degli altri due.

*SPECIFICA

*INPUT: una sequenza di interi
*PRE-CONDIZIONE: la lunghezza del'array //******* QUESTO VA NELL'INPUT -0.1
*OUTPUT: un intero
*POST-CONDIZIONE: la funzione restituisce 1 se in tutte le terne di elementi adiacenti della sequenza è presente
 almeno un elemento multiplo di uno degli altri due, restituisce 0 altrimenti

*TIPO DI PROBLEMA: verifica universale*/

#include <stdio.h>


int multipli(int array[],int lunghezza)
{
	int verifica=1;   //variabile universale
	int i=0;    //variabile contatore
     // verifico che in una tripla non ci sono multipli
	for(i=0; i<lunghezza-2; i++) //***** SENZA && VERIFICA, SCORRI SEMPRE TUTTA LA SEQUENZA -0.2
		{
			if((array[i]%2!=array[i+1]) && (array[i]%2!=array[i+2]) &&
			   (array[i+1]%2!=array[i]) && (array[i+1]%2!=array[i+2]) &&
			   (array[i+2]%2!=array[i+1]) && (array[i+2]%2!=array[i]))
				  verifica=0;
		}//******** CONDIZIONE SBAGLIATA -1.5
         //******** ESSERE MULTIPLO DI SI ESPRIME COME array[i]%array[i+1]==0, IL 2 NON C'ENTRA NIENTE
		return verifica;
}

int main()
{
	int i;
	int dim;
	printf("Quanti interi ha la sequenza?\n");
	scanf("%d", &dim);

	int lunghezza[dim];
	for(i=0; i<dim; i++)
	{
		printf("Inserisci un intero:\n");
		scanf("%d", &lunghezza[i]);
	}

	int esiste=multipli(lunghezza,dim);
	{
	if(esiste==1)
	  printf("Esiste per ciascuna terna di elementi adiacenti della sequenza\nalmeno un elemento della terna multiplo di uno degli altri due\n");
	else
	  printf("Esiste almeno un elemento per cui non e' vero che\nper ciascuna terna di elementi adiacenti della sequenza\nalmeno un elemento della terna multiplo di uno degli altri due\n");
	}


}
