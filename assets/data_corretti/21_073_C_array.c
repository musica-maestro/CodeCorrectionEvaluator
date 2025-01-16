/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................11
*/
#include <stdio.h>
/*SPECIFICA
 * Input: una sequenza di numeri interi e un numero L che indica la sua lunghezzza.
 * Pre-condizione: la lunghezza deve essere un intero positivo.
 * Output: un valore booleano.
 * Post-condizione: restituirà true se esiste una tripla di elementi consecutivi
 * che contienealmeno 2 elementi il cui valore è compreso tra -10 e 10 e che contiene
 * esattamente due numeri multipli di 3, false altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale.*/

/*funzione che verifica se una stringa ha una tripla di elementi consecutivi
 * che contiene almeno due elementi il cui valore è compreso tra -10 e 10 e
 * che contiene esattamente due elementi multipli di 3*/
int compresiMultipli3(int array[],int l){
	int i=0; //indice
	int esiste=0;
	int quantiDivisibiliPer3, compreso10;
	while(i<l-2&&!esiste){
		/*variabile che indica quanti numeri possono essere divisibili per 3*/
		quantiDivisibiliPer3=((array[i]%3)!=0)+((array[i+1]%3)!=0)+((array[i+2]%3)!=0);
		/*variabile che indica quanti numeri sono compresi tra -10 e 10*/
		compreso10=(array[i]>=-10&&array[i]<=10)+(array[i+1]>=-10&&array[i+1]<=10)+(array[i+2]>=-10&&array[i+2]<=10);
		if(quantiDivisibiliPer3==1&&compreso10>=2)
			esiste=1;
		else
			i++;
	}
	return esiste;
}
/*funzione che interagisce con l'utente stampa un messaggio se la sequenza inserita
 * soddisfa le richieste*/
int main(){
	/*variabili*/
	int i=0;
	int lunghezza;
	/*input*/
	printf("Ciao! Quanto vuoi lunga la tua sequenza? ");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	while(i<lunghezza){
		printf("\nInserisci che valore dare al %d elemento: ",i+1);
		scanf("%d",&array[i]);
		i++;
	}
	/*output*/
	if(compresiMultipli3(&array[0],lunghezza))
		printf("La stringa inserita contiene almeno due elementi il cui valore\ne' compreso tra -10 e 10 e che contiene esattamente due elementi multipli di 3!\n");
	else
		printf("La stringa inserita NON contiene almeno due elementi il cui valore\ne' compreso tra -10 e 10 e che contiene esattamente due elementi multipli di 3.\n");
}
