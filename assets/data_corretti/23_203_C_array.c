/* SPECIFICA (max 1):......0.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.1
*/
/*programma che data una sequenza di interi positivi verifica se per ogni tripla di
elementi adiacenti nella sequenzza sono presenti almeno due numeri composti da una sola
cifra
INPUT:array di l elementi  //******** MANCA IL TIPO -0.2
PRE-CONDIZIONE:lunghezza array>=3  //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
OUTPUT:se per ogni tripla adiacente erano presenti almeno due interi ad una cifra //********* L'OUTPUT DEVE ESSERE UN BOOLEANO -0.2
//******* MANCA POST CONDIZIONE -0.3
*/
/*TIPO DI PROBLEMA: problema di verifica universale*/

#include <stdio.h>

int dueCifre (int* array,int l){
	int ris=1;//variabile che rappresenta il risultato
	for (int i=0;i<l-2;i++){
		if ((array[i]>=10 && array[i+1]>=10)||
		    (array[i]>=10 && array[i+2]>=10)||
		    (array[i+2]>=10 && array[i+1]>=10)||
		    (array[i]>=10 && array[i+1]>=10 && array[i+2]>=10))
			ris=0;
	}
	return ris;
}


int main(){
	int l;  //lunghezza dell'array
	printf("quanti valori vuoi inserire? ");
	scanf("%d",&l);
	int array[l]; //array
	for (int i=0;i<l;i++){
		printf("inserisci il %d numero della sequenza: ",i+1);
		scanf("%d",&array[i]);
	}
	if(dueCifre(array,l))
		printf("per ogni tripla adiacente dell'array tutte contenevano almeno due elementi composti da una sola cifra");
	else
		printf("non tutte le triple dell'array contenevano due elementi composti da una sola cifra");
}