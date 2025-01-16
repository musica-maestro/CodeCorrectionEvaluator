/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9
*/
/*SPECIFICA
	*Input: lunghezza; sequenza di interi.
	*PRE-CONDIZIONI. lunghezza>0; ogni elemento di interi deve essere intero.
	*DATI DI USCITA: condizione.
	*POST-CONDIZIONI: condizione = 1 se in tutte le terne di elementi adiacenti almeno un elemento è multiplo di uno degli altri due; altrimenti, condizione = 0.
	*TIPO DI PROBLEMA: verifica universale. */

#include <stdio.h>

int multipli(int interi[], int lunghezza){
	int condizione = 1;
	if(lunghezza<3){
		condizione = 0;
	}
	else{
		for(int i=2; i<lunghezza && condizione; i++){
			if((interi[i]%interi[i-1]==0) || (interi[i]%interi[i-2]==0) || (interi[i-1]%interi[i]==0) ||
			   (interi[i-2]%interi[i]==0) || (interi[i-2]%interi[i-1]==0) || (interi[i-1]%interi[i-2]==0));
			   //******** PARTE IF MACANTE (MOLTO BRUTTO) -1
			else{
				condizione = 0;
			}
		}
	}
	return condizione;
}

int main(){
	int lunghezza;
	printf("Dimmi la lunghezza: ");
	scanf("%d", &lunghezza);
	int interi[lunghezza];
	printf("Inserisci i valori: \n");
	for(int i=0; i<lunghezza; i++){
		scanf("\n%d", &interi[i]);
	}

	if(multipli(interi, lunghezza)){
		printf("\nIn tutte le terne di elementi adiacenti almeno un elemento %c multiplo di uno degli altri due.", 138);
	}
	else{
		printf("\nNon in tutte le terne di elementi adiacenti almeno un elemento %c multiplo di uno degli altri due.", 138);
	}

}