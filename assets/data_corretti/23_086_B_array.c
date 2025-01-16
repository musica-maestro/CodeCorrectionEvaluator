/* SPECIFICA (max 1):......0  //******** CONTROLLARE
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............0
*/
#include <stdio.h>
/*

Problema: Esistenza Universale  //******** O E' ESISTENZIALE, O E'UNIVERSALE -1
*/
int duePositivi (int *array,int n)
{
	int cont=0;
		while(array[strlen(array)]!='\0') //******* '\0' E' IL SEGNALATORE DI FINE STRINGA, MA QUESTO E' UN ARRAY DI INTERI
	{                                     //******* NON DI CARATTERI
		 if (array[stlen(array)-n]>0)
		 {

		 }
	}

}
int main ()
{
	int n,i,risultato;
	printf("inserisici il numero di elementi da immettere nell array: ");
	scanf("%d",&n);
	int array[n];
	i=n;
	while (i>0)
	{
		printf("insereisci l elemento: ");
      scanf(array[n-i])  //********* SINTASSI SCANF ERRATA -1
      i--
	}
	risultato=duePositivi(array,n);
                         //******** MANCA L'OUTPUT -1

}