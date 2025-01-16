/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.5
*/
/* SPECIFICA:
 * Input: Una sequenza di interi s e la sua lunghezza l
 * Pre-condizione: l>=3
 * Output: la variabile verificato
 * Post-condizione: Se il valore della variabile verificato è uguale ad 1 allora la condizione è verificata
 * se invece il valore della variabile verificato è 0 la condizione non è verificata.
 * tipo del programma: verifica esistenziale
 * */

#include <stdio.h>

int isCompreso(int numeri[], int lunghezza){

	int i=0;
	int compreso=0;

	while(i<lunghezza-2 && compreso==1){
		if((((numeri[i]>=-10) && (numeri[i]<=10)) && ((numeri[i+1]<=10) && (numeri[i+1]<=10))) ||
		(((numeri[i]>=-10) && (numeri[i]<=10)) && ((numeri[i+2]<=10) && (numeri[i+2]<=10))) ||
		(((numeri[i+1]>=-10) && (numeri[i+1]<=10)) && ((numeri[i+2]<=10) && (numeri[i+2]<=10)))){
			compreso=1;

		}
		else{
			i++;
		}

	}

	return compreso;
}


int isMultiplo(int numeri[], int lunghezza){

	int i=0;
	int multiplo=0;

	while(i<lunghezza-2 && multiplo==1){
		if(((numeri[i]%3==0) && (numeri[i+1]%3==0)) || ((numeri[i]%3==0) && (numeri[i+2]%3==0)) || ((numeri[i+1]%3==0) && (numeri[i+2]%3==0))){
			multiplo=1;
		}      //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
				//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		else{
			i++;

		}
	}

	return multiplo;
}

int compresiMultipli3(int numeri[],int lunghezza){
	int trovato;
	int i=0;

	trovato=0;

	while(i<lunghezza-2 && trovato==1){
		if(isCompreso(numeri,lunghezza) && isMultiplo(numeri,lunghezza)){
			trovato=1;
		}                   //****  LA FUNZIONE isCompreso  RESTITUISCE VERO SE ESISTE UNA
		else{               //****  TRIPLA CHE SODDISFA LA PRIMA CONDIZIONE
			i++;            //****  LA FUNZIONE isMultiplo RESTITUISCE VERO SE ESISTE UNA
			                //****  TRIPLA CHE SODDISFA LA SECONDA CONDIZIONE
		}                   //****  MA NON E' DETTO CHE LE DUE TRIPLE COINCIDANO!!! -2






	}
	return trovato;
}
int main()
{
	int lunghezza;

	printf("Caro utente, questo %c un programma che ti controlla se una sequenza di interi\n", 138);
	printf("contiene almeno una tripla di numeri consecutivi\n");
	printf("che contiene almeno due elementi il cui valore è compreso fra -10 e 10\n");
	printf("che contiene esattamente due elementi multipli di 3\n");
	printf("Inserisci la lunghezza: ");
	scanf("%d", &lunghezza);

	int numeri[lunghezza];

	printf("inserisci gli elementi della sequenza\n");

	for(int i=0; i<lunghezza; i++){
		scanf("%d", &numeri[i]);
	}

	compresiMultipli3(numeri,lunghezza);

	if(compresiMultipli3(numeri,lunghezza)==1){
		printf("esiste una tripla appartenente alla sequenza che soddisfa la condizione\n");
	}
	else{
		printf("NON esiste una tripla appartenente alla sequenza che soddisfa la condizione");
	}
}
