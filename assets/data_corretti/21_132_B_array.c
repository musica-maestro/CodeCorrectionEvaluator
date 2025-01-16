/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................3.5
*/
/*SPECIFICA
 * Input: una sequenza e la lunghezza della sequenza //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.5
 * Pre-condizione:la sequenza è composta da interi e la lunghezza è >=3 //******** SEQUENZA DI INTERI ANDAVA SOPRA
 * Output:un valore booleano che verifica o nega l'esistenza universale
 * Post-Condizione: l'algoritmo torna 1 se tutte le terne della sequenza contengono esattamente due elementi maggiori o uguali a 5, altrimenti 0
 * TIPO DI PROBLEMA: verifica universale*/


#include <stdio.h>

int maggiori5Pari(int array[], int len) {
	int esistenza = 1
	int cont = 0
	while (esistenza && i<len){  //********* DUE ITERAZIONI, LA FUNZIONE NON CALCOLA NULLA 0
		for (i=1;i<len-1;i++)
			if (array[i]>=5)
				cont++;
				if (array[i+1])
					cont++
			else
				i++


	}
}






int main(int argc, char **argv)
{
	int lunghezza;
	printf("Ciao utente, questo %c un programma che verifica che ogni tripla della sequenza inserita abbia esattamente 2 elementi maggiori o uguali a 5 e due elementi pari\n", 138);
	printf("Quanti interi vuoi inserire?");
	scanf("%d", &lunghezza);
	printf("Perfetto, ora inserisci gli elementi\n");
	int array[lunghezza];
	int i=0;
	for (i=0;i<lunghezza;i++){
		printf("Elemento [%d]", i+1);
		scanf("%d", &array[i]);
	}
	if (maggiori5Pari(array[],lunghezza)){ //******** COME RICHIAMI LA FUNZIONE? (maggiori5Pari(array,lunghezza)) -1
		printf("Caro utente, ogni tripla della sequenza da lei indicata ha esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari");
	}
	else
	printf("Caro utente, putroppo non tutte le triple hanno hanno esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari");

	return 0;
}
