/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8
*/
/*SPECIFICA
 *INPUT: una sequenza s di interi e la sua lunghezza l;
 *PRE-COND: l è una lunghezza di s
 *OUTPUT: un intero b
 *POST-COND: b è l se esiste una terna di elementi in cui è presente
            un elemneto uguale al resto della divisione tra gli altri due, 0 altrimenti
 *TIPO DI PROBLEMA: verifica universale *\     //*******NO, E' ESISTENZIALE -1

//***** MANCA */ // -0.5

#include <stdio.h>

int restoDivisione (int interi [], int lunghezza){
	for (int i=0; i<lunghezza-2; i++){
		if (interi [i]==interi [i+1]%interi [i+2] || interi[i]==interi[i+2]%interi[i+1]
			|| interi[i+1==interi[i+2] || interi[i+2] || interi[i+1]==interi[i+2]%interi[i]
			|| interi [i+2]==interi[i]%interi[i+1] || interi[i+2]==interi[i+1]%interi[i]){

	            return 1;

            }//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
    }
    return 0;

}

int main (){
	int lunghezza;
    printf("Quanti interi vuoi introdurre? ");
    scanf("%d", &lunghezza);

    int sequenza [lunghezza];
    printf("\n");
    for (int i=0; i<lunghezza; 1++){ //**** i++ -0.5
    	printf("Introduci un intero:  ");
	    scanf("%d", &sequenza[i]);
	}

	if(restoDivisione(sequenza,lunghezza))
    printf("\n Esiste una terna di elementi adiacenti nell'array in cui \
    	è presente un elemento uguale al resto della divisione tra gli altri due \n ");
    else
    	printf("\n Non è presente alcuna terna di elementi adiacenti in cui è presente \
    		un elemento uguale al resto della divisione tra glòi altri due \n ");


}







