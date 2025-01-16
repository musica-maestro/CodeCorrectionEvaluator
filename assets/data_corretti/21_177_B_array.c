/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
/*SPECIFICA:
 * Input: una sequenza di interi x_1, ..., x_n e un  intero n
 * Pre-condizione: n è la dimensione della sequenza
 * Output: una variabile booleana di universalità tutti
 * Post-condizione: tutti vale true (1) se ogni tripla di elementi consecutivi nella sequenza contiene
 * esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari, tutti vale false (0) altrimenti
 *
 * TIPO DI PROBLEMA: verifica universale*/

#include <stdio.h>


/*DICHIARAZIONE FUNZIONI*/
int maggiori5Pari (int seq[], int dim);
int paro (int n);
int maggiore (int m);


/*FUNZIONE PRINCIPALE*/
int main() {
	int dimensione;					//dimensione della sequenza di interi

	/*INPUT*/
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &dimensione);

	int sequenza[dimensione];		//array di interi per la sequenza

	/*INSERIMENTO ARRAY*/
	for (int i = 0; i < dimensione; i++) {
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/*OUTPUT*/
	if(maggiori5Pari(sequenza, dimensione))
		printf("\nOgni tripla di elementi consecutivi nella sequenza contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari!\n");
	else
		printf("\nNon tutte le triple di elementi consecutivi nella sequenza contengono esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n");

}

/*Funzione che presi come parametri una sequenza di interi e la sua dimensione, restituisce 1 se ogni tripla di elementi consecutivi nella sequenza contiene
 * esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari, restituisce 0 altrimenti*/
int maggiori5Pari (int seq[], int dim) {
	//pre: dim è la dimensione di seq
	int tutti;		//variabile booleana di universalità
	int i = 0;			//per scorrere la sequenza

	/*inizializzata a true (1), cosi che se nella sequenza esiste almeno una tripla che non soddisfa la proprietà, tutti varrà false (0)*/
	tutti = 1;

	/*vai avanti fino a che l'indice della sequenza è minore della dimensione della sequenza - 2 e fino a che tutti vale true (1) */
	while(i < dim - 2 && tutti) {
		/*se la tripla corrente contiene esattamente due elementi maggiori o uguali a 5
		 * ed almeno due elementi pari allora vai alla prossima tripla, altrimenti tutti vale false (0)*/
		 if ( !( ( (maggiore(seq[i]) && maggiore(seq[i + 1]) && !(maggiore(seq[i + 2])))
		 || (maggiore(seq[i]) && maggiore(seq[i + 2]) && !(maggiore(seq[i + 1])))
		 || (maggiore(seq[i + 1]) && maggiore(seq[i + 2]) && !(maggiore(seq[i]))) )
		 && ( (paro(seq[i]) && paro(seq[i + 1])) || (paro(seq[i + 1]) && paro(seq[i + 2])) || (paro(seq[i]) && paro(seq[i + 2])) ) ) )
			 /*la tripla corrente non verifica la proprietà, per cui tutti vale false(0)*/
			 tutti = 0;
		 else
			 /*la tripla corrente soddisfa la proprietà, per cui vai alla prossima tripla*/
			 i++;
	}
	return tutti;
}

/*Funzione che preso come parametro un intero restituisce 1 se è pari, 0 altrimenti*/
int paro (int n) {
	return n%2 == 0;
}

/*Funzione che preso come parametro un intero restituisce 1 se è maggiore o uguale a 5, 0 altrimenti*/
int maggiore (int m) {
	return m >= 5;
}