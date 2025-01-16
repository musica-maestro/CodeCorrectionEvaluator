/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.5
*/
/*SPECIFICA
* Input: insieme di interi  //**** MANCA LA LUNGHEZZA -0.2
* Pre-condizione: interi > 0
* Output; un valore intero
* Post-condizione: 1 se la sequenza soddisfa la propriet√†, 0 se non la soddisfa
//*** DEVI SPECIFICARE LA PROPRIETA' -0.3
* TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>


int divisioneTripla(int triplaDaDividere[])
{
	int resti[6];

	int i = 0;
	int k = 0;
	int isTrue = 0;


	//Calcolo tutti i resti della tripla  //**** QUANTO E' COMPLICATA!!! -2

	resti[0] = triplaDaDividere[0] % triplaDaDividere[1];
	resti[1] = triplaDaDividere[0] % triplaDaDividere[2];

	resti[2] = triplaDaDividere[1] % triplaDaDividere[0];
	resti[3] = triplaDaDividere[1] % triplaDaDividere[2];

	resti[4] = triplaDaDividere[2] % triplaDaDividere[0];
	resti[5] = triplaDaDividere[2] % triplaDaDividere[1];

	for(i=0;i<6;i++)
	{
		if(resti[i] == triplaDaDividere[0] || resti[i] == triplaDaDividere[1] || resti[i] == triplaDaDividere[2])
		{
			printf("La proprieta e' verificata \n");
			isTrue = 1;
		}

		i++;

	}

	//TEST
	for(i=0;i<6;i++)
	{
		//printf("Array resti: ");
		printf("%d", resti[i]);

	}

	return isTrue;
}



int restoDivisione(int array[], int lunghezza)
{
	int j=0;
	int tripla[3];
	int isProprietaVerificata = 0;

	//preparo una tripla
	for(int i=0;i<lunghezza-2;i++)
	{
		tripla[j] = array[i];
		tripla[j+1] = array[i+1];
		tripla[j+2] = array[i+2];

		//controllo se la tripla soddisfa la propriet√
		isProprietaVerificata = divisioneTripla(tripla);

		i++;
	}

	return isProprietaVerificata;
}






int main()
{

	//int x =8;
	//printf("Resto di 8/3= %d", x%3);


	//Interazione con l'utente
	int i;
	printf("Quanti interi ha la sequenza? \n");
	scanf("%d", &i);

	int sequenza[i];

	for (int j = 0; j < i; j++)
	{
		printf("Inserisci l'intero numero %d \n", j+1);
		scanf("%d", &sequenza[j]);
	}


	//Fine interazione con l'utente

	if (restoDivisione(sequenza, i) == 1)
	{
		printf("\n Nella sequenza ESISTE una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione degli altri due");
	}

	else
	{
		printf("\n Nella sequenza NON ESISTE una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione degli altri due");
	}

	printf("%d", restoDivisione(sequenza, i));


}