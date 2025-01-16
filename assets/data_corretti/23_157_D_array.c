/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
#include <stdio.h>

/* SPECIFICA
Input: Un intero n ed una lista di n elementi interi
Pre-condizione: n > 0
Output: Una variabile di tipo intero(che può soltanto valere 0 o 1) denominata 'esiste'
Post-condizione: 'esiste' ha valore 1 se esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione
degli altri due, altrimenti ha valore 0
Tipo di problema: Verifica esistenziale
*/

/*Funzione ausiliaria per controllare se esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione
degli altri due*/
int esisteF(int a,int b,int c){
	int h;
	if((b != 0 && a%b == c) || (a != 0 && b%a == c)){//verifico se il primo elemento diviso il secondo(o viceversa) abbiano come resto il terzo elemento, prima mi assicuro di non effettuare una divisione per 0
		h = 1;
	}else if((c != 0 && a%c == b) || (a != 0 && c%a == b)){//verifico se il terzo elemento diviso il primo(o viceversa) abbiano come resto il secondo elemento, prima mi assicuro di non effettuare una divisione per 0
		h = 1;
	}else if((c != 0 && b%c == a ) || (b != 0 && c%b == a)){//verifico se il terzo elemento diviso il secondo(o viceversa) abbiano come resto il primo, prima mi assicuro di non effettuare una divisione per 0
		h = 1;
	}else{
		h = 0;
	}
	return h;
}

int restoDivisione(int *x,int n){
	int esiste = 0;
	for(int i = 0;i < n-2 && esiste == 0;i++){//Ciclo finchè non ho controllato ogni terna o non ho trovato terne che soddisfano la condizione
		if(esisteF(x[i],x[i+1],x[i+2]) == 1){//Utilizando la funzione ausiliaria 'esisteF' verifico se la condizione del testo è verificata
			esiste = 1;
		}
	}
	return esiste;
}


int main(){
	int n = -1,esiste = 0;
	do{
		printf("Quanti interi devono essere inseriti? Ricorda che la lunghezza deve essere un numero intero positivo: ");
		scanf("%d",&n);
	}while(n < 0);//Inserisco la lunghezza dell'array(essa deve essere un intero positivo, tramite un ciclo mi assicuro che lo sia)
	int x[n];
	for(int i = 0;i < n;i++){//Carico l'array
		printf("\nInserire un elemento intero che avra' come indice %d : ",i);
		scanf("%d",&x[i]);
	}
	esiste = restoDivisione(x,n);//Assegno il valore della funzione utilizzata alal variabile esiste, a seconda del suo valore avrò un determinato output
	if(esiste){
		printf("\nEsiste una tripla di elementi adiacenti in cui uno dei tre e' il resto della divisione degli altri due, 'esiste' ha valore %d\n", esiste);
	}else{
		printf("\nNon esiste una tripla di elementi adiacenti in cui uno dei tre e' il resto della divisione degli altri due, 'esiste' ha valore %d\n", esiste);
	}
	return 0;
}