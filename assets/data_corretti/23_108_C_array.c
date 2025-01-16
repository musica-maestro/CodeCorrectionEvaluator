/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.7
*/
/* SPECIFICA
 * Input: n, (x1, x2, ...,xn)
 * Pre-condizione: n>=0 (n è la lunhgezza dell'array) e (x1, x2, ...,xn) sequenza di interi //******* POSITIVI! -0.2
 * Output: valore booleano tutte
 * Post-condizione: tutte vale 1 se in ogni tripla di elementi consecutivi della sequenza
 					sono presenti almeno due numeri composti da una sola cifra //********** FALSO, ALTRIMENTI -0.1

 * TIPO DI PROBLEMA: Verifica universale */

#include <stdio.h>

/* Funzioni di supporto */
int dueUnaCifra(int seq[], int n);

/* Funzione principale */
int main(){
	/* Input */
	int lunghezza;			// Dimensione array
	printf("\nCiao utente, sono un programma che legge un array di interi e restituisce 1 o 0 se in ogni tripla di\n");
	printf("di consecutivi della sequenza sono presenti almeno due interi composti da una sola cifra\n");
	printf("\nIntroduci la lunghezza della sequenza di interi: ");
	scanf("%d", &lunghezza);
	printf("\n");

	/* Dichiaro l'array e inserisco i valori al suo interno */
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Elemento della sequenza di indice %d = ", i);
		scanf("%d", &sequenza[i]);
	}

	/* Output */
	if(dueUnaCifra(sequenza, lunghezza)){
		printf("\nIn ogni tripla di elementi consecutivi della sequenza\n");
		printf("sono presenti almeno due interi composti da una sola cifra.\n");
	}
	else{
		printf("\nO la stringa %c troppo corta oppure\n", 138);
		printf("esiste almeno una tripla di elementi consecutivi nella sequenza\n");
		printf("dove %c presente un solo intero composto da una sola cifra.\n", 138);
	}

}

/* Funzione che riceve due parametri: un array di interi e la sua lunghezza.
 * Controlla se in ogni tripla di elementi consecutivi della sequenza sono
 * presenti almeno due interi composti da una sola cifra
 * Restituisce un valore booleano */
int dueUnaCifra(int seq[], int n){
	// Pre: n>=0
	int i;					// Contatore
	int unaCifra = 1;		// Variabile d'universalità

	/* Se non ho almeno tre elementi nella sequenza non si può verificare la proprietà */
	if(n<3)
		unaCifra = 0;

	/* Controllo l'array fino al terzultimo elemento dato che ho
	 * bisogno di lavorare sulle triple di elementi consecutivi della sequenza */
	for(i=0; i<n-2 && unaCifra; i++){
		/* Controllo se esiste nella tripla di elementi consecutivi controllata
		 * esiste un solo intero composto da una sola cifra */
		if(!(((seq[i]>=-9 && seq[i]<10) && (seq[i+1]>=-9 && seq[i+1]<10)) ||
			((seq[i]>=-9 && seq[i]<10) && (seq[i+2]>=-9 && seq[i+2]<10)) ||
			((seq[i+1]>=-9 && seq[i+1]<10) && (seq[i+2]>=-9 && seq[i+2]<10))))
			unaCifra = 0;
	}
	return unaCifra;				// Valore di ritorno
}


