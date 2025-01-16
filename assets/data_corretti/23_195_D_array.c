/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.9
*/
/* SPECIFICHE:
 * Input: intero n, sequenza di interi;
 * Pre-condizioni: nessuna;
 * Output: intero esiste;
 * Post-condizioni: esiste ritorna 1 se nella sequenza di interi è presente una tripla
 * di elementi adiacenti in cui uno dei tre è il resto della divisione intera degli altri
 * due, altrimenti torna 0.

  *TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

/* funzione che riceve un array di interi e la sua lunghezza n e che verifica la presenza
   di una tripla di interi consecutivi per i quali uno dei tre è il resto della divisione
   intera degli altri due */
int restoDivisione(int interi[], int lunghezza){
	int esiste=0; //inizializzo a 0 perché ancora non ho trovato una tripla
	int i=0;      // variabile contatore

    /* fintanto che non ho controllato tutte le triple ed esiste è ancora false... */
	while(i<lunghezza-3 && !esiste){  //****** i<=lunghezza-3  -0.5
		/* verifico se nella tripla di interi consecutivi uno dei tre è il resto della
		 * divisione degli altri due */
         if( (interi[i]==(interi[i+1]%interi[i+2]))||
         	 (interi[i]==(interi[i+2]%interi[i+1])) ||
         	 (interi[i+1]==(interi[i]%interi[i+2])) ||
         	 (interi[i+1]==(interi[i+2]%interi[i])) ||
         	 (interi[i+2]==(interi[i]%interi[i+1])) ||
         	 (interi[i+2]==(interi[i+1]%interi[i])) )
         	esiste=1;
         else
         	i++;
	}
	return esiste;
}

/* funzione principale */
int main(){
	int dimensione; //variabile che ospiterà la dimensione dell'array

	/* INPUT */
	printf("Questo programma prende in input una sequenza di interi e ");
	printf("verifica se esiste una tripla di interi consecutivi che \nsoddisfano ");
	printf("la seguente condizione: uno dei tre deve essere il resto della divisione ");
	printf("intera degli altri due. \n\n");

	printf("Caro utente, quanti numeri vuoi inserire nella sequenza?"); //**** APPICCICATO -0.1
	scanf("%d", &dimensione);

	int sequenza[dimensione]; //dichiaro l'array con dimensione scelta dall'utente

	printf("\n");
	for(int i=0;i<dimensione;i++){
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}

    /* OUTPUT */
	if(restoDivisione(sequenza,dimensione))
		printf("La tripla di interi cercate esiste!");
	else
		printf("La tripla di interi cercata non esiste!");

}