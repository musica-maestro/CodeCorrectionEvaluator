/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.2
*/
/*SPECIFICA
*INPUT: 'lunghezza' della sequenza e la sequenza stessa//******** MANCA IL TIPO -0.2
*PRE-CODIZIONE: lunghezza >=3
*OUTPUT: var intera 'risultato'
*POST-CONDIZIONE: risultato vale 1 se esiste una terna di elementi adiacenti  in cui è presente almeno un multiplo di uno degli altri due, altrimenti restituisce 0

*TIPO DI PROBLEMA: Verifica esistenziale*/

#include <stdio.h>

/*controlla se un elemento della tripla è il resto della divisione intera tra gli altri due*/
int isMultiplo(int a,int b,int c){
	return (a == b%c || a == c%b) || (b == a%c || b == c%a) || (c == a%b || c == b%a);
}


int restoDivisione(int seq[], int l){
	int esiste = 0;											//variabile di esistenza

	/*controlla se un elemento è multiplo*/
	for (int i = 0; i < l-1 && !esiste; ++i)				//ultima tripla= l-2, l-1, l //**** APPUNTO, NO! i<l-2 -0.5
	{
		/*se la condizione è vera aggiorna la variabile d'esitenza, altrimenti controlla la prossima terna*/
		if(isMultiplo(seq[i], seq[i+1], seq[i+2])){
			esiste=1;
		}
	}
	return esiste;
}


int main(){
	int lunghezza=3;										//lunghezza della sequenza di interi
	int risultato; 											//variabile risultato

	/* INPUT */
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];								//sequenza di interi

	printf("Inserire i %d interi della sequenza:\n");
	for (int i = 0; i < lunghezza; ++i)
	{
		scanf("%d", &sequenza[i]);
	}

	/*invoca la funzione ausiliaria*/
	risultato=restoDivisione(sequenza,lunghezza);

	/* OUTPUT */
	if(risultato)                                //*** NO LETTERE ACCENTATE -0.1
		printf("Nella sequenza esiste almeno una terna in cui un elemento è il resto della divisione tra gli altri due!\n");
	else
		printf("Nella sequenza non esiste nemmeno una terna in cui un elemento è il resto della divisione tra gli altri due!\n");
}