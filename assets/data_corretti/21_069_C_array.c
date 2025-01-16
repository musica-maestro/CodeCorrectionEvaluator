/* SPECIFICA (max 1.5):....0.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.6
*/

#include <stdio.h>

/*SPECIFICA
 *Input: Lunghezza della sequenza e i suoi valori  //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Pre-condizione: la lunghezza della sequenza è minimo di tre valori
 * Output: Messaggio di conferma dell'esistenza o della inesistenza della tripla ricercata.
 * Post-consizione: b assume solo valori 0 e 1.
 * Tipo di problema : verfica esistenziale.   //******** CONFONDI OUTPUT E POST-CONDIZIONE -0.5
											  //******** POST-CONDIZIONE NON COMPLETA -0.3
 */



int compresiMultipli3(int array[], int l)
{
	int b=0;
	//ciclo per il controllo delle triple
	for(int i=0; i<l-2 && b==0;i++)
	{
		//controllo dei valori compresi tra 10 e -10
		if((array[i]>=-10 && array[i]<=10) || ((array[i+1]>=-10 && array[i+1]<=10) && (array[i+2]>=-10 && array[i+2]<=10)))
		{
			if((array[i+1]>=-10 && array[i+1]<=10) || (array[i+2]>=-10 && array[i+2]<=10))
			//***** PER FORZA, SE SONO TUTTI E TRE COMPRESI TRA -10 E 10! -2
				//controllo dei multipli di 3
				if(((array[i]%3==0) && (array[i+1]%3==0) && (array[i+2]%3!=0))
				|| ((array[i]%3==0) && (array[i+1]%3!=0) && (array[i+2]%3==0))
				|| ((array[i]%3!=0) && (array[i+1]%3==0) && (array[i+2]%3==0)))
				{
					b=1;
				}
			}

		}
	}
	return b;
}



int main(int argc, char **argv)
{
	//dimensione dell'array
	int l;
	//variabile booleana per l'output
	int b=0;
	printf("Algoritmo che verifica l'esistenza di una tripla di interi, che contiene due elementi il cui valore %c compreso fra -10 e 10, e che contiene esattamente due elementi multipli di 3.\n", 138);
	//input
	printf("Inserire la lunghezza della sequenza di interi: ");
	scanf("%d", &l);
	//dichiarazione dell'array
	int array[l];
	//ciclo per l'inserimento dei valori
	for(int i=0; i<l; i++)
	{
		printf("Inserire il %d%c numero della sequenza: ",i+1, 167);
		scanf("%d", &array[i]);
	}
	//Richiamo della funzione
	b=compresiMultipli3(array, l);
	//Output
	if(b==1)
	{
		printf("Esiste una tripla di numeri consecutivi che contiene almeno due caratteri il cui valore %c compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3\n", 138);
	}
	else
	{
		printf("Non esiste una tripla di numeri consecutivi che contiene almeno due caratteri il cui valore %c compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3\n", 138);
	}

	return 0;
}
