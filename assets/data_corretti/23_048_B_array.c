/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
#include<stdio.h>
/*
INPUT:SEQUENZA DI NUMERI(ARRAY DI INTERI)   //******** MANCA LA LUNGHEZZA -0.2
PRE CONDIZIONE:I NUMERI DEVONO ESSERE INTERI E ALMENO 3
OUTPUT:VARIABILE RISULTATO
POST CONDIZIONE:RISULTATO VALE 1 SE TUTTE LE TRIPLE DI NUMERI CONSECUTIVE CONTENGONO ESATTAMENTE DUE NUUMERI PARI, O ALTRIMENTI

PROBLEMA DI VERIFICA UNIVERSALE*/

int duePositivi(int a[],int n){
	int risultato=1;
	int i=0;
	while(i<n-2 && risultato){
		if(((a[i]>0) + (a[i+1]>0) + (a[i+2]>0))!=2){
			risultato=0;
		}
		else{
			i++;
		}
	}
	return risultato;


}

int main(){
	int lunghezza;
	printf("Quanto vuoi che sia lunga la sequenza ?\n");
	scanf("%d",&lunghezza);
	int array[lunghezza];

	for(int i=0;i<lunghezza;i++){
		printf("Prego inserisci l'intero: \n");
		scanf("%d",&array[i]);
	}

	if(duePositivi(array,lunghezza)){
		printf("Tutte le triple di elementi adiacenti contengono esattamente due numeri positivi\n");
	}
	else{
		printf("Non tutte le triple di elementi adiacenti contengono esattamente due numeri positivi\n");
	}
}