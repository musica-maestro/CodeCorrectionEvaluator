/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................6.8
*/
/*SPECIFICA:VERIFICARE L'ESISTENZA DI UNA TRIPLA DI ELEMENTI LA QUALE ALMENO DUE ABBIANO UNA SOMMA FRA 10 E 20.
*INPUT:una sequenza(array) e la sua lunghezza(lunghezza). //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY? -0.6
*PRE-CONDIZIONE:dichiarare la lunghezza della sequenza.
* OUTPUT:ritorno.     //******** OUTPUT: MANCA IL TIPO -0.2
* POST-CONDIZIONE:La funzione restituisce:1 se esiste,0:se non esiste//******** LA POST-CONDIZIONE NON DICE NULLA -0.5.
* TIPO DI PROBLEMA: VERIFICA ESISTENZIALE	*/

#include <stdio.h>

int ugualiCompresi(int* array, int lunghezza){
 int ritorno=0;
 for(int i=0;i<lunghezza-2;i++) //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
 if(array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20 || array[i+1]+array[i+2]>=10 && array[i+1]+array[i+2]<=20)
 //******** MANCA UNA COMBINAZIONE (array[i],array[i+2]) -0.5
 //******** MANCA LA CONDIZIONE CHE ESATTAMENTE DUE ELELMENTI SIANO UGUALI -1.5
  ritorno=1;


   return ritorno;
}




int main()
{
	int lunghezza;
	int ritorno;
	printf("Caro utente inserisci la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);
	int array[lunghezza];
	printf("Caro utente inserisci la sequenza\n");
	for(int i=0;i<lunghezza;i++)
	scanf("%d", &array[i]);   //******** NON E' INDENTATO! -0.2
	ritorno=ugualiCompresi(array,lunghezza);
	if(ritorno==1)
	   printf("Caro utente nella sequenza esiste una tripla di elementi che hanno una somma compresa fra 10 e 20\n");
	else
	    printf("Caro utente nella sequenza non esiste una tripla di elementi che hanno una somma compresa fra 10 e 20\n");


}
