/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............8
*/
/*
   SPECIFICA

 * Input: Dimensione array e tutti i valori dell'array;

 * Pre-Condizione: Numeri interi per quanto rigarda l'inserimento dentro l'array e un numero positivo per la dimesione;

 * Output: Una stringa che dirà se è si o no un istanza del problema; //*** NON UNA STRINGA, UN BOOLEANO -0.2

 * Post-condizione: La funzione restituisce 1 se l'istanza è positiva e 0 se non è positiva;
//***** RESTITUISCE 1 SE...., 0 ALTRIMENTI. DEVI SPECIFICARE QUANDO L'ISTANZA E' POSITIVA -0.3
 * TIPO DI PROBLEMA: Verifica esisteniale;

 */

#include <stdio.h>
#include <stdlib.h>


/* Questa funzione mi restituisce 1 se x, y o z tra di loro divisi il resto è uguale all'elemento della terna rimasto scoperto
   Senno torna 0 */
int condictionTerna(int x, int y, int z){
	int result = 0;
	if((x % y) == z)
		result = 1;
	else if((y % x) == z)
		result = 1;
	else if((y % z) == x)
		result = 1;
	else if((z % y) == x)
		result = 1;
	else if((x % z) == y)
		result = 1;
	else if((z % x) == y)
		result = 1;
	return result;

}
/* Questa funzione utilizza condictionTerna per determinare se la terna è di istanza positiva */
int restoDivisione(int array[], int dim){
	int result = 0;

	for (int i = 0; i < dim - 1 && result == 0; i++){//*** i<dim-2 -0.5
		if(condictionTerna(array[i], array[i + 1], array[i + 2]) == 1)
			result = 1;
	}

	return result;
}

/* Questa funzione serve semplicemente per riempire l'array */

void insertArray(int array[], int dim){
	for (int i = 0; i < dim; i++){
		printf("inserisci il %d posto dell'array: ", i);
		scanf("%d", &array[i]);
	}
}

int main(){
	int x;

	printf("Inserisci la dimensione dell'array: ");
	scanf("%d", &x);

	int array[x];

	insertArray(array, x);

	/* Stampo un testo adeguato per il risultato del problema */
	if(restoDivisione(array, x) == 1)
		printf("Questo array %c un instanza positiva del problema!!\n", 138);
	else
		printf("Questo array NON %c un instanza positiva del problema!!\n", 138);
	return 0;  //***** DEVI INDICARE QUALE PROPRIETA' VIENE VERIFICATA, OPPURE NO -1
}
