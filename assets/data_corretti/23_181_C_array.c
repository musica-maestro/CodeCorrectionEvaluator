/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
 *Input: s, s interi dentro l'array
 *Pre-condizioni: s intero positivo che rappresenta la lunghezza dell'array, s interi che compongo l'array  //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
 *Output: Risposta positiva o negativa della richiesta
 *Post-condizioni: Se la richiesta e' soddisfatta, la funzione restituisce uno ed abbiamo una risposta positiva; se la funzione restituisce 0 si ha una riposta negativa
 *TIPO DI PROBLEMA: Verifica Universale
*/


#include <stdio.h>

/*Funzione che ha come parametri un array di interi e e un intero che rappresenta la lunghezza dell'array.
 *La funzione restituisce 1 se in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra, 0 altrimenti */
int DueUnaCifra(int array[], int n){
int x=0;			//variabile contatore delle triple di elementi soddisfano la richiesta

	/*Inizio lettura delle triple */
	for (int i=0; i<n-2;i++){
		/*Se nela tripla in questione gli elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra allora sommagli uno */
		if ((array[i]<10 && array[i+1]<10) || (array[i]<10 && array[i+2]<10) || (array[i+1]<10 && array[i+2]<10))
			x++;
	}

	// Se la variabile contatore e' pari alle triple dell'array restituisci 1, altrimenti 0
	if (x==(n-2))
		x=1;
	else
		x=0;

return x;

}

/*Funzione principale */
int main (){
	int n ;			//variabile per stabilire la lunghezza dell'array
	/*Input lunghezza array (n) */
	printf("Quanto deve essere lungo l'array ? ");
	scanf("%d",&n);

	int array[n];		//array di lunghezza  n

	/*Input degli n elementi, all'interno dell'array  */
	printf("Inserisci i %d numeri all'interno dell'array \n",n );
	for (int i=0;i<n;i++)
		scanf("%d",&array[i]);

	/*Output */
	if(DueUnaCifra(array,n)) 		//Caso x=1
		printf("In tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra");
	else 							//Caso x=0
		printf("Non in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra");


}