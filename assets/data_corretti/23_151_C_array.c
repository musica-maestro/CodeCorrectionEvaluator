/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.3
*/
#include <stdio.h>

/*SPECIFICA
   Input:Una sequenza di interi 'Array' e un intero 'l'
   Pre-condizione:l'intero 'l' rappresenta la lunghezza della sequenza di interi /******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
   Output:un intero 'r'
   Post-condizione:L'intero 'r' ha valore 1 se tutte le terne adiacenti della sequenza di interi contengono almeno due numeri con una sola cifra e 0 altrimenti
   TIPO DI PROBLEMA: Verifica universale  */


int dueUnaCifra(int Array[],int l){
	int r=1; /*Risultato che se uguale a 1 verifica la mia post-condizione, mentre se 0 non la verifica */
	int i=0; /*Indice di un elemento dell'array*/
	while(i<l-1&&r==1){ /*Esco dal while se arrivo alla fine dell'array o non viene verificata la mia condizione*/
		if((Array[i]>9&&Array[i+1]>9)||
			(Array[i+1]>9)&&(Array[i+2>9])|| /*Se trovo una terna con almeno due numeri a due cifre la mia condizione diventa non verificata*/
			(Array[i]>9&&Array[i+2]>9)){ //******* ATTENZIONE! Array[i+2>9] INVECE DI Array[i+2]>9 -0.5
		   	r=0;

		}
	else
		i++; /*Se in questa terna ci sono almeno due numeri con una sola cifra passo alla terna adiacente*/
	}
	return r;
}

int main(){
	int l;  /*Intero che rappresenta la lunghezza dell'array*/
	int r;  /*Intero che rappresenta il risultato*/
	printf("Salve utente, di quanto vuoi sia composta la tua sequenza di interi?\n");
	scanf("%d",&l);  /*L'utente decide di quanto deve essere lungo l'array*/
	int Array[l];     /*Creo l'array con la lunghezza appena inserita*/
	printf("Adesso introduci gli interi che formano la tua sequenza.\n");
	for(int i=0;i<l;i++){
		scanf("%d",&Array[i]); /*Riempimento dell'array da testiera*/
	}
	r=dueUnaCifra(Array,l);  /*Invoco la funzione dueUnaCifra che mi restituisce 0 o 1*/
	if(r==1){
		printf("Tutte le terne contengono almeno due numeri di una sola cifra!\n");
	}
	else
		printf("Non tutte le terne conengono almeno due numeri di una sola cifra.\n");
}