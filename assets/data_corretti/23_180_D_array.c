/* SPECIFICA (max 1):......0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.2
*/
/*
SPECIFICA: scrivere un programma che trova una tripla consequitiva in una sequenza di numeri, un elemento rappresenta il resto degli altri due
INPUT: una sequenza di numeri //******** MANCA LA LUNGHEZZA -0.2
PREREQUISITO: almeno 3 numeri conteneti poi un numero rappresentante iol resato di una divisione degli altri due caratteri //**** NO! -0.2
OUTPUT: booleano
POSTREQUISITO: se il booleano è posityivo allora esiste una tripla contenete il resto della divisione degli altri due
*/     //****** IL BOOLEANO E' POSITIVO SE ESISTE.... FALSO ALTRIMENTI -0.2
//tipo esistenziale

#include <stdio.h>


int restoDivisione(int *array,int i)
{
int esito=0;
	for (int j = 0; j <= i-3; j++) //****** SENZA LA VAR. BOOLEANA NELLA CONDIZIONE, ANCHE SE TROVI
	{                              //****** UNA TERNA CHE NON SODDISFA LA PROPRIETA' VAI AVANTI A CONTROLLARE -0.2
		//if che verifica se un caarattere (numerico dell'array e' il resto degli altri due)
		if ((array[j]%array[j+1]==array[j+2])||(array[j+1]%array[j]==array[j+2])||
		    (array[j+2]%array[j+1]==array[j])||(array[j+1]%array[j+2]==array[j])||
		    (array[j+2]%array[j]==array[j])||(array[j]%array[j+2]==array[j+1]))
		{
			esito=1;
		}
	}
return esito;//risposta della funzione
}


int main()
{
	printf("salve sono un programma che verifica in una tripla di numeri se uno e' il resto degli altri due\n");			//introduzione al programma
	printf("inserire lunghezza sequenza\n");

	int i=0;
	scanf("%d",&i);

	int array[i];					//inizzializzazione array con il valore scelto dall'utente
	for (int j= 0; j <= i-1; j++)
	{
		printf("inserire il valore al ponsto n %d\n",j+1 );
		scanf("%d",&array[j]);
	}//inserimento valori dell'array

	if (restoDivisione(array, i)==1)//evocazione funzione e post condizione
	{
		printf("esiste una tripla che contiene un elemento che rappresenta il resto degli altri due \n");
	}
	else
	{
		printf("NON esiste una tripla che contiene un elemento che rappresenta il resto degli altri due \n");
	}
	//risposta programma
}