/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............8.7
*/
#include <stdio.h>

/*
	SPECIFICA:
	Input = Una sequenza di Interi (x1,...,xn)
	Pre-Condizione = Devono esserci almeno 3 Elementi nella sequenza//******** MANCA LA LUNGHEZZA -0.2
	Output = Un intero "booleana"
	Post-Condizione = Il valore di "booleana" è 1 quando all interno di una tripla di interi adiacenti esiste ALMENO
					  un valore che  uguale alla divisione tra interi tra 2 numeri della tripla. /********** FALSO, ALTRIMENTI -0.1

	TIPO = Verifica Esistenziale
*/

int restoDivisione(int s[], int l)
{
	int booleana=0;
	int i=0;

	while(i<l-2 && booleana==0)
	{
		if ( ( (s[i]==( s[i+1]%s[i+2] )) || ( s[i]==(s[i+2]%s[i+1]  )) ) ||      // Questa if controlla se il primo valore è la divisione tra secondo e terzo o tra terzo e secondo
			(  (s[i+1]==( s[i]%s[i+2] )) || ( s[i+1]==( s[i+2]%s[i] )) ) ||    // e fa lo stesso per il secondo controllando se è uguale alla divisione tra primo e terzo o terzo e primo
		   (   (s[i+2]==( s[i]%s[i+1] )) || ( s[i+2]==(s[i+1]%s[i]) ) )  )     // lo stesso per il terzo vedendo se è uguale alla divisione tra primo e secondo o secondo e primo
		{
			booleana=1;
		}
		else
			i++;
	}

			return booleana;
}

int main(int argc, char const *argv[])
{

	printf("Inserisci la lunghezza della sequenza \n");
	int lunghezza;
	scanf("%d", &lunghezza);
	int array[lunghezza];
    //***** DEVI ANCHE CHIEDERE DI INSERIRE I VALORI -0.5
	for (int i = 0; i < lunghezza ; ++i)
	{
		scanf("%d", &array[i] );
	}


	if (restoDivisione(array, lunghezza)==1)
	{
		printf("L'istanza e positiva\n"); //************ OUTPUT NON ESPLICATIVO -0.5
	}
	else
		printf("L'istanza e negativa\n");


	return 0;
}