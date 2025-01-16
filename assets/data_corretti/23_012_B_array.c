/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
*Input: una sequenza di interi 's' e un intero 'lunghezza'
*Pre-condizione: gli elementi della sequenza sono interi,
'lunghezza' e' un intero ed e' la lunghezza della sequenza 's', 'lunghezza ', 'lunghezza'>= 3
*Output: un intero 'bl' (valore booleano)
*Post-condizione: 'bl' vale 1 se in ogni tripla di elementi adiacenti
 ci sono esattamente due numeri positivi (maggiori stretti di zero) , vale 0 altrimenti.
*TIPO DI PROBLEMA: Verifica Universale*/


#include <stdio.h>

/*funzione che controlla se in ogni tripla sono presenti esattamente due interi positivi*/
int duePositivi(int s[], int l){
	//pre: l >= 3

	int bl = 1; //valore booleano
	int i = 0; //variabile contatore

	/*finche' non valuto tutte le triple e il valore booleano e' True: */
	while((i < l -2) && bl)
	{
		/*Se una tripla conseutiva non rispetta le condizioni imposto il valore booleano su false*/
		if (
			!((s[i]>0 && s[i+1]>0 && s[i+2]<0)|| //*** LO ZERO NON LO CALCOLI? -0.2
			(s[i]>0 && s[i+1]<0 && s[i+2]>0)||
			(s[i]<0 && s[i+1]>0 && s[i+2]>0))
			)
		{
			bl = 0; //valore booleano su false
		}
		i++; // altrimenti cerco la tripla dopo
	}

	return bl;

}

/*Funzione principale*/
int main(){
	int lunghezza; // lunghezza dell'array

	/*INPUT*/
	printf("Caro utente inserisci una lunghezza per la sequenza: \n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	for (int i = 0; i < lunghezza; ++i)
	{
		printf("Inserisci un intero: \n");
		scanf("%d", &sequenza[i]);
	}

	/*OUTPUT*/
	if (duePositivi(sequenza, lunghezza))
	{
		printf("in ogni tripla di elementi adiacentici ci sono esattamente due numeri positivi\n");
		printf("(maggiori stretti di 0)\n");
	} else {
		printf("in ogni tripla di elementi adiacentici NON ci sono esattamente due numeri positivi\n");
	}
}