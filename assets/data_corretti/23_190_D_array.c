/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*Programma che, data una sequenza di interi, verifica se all'interno della sequenza
esiste una tripla di elementi adiacenti in cui uno dei tre è il resto della divisione
(tra elementi di tipo int) degli altri due*/

/*SPECIFICA
*INPUT: Una sequenza di interi s e la sua lunghezza l
*PRE-CONDIZIONE: l è la lunghezza della sequenza
*OUTPUT:un intero "resto"
*POST-CONDIZIONE: "resto" è pari a 1 se esiste una terna di elementi adiacenti nell'array in cui
è presente almeno un elemento multiplo di uno degli altri due, restituisce 0 altrimenti
*TIPO DI PROBLEMA: Verifica esistenziale
*/

#include <stdio.h>

int restoDivisione(int seq[],int l){
	int resto=0;
	int i=0;
	while (i<l-2 && !resto){
		if((seq[i]%seq[i+1]==seq[i+2]) ||
		(seq[i]%seq[i+2]==seq[i+1]) ||
		(seq[i+1]%seq[i+2]==seq[i]) ||
		(seq[i+1]%seq[i]==seq[i+2])||
		(seq[i+2]%seq[i]==seq[i+1])||
		(seq[i+2]%seq[i+1]==seq[i]))
			resto=1;
		else
			i++;
	}
return resto;
}
int main(){
	int len;
	int i;

	printf("Caro utente, questo %c un programma che verifica se all'interno della sequenza ",138);
	printf("esiste una tripla di elementi adiacenti in cui uno dei tre %c il resto della divisione ",138);
	printf("degli altri due\n\n");

	printf("Inserisci la lunghezza della sequenza: ");
	scanf("%d",&len);

	int array[len];

	for(i=0;i<len;i++){
		printf("Inserisci i valori della sequenza: ");
		scanf("%d", &array[i]);
	}
	if(restoDivisione(array,len)){
		printf("Esiste una terna di elementi adiacenti nella sequenza ");
		printf("in cui uno dei tre %c il resto della divisione dei altri due",138);
	}
	else{
		printf("NON Esiste una terna di elementi adiacenti nella sequenza ");
		printf("in cui uno dei tre %c il resto della divisione dei altri due",138);
	}

}