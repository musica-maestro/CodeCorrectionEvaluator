/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...0.5
   TOTALE (10).............7.5
*/
/* SPECIFICA:
   input: una sequenza di interi s e la sua lunghezza l
   pre-condizione: l è la lunghezza di s
   output: un intero
   post-condizione:se l'intero vale 1 vuol dire che esiste
                   una tripla di elementi adiacenti in cui uno dei tre
                   e' il resto della divisione degli altri due, se vale
                   zero allora il contrario
   TIPO DI PROBLEMA: verifica esistenziale

   */



# include <stdio.h>

   int restoDivisione(int interi[], int lunghezza){

	int i;
    //****** i=0; -0.5
	for(i=1; i<lunghezza-2; i++){
		if( interi[i] == interi[i+1] % interi[i+2]  ||
             interi[i] == interi[i+2] % interi[i+1] ||
             interi[i+1] == interi[i] % interi[i+2]  ||
              interi[i+1] == interi[i+2] % interi[i]||
             interi[i+2] == interi[i+1] % interi[i] ||
             interi[i+2] == interi[i] % interi[i+1])


       return 1;//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	}
	return 0;
}


int main(){

	int lunghezza;

	printf("Ciao utente, ");
	printf("quanti interi ha la tua sequenza: ");
	scanf("%d", &lunghezza);


	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++){

	printf("Introduci gli interi della sequenza: ");

	scanf("%d", &sequenza[i]);
}

    printf("Il risultato e': %d. "); //****** DEVI RICHIAMARE LA FUNZIONE! -0.5
    //****** NON DICI SE LA CONDIZIONE E' VERIFICATA O MENO -0.5
	restoDivisione(sequenza, lunghezza); //**** QUI, COSì NON SERVE A NIENTE -0.5

	}




