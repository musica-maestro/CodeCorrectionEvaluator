/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.3
*/
/*
SPECIFICA
Input: una sequenza numerica e la sua lunghezza
Pre-condizioni: lunghezza >=0  //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
Output: un intero RISULTATO
Post-condizioni: RISULTATO vale 1 se in ogni tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una cifra sola
 e vale 0 altrimenti
TIPO DI PROBLEMA: verifica universale
*/

#include <stdio.h>

	/* funzione che controlla se ogni tripla di elementi della sequenza contiene almeno due numeri composti da una cifra sola */
	int dueUnaCifra( int sequenza[], int lunghezza){

		int risultato = 1;
		int i=0;
		for (int i = 0; (i < lunghezza-2) && risultato; ++i){

			/* condizione che controlla se la tripla di elementi della sequenza contiene almeno due numeri composti da una cifra sola */
			if( (sequenza[i]>9 && sequenza[i]<-9) && ( (sequenza[i+1]>9 && sequenza[i+1]<-9) ||
			    (sequenza[i+2]>9 && sequenza[i+2]<-9) ) ||
				( (sequenza[i+1]>9 && sequenza[i+1]<-9) && ( (sequenza[i]>9 && sequenza[i]<-9) ||
				(sequenza[i+2]>9 && sequenza[i+2]<-9) ) ) ||
				((sequenza[i+2]>9 && sequenza[i+2]<-9) && ( (sequenza[i+1]>9 && sequenza[i+1]<-9)
				|| (sequenza[i]>9 && sequenza[i]<-9) ) )
			 ){ //******** CONDIZIONE SBAGLIATA! -2
				risultato = 0;
				return risultato;//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
			}

		}
	return risultato;

	}

int main(){

	int lunghezza;
	printf("Ciao, sono un programa che verifica se in ogni tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una cifra sola \n");
	/* faccio inserire all utente la lunghezza della sequenza */
	printf("Dammi la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	/* ora faccio inseire all utente gli elementi della sequenza */
	printf("Inserisci gli elementi della sequenza\n");
	for (int i = 0; i < lunghezza; ++i)
	{
		scanf("%d", &sequenza[i]);
	}

		if(dueUnaCifra(sequenza, lunghezza)){
			printf("Ogni tripla di elementi adiacenti della sequenza contiene almeno due numeri composti da una cifra sola\n");
		}
		else{
			printf("Non ogni tripla di elementi adiacenti della sequenza contiene almeno due numeri composti da una cifra sola\n");
		}

	return 0;
}