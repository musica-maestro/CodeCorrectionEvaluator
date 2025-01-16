/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
#include<stdio.h>

/* SPECIFICA:
*Input: sequenza di interi s e la sua lunghezza l;
*Pre-condizioni: l è la lunghezza di s;
*Output: valore booleano "esiste";
*Post-condizioni: "esiste" vale 1 se per ogni tripla di elementi adiacenti uno dei tre è il resto della divisione (tra elementi di tipo int) degli altri due, "esiste" vale 0 altrimenti;
*TIPOLOGIA DI PROBLEMA: problema di verifica esistenziale;
*/

/* funzione che dice se esiste almeno una tripla di elementi adiacenti nella quale un numero dei tre è uguale alla divisione (tra elementi di tipo int) degli altri due */

int restoDivisione(int * array, int l) {
	int i=0;       //variabile contatore
	int esiste=0;  //variabile esistenza
	/* scorro tutti gli elementi della sequenza */
	while(i<=l-3&&!esiste)
		/* vedo se almeno uno dei tre adiacenti, è uguale al resto della divisione di tipo int tra gli altri due */
		if(array[i]==(int)(array[i+1]%array[i+2])||array[i+1]==(int)(array[i]%array[i+2])||
		   array[i+2]==(int)(array[i]%array[i+1])||array[i]==(int)(array[i+2]%array[i+1])||
		   array[i+1]==(int)(array[i+2]%array[i])||array[i+2]==(int)(array[i+1]%array[i]))
			/* se così. cambio la variabile a true (1) */ //***** NON SERVE IL CAST, IL RISULTATO E' INTERO -0.5
			esiste=1;
		/* altrimenti */
		else
			/* vado avanti */
			i++;
		/* restituisco il valore booleano "esiste" */
		return esiste;
	}
int main() {
	int l;    //lunghezza della sequenza

	/* INPUT */

	printf("ciao, utente, sono un programma che dice se per ogni tripla ");
	printf("di elementi adiacenti, esiste almeno un numero che risulta uguale ");
	printf("al resto della divisione degli altri due\n");
	printf("ora, dammi la lunghezza della tua sequenza:\n");
	/* salvo la lunghezza dell'array */
	scanf("%d", &l);
    /* dichiaro l'array di data lunghezza */
	int array[l];
	/* chiedo tutti i numeri */
	printf("bene, ora dammi tutti i numeri:\n");
	/* salvo tutti i numeri nell'array */
	for(int i=0;i<l;i++) {
		printf("numero: \n");
		scanf("%d", &array[i]);
	}

	/* OUTPUT */

	/* se esiste almeno una tripla di interi che soddisfa la proprietà */
	if(restoDivisione(array, l))
		/* informo l'utente */
		printf("la tua sequenza rispetta la proprieta\'");
	/* se la sequenza non soddisfa la proprietà */
	else
		/* informo l'utente */
		printf("la tua sequenza non rispetta la proprieta\'");
}