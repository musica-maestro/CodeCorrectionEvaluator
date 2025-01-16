/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.5
*/
/*SPECIFICA
 * Input: una sequenza di interi "s" e una lunghezza "L"
 * Pre-condizioni: l>=1 è la lunghezza di s
 * Output: true/false
 * Post-condizioni: true se esiste una tripla di interi consecutivi contenenti almeno
 * due elementi di valore compreso tra -10 e 10 e esattamente due multipli di 3
 * false altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale*/

 /*funzione che prende come parametro un array di interi(e la sua lunghezza)
  * e restituisce 1 se esiste una tripla di interi consecutivi contenente almeno
 * due elementi di valore compreso tra -10 e 10 e esattamente due multipli di 3,
 * restituisce 0 altrimenti*/
 int compresiMultipli3(int interi[],int lunghezza){
	 int i=0;    //variabile contatore
	 int tripla=0;  //variabile di esistenza
	 while(i<lunghezza-2 && !tripla){
		 /*verifica se la tripla corrente soddisfa la condizione*/
		 // ********* UGUAGLIANZA? -0.5
		 if(((interi[i]>-10 && interi[i]<10 && interi[i+1]>-10 && interi[i+1]<10)
		 || (interi[i]>-10 && interi[i]<10 && interi[i+2]>-10 && interi[i+2]<10)
		 || (interi[i+1]>-10 && interi[i+1]<10 && interi[i+2]>-10 && interi[i+2]<10))
			 && ((interi[i]%3==0 && interi[i+1]%3 == 0 && interi[i+2]%3!=0)
			 || (interi[i]%3==0 && interi[i+2]%3 == 0 && interi[i+1]%3!=0)
			 || (interi[i+1]%3==0 && interi[i+2]%3 == 0 && interi[i]%3!=0)) )
				 tripla=1;  //aggiorna il valore di tripla
		 else
			 i++;    //cerca un'altra tripla buona
	 }
	 return tripla;
 }



#include <stdio.h>

int main(int argc, char **argv)
{
	int lunghezza;  //lunghezza sequenza
	/*INPUT*/
	printf("Questo programma verifica se esiste una tripla di interi consecutivi contenenti ");
	printf("due elementi di valore compreso tra -10 e 10 e esattamente due multipli di 3\n");
	printf("Quanto vuoi che sia lunga la sequenza? ");
	scanf("%d",&lunghezza);
	/*riempi la sequenza*/
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Inserisci un intero: ");
		scanf("%d",&sequenza[i]);
	}

	/*OUTPUT*/
	if(compresiMultipli3(sequenza,lunghezza))
		printf("Esiste una tripla contenente almeno due elementi di valore compreso tra -10 e 10 e esattamente due multipli di 3.\n");
	else
		printf("Non esiste una tripla contenente almeno due elementi di valore compreso tra -10 e 10 e esattamente due multipli di 3.\n");
}
