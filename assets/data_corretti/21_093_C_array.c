/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................6,5
*/

// specifica //
// input 3 interi// //******** NO!!!! -0.5
// pre condizione : i valori in input devono essere interi e almeno 3//
//output: la funzione restituisce 0 o 1 dipendentemente dall input//
//post condizione il valore deve essere booleano quindi o 0 o 1// //**** QUESTO E' L'OUTPUT -0.5
// TIPO DI PROBLEMA verifica esistenziale//


#include <stdio.h>
int compresiMultipli3 (int sequenza [], int lunghezza)
{   //****** NON USI LA VARIABILE BOOLEANA! LA PROGRAMMAZIONE CHE INSEGNAMO IN QUESTO CORSO E' STRUTTURATA, UN SOLO PUNTO DI INGRESSO ED UN SOLO
	// PUNTO DI USCITA (CHE E' MEGLIO PER UNA SERIE DI MOTICI SCRITTI SULLE SLIDES), IL PROGRAMMA CHE HAI SCRITTO NON E' STRUTTURATO -3
	int i=0;
	while (i+2<lunghezza)
	{
		if (sequenza[i]%3==0)
		{
			if (sequenza[i+1]%3==0)
			{
				if(sequenza[i+2]%3==0)
				{
					i++;
				}
				else
				{
					if(((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+1]>=-10 && sequenza[i+1]<=10)) || ((sequenza[i+1]>=-10 && sequenza[i+1]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10))
					|| ((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10) ))
					{
						return (1);
					}
					else
					{
						i++;
					}
				}
			}
			else
			{
				if (sequenza[i+2]%3!=0)
				{
					i++;
				}
				else
				{
					if(((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+1]>=-10 && sequenza[i+1]<=10)) || ((sequenza[i+1]>=-10 && sequenza[i+1]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10))
					|| ((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10)))
					{
						return(1);
					}
					else
					{
						i++;
					}
				}
			}

		}
		else
		{
			if (sequenza[i+1]%3==0 && sequenza [i+2]%3==0)
			{
				if(((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+1]>=-10 && sequenza[i+1]<=10)) || ((sequenza[i+1]>=-10 && sequenza[i+1]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10))
					|| ((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10)))
					{
						return (1);

					}
				else
				{
					i++;
				}
			}
			else
			{
				i++;
			}
		}
	}


return(0);
}




int main()
{
	int lunghezza;
	int soluzione;

	printf("inserisci la quantita di numeri desiderata");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for (int i=0;i<lunghezza;i++)
	{
		printf("inserisci i numeri desiderati");
		scanf("%d", &sequenza[i]);
	}
soluzione=compresiMultipli3(sequenza,lunghezza);
if(soluzione==1)
{
	printf("la tua stringa rispetta le condizoni");

}
else
{
	printf("la tua stringa non rispetta le condizioni");
}
}//******** OUTPUT MOLTO POVERO -0.5
