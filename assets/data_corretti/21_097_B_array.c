/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.3
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................6,1
*/
/*SPECIFICA:
 * INPUT: UNA SEQUENZA DI NUMERI
 * PRE-CONDIZIONE: I NUMERI INSERITI DEVONO ESSERE INTERI
 * OUTPUT: 'esiste'
 * POST-CONDIZIONE: 'esiste' VALE 1 SE TUTTE LE TRIPLE CONTENGONO ESATTAMENTE DUE NUMERI MAGGIORI DI 5 E ALMENO DUE NUMERI PARI
 * VERIFICA UNIVERSALE */
#include <stdio.h>
/*funzione che data una sequenza di numeri restituisce 1 se la sequenza contiene tutte triple con esattamente due numeri maggiori di 5 e almeno due numeri pari*/
int maggiori5Pari (int array[],int dim){
	int i;  /*contatore*/
	int esiste=0;  /*variabile booleana di ritorno*/ //******** INIZIALIZZAZIONE SBAGLIATA -1
	i=0;
	for(i=0;i<dim-2;i++)   /*controllo tutti gli elementi dell'array*/ //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if(((array[i]>=5 && array[i+1]>=5 && array[i+2]<5)
		|| (array[i]>=5 && array[i+1]<5 && array[i+2]>=5)
		|| (array[i]<5 && array[i+1]>=5 && array[i+2]>=5))&&
		((array[i]%2==0 && array[i+1]%2==0 && array[i+2]%2==0)
		|| (array[i]%2==0 && array[i+1]%2==0 && array[i+2]%2!=0)
		|| (array[i]%2==0 && array[i+1]%2!=0 && array[i+2]%2==0)
		|| (array[i]%2!=0 && array[i+1]%2==0 && array[i+2]%2==0))) /*valuto la condizione per ogni tripla*/
		//******** DEVI CONTROLLARE CHE ALMENO 2 SIANO PARI, NON ESATTAMENTE 2 -1
			esiste=1; /*se la condizione e' verificata la funzione termina con valore 1*/
			else  								//******** INDENTATO MALE -0.2
				esiste=0; /*altrimenti restituisce valore 0*/
	//******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	return esiste;
	}
/*funzione principale*/
int main(int argc, char **argv)
{
	int dimensione; /*lunghezza array*/
	int i=0;     /*contatore per il riempimento dell'array*/
	printf("Programma che verifica per una sequenza di numeri interi se ogni tripla di numeri contiene \n esattamente due valori maggiori di 5 e almeno due valori pari. \n"); /**/
	printf("Lunghezza array: ");
	scanf("%d",&dimensione);     /*input da tastiera della lunghezza dell'array*/
	int array[dimensione];
	printf("Riempi l'array: ");  /*input da tastiera di ogni elemento dell'array*/
	for(i=0;i<dimensione;i++)
		scanf("%d",&array[i]);

	if(maggiori5Pari(array, dimensione))           /*richiamo la funzione maggiori5Pari*/
		printf("Ogni tripla contiene due numeri maggiori di 5 e almeno due pari"); /*se il valore restituito dalla funzione e' 1 stampa questo*/
		else //******** INDENTATO MALE -0.2
			printf("Ci sono triple che non contengono due numeri maggiori di 5 e almeno due pari"); /*se il valore restituito dalla funzione e' 0 stampa questo*/
}
