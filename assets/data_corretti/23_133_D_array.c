/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/* SPECIFICA DEL PROBLEMA:

 * INPUT: Una sequenza di interi seq e la sua lunghezza l.

 * PRECONDIZIONI: l è la lunghezza di seq.

 * OUTPUT: Un intero 'esiste' (valore booleano).

 * POSTCONDIZIONI: 'esiste' vale 1 se all'interno della sequenza esiste una tripla di elementi adiacenti in cui uno
                    dei tre è il resto della divisione (tra elementi di tipo int) degli altri due, vale 0 altrimenti.


 * TIPO DI PROBLEMA: Verifica esistenziale. */



#include <stdio.h>



/* Funzione che riceve come parametri un array di interi seq e la sua lunghezza l e restituisce 1 se
 * all'interno della sequenza esiste una tripla di elementi adiacenti in cui uno dei tre è il resto
 * della divisione (tra elementi di tipo int) degli altri due, altrimenti restituisce 0. */
 int restoDivisione(int* seq, int l){
 	//pre: l è la lunghezza di seq.
 	int i; 									// variabile contatore
 	int esiste; 						    // variabile di esistenza

 	/* Inizializza il contatore al primo elemento della sequenza. */
 	i=0;

 	/* Inizializza la variabile di esistenza a 0 perche non ha ancora trovato nessun elemento che verifichi la proprietà. */
 	esiste=0;

 	/* Scorri tutta la sequenza finché non finisce o finché non trovi un elemento che soddisfi la proprietà. */
 	while(i<l-2 && esiste==0){

 		/* Se un elemento è uguale al resto della divisione degli altri due aggiorna il valore di 'esiste' */
 		if((seq[i]==seq[i+1]%seq[i+2] || seq[i]==seq[i+2]%seq[i+1])||
 		   (seq[i+1]==seq[i]%seq[i+2] || seq[i+1]==seq[i+2]%seq[i])||
 		   (seq[i+2]==seq[i]%seq[i+1] || seq[i+2]==seq[i+1]%seq[i]))
 			esiste=1;

 		/* Altrimenti vai avanti */
 		else
 			i++;

 	}

 	return esiste;

 }





/* Funzione principale */
int main(){
	int lunghezza;		// per la lunghezza dell'array.

    /* INPUT */
	printf("Caro utente inserisci la lunghezza della sequenza: ");
	scanf("%d", &lunghezza);
	int seq[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Inserisci un intero: ");
		scanf("%d", &seq[i]);
	}

	/* OUTPUT */
	if(restoDivisione(seq,lunghezza)){
		printf("All'interno della sequenza esiste una tripla di elementi adiacenti in cui uno ");
		printf("dei tre %c il resto della divisione (tra elementi di tipo int) degli altri due", 138);
	}
	else{
		printf("All'interno della sequenza non esiste nemmeno una tripla di elementi adiacenti in cui uno ");
		printf("dei tre %c il resto della divisione (tra elementi di tipo int) degli altri due", 138);
	}
}

