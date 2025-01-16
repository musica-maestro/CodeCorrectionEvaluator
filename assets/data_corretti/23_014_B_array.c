
/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...0.8
   TOTALE (10).............5.8
*/
/*SPECIFICA
*Input:array di interi, lunghezza
*Pre-condizione:valori interi
*Output:valore booleano
*Post-condizione:1 se tutte le triple di numeri adiacenti hanno 2 positivi, o altrimenti
*TIPO DI PROBLEMA:Verifica Universale*/

#include<stdio.h>
int duePositivi(int array[], int lunghezza){
	int i;
	int conta=0; //***** DEVE ESSERE =1 -1
	for(i=0;i<lunghezza-2;i++){
		if((array[i]>0 && array[i+1]>0) || (array[i+1]>0 && array[i+2]>0))
		//****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
		//****** MANCA UNA CONDIZIONE -0.5
			conta=1;
	}
	return conta;
}
int main(){
	int i; //dichiaro la variabile conteggio del ciclo for
	int n; //dichiaro la variabile lunghezza dell'array
	int conta; //dichiaro la variabile conta
	printf("quanto vuoi lunga la sequenza?"); //istruzione per assegnare la lunghezza della sequenza //***** APPICCICATO -0.1
	scanf("%d",&n);
	int array[n]; //dichiaro la sequenza array
	for(i=0;i<n;i++){
		printf("inserire il valore nella cella [%d]",i); //istruzione di stampa per assegnare a ogni cela un valore //***** APPICCICATO -0.1
		scanf("%d",&array[i]);
	}
	conta=duePositivi(array,n);
	printf("%d",conta);  //************ OUTPUT PRATICAMENTE MANCANTE -1
}