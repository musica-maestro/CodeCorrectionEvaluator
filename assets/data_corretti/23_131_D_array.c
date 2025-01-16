/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.7
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.3
*/
/* SPECIFICA
*INPUT: x1,..., xn  //**** MANCA LA LUNGHEZZA -0.2
*PRECONDIZIONE:  x1,..., xn sono interi
*OUTPUT: un valore booleano che vale 1 se all'interno della sequenza esiste una tripla di elementi adiacenti in cui uno dei tre
* è il resto della divisione degli altri due, restituisce 0 altrimenti.
//**** METTI INSIEME OUTPUT E POSTCONDIZIONE -0-2
*TIPO DI PROBLEMA: Problema di verifica esistenziale. */





#include <stdio.h>

int restoDivisione(int sequenza[], int lunghezza){
	int esiste=0;
	int i;
	int quoziente;






	while(i<lunghezza-2){ //**** COSI' SCORRI TUTTA LA SEQUENZA ANCHE SE TROVI SUBITO UNA TERNA CHE SODDISFA -0.3
    if((sequenza[i+1]%sequenza[i+2]== 0+sequenza[i]) || (sequenza[i+2]%sequenza[i+1]==0 +sequenza[i]) ||
    	(sequenza[i]%sequenza[i+1]== 0+sequenza[i+2]) || (sequenza[i+1]%sequenza[i]== 0+sequenza[i+2]) ||
    	(sequenza[i]%sequenza[i+2]== 0+sequenza[i+1]) || (sequenza[i+2]%sequenza[i]== 0+sequenza[i+1]))
    	esiste=1;
    else
    	i++;
	}
	return esiste;
}



int main(){
	int lunghezza;
	printf("Ciao utente, quanti interi vuoi darmi?: ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for(int i=0; i<lunghezza; i++){
		printf("Dammi un elemento: ");
	    scanf("%d", &sequenza[i]);
	}

	    if(restoDivisione(sequenza,lunghezza))
	    	printf("Nella sequenza da te introdotta esiste una terna di elementi adiacenti  in cui uno dei tre e' il resto della divisione degli altri due! ");
	    else
	    	printf("Nella sequenza da te introdotta non esiste alcuna terna di elementi adiacenti  in cui uno dei tre e' il resto della divisione degli altri due! ");

}