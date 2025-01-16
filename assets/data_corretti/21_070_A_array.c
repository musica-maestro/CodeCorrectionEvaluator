/* SPECIFICA (max 1.5):....1.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.1
*/
#include <stdio.h>
/* Specifica del problema
 *
 *
 * input:un array con lunghezza l
 * precondizioni:interi positivi o negativi  //******** MANCA LA PRECONDIZIONE LUNGHEZZA>0 -0.2
 * output:una variabile ugualieCompresi che può valere 0 o 1
 * postcondizioni:la variabile ugualieCompresi vale 1 se esistono in almeno una tripla degli elementi tali che la loro somma
 * sia compresa tra 10 e 20 e tale che abbia almeno due elementi uguali fra loro
 //******** POST-CONDIZIONE NON COMPLETA (FALSO, ALTRIMENTI) -0.2
 *
 * Tipo di problema: verifica esistenziale
 * */

int compresoDieciVenti (int seq[], int q, int k  ){      //**** BASTA PASSARE DUE INTERI, L'IMPORTANTE E' COME LI RICHIAMI
	return (seq[q]+seq[k])<=20  &&  (seq[q]+seq[k])>=10 ;
}

int ugualiCompresi (int arr[], int l) {
	int ugualieCompresi; // variabile da ritornare
	ugualieCompresi=0;
	int i; // variabile contatore
	for(i=0; (i<l-2)&&(!ugualieCompresi) ; i++){
		if ( (  compresoDieciVenti(arr,i,i+1) || compresoDieciVenti(arr,i+1,i+2) || compresoDieciVenti(arr,i,i+2) )
		&& ( arr[i]==arr[i+1]  || arr[i+1]==arr[i+2] || arr[i]==arr[i+2] ))
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

			ugualieCompresi=1;
	}
	return ugualieCompresi;
}





int main() {
	int l; // lunghezza dell'array
	int i ; // variabile contatore

	/* input */
	printf("Ciao sono un programma che verifica se almeno una tripla\n");
	printf("di una sequenza di interi rispetta le seguenti condizioni:\n");
	printf("1) La somma di due elementi e' compresa tra 10 e 20");
	printf("2) Almeno due elementi sono uguali fra loro\n");
	printf("Inserisci la lunghezza della sequenza:\n");
	scanf("%d",&l);
	/* definizione array*/
	int sequenza[l];
	for(i=0;i<l;i++){
		printf("\nInserisci il numero della sequenza\n");
		scanf("%d",&sequenza[i]);


	}
	/*output*/
	if(ugualiCompresi(sequenza,l))
		printf("La stringa contiene almeno una terna con due numeri che hanno somma compresa fra dieci e venti e due numeri uguali fra loro");
	else
		printf("La stringa non contiene almeno una terna con due numeri che hanno somma compresa fra dieci e venti e due numeri uguali fra loro");

	return 0;




}