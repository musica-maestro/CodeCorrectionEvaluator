/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA:
*Input:un numero intero n, che rappresenta la quantità di interi che l'utente vuole inserire, e una sequenza di interi positivi x1,x2,...,xn
*Pre-condizione: n>=0 e x1,x2,...xn sono interi positivi
*Output: variabile booleana triple
*Post-condizione: triple vale 1 se, nella sequenza data, ogni tripla di elementi adiacenti ha almeno 2 numeri composti da una cifra, altrimenti vale 0

TIPO DI PROBLEMA: problema di verifica universale*/

#include <stdio.h>

/*Funzione che visita ogni tripla di elementi adiacenti presente nella sequenza e verifica se in ognuna ci sono almeno 2 numeri da una sola cifra*/

int dueUnaCifra(int array[], int n){
//pre: n>=0 && array composto da numeri interi >0

	int i=0; //contatore
	int triple=1; //variabile booleana

/*visita ogni tripla di elementi della sequenza*/
	while(i<n-2 && triple)

/*esiste una tripla in cui non ci sono almeno 2 interi positivi composti da una cifra?*/
		if((array[i]>=10 && array[i+1]>=10) || (array[i]>=10 && array[i+2]>=10) || (array[i+1]>=10 && array[i+2]>=10)) //si
			triple=0;
		else //no
			i++;

	return triple;
}

/*funzione principale*/
int main(){

/*input*/
	int lunghezza;
	printf("Ciao utente, questo programma verifica se, nella sequenza inserita di interi positivi, ogni tripla di elementi adiacenti ha almeno 2 numeri composti da una sola cifra. \n");
	printf("Quanti interi positivi vuoi inserire? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for (int i = 0; i < lunghezza; i++){

		printf("Inserisci un intero positivo alla volta: ");
		scanf("%d", &sequenza[i]);
	}

/*output*/
	if(dueUnaCifra(sequenza, lunghezza))
		printf("Nella sequenza inserita ogni tripla di elementi adiacenti ha almeno 2 numeri composti da una sola cifra.");
	else
		printf("Nella sequenza inserita esiste almeno una tripla di elementi adiacenti in cui non ci sono almeno 2 numeri composti da una sola cifra.");
}