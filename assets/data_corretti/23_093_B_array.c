/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.3
*/
/* SPECIFICA
 * Input: sequenza di interi e lunghezza n
 * Pre-condizione: n>=3
 * Output: variabile booleana verificato
 * Post condizione: verificato=true se intutte le triple di elementi
 * adiacienti della sequenza ci sono esattamente due numeri positivi, altrimenti verificato=false.
 * TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>

/* la funzione restituisce 1 se in tutte le triple di elementi adiacenti della sequenza ci sono esattamente
 * due numeri positivi, altrimenti 0 */
int duePositivi(int array[],int lunghezza){
	int verificato=1;      // variabile di esistenza

	for(int i=0;i<lunghezza-2;i++)  //********* COSI' ESAMINI TUTTA LA SEQUENZA, SENZA FERMARTI APPENA TROVI LA PROP. NON SODDISFATTA -0.2
		if(!(array[i]>0 && array[i+1]>0 || array[i]>0 && array[i+2]>0 || array[i+1]>0 && array[i+2]>0))
		//****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
			verificato=0;

	return verificato;
}

/* funzione principale */
int main(){
	int n;    // variabile conteggio
	printf("ciao utente quanti interi vuoi introdurre? ");
	scanf("%d",&n);
	int array[n];
	for(int i=0;i<n;i++){
		printf("per favore introduci un intero: ");
		scanf("%d",&array[i]);
	}
	if(duePositivi(array,n))
		printf("in tutte le triple ci sono esattamente due numeri positivi");
	else
		printf("non in tutte le triple ci sono esattamente due numeri positivi");
}