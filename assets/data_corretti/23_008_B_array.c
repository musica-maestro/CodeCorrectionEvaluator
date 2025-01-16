/* SPECIFICA (max 1):......0    //******** MANCA
   TIPO PROBLEMA (max 1):..0    //******** MANCA
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............6.4
*/
/*
SPECIFICA
*/

#include <stdio.h>

int duePositivi(int *array, int lunghezza_array)
{
	int verifica; //serve per verificare se TUTTE le triple di elementi adiacenti della sequenza
	int i;
	for(i=0; i<lunghezza_array-2; i++)
	{
		verifica = 0;
		if(array[i]>0 && array[i+1]>0 && array[i+2]<0)
		{
			verifica=1;
		}
		else
		{
			verifica = 0;
			if (array[i]<0 && array[i+1]>0 && array[i+2]>0)
			{
				verifica=1;
			}
			else
			{
				verifica = 0;
				if(array[i]>0 && array[i+1]<0 && array[i+2]>0)
				{
					verifica = 1;
				}
				else
				{
					verifica = 0;
				}
			}
		//******** COSI'RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
		}

	}

	return verifica;
}

int main()
{
	int lunghezza_array;
	printf("Ciao utente, inserisci la quantità di interi da introdurre\n");
	scanf("%d", &lunghezza_array);
	int array[lunghezza_array];
	for(int i=0; i<lunghezza_array;i++)
	{
		printf("Inserici l'intero"); //******** APPICCICATO -0.1
		scanf("%d", &array[i]);
	}

	if(duePositivi(array, lunghezza_array))
	{
		printf("Tutte le triple contengono esattamente due positivi");

	}
	else
	{
		printf("Non tutte le triple contengono esattamente due numeri positivi");
	}
}